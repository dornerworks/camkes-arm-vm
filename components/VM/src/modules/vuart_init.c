/*
 * Copyright 2019, DornerWorks
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DORNERWORKS_BSD)
 */

#include <vmlinux.h>

#include <sel4arm-vmm/vm.h>
#include <sel4arm-vmm/plat/devices.h>

#include <camkes.h>

extern void *serial_getchar_buf;

//this matches the size of the buffer in serial server
#define BUFSIZE 4088

void handle_serial_console()
{
    struct {
        uint32_t head;
        uint32_t tail;
        char buf[BUFSIZE];
    } volatile *buffer = serial_getchar_buf;

    char c;
    if (buffer->head != buffer->tail) {
        c = buffer->buf[buffer->head];
        buffer->head = (buffer->head + 1) % sizeof(buffer->buf);
        vuart_handle_irq(c);
    }
}


/* Install vuart */
static void vconsole_init_module(vm_t *vm, void *cookie)
{
    vm_install_vconsole(vm, guest_putchar_putchar);
}

DEFINE_MODULE(vconsole, NULL, vconsole_init_module)
