#include <stdio.h>	// Standard input/output library
#include <string.h>	// String library, provides most functionality for strings
					// strcpy, strlen, etc.

// Creates a function named main
// Main will return an integer
// Main takes no parameters
int main(void) {
	
	//Creates a character array of max length 20
	char name[20];
	char last[20];

	//printf -> print function
	//Takes one or more parameters
	//No automatic newlines/spacimng
	printf("%p %p\n", name, last);

	printf("Enter your name: ");
	
	//Scanf -> Input function
	//First param -> "Format specifier", %<something>
	//Second param -> the memory starting address where the data should be written

	scanf("%s", name);
	printf("Hello %s\n", name);

	printf("Enter your last name: ");
	scanf("%s", last);
	printf("Hello %s %s\n", name, last);


}