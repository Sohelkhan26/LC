class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> count(26);
        int n = s.size();
        for(char &c : s)
            if(c != '?')
                count[c - 'a']++;
        auto smallest = [&]() -> char {
            int mn = *min_element(count.begin(), count.end());
            for (int i = 0; i < 26; i++) {
                if (count[i] == mn) {
                    count[i]++;  // Increment as soon as you use it
                    return (char)(i + 'a');
                }
            }
            return 'a';  // fallback, never reached
        };
        vector <char>ans;
        for (int i = 0; i < n; i++) 
            if (s[i] == '?') 
                ans.push_back(smallest());
            
        sort(ans.begin() , ans.end());
        int i = 0;
        for(char &c : s)
            if(c == '?')
                c = ans[i++];
        return s;
    }
};


/*
when n > 26 ? any char will increase cost[i], to minimize cost, use char which has min count so far.
lexicographical case ? 
*/