class Solution {
public:
    int maximumLength(string s) {
        int n = s.size() , ans = -1;
        vector<int> maxLen(n);
        maxLen[0] = 1;
        for(int i = 1 ; i < n ; i++)
            maxLen[i] = (s[i] == s[i - 1] ? maxLen[i - 1] + 1 : 1);
        vector<vector<int>> freq(26);
        for(int i = 0 ; i < n ; i++)
            freq[s[i] - 'a'].push_back(maxLen[i]);
        for(int i = 0 ; i < 26 ; i++){
            sort(freq[i].rbegin() , freq[i].rend());
            if(freq[i].size() > 2)
                ans = max(ans , freq[i][2]);
        }
        return ans;
    }
};