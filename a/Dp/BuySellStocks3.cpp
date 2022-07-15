#include<bits/stdc++.h>
int f(int idx,int buy,vector<int> &prices,int n,int cap,vector<vector<vector<int>>> &dp)
{
    int profit = 0;
    if(cap == 0) return 0;
    if(idx == n) return 0;
    if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
    if(buy)
    {
      profit = max(-prices[idx]+f(idx+1,0,prices,n,cap,dp),0+f(idx+1,1,prices,n,cap,dp));
    }
    else{
      profit = max(prices[idx]+f(idx+1,1,prices,n,cap-1,dp),0+f(idx+1,0,prices,n,cap,dp));
    }
    return dp[idx][buy][cap] = profit;
}
int maxProfit(vector<int>& prices, int n)
{
    int cap =2;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,-1)));
    return f(0,1,prices,n,2,dp);
}

//Iterative