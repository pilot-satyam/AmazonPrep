int mod = 1e9+7;
int solve(int idx,vector<int> &num,int target,vector<vector<int>> &dp)
{
    if(idx == 0){
        if(target == 0 and num[0]==0) return 2;
        if(target == 0 or target == num[0]) return 1;
        return 0;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int notPick = solve(idx-1,num,target,dp);
    int Pick = 0;
    if(target >= num[idx])
        Pick = solve(idx-1,num,target-num[idx],dp);
    return dp[idx][target] = (notPick+Pick)%mod;
}

int findWays(vector<int> &num,int target)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (target+1,-1));
    return solve(n-1,num,target,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(auto &it : arr) totSum+=it;
    if(totSum-d <0 or (totSum-d)%2) return false;
    return findWays(arr,(totSum-d)/2);
}


