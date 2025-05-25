class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map <string,int> all;
        for(auto &r : responses){
            set <string> st(r.begin() , r.end());
            for(const string &s : st)
                all[s]++;
        }
        vector <pair<int,string>> freq;
        for(auto &[s , c] : all)    
            freq.push_back({c , s});
        sort(freq.begin() , freq.end() , [&](auto a , auto b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        return freq[0].second;
    }
};