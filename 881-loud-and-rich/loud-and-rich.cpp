class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[501];
        vector <int> ans(n , -1);
        for(auto it : richer){
            int rich = it[0] , poor = it[1];
            adj[poor].push_back(rich);
        }
        function<int(int)> dfs = [&](int i) -> int{
            if(ans[i] >= 0) // If the answer was calculated for any previous dfs calls, returns immediately.
                return ans[i];
            ans[i] = i; //Input can be given such that, No other person can be reachable from i. Than that person himself is the quietest. These kind of person/node have no outdegree. Let's call them lone nodes. For lone nodes, for loop won't execute. The ans for lone nodes is itself. ans[i] = i.
            for(int j : adj[i])
                if(quiet[ans[i]] > quiet[dfs(j)])
                    ans[i] = ans[j];
            return ans[i];
        };
        for(int i = 0 ; i < n ; i++)
            dfs(i); // dfs returns the quietest person reachable from i
        return ans;
    }
};

/*
Person and node term is used interchangeably.
For every ith node we call the dfs function and ask for the quietest person reachable from i.
Which in turn calls for their respective quietest persons.If a node was previously visited, that means, it's corresponding quietest person is already calculated, dfs will return immediately.Every node will be visited once only.
*/