class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0 , count = 1;
        for(char &ch : s)
            if(ch == c)
                ans += count++;
        return ans;
    }
};