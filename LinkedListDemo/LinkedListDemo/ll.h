#pragma once
//This will contain type definitions
//And function prototypes for our linked list class

struct node {
	char name[50];	//nodes will store names of size 50 or less
	struct node* next;		//pointer to the next node in the list
};

struct LinkedList {
	int size;			//Will track how big the list is
	struct node* head;  //Will track the most recently added item in the list
};

//Function prototype for the initialize function
void initialize(struct LinkedList* list);
void addItem(struct LinkedList* list, char* person);
void printList(struct LinkedList* listToPrint);