#include<bits/stdc++.h>
using namespace std;
int f(int idx,vector<int> &price,int n,vector<vector<int>> &dp)
{
	if(idx == 0)
	{
		return n*price[0];
	}
	if(dp[idx][n]!=-1)
		return dp[idx][n];
	int nonPick = 0 + f(idx-1,price,n,dp);
	int rodLength = idx+1; //Rodlength is taken as 1 based indexing
	int Pick = INT_MIN;
	if(rodLength <= n)
	{
		Pick = price[idx] + f(idx,price,n-rodLength,dp);
	}
	return dp[idx][n] = max (Pick,nonPick);
}

int cutRod(vector<int> &price, int n)
{
	int sz = price.size();
	vector<vector<int>> dp(sz+1,vector<int> (n+1,-1));
	return f(sz,price,n,dp);
}

//Tabulation

int f(int idx,vector<int> &price,int n,vector<vector<int>> &dp)
{
	if(idx == 0)
	{
		return n*price[0];
	}
	if(dp[idx][n]!=-1)
		return dp[idx][n];
	int nonPick = 0 + f(idx-1,price,n,dp);
	int rodLength = idx+1;
	int Pick = INT_MIN;
	if(rodLength <= n)
	{
		Pick = price[idx] + f(idx,price,n-rodLength,dp);
	}
	return dp[idx][n] = max (Pick,nonPick);
}

int cutRod(vector<int> &price, int n)
{
	int sz = price.size();
	vector<vector<int>> dp(sz+1,vector<int> (n+1,0));
	for(int n=0;n<=sz;n++)
	{
		dp[0][n] = n*price[0];
	}
	for(int idx = 1;idx <n;idx++)
	{
		for(int n = 0;n<=sz;n++)
		{
		int nonPick = 0 +dp[idx-1][n];
		int rodLength = idx+1;
		int Pick = INT_MIN;
		if(rodLength <= n)
		{
			Pick = price[idx] + dp[idx][n-rodLength];
		}
		 dp[idx][n] = max (Pick,nonPick);
		}
	}
	return dp[n-1][sz];
}
