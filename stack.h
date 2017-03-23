#include <stdlib.h>
#include <stdio.h>
#ifndef _STACK_
#define _STACK_
typedef struct STACK{
	int *s;
	int top;
	int n;
} stack;
stack *creat_stack(int n);
int stack_empty(stack *mystack);
int push(stack *mystack,int x);
int pop(stack *mystack);
#endif