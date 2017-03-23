#include <stdio.h>
#include <stdlib.h>
#ifndef _QUEUE_
#define _QUEUE_
	typedef struct queue{
		int * a;
		int tail;
		int head;
		int n;
	}queue;
	queue * creat_queue(int n);
	int enqueue(queue *myqueue,int x);
	int dequeue(queue *myqueue);
#endif
