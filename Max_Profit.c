int maxProfit(int* prices, int pricesSize){
    int buy=prices[0];
    int dif=0;
    for(int i=1;i<pricesSize; i++)
    {
        if(prices[i]<buy)
        {
            buy=prices[i];
        }
        else
        {
            if(dif < prices[i]-buy)
            dif=prices[i]-buy;
        }
    }
    return dif;
}