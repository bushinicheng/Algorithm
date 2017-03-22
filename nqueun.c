#include <stdio.h>  
#include <math.h>
#include <stdlib.h>
int check(int *a,int m,int* count,int n){
    int temp=0;
    int flag=1;
    
    if(m==0)
        return flag;
    for(int i=0;i<n;i++){
        count[i]=0;
      }
    for(int i=0;i<=m;i++){
    temp=a[i];
    count[temp]++;
    if(i<m&&abs(a[m]-a[i])==abs(m-i)){
      flag=0;
      return flag;
    }
   }
    for(int i=0;i<n;i++){
        if(count[i]>1){
            flag=0;
            return flag;
        }
    }
   return flag;
}
int try(int *a,int n,int i,int *count){
    int flag=0;
    int temp=0;
    if(i==n-1){
        for(int j=0;j<n;j++){
            a[n-1]=j;
            if(check(a,n-1,count,n))
                flag++;
        }
    }
    else{
        for(int j=0;j<n;j++){
            a[i]=j;
            if(i==0){
                temp=try(a,n,i+1,count);
                flag+=temp;
            }
            else if(a[i]!=a[i-1]&&a[i]!=a[i-1]+1&&a[i]!=a[i-1]-1&&check(a,i,count,n)){
                temp=try(a,n,i+1,count);
                flag+=temp;
            }
        }
    }
    return flag;
}

int main(){
  int n=0;
  scanf("%d",&n);
  if(n==0)
    printf("%d\n", n);
  else{
    int result =0;
    int *a=(int *)malloc(n*sizeof(int));
    int *count=(int *)malloc(n*sizeof(int));
    result=try(a,n,0,count);
    printf("%d\n",result);
  }
}
