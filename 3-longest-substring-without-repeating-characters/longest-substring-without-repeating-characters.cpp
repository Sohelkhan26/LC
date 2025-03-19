class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 , n = s.size();
        unordered_map <char,int> freq;
        for(int left = 0 , right = 0 ; right < n ; right++){
            freq[s[right]]++;
            while(freq[s[right]] != 1 and left <= right)
                if(--freq[s[left++]] == 0)
                    freq.erase(s[left - 1]);
            ans = max(ans , (int)freq.size());
        }
        return ans;
    }
};