/* @TAG(DATA61_BSD) */
/*
 * CAmkES tutorial part 1: components with RPC. Server part.
 */
#include <stdio.h>

/* generated header for our component */
#include <camkes.h>

void hello_say_hello(const char *str) {
    printf("Component %s saying: %s\n", get_instance_name(), str);
}