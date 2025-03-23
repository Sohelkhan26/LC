class Solution {
public:
    typedef long long ll;
    typedef pair <ll,ll> p;
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector <ll> dist(n , LLONG_MAX) , ways(n);
        vector <p> adj[201];
        for(auto it : roads){
            int u = it[0] , v = it[1] , time = it[2];
            adj[v].push_back({u , time}) , adj[u].push_back({v , time});
        }
        priority_queue <p , vector<p> , greater<p>> pq;
        pq.push({0 , 0});
        ways[0] = 1;
        while(not pq.empty()){
            auto [t , curr] = pq.top(); pq.pop();
            if(dist[curr] < t)
                continue;
            for(auto [nei , time] : adj[curr]){
                if(dist[nei] > t + time + 0ll){
                    ways[nei] = ways[curr];
                    dist[nei] = t + time;
                    pq.push({t + time , nei});
                }else if(dist[nei] == t + time){
                    ways[nei] = (ways[nei] + ways[curr]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};