class Solution {
public:
    string minWindow(string s, string t) {
        vector <int> freq(128);
        for(char &c : t)
            freq[c]++;
        int n = s.size() , len = n + 1 , target = t.size() , start = 0;
        for(int left = 0 , right = 0 ; right < n ; right++){
            if(freq[s[right]]-- > 0) // negative means extra character are in window
                target--; // don't decrease count for extra characters
            while(target == 0){
                if(right - left + 1 < len)
                    start = left , len = right - left + 1;
                if(freq[s[left++]]++ == 0) // char not present in 't' will have negative frequency
                    target++; // shrink window for extra characters
            }
        }
        return len == n + 1 ? "" : s.substr(start , len);
    }
};