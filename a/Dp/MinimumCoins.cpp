int f(int idx,vector<int> &nums,int t,vector<vector<int>> &dp)
{
	if(idx == 0)
	{
		if(t%nums[0] == 0) 
			return t/nums[0];
		return 1e9;
	}
	if(dp[idx][t]!=-1) return dp[idx][t];
	int notTake = 0+f(idx-1,nums,t,dp);
	int Take = INT_MAX;
	if(nums[idx] <= t)
		Take = 1+f(idx,nums,t-nums[idx],dp);
	return dp[idx][t] = min(Take,notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
	vector<vector<int>> dp(n+1,vector<int> (x+1,-1));
	int ans = f(n-1,num,x,dp);
	if(ans >= 1e9) return -1;
	return ans;
}

// Iterative
#include <bits/stdc++.h>

using namespace std;

int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}

int main() {

  vector<int> arr ={1,2,3};
  int T=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}