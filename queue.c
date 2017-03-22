#include "queue.h"
queue * creat_queue(int n){
	queue *myqueue=(queue*)malloc(sizeof(queue));
	myqueue->a=(int *)malloc(n*sizeof(int));
	myqueue->head=-1;
	myqueue->tail=-1;
	myqueue->n=n;
	return myqueue;
}
int enqueue(queue *myqueue,int x){
	int temp=0;
	if(myqueue->head==-1){
		myqueue->head=myqueue->tail=0;
		myqueue->a[temp]=x;
	}
	else{
		myqueue->tail=myqueue->tail%myqueue->n+1;
		if(myqueue->tail!=myqueue->head-1){
			temp=myqueue->tail;
			myqueue->a[temp]=x;
		}
	}
	return x;
}
int dequeue(queue *myqueue){
	if(myqueue->tail==myqueue->head){
		int temp=myqueue->head;
		myqueue->head=myqueue->tail=-1;
		return myqueue->a[temp];
	}
	else{
		int temp=0;
		temp=myqueue->head;
		myqueue->head=myqueue->head+1;
		return myqueue->a[temp];
	}
}