//Recursive
#include<bits/stdc++.h>
using namespace std;

//Best SOLN 
//T.C O(NLogN)
//S.c O(N)

int LengthOfLis(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        if(nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
        }
        else
        {
            int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
        // temp[idx] = nums[i];
    }
    return temp.size();
}

class Solution {
public:
    int f(int idx,int prev,vector<int> &nums,int n,vector<vector<int>> &dp)
    {
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int len = 0+f(idx+1,prev,nums,n,dp);
        if(prev == -1 or nums[prev] < nums[idx])
        {
            len = max(len,1+f(idx+1,idx,nums,n,dp)); //prev is current idx if we take present idx
        }
        return dp[idx][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        return f(0,-1,nums,n,dp);
    }
};

// Tabulated Code 

 int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       for(int idx = n-1;idx>=0;idx--)
       {
           for(int prev = idx-1;prev>=-1;prev--)
           {
       int len = 0+dp[idx+1][prev+1];
        if(prev == -1 or nums[prev] < nums[idx])
        {
            len = max(len,1+dp[idx+1][idx+1]);
        }
         dp[idx][prev+1] = len;
           }
       }
        return dp[0][-1+1];
    }

    //reduced T.C which is also required to print the subsequence
     int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
       vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i] > nums[prev])
                {
                    dp[i] = max(dp[i],1+dp[prev]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }

    