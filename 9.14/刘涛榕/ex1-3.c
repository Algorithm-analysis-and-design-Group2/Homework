#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag[100];//标记集合中的索引
int maxProfit(int *prices,int priceSize) 
{
    int maxProfit = 0;
    int curMinPrice = prices[0];
    for (int i = 0; i < priceSize; i++) 
    {
        if (prices[i] < curMinPrice) 
        {
            curMinPrice = prices[i];
        }
        if (prices[i] - curMinPrice > maxProfit) 
        {
            maxProfit =  prices[i] - curMinPrice;
            //flag[i]=1;
        }
        
        /*for(int j = 0; j < priceSize; j++) 
        {
            if(flag[j] == 1) 
            {
                printf("%d ", prices[j]);
            }
        }*/
    }
    return maxProfit;
}

int main()
{
    int priceSize;
    int prices[]={};
    scanf("%d", &priceSize);

    for(int i = 0; i < priceSize; i++) 
    {
        scanf("%d", &prices[i]);
    }

    int a = maxProfit(prices,priceSize);
    printf("%d",a);
    return 0;
}
