#include "doulinkedlist.h"
DouLinkedList* list_search(DouLinkedList* mylist,int key){
	DouLinkedList *head=mylist;
	while(head!=NULL&&head->val!=key)
		head=head->next;
	return head;
}
DouLinkedList* list_insert(DouLinkedList* mylist,int key){
	DouLinkedList *head=(DouLinkedList *)malloc(sizeof(DouLinkedList));
	head->pre=NULL;
	head->next=mylist;
        head->val=key;
	if(mylist!=NULL)
		mylist->pre=head;
	return head;
}
DouLinkedList* list_delete(DouLinkedList* mylist,int key){
	DouLinkedList *head=mylist;
	DouLinkedList *p=head;
	DouLinkedList *delete=NULL;
	if(head==NULL)
		return NULL;
	while(p!=NULL&&p->val!=key)
		p=p->next;
	delete=p;
	p=p->pre;
	if(p==NULL)
		return NULL;
	if(delete->next==NULL){
		p->next=NULL;
		delete->pre=NULL;
		free(delete);
		return head;
	}
	else{
		p->next=delete->next;
		delete->next->pre=p;
		free(delete);
		return head;
	}
}