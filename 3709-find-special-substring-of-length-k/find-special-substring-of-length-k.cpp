class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size() , left = 0;
        for(int right = 0 ; right < n ; right++){
            if(s[left] == s[right])continue;
            if(right - left == k)
                return true;
            left = right;
        }
        return n - left == k;
    }
};

/*
Problem statement is confusing. 
Check if same characters form a sub array of length exactly k.

*/