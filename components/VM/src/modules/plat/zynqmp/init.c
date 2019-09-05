/*
 * Copyright 2019, DornerWorks
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DORNERWORKS_BSD)
 */
#include <autoconf.h>

#include <vmlinux.h>

#include <sel4arm-vmm/vm.h>
#include <sel4arm-vmm/plat/devices.h>

#include <camkes.h>

int WEAK camkes_dtb_untyped_count(void);
seL4_CPtr WEAK camkes_dtb_get_nth_untyped(int n, size_t *size_bits, uintptr_t *paddr);

static const struct device *linux_pt_devices[] = {
    &dev_uart0,
    &dev_uart1,
};

static const struct device *linux_ram_devices[] = {

};

static void
plat_init_module(vm_t* vm, void *cookie)
{
    int err;
    int num_camkes_dtb_objects;

    size_t size_bits;
    uintptr_t paddr;

    if(camkes_dtb_untyped_count) {
        num_camkes_dtb_objects = camkes_dtb_untyped_count();
    } else {
        num_camkes_dtb_objects = 0;
    }

    /* Install pass-through devices */
    for (int i = 0; i < sizeof(linux_pt_devices) / sizeof(*linux_pt_devices); i++) {
        for (int j = 0; j < num_camkes_dtb_objects; j++) {
            /* check if we have access to the device */
            if (camkes_dtb_get_nth_untyped(j, &size_bits, &paddr)) {
                if (paddr == linux_pt_devices[i]->pstart && (BIT(size_bits) == linux_pt_devices[i]->size)) {
                    err = vm_install_passthrough_device(vm, linux_pt_devices[i]);
                    assert(!err);
                }
            }
        }
    }
}

DEFINE_MODULE(plat, NULL, plat_init_module)
