class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map <long long,int> mp;
        int n = coordinates.size() , ans = 0 , base = 1e6 + 7;
        for(int i = 0 ; i < n ; i++){
            int x1 = coordinates[i][0] , y1 = coordinates[i][1];
            long long key1 = 1ll * x1 * base + y1;
            for(int val = 0 ; val <= k ; val++){
                int x2 = x1 xor val;
                int y2 = y1 xor (k - val);
                long long key2 = 1ll * x2 * base + y2;
                ans += mp[key2];
            }
            mp[key1]++;
        }
        return ans;
    }
};