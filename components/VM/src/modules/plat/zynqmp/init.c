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

static const struct device *linux_pt_devices[] = {
    &dev_uart1,
};

static const struct device *linux_ram_devices[] = {

};

static void
plat_init_module(vm_t* vm, void *cookie)
{
    int err;

    /* Install pass-through devices */
    for (int i = 0; i < sizeof(linux_pt_devices) / sizeof(*linux_pt_devices); i++) {
        err = vm_install_passthrough_device(vm, linux_pt_devices[i]);
        assert(!err);
    }
}

DEFINE_MODULE(plat, NULL, plat_init_module)
