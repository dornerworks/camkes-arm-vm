/* @TAG(DATA61_BSD) */
/*
 * CAmkES tutorial part 1: components with RPC. Client part.
 */

#include <stdio.h>

/* generated header for our component */
#include <camkes.h>

/* run the control thread */
int run(void) {
    printf("Starting the client\n");
    printf("-------------------\n");

    char *shello = "hello world";
    hello_say_hello(shello);

    printf("After the client\n");
    return 0;
}