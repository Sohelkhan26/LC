class Solution {
public:
    int n;
    int dp[16];
    bool valid(int n){
        for(int i = 1 ; i <= n ; i *= 5)
            if(i == n)
                return true;
        return false;
    }
    int solve(int start , string &s){
        if(start == n)
            return 0; // can't split into any more substr
        if(dp[start] != -1)
            return dp[start];
        int ans = 1e9;
        if(s[start] == '0') // leading zero can't split at this starting point
            return ans;
        for(int len = 1 ; start + len <= n ; len++){
            string temp = s.substr(start , len); 
            if(valid(stoi(temp , nullptr , 2))) // power of 5 , leading zero handled earlier. third parameter in stoi() is the base by default 10(decimal)
                ans = min(ans , 1 + solve(start + len , s));
        }
        return dp[start] = ans;
    }
    int minimumBeautifulSubstrings(string s) {
        n = s.size();
        memset(dp , -1 , sizeof(dp));
        int ans = solve(0 , s);
        return ans == 1e9 ? -1 : ans;
    }
};

/*
Given a string split into max number of substring such that each string has no leading zero and a power of 5.
since string size is small brute force is good enough.
for a starting position try every length of substring that is valid and solve the rest of the subproblem. 
*/