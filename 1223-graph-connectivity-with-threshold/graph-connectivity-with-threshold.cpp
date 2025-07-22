class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector <int> parent(n + 1 , -1);
        function<int(int)> find = [&](int i){
            if(parent[i] == -1) 
                return i;
            return parent[i] = find(parent[i]);
        };
        auto Unite = [&](int a , int b){
            a = find(a) , b = find(b);
            if(a == b)
                return false;
            parent[a] = b;
            return true;
        };
        for(int i = 1 ; i <= n ; i++){
            if(i > threshold){
                for(int j = i ; j <= n ; j += i)
                    Unite(i , j);
            }
        }
        vector <bool> ans;
        for(auto &q : queries){
            int a = q[0] , b = q[1];
            ans.push_back(find(a) == find(b));
        }
        return ans;
    }
};