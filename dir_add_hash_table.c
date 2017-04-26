#include "dir_hash.h"
hash_table *new_hash_table(int n){
	hash_table* mytable=(hash_table*)malloc(n*sizeof(hash_table));
	for(int j=0;j<n;j++)
		mytable[j]=NULL;
	return mytable;
}
ele* direct_address_search(hash_table* mytable,int key){
	return mytable[key];
}
void direct_address_insert(hash_table* mytable,ele* inserted){
	int temp=inserted->key;
	mytable[temp]=inserted;
}
void direct_address_delete(hash_table* mytable,ele* deleted){
	int temp=deleted->key;
	mytable[temp]=NULL;
}
void direct_address_print(hash_table* mytable,int n){
	for(int j=0;j<n;j++){
		if(mytable[j]!=NULL){
			printf("%s:\t%d\t%s:\t%c\n", "KEY",mytable[j]->key,"DATA",mytable[j]->data);
		}
	}
}

