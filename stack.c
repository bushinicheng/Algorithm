#include "stack.h"
stack *creat_stack(int n){
	stack* mystack=(stack *)malloc(sizeof(stack));
	mystack->s=(int *)malloc(n*sizeof(int));
	mystack->top=-1;
	mystack->n=n;
	return mystack;
}
int stack_empty(stack *mystack){
	if(mystack->top==-1){
		return 1;
	}
	else
		return 0;
}
int push(stack *mystack,int x){
	if(mystack->top<mystack->n-1){
		mystack->top++;
		int temp=mystack->top;
		mystack->s[temp]=x;
		return x;
	}
}
int pop(stack *mystack){
	if(!stack_empty(mystack)){
		int temp=mystack->top;
		mystack->top--;
		return mystack->s[temp];	
	}
}