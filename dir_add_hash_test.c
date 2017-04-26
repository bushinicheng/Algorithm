#include "dir_hash.h"
int main (){
	hash_table* mytable=new_hash_table(10);
	ele myele1={0,'a'};
	ele myele2={1,'b'};
	ele myele3={2,'c'};
	ele myele4={3,'d'};
	ele myele5={4,'e'};
	direct_address_insert(mytable,&myele1);
	direct_address_insert(mytable,&myele2);
	direct_address_insert(mytable,&myele3);
	direct_address_insert(mytable,&myele4);
	direct_address_insert(mytable,&myele5);
	direct_address_print(mytable,5);
}