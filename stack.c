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
	else{
		int *deleted=mystack->s;
		int n=mystack->n;
		int *s_new=(int*)malloc(2*n*sizeof(int));
		for(int i=0;i<n;i++)
			s_new[i]=deleted[i];
		mystack->top++;
		s_new[n]=x;
		mystack->s=s_new;
		mystack->n=2*n;
		free(deleted);
		return x;
	}
}
int stack_delete(stack* mystack){
	free(mystack);
}
int pop(stack *mystack){
	if(!stack_empty(mystack)){
		int temp=mystack->top;
		mystack->top--;
		return mystack->s[temp];	
	}
}