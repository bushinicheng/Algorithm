#include "queue.h"
int main (){
	queue *myqueue=creat_queue(10);
	printf("enqueue:\t%d\n",enqueue(myqueue,1));
	printf("enqueue:\t%d\n",enqueue(myqueue,110));
	printf("dequeue:\t%d\n",dequeue(myqueue));
	printf("enqueue:\t%d\n",enqueue(myqueue,12));
	printf("dequeue:\t%d\n",dequeue(myqueue));
	printf("dequeue:\t%d\n",dequeue(myqueue));
	printf("dequeue:\t%d\n",dequeue(myqueue));
	printf("dequeue:\t%d\n",dequeue(myqueue));
}