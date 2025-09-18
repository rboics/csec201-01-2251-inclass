#include <stdio.h>
#include <string.h>

void SayHello(void) {
	printf("Hello World\n");
}

void SayHello(char* name) {
	printf("Hello %s\n", name);
}