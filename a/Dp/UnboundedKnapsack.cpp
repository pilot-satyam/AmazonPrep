
#include<bits/stdc++.h>
using namespace std;
int f(int idx,int w,vector<int> &p,vector<int> &wt,vector<vector<int>> &dp)
	{
	if(idx == 0)
	{
		return ((int)(w/wt[0])) * p[0];
	}
	if(dp[idx][w]!=-1)
		return dp[idx][w];
		int nonPick = 0+f(idx-1,w,p,wt,dp);
		int Pick = 0;
		if(wt[idx] <= w){
			Pick = p[idx] + f(idx,w-wt[idx],p,wt,dp);
		}
	 return dp[idx][w]= max(Pick,nonPick);    
    }

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return f(n-1,w,profit,weight,dp);
}


//Iterative
#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

int main() {

  vector<int> wt = {2,4,6};
  vector<int> val = {5,11,13};
  int W=10;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<unboundedKnapsack
  (n,W,val,wt);
}