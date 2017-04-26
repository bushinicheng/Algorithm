//from http://www.2cto.com/kf/201408/326511.html
#include <stdio.h>
#include <stdlib.h>
#define n 10
struct Player{
	int cost;
	int vorp;
};
void free_agent_vorp(struct Player **p,int N,int P,int X){
	int **v,**who;
	v=(int **)malloc((N+1)*sizeof(int *));
	for(int i=0;i<=N;i++){
		v[i]=(int *)sizeof(X*sizeof(int));
	}
	who=(int **)malloc((N+1)*sizeof(int *));
	for(int i=0;i<=N;i++){
		who[i]=(int *)sizeof(X*sizeof(int));
	}
	for(int x=0;x<=X;x+=10){
		v[N][x]=-0x7fffffff;
		who[N][x]=0;
		for(int k=0;k<=P;k++){
			if(p[N][k].cost<=x&&p[N][k].vorp>v[N][x]){
				v[N][x]=p[N][k].vorp;
				who[N][x]=k;
			}
		}
	}
	for(int i=N-1;i>=1;i--){
		for(int x=0;x<=X;x+=10){
			v[i][x]=v[i+1][x];
			who[i][x]=0;
			for(int k=0;k<=P;k++){
				if(x-p[i][k].cost>=0&&v[i+1][x-p[i][k].cost]+p[i][k].vorp>v[i][x]){
					v[i][x]=v[i+1][x-p[i][k].cost]+p[i][k].vorp;
					who[i][x]=k;
				}
			}
		}
	}
	printf("%s = %d\n", "max value",v[1][X]);
	int amt=X;
	for(int i=1;i<=N;i++){
		int k=who[i][amt];
		if(k!=0){
			printf("第%d个位置 xuan 第%d个人",i,k);
			amt-=p[i][k].cost;//签约了一个球员后，剩余的总费用。(相当于剩余的总重量)
		}
	}
	printf("The total money spent is %d",X-amt);	
}
void main()
{
	struct Player **p;
	int N=10,P=8,X=300;//X代表总费用(背包总重量X); 
	p= (struct Player **)malloc((N+1)*sizeof(struct Player*));
	for (int i=0;i<=N;i++)
	{
		p[i]=(struct Player*)malloc((P+1)*sizeof(struct Player));
	}
	for (int i=0;i<=N;i++)
	{
		for (int j=0;j<=P;j++)
		{
			p[i][j].cost=10*(j+1);//球员的费用(相当于物品的重量，其中0号位置不使用)
			p[i][j].vorp=rand()%300;//球员的价值(相当于物品的价值，0号位置置为空)
		}
	}
	free_agent_vorp(p,N,P,X);
}