class Solution {
public:
    int k;    
    long long int calc(int node,int par,vector<pair<int,int>> adj[],vector<int> &dp){
        priority_queue <int, vector<int>, greater<int> > pq; 
        long long int s=0;
        for(auto it:adj[node]){
            if(it.first==par) continue;
            s=s+calc(it.first,node,adj,dp);
            if(it.second>dp[it.first]) pq.push(it.second-dp[it.first]); //consider only when taking the edge is beneficial over the kth largest of child
            if(pq.size()>k) pq.pop();
        }

        if(pq.size()<k) dp[node]=0;
        else dp[node]=pq.top();  //store the kth largest one
        while(pq.size()>0) {
                s=s+pq.top();
                pq.pop();}
        return s;
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k1) {
        k=k1;
        int n=edges.size()+1;
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dp(n);
        return calc(0,-1,adj,dp);       
    }
};