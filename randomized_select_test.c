#include <stdio.h>
int main (){
	int a[]={4,1,5,8,4,3,9,0,10,67};
	int min=0;
	min=randomized_select(a,0,9,5);
	printf("%d",min);
}