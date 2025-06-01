class Solution {
public:
    int solve(int n , vector<int> &a , unordered_set<int> &diff){
        int ans = -1;
        a.emplace_back(1);
        a.emplace_back(n);
        bool verify = not diff.empty();
        for(int i = 0 ; i < a.size() ; i++){
            for(int j = i + 1 ; j < a.size() ; j++){
                int d = abs(a[j] - a[i]);
                if(verify){
                    if(diff.contains(d))
                        ans = max(ans , d);
                }else diff.insert(d);
            }
        }
        return ans;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set <int> diff;
        solve(m , hFences , diff);
        int ans = solve(n , vFences , diff) , mod = 1e9 + 7;
        return ans != -1 ? (1ll * ans * ans) % mod : ans;
    }
};