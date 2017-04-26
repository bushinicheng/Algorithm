//from https://www.kancloud.cn/windmissing/algorithms-my-answer/115234
#include <stdio.h>
#include <string.h>
#define C1 1
#define C2 3
#define NIL -1
#define DELETED -2
int m;
typedef int (*probing)(int k,int i);
//除法散列

int h(int k){
	return k%m;
}
//h2必须要与m互质
int h2(int k)
{
    return 1 + k % (m-1);
}
//线性探查
int linear_probing(int k,int i){
	return (h(k)+i)%m;
}
//二次探测
int quadratic_probing(int k,int i){
	return (h(k)+C1*i+C2*i*i)%m;
}
int double_probing(int k,int i){
	return (h(k)+i*h2(k))%m;
}
int hash_insert(int* table,int k,probing p){
	int i=0,j=0;
	do{
		j=p(k,i);
		printf("KEY:\t%d\tHASH:\t%d\n",k,j);
		if(table[j]==NIL||table[j]==DELETED){
			table[j]=k;
			return j;
		}
		i++;
	}while(i!=m);
	printf("%s\n", "overflow!");
}
int hash_search(int *table,int k,probing p){
	int i=0,j;
	while(1){

		j=p(k,i);
		if(table[j]==NIL||i==m)
			break;
		if(table[j]==k){
			printf("find it:\tKEY:\t%d\tHASH:\t%d\n",k,j);
			return j;
		}
		i++;
	}
}
void hash_delete(int *table,int k,probing p){
	int j=hash_search(table,k,p);
	if(j!=NIL)
		table[j]=DELETED;
}
void print(int *table){
	for(int i=0;i<m;i++){
		printf("%d\t",table[i]);
	}
	printf("\n\n");
}
int main(){
	int i=0,j=0;
	m=2;
	int table[2]={0};
	int a[2]={10, 22};
	probing p[3]={linear_probing,quadratic_probing,double_probing};
	char* strprobing[3]={"linear_probing","quadratic_probing","double_probing"};
	for(i=0;i<3;i++){
		printf("%s\n",strprobing[i]);
		memset(table,NIL,sizeof(table));
		for(j=0;j<2;j++)
			hash_insert(table,a[j],p[i]);
		putchar('\n');
		//print(table);
	}
	hash_insert(table,100,double_probing);
	hash_search(table,88,double_probing);
	hash_search(table,59,double_probing);
	hash_search(table,100,double_probing);
	hash_delete(table,59,double_probing);
	return 0;
}
