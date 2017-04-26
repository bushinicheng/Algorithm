#include "stack.h"
int main (){
	stack *mystack=creat_stack(1);
	printf("push:\t%d\n",push(mystack,1));
	printf("push:\t%d\n",push(mystack,110));
	printf("push:\t%d\n",push(mystack,110));
	printf("pop:\t%d\n",pop(mystack));
	printf("pop:\t%d\n",pop(mystack));
	printf("pop:\t%d\n",pop(mystack));
	printf("isempty:\t%d\n",stack_empty(mystack));
	stack_delete(mystack);

}