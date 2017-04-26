#include <stdio.h>
#include <stdlib.h>
#ifndef _DIR_ADD_HASH_TABLE_
#define _DIR_ADD_HASH_TABLE_
typedef struct Ele{
	int key;
	char data;
}ele;
typedef ele* hash_table;
hash_table* new_hash_table(int n);
ele* direct_address_search(hash_table* mytable,int key);
void direct_address_insert(hash_table* myhash,ele* inserted);
void direct_address_delete(hash_table* mytable,ele* deleted);
void direct_address_print(hash_table* mytable,int n);
#endif


