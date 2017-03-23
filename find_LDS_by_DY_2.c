#include <stdio.h>
#include <stdlib.h>
typedef struct COUNT{
	int pre;
	int val;
}count;
int lds(int *a,int n,count* mycount){
    for(int i=0;i<n;i++){
        if(mycount[i].pre!=-1)
            mycount[i].val=1;
    }
    for(int i=1;i<n;i++){
        if(mycount[i].pre!=-1){
            for(int j=0;j<i;j++){
                if(mycount[j].pre!=-1&&a[i]<a[j]&&mycount[i].val<mycount[j].val+1){
                    mycount[i].val=mycount[j].val+1;
                    mycount[i].pre=j;
                }
            }
    	}
    }
    int index=0;
    int max=0;
    for(int i=0;i<n;i++){
    	if(max<mycount[i].val&&mycount[i].pre!=-1){
    		max=mycount[i].val;
    		index=i;
    	}
        
    }
    return index;
}
int getrsv(int *a,int n,count *mycount,int index){
    int sum=mycount[index].val;
    int temp=0;
    int rsv=1;
    while(sum<n){
    	temp=mycount[index].pre;
    	if(temp!=-1){
    		mycount[index].pre=-1;
    		index=temp;
    	}
    	else{
    		rsv++;
    		index=lds(a,n,mycount);
    		sum+=mycount[index].val; 		
    	}

    }
    return rsv;
}
int main (){
    int n=0;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    count *mycount=(count *)malloc(n*sizeof(count));
    for(int i=0;i<n;i++){
        mycount[i].pre=i;
    }
    int i=0;
    while(scanf("%d",&a[i++])!=EOF);
    int index=lds(a,n,mycount);
    int max=mycount[index].val;
    int rsv=getrsv(a,n,mycount,index);
    printf("%d\n", max);
    printf("%d\n", rsv);
}
