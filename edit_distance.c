//from http://blog.csdn.net/yutianzuijin/article/details/50273335
#include <string.h>
#include <stdio.h>
#define MAX_LEN 7
int edit_distance(char* a,char* b,int operation[][MAX_LEN+1]){
    int len_a=strlen(a);
    int len_b=strlen(b);
    int dist[len_a+1][len_b+1];
    for(int i=0;i<=len_a;i++){
        dist[i][0]=i;
        operation[i][0]=3;
    }
    for(int j=0;j<=len_b;j++){
        dist[0][j]=j;
        operation[0][j]=2;
    }
    operation[0][0]=0;
    for(int i=1;i<=len_a;i++){
        for(int j=1;j<=len_b;j++){
            int cost=(a[i-1]==b[j-1]?0:1);
            int deletion=dist[i-1][j]+1;
            int insertion=dist[i][j-1]+1;
            int substitution=dist[i-1][j-1]+cost;
            if(deletion>insertion){
                if(substitution>insertion){
                    dist[i][j]=insertion;
                    operation[i][j]=2;
                }
                else{
                    dist[i][j]=substitution;
                    operation[i][j]=cost;
                }
            }
            else{
                if(substitution>deletion){
                    dist[i][j]=deletion;
                    operation[i][j]=3;
                }
                else{
                    dist[i][j]=substitution;
                    operation[i][j]=cost;
                }
            }
        }
    }
    return dist[len_a][len_b];
}
void backtrace(char* a,char* b,int operation[][MAX_LEN+1]){
    int insertion=0,deletion=0,substitution=0;
    int i,j;
    int len_a=strlen(a);
    int len_b=strlen(b);
    for(i=len_a,j=len_b;i>=0&&j>=0;){
        switch(operation[i][j]){
            case 0:
                printf("pos %d right\n", i);
                i--;
                j--;
            continue;
            case 1:
                printf("pos %d substitution (%c-->%c)\n", i,a[i-1],b[j-1]);
                i--;
                j--;
                substitution++;
                continue;
            case 2:
                printf("pos %d insert (%c)\n",i,b[j-1]); 
                j--;
                insertion++;
                continue;
            case 3:  
            printf("pos %d delete (%c)\n",i,a[i-1]);  
            i--;  
            deletion++;  
            continue;  
        }
    }
    printf("insert:%d,delete:%d,substitute:%d\n",insertion,deletion,substitution); 
}
int main(){
    char* a="hello";
    char* b="halluo";
    int len_a=strlen(a);
    int len_b=strlen(b);
    int n=len_a>len_b?len_a:len_b;
    int operation[n+1][n+1];
    edit_distance(a,b,operation);
    backtrace(a,b,operation);
    return 0;
}