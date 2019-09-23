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

cmake_minimum_required(VERSION 3.8.2)

project(camkes-arm-vm-hello-world C)

ApplyData61ElfloaderSettings(${PLATFORM} arm_hyp)

DeclareCAmkESComponent(Client SOURCES components/Client/src/client.c)
DeclareCAmkESComponent(EchoServer SOURCES components/Echo/src/echo.c)

DeclareCAmkESRootserver(hello-1.camkes)
