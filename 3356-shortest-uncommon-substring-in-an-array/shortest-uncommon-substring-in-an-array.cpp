class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        auto subs = [&](string &s){
            int n = s.size();
            vector<string> ans;
            for(int i = 0 ; i < n ; i++){
                for(int len = 0 ; i + len <= n ; len++)
                    ans.push_back(s.substr(i , len));
            }
            sort(ans.begin() , ans.end() , [&](string a , string b){
                return a.size() < b.size() or (a.size() == b.size() and a < b);
            });
            return ans;
        };
        vector<string> ans(arr.size());
        for(int i = 0 ; i < arr.size() ; i++){
            auto v = subs(arr[i]);
            for(const string &substring : v){
                bool ok = true;
                for(int j = 0 ; j < arr.size() ; j++){
                    if(i != j and arr[j].find(substring) != -1){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    ans[i] = substring;
                    break;
                }
            }
        }
        return ans;
    }
};