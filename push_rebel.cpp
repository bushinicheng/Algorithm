//from http://blog.csdn.net/aaron_1996/article/details/47354931
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<queue>  
#define INF 0x3f3f3f3f  
#define V 205  
using namespace std;  

int height[V],over[V];  
int matcher[V][V], e_num, v_num;  
int src,des;  
queue<int>lister;  

int push_rebel(int s,int t)  
{  
       int jieguo=0;  
  
       while(!lister.empty())lister.pop();  
       memset(height,0,sizeof(height));  
       memset(over,0,sizeof(over));  
       over[s]=INF;over[t]=-INF;  
       height[s]=v_num;  
       lister.push(s);  
  
       int index,temp,i;  
       while(!lister.empty())  
       {  
               index = lister.front();  
               lister.pop();  
               for(i=1;i<=v_num;i++)  
               {  
                        temp = min(over[index],matcher[index][i]);  
                        if(temp>0&&(height[index]==height[i]+1|| index == s))//检查是否满足push操作  
                        {  
                                 matcher[index][i] -= temp;  
                                 matcher[i][index] += temp;  
                                 if(i==t)jieguo += temp;  
                                 over[index] -= temp;over[i] += temp;  
                                 if(i!=s&&i!=t)lister.push(i);//若i非源点和汇点，则压入队列  
                        }  
                        if(over[index]<=0)break;  
               }  
               if(index!=s&&index!=t&&over[index]>0)  
               {  
                       lister.push(index);  
                       height[index]++;  
               }//若index依然满溢，则增加index点的高度  
       }  
       return jieguo;  
}  
int main()  
{  
        freopen("input","r",stdin);  
        int  i,  u, v, w, ans;  
        while(scanf("%d %d",&e_num,&v_num)!=EOF)  
        {  
                  memset(matcher,0,sizeof(matcher));  
                  ans = 0;  
                  for(i = 1;i <= e_num; i++)  
                  {  
                          cin >> u >> v >> w;  
                          matcher[u][v] += w;  
                  }  
                  src = 1;des =  v_num;  
                  ans = push_rebel(src, des);  
                  cout << ans << endl;  
  
        }  
        return 0;  
}  
