class Solution {
public:
    int maxRepOpt1(string s) {
        int n = s.size() , ans = 0;
        unordered_map <char,int> freq;
        for(char &c : s)
            freq[c]++;
        for(char c = 'a' ; c <= 'z' ; c++){
            if(freq[c] == 0)
                continue;
            int gap = 0;
            for(int left = 0 , right = 0 ; right < n ; right++){
                gap += (s[right] != c);
                while(gap > 1)
                    gap -= (s[left++] != c);
                ans = max(ans , (freq[c] > right - left ? right - left + 1 : 0));
            }
        }
        return ans;
    }
};

/*
store freq of each char
for a-z, do sliding window
shrink if freq[c] == 0 and no move left -> wrong
shrink window if gap > 1
Only one small catch: ans will be min of longest substring with one different character & freq(c) since we may not have extra character to fill gap.
*/