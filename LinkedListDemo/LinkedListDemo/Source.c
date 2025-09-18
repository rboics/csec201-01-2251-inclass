#include <stdio.h>
#include <stdlib.h> //Needed for malloc
#include "ll.h"

//This will contain main

void main(void) {
	struct LinkedList list1; //list1 will exist on the stack
	
	//Declare a list on the heap
	//Note: list2 is a pointer that exists on the stack
	//List2 will contain the address of an unnamed LinkedList on the heap
	//Also note: that unnamed LinkedList is really just 8 bytes
	struct LinkedList* list2 = (struct LinkedList*)malloc(sizeof(struct LinkedList));

	initialize(list2);
	addItem(list2, "Rob");
	addItem(list2, "Bill");
	addItem(list2, "Matt");
	printList(list2);

	printf("%p\n", &list1);
	initialize(&list1);
	addItem(&list1, "Rob");
	addItem(&list1, "Bill");
	addItem(&list1, "Matt");
	printList(&list1);

}