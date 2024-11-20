/*
find the element whose count is less than k
that character surely won't be included in the answer
so we have to solve it for the left and right string without including that character and return the maximum length. 
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 or k > s.size())  
            return 0;
        if(k == 0)
            return s.size();
        vector<int> count(26);
        for(char c : s)
            count[c - 'a']++;
        int n = s.size() , i = 0;
        while(i < n and count[s[i] - 'a'] >= k)
            i++;
        if(i == n)
            return n;
        int left = longestSubstring(s.substr(0 , i) , k);
        int right = longestSubstring(s.substr(i + 1) , k);
        return max(left , right);
    }
};