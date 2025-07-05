class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size() , ans = 0;
        char prev = word[0];
        unordered_map <char,int> freq;
        for(int left = 0 , right = 0 ; right < n ; right++){
            if(prev > word[right])
                freq.clear() , left = right;
            freq[word[right]]++;
            if(freq.size() == 5) 
                ans = max(ans , right - left + 1);
            prev = word[right];
        }
        return ans;
    }
};