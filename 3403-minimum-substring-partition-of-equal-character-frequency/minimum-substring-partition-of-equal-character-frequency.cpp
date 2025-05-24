class Solution {
public:
    int dp[1001] , Max = 10000;
    bool balanced(vector <int> &freq){ // check balanced or not
        int same = -1;
        for(int i : freq){
            if(not i)continue;
            if(same == -1)
                same = i;
            if(same != i) // all the non-zero frequency should be same in this string.
                return false;
        }
        return true;
    }
    int solve(const string &s , int i){ // min no of substring you can partition "s" into, starting from i
        if(i == s.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        vector <int> freq(26);
        int ans = Max;
        for(int j = i ; j < s.size() ; j++){ // we try to include one by one char
            freq[s[j] - 'a']++;
            if(balanced(freq)) // even after adding this char , substring is balanced we can cut here and solve for the new subproblem starting from j + 1 or, in the next iteration of loop we add more character to the current substring
                ans = min(ans , 1 + solve(s , j + 1)); // If we cut at point 'j' 1 + solve(s , j + 1) number of substring is created
        }
        return dp[i] = ans; 
    }
    int minimumSubstringsInPartition(string s) {
        memset(dp , -1 , sizeof(dp));
        int ans = solve(s , 0);
        return ans == Max ? 0 : ans; // ans was not changed, so we have to keep the whole string intact.
    }
};

/*
Partition string "s" into balanced substring , try to make each 
substring as long as possible.
For each character we can either 
inlcude in the current substring
or if the current substring is balanced , we cut it here and 
try to make new balanced substring from next index.
*/