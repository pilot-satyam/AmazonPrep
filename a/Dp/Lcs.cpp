#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,string &s,string &t,vector<vector<int>> &dp)
{
	if(i<0 or j<0)
		return 0;
	if(dp[i][j]!=-1) 
		return dp[i][j];
	if(s[i] == t[j])
		return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
	return dp[i][j] = 0 + max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}
int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n,vector<int> (m,-1));
	return f(n-1,m-1,s,t,dp);
}

int main()
{
string s1,s2;
cin>>s1>>s2;
cout<<lcs(s1,s2)<<endl;
}