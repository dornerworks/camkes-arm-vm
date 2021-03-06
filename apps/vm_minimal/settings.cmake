#
# Copyright 2018, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_BSD)
#

set(supported "tk1;tx1;tx2;exynos5422")
if(NOT "${PLATFORM}" IN_LIST supported)
    message(FATAL_ERROR "PLATFORM: ${PLATFORM} not supported.
         Supported: ${supported}")
endif()
if(${PLATFORM} STREQUAL "tk1")
    set(KernelArmSMMU ON CACHE BOOL "" FORCE)
    set(KernelARMSMMUInterruptEnable ON CACHE BOOL "" FORCE)
endif()

set(LibUSB OFF CACHE BOOL "" FORCE)
if(${PLATFORM} STREQUAL "exynos5422")
    set(VmPCISupport ON CACHE BOOL "" FORCE)
    set(VmVirtioNet ON CACHE BOOL "" FORCE)
    set(VmInitRdFile ON CACHE BOOL "" FORCE)
endif()
