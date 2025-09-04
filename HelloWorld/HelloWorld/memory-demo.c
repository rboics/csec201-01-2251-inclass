#include <stdio.h>

int main(void) {
	int x = 1;
	char y = 'A';
	float z = 2.5;

	//Access the contents of each veriable
	// %p -> format specifier for printing memory addresses
	// & -> "memory address that the variable begins at"

	//Notice: when using scanf with a single variable, we need &
	scanf("%d", &x);

	printf("%d \t %p\n", x, &x);
	printf("%c \t %p\n", y, &y);
	printf("%f \t %p\n", z, &z);



}