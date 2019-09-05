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
#include <camkes.h>
#include <sel4/sel4.h>

#include <vka/vka.h>

/*? macros.show_includes(me.instance.type.includes) ?*/

/*- set ep = alloc("irq_init_ep", seL4_EndpointObject, read=True, write=True, grant=True) -*/
/*- set cnode = alloc_cap('cnode', my_cnode, write=True) -*/

seL4_CPtr /*? me.interface.name ?*/_get_irq(vka_t *vka, int irq, int affinity) {

    int error;
    seL4_MessageInfo_t info = seL4_MessageInfo_new(0, 0, 0, 2);

    seL4_SetMR(0, affinity);
    seL4_SetMR(1, irq);

    seL4_Send(/*? ep ?*/, info);

    seL4_CPtr irq_idx;

    error = vka_cspace_alloc(vka, &irq_idx);
    ZF_LOGF_IF(error != 0, "Failed to allocate cslot\n");

    cspacepath_t slot;
    vka_cspace_make_path(vka, irq_idx, &slot);

    seL4_SetCapReceivePath(/*? cnode ?*/, irq_idx, seL4_WordBits);

    info = seL4_Recv(/*? ep ?*/, NULL);
    ZF_LOGF_IF(seL4_MessageInfo_get_extraCaps(info) != 1, "Did not get cap from InitIRQ\n");

    return irq_idx;
}
