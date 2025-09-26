#include <stdio.h>	//<> used for C libraries
#include "Hello.h"	//"" used for user-defined libraries
					//    in the same project folder
#include <string.h>


int main(void) {
	char name[50];
	printf("Enter your name: ");
	scanf("%s", name);
	SayHello(name);
	
}