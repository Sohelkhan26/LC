class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>> v;
        int n = grid.size() , m = grid[0].size() , point = 0;
        for(int i = 0 ; i < queries.size() ; i++)
            v.push_back({queries[i] , i});
        sort(v.begin() , v.end());
        vector <int> ans(queries.size() , n * m);
        priority_queue <vector<int> , vector<vector<int>> , greater<> > pq;
        int dir[] = {1 , 0 , -1 , 0 , 1};
        vector<vector<bool>> vis(n , vector<bool> (m));
        pq.push({grid[0][0] , 0 , 0});
        vis[0][0] = true;
        for(auto [limit , index] : v){
            while(not pq.empty() and pq.top()[0] < limit){
                auto it = pq.top(); pq.pop();
                int val = it[0] , i = it[1] , j = it[2];
                point++;
                for(int k = 0 ; k < 4 ; k++){
                    int newI = i + dir[k] , newJ = j + dir[k + 1];
                    if(min(newI , newJ) >= 0 and newI < n and newJ < m and not vis[newI][newJ])
                        pq.push({grid[newI][newJ] , newI , newJ}) , vis[newI][newJ] = true;
                }
            }
            ans[index] = point;
        }
        return ans;
    }
};

/*
If for a query i, point is 10 then for a bigger query point will be at least 10(could be greater).
Process the queries in ascending order.
*/