#include <stdio.h>
#include <time.h>  
int main (){  
    int i;  
    mysrand (time (NULL));  
    for (i = 0; i < 100; i++){  
      	printf("%ld,\t",myrand (1,100));  
    	//myrand (2,50)
      }

    return 0;  
} 