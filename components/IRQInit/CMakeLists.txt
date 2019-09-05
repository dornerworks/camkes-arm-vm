#
# Copyright 2019, DornerWorks
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DORNERWORKS_BSD)
#

cmake_minimum_required(VERSION 3.8.2)

project(IRQInit C)

file(GLOB src src/*.c)

# Declare the CAmkES VM component
DeclareCAmkESComponent(
    IRQInit
    SOURCES
    src/irq_init.c
    LIBS
    sel4camkes sel4allocman
)
