#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    int mini = INT_MAX;     
    int maxProfit = 0;
    int n = prices.size();
    for(int i=0;i<n;i++)
    {
        mini = min(mini,prices[i]);
        int cost = prices[i]-mini;
        maxProfit = max(maxProfit,cost);
       // mini = min(mini,prices[i]);
    }
    return maxProfit;
}
int main()
{

}