// Problem Statement
// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
// You need to figure out the total number of ways W, in which you can make a change for value V using coins
//  of denominations from D. Print 0, if a change isn't possible.

//Recursive DP Solution
#include<bits/stdc++.h>

long f(int idx,int t,int *a,vector<vector<long>> &dp)
{
	if(idx==0){
		return (t%a[idx] == 0);
	}
	if(dp[idx][t]!=-1)
		return dp[idx][t];
	long nonPick = 0 + f(idx-1,t,a,dp);
	long Pick = 0;
	if(a[idx] <= t)
	{
		Pick = f(idx,t-a[idx],a,dp);
	}
	return dp[idx][t] = nonPick+Pick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
	vector<vector<long>> dp(n+1,vector<long> (value+1,-1));
    return f(n-1,value,denominations,dp);
}


//Iterative Solution
long countWaysToMakeChange(int *a, int n, int value)
{
	vector<vector<long>> dp(n,vector<long> (value+1,0));
    for(int t = 0;t<=value;t++)
	{
		dp[0][t] = (t%a[0] == 0);
	}
	for(int idx = 1;idx<n;idx++)
	{
		for(int t=0;t<=value;t++)
		{
			long nonPick = dp[idx-1][t];
	        long Pick = 0;
	        if(a[idx] <= t)
		     Pick = dp[idx][t-a[idx]];
	          dp[idx][t] = nonPick+Pick;
		}
	}
	return dp[n-1][value];
}