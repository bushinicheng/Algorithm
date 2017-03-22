#include <stdio.h>
#include <stdlib.h>
#ifndef _DOULINKEDLIST_
#define _DOULINKEDLIST_
typedef struct DouLinkedList{
	struct DouLinkedList* pre;
	struct DouLinkedList* next;
	int val;
}DouLinkedList;
DouLinkedList* list_search(DouLinkedList* mylist,int key);
DouLinkedList* list_insert(DouLinkedList* mylist,int key);
DouLinkedList* list_delete(DouLinkedList* mylist,int key);
#endif