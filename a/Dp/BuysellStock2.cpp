#include<bits/stdc++.h>
long f(int idx,int buy,long *values,int n,vector<vector<long>> &dp)
{
    long profit = 0;
    if(idx == n)
        return 0;
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    if(buy)
    {
        profit = max(-values[idx]+f(idx+1,0,values,n,dp),0+f(idx+1,1,values,n,dp));
      }
    else
    {
        profit = max(values[idx]+f(idx+1,1,values,n,dp) , 0+f(idx+1,0,values,n,dp));
    }
    return dp[idx][buy] = profit;
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n,vector<long> (2,-1));
   return f(0,1,values,n,dp);
}