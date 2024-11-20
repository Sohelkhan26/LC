/*
Apply sliding window. Main technique of sliding window is to extend and shrink the window based on some condition.
Window will be extended until the end of the string. How should we shrink the window?
The trick used here is that we allow a fixed number of unique characters in the window. If the unique characters in the window exceeds that fixed number then we shrink the window. We do this for 1..26 
*/
class Solution {
public:
    bool check(vector<int> &count , int k){
        int mx = INT_MAX;
        for(int i : count)
            if(i)
                mx = min(i , mx);
        return mx >= k;
    }
    int longestSubstring(string s, int k) {
        int maxChar = set<char> (s.begin() , s.end()).size() , ans = 0 , n = s.size();
        for(int i = 1 ; i <= maxChar ; i++){
            unordered_set <char> currChar;
            vector<int> count(26);
            for(int left = 0 , right = 0 ; right < n ; right++){
                currChar.insert(s[right]);
                count[s[right] - 'a']++;
                while(currChar.size() > i){ // shrink the window
                    char c = s[left++];
                    if(--count[c - 'a'] == 0)
                        currChar.erase(c);
                }
                if(check(count , k))
                    ans = max(ans , right - left + 1);
            }   
        }
        return ans;
    }
};