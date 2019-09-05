/*
 * Copyright 2019, DornerWorks
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DORNERWORKS_BSD)
 */

#include <stddef.h>
#include <sel4/sel4.h>
#include <camkes/tls.h>
#include <simple/simple_helpers.h>
#include <vka/vka.h>

/*? macros.show_includes(me.instance.type.includes) ?*/

/*- set ep = alloc("irq_init_ep", seL4_EndpointObject, read=True, write=True, grant=True) -*/
/*- set cnode = alloc_cap('cnode', my_cnode, write=True) -*/

/*- set irq_list = configuration[me.instance.name].get('irqs') -*/

static int is_irq_configured(int irq) {
    switch(irq) {
    /*- if irq_list is not none -*/
    /*- for irq in irq_list -*/
    case /*? irq ?*/:
        return true;
    /*- endfor -*/
    /*- endif -*/
    default:
        return false;
    }
}

#define NUM_PPI 32
#define IRQ_IS_PPI(irq) ((irq) < NUM_PPI)

extern vka_t vka;
extern simple_t camkes_simple;

int /*? me.interface.name ?*/__run(void) {

    int error;
    seL4_MessageInfo_t info;

    while(1) {

        info = seL4_Recv(/*? ep ?*/, NULL);
        if (seL4_MessageInfo_get_length(info) != 2)
        {
            ZF_LOGE("Improper message length from VMM\n");
            seL4_Send(/*? ep ?*/, info);
            continue;
        }

        seL4_Word core = seL4_GetMR(0);
        seL4_Word irq = seL4_GetMR(1);

        if (!IRQ_IS_PPI(irq) || !is_irq_configured(irq) || core > CONFIG_MAX_NUM_NODES)
        {
            ZF_LOGE("WARNING: VMM Passed in invalid arguments\n");
            seL4_Send(/*? ep ?*/, info);
            continue;
        }

        seL4_CPtr cap;
        cspacepath_t dest;

        /* allocate a cslot for the irq cap */
        error = vka_cspace_alloc(&vka, &cap);
        ZF_LOGF_IF(0 != error, "Failed to allocate cslot for irq\n");

        vka_cspace_make_path(&vka, cap, &dest);

        /* Switch to the proper core */
        error = seL4_TCB_SetAffinity(camkes_get_tls()->tcb_cap, core);
        ZF_LOGF_IF(0 != error, "Failed to switch to core");

        /* Turn on PPI for that core */
        error = seL4_IRQControl_Get(simple_get_irq_ctrl(&camkes_simple), irq,
                                    dest.root, dest.capPtr, dest.capDepth);
        ZF_LOGF_IF(seL4_NoError != error, "Failed to turn on irq\n");

        /* Share cap with calling core */
        info = seL4_MessageInfo_new(0, 0, 1, 0);
        seL4_SetCap(0, dest.capPtr);
        seL4_Send(/*? ep ?*/, info);

        error = seL4_TCB_SetAffinity(camkes_get_tls()->tcb_cap, 0);
        ZF_LOGF_IF(0 != error, "Failed to switch back to core 0");
    }
}
