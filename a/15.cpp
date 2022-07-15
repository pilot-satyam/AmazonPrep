#include<bits/stdc++.h>
using namespace std;

void dfs(int node,stack<int> &st,vector<int> &vis,vector<int> adj[]){
    vis[node] = 1; //marking the node as visited 
    for(auto it : adj[node]) //looping over its adjacent nodes
    { 
        if(!vis[it])
        {
            dfs(it,st,vis,adj);
        }
    }
    st.push(node);
}

void revDfs(int node,vector<int> &vis,vector<int> transpose[])
{
    cout<<node<<" ";
    vis[node] = 1;
    for(auto it : transpose[node])
    {
        if(!vis[it])
        {
            revDfs(it,vis,transpose);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); //since directed graph
    }
    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i]){
            dfs(i,st,vis,adj);
        }
    }
//Step 2
    vector<int> transpose[n];
    for(int i=0;i<n;i++){
        vis[i] = 0; //mark all as zero since they are already marked 1 earlier
        for(auto it : adj[i]){
            transpose[it].push_back(i); //Reveresed since earlier the call was made from 'i' to 'it' but here 'it' to 'i'
        }
    }
//Step 3
while(!st.empty())
{
    int node = st.top();
    st.pop();
    if(!vis[node]){
        cout<<"SCC:";
        revDfs(node,vis,transpose);
        cout<<endl;
    }
}
}

// 2nd Method
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	vector<int> order;
	
	void dfs(int src,vector<int> &vis,vector<int> g[])
	{
	    vis[src] = 1;
	    for(auto x : g[src])
	    {
	        if(!vis[x]){
	            dfs(x,vis,g);
	        }
	    }
	    order.push_back(src);
	}
	
	void rdfs(int src,vector<int> &vis1,vector<int> rev[])
	{
	    
	    vis1[src] = 1;
	    for(auto x : rev[src])
	    {
	        if(!vis1[x])
	        {
	            rdfs(x,vis1,rev);
	        }
	    }
	    
	}
	
	
    int kosaraju(int V, vector<int> adj[])
    {
       order.clear();
       vector<int> rev[V];
       for(int y=0;y<V;y++){
           for(auto x:adj[y]){
               rev[x].push_back(y);
           }
       }
       vector<int> vis(V,0);
       for(int i=0;i<V;i++)
       {
           if(!vis[i])
           {
               dfs(i,vis,adj);
           }
           
       }
       
       vector<int> vis1(V,0);
       int com = 0;
       for(int i=V-1;i>=0;i--)
       {
           if(!vis1[order[i]])
           {
               rdfs(order[i],vis1,rev);
               com++;
           }
       }
       return com;
       
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}
    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }
    return 0;
}