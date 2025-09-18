//This will contain the implementations of
//the functions whose prototypes are in ll.h
//NOTE: best practice is to name the header file
//the same as the source file, but there's no enforcement
#include <stdio.h>
#include <stdlib.h> //Contains the definition of malloc
#include <string.h>
#include "ll.h"

void initialize(struct LinkedList* list) {
						//IF we passed in struct LinkedList list instead	
	list->size = 0;		//list.size = 0;
	list->head = NULL;  //list.head = NULL;
}

void addItem(struct LinkedList* list, char* person) {
	//Goal: Create a new node, copy person into that node, and add the node to list

	//Create a new node
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	//Copy person into our new node
	strcpy(newNode->name, person);

	//Make the new node point at the previous of the list
	newNode->next = list->head;	

	//Make new node be the head
	list->head = newNode;
	//Increment size to reflect the change
	list->size++;
}

void printList(struct LinkedList* listToPrint) {
	struct node* temp = listToPrint->head; //find the head of the list
	if (temp == NULL) {
		printf("List is empty\n");
		return;
	}
	while (temp != NULL) {
		printf("%s -> ", temp->name);
		temp = temp->next;
	}
	printf("NULL\n");
}
