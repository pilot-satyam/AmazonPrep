T.C -> O(n*w)
S.c -> O(n*w) + O(n)

int f(int idx,int w,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp)
{
	if (idx == 0)
	{
		if(wt[0] <= w) return val[0];
		else 
			return 0;
	}
	if(dp[idx][w]!=-1) return dp[idx][w];
	int notTake = 0 + f(idx-1,w,wt,val,dp);
	int Take = INT_MIN;
	if(wt[idx] <= w)
		Take = val[idx] + f(idx-1,w-wt[idx],wt,val,dp);
	return dp[idx][w] = max(notTake,Take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//int n = weight.size();
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}