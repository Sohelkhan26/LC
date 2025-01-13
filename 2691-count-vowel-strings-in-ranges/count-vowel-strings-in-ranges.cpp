class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector <int> pref(n);
        auto check = [&](string s) -> bool{
            set <char> st = {'a' , 'e' , 'i' , 'o' , 'u'};
            return st.contains(s[0]) and st.contains(s[s.size() - 1]);
        };
        pref[0] = check(words[0]);
        for(int i = 1 ; i < n ; i++)
            pref[i] = pref[i - 1] + check(words[i]);
        vector <int> ans;
        for(auto it : queries){
            int l = it[0] , r = it[1];
            ans.push_back(pref[r] - (l == 0 ? 0 : pref[l - 1]) );
        }
        return ans;
    }
};