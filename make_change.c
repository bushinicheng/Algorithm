//from http://haolloyin.blog.51cto.com/1177454/352115/
/**  
 * 硬币找零：动态规划算法  
 *   
 * @param values  
 *            :保存每一种硬币的币值的数组  
 * @param valueKinds  
 *            :币值不同的硬币种类数量，即coinValue[]数组的大小  
 * @param money  
 *            :需要找零的面值  
 * @param coinsUsed  
 *            :保存面值为i的纸币找零所需的最小硬币数  
 */ 
#include <stdio.h>
void make_change(int values[],int valueKinds,int money,int coinsUsed[]){
	for(int i=0;i<=money;i++){
		coinsUsed[i]=0;
	}
	//coinsUsed[0]=0;
	int cents=0;
	for(cents=1;cents<=money;cents++){
		int minCoins=cents;
		for(int kind=0;kind<valueKinds;kind++){
			if(values[kind]<=cents){
				int temp=coinsUsed[cents-values[kind]]+1;
				if(temp<minCoins){
					minCoins=temp;
					coinsUsed[cents]=minCoins;
				}
			}
		}
	}
	printf("money %d :changes %d\n",cents,coinsUsed[money]);
}
int main(){
	int valueKinds=5;
	int coinvalue[]={25,21,10,5,1};
	int money=63;
	int coinsUsed[money+1];
	make_change(coinvalue,valueKinds,money,coinsUsed);
}