#include <stdio.h>
#include <stdlib.h>
int lds(int *a,int n,int* count){
    for(int i=0;i<n;i++){
        if(count[i]>0)
            count[i]=1;
    }
    for(int i=1;i<n;i++){
        if(count[i]<0)
            continue;
        for(int j=0;j<i;j++){
            if(count[j]>0&&a[i]<a[j]&&count[i]<count[j]+1)
                count[i]=count[j]+1;
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        max=max<count[i]?count[i]:max;
    }
    return max;
}
int getrsv(int *a,int n,int *count,int max){
    int sum=max;
    int rsv=1;
    while(sum<n){
        int min=1;
        if(max>1){
            for(int i=0;i<n&&min<max;i++){
                if(count[i]>min){
                    count[i]=-1;
                    min++;
                }
            }
        }
        else{
            for(int i=0;i<n&&min<max;i++){
            if(count[i]==min){
                count[i]=-1;
                break;
            }
        }
        }
        max=lds(a,n,count);
        sum+=max;
        rsv++;
    }
    return rsv;
}
int main (){
    int n=0;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    int *count=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        count[i]=1;
    }
    int i=0;
    while(scanf("%d",&a[i++])!=EOF);
    int len=lds(a,n,count);
    int rsv=getrsv(a,n,count,len);
    printf("%d\n", len);
    printf("%d\n", rsv);

}
