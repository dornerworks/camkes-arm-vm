/*
 * Copyright 2019, DornerWorks
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DORNERWORKS_BSD)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <simple/simple.h>
#include <simple/simple_helpers.h>
#include <allocman/allocman.h>
#include <allocman/bootstrap.h>
#include <allocman/vka.h>
#include <vka/vka.h>
#include <vspace/vspace.h>
#include <sel4utils/vspace.h>

/* Global variables for seL4 Environment used in system_init */
static allocman_t *allocman;
static char allocator_mempool[8388608];
static vspace_t vspace;
static sel4utils_alloc_data_t vspace_data;

vka_t vka;
simple_t camkes_simple;

void camkes_make_simple(simple_t *simple);

/* Create the seL4 Management tools for DMA, Hardware Access, etc... */
static void init_system(void)
{
    int error UNUSED;

    /* Camkes adds nothing to our address space, so this array is empty */
    void *existing_frames[] = {
        NULL
    };

    /* Create the simple runtime environment. Has untyped, frames, etc... */
    camkes_make_simple(&camkes_simple);

    /* Initialize allocator */
    allocman = bootstrap_use_current_1level(
            simple_get_cnode(&camkes_simple),
            simple_get_cnode_size_bits(&camkes_simple),
            simple_last_valid_cap(&camkes_simple) + 1,
            BIT(simple_get_cnode_size_bits(&camkes_simple)),
            sizeof(allocator_mempool), allocator_mempool
    );
    ZF_LOGF_IF(allocman == NULL, "Failed to create allocman");

    error = allocman_add_simple_untypeds(allocman, &camkes_simple);

    ZF_LOGF_IF(error, "Failed to add untypeds to allocman");
    allocman_make_vka(&vka, allocman);

    /* Initialize the vspace */
    error = sel4utils_bootstrap_vspace(&vspace, &vspace_data,
                                       simple_get_init_cap(&camkes_simple, seL4_CapInitThreadPD), &vka,
                                       NULL, NULL, existing_frames);
    ZF_LOGF_IF(error, "Failed to add untypeds to allocman");
}

void pre_init(void)
{
    /* initialize seL4 allocators and give us a half sane environment */
    init_system();
}
