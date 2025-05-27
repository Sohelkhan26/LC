class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0;
        int n = s.size();
        unordered_map <char,vector<int>> prev;
        auto mirror = [&](char c){
            return ('z' - c) + 'a';
        };
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(not prev[mirror(c)].empty()){
                ans += i - prev[mirror(c)].back();
                prev[mirror(c)].pop_back();
            }else prev[c].push_back(i);
        }
        return ans;
    }
};