#include "doulinkedlist.h"
int main (){
	DouLinkedList *mylist=NULL;
	DouLinkedList *p=mylist;
	mylist=list_insert(mylist,1);
	mylist=list_insert(mylist,1);
	mylist=list_insert(mylist,1);
	mylist=list_insert(mylist,1);
    p=mylist;
	while(p!=NULL){
		printf("%d\t",p->val);
		p=p->next;
	}
	putchar('\n');
	
	mylist=list_insert(mylist,2);
        p=mylist;
	while(p!=NULL){
		printf("%d\t",p->val);
		p=p->next;
	}
	putchar('\n');
	mylist=list_insert(mylist,3);
        p=mylist;
	while(p!=NULL){
		printf("%d\t",p->val);
		p=p->next;
	}
	putchar('\n');
	mylist=list_delete(mylist,1);
        p=mylist;
	while(p!=NULL){
		printf("%d\t",p->val);
		p=p->next;
	}
	putchar('\n');
	mylist=list_search(mylist,1);
        p=mylist;
	while(p!=NULL){
		printf("%d\t",p->val);
		p=p->next;
	}
	putchar('\n');
	mylist=list_search(mylist,2);
        p=mylist;
	while(p!=NULL){
		printf("%d\t",p->val);
		p=p->next;
	}
	putchar('\n');
	mylist=list_search(mylist,3);
        p=mylist;
	while(p!=NULL){
		printf("%d\t",p->val);
		p=p->next;
	}
	putchar('\n');
}