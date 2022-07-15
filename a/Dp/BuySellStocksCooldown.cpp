#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int idx,int buy,vector<int> &prices,vector<vector<int>> &dp)
    {
        int n = prices.size();
        if(idx >= n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[idx]+f(idx+1,0,prices,dp),0+f(idx+1,1,prices,dp));
        }
        else
        {
            profit = max(prices[idx]+f(idx+2,1,prices,dp),0+f(idx+1,0,prices,dp));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return f(0,1,prices,dp);
    }
};

//Iterative

 int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy =0;buy<=1;buy++)
            {
                if(buy==1)
        {
            dp[idx][buy] = max(-prices[idx]+dp[idx+1][0],0+dp[idx+1][1]);
        }
        else
        {
            dp[idx][buy] = max(prices[idx]+dp[idx+2][1],0+dp[idx+1][0]);
        }
            }
        }
        return dp[0][1];
    }

//Space Optimised And TC Optimised Solution
//T.C - O(n)
//S.c - O(6)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> cur(2,0);
        for(int idx=n-1;idx>=0;idx--)
        {
           
        
           cur[1] = max(-prices[idx]+front1[0],0+front1[1]);
        
        
        
            cur[0] = max(prices[idx]+front2[1],0+front1[0]);
            front2 = front1;
            front1 = cur;
        
            }
        return cur[1];
        }
   
};