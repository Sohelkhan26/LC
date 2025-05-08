class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> freq; // should store char count of all character at index i of (words[j]) 
    int dp[1000][1000];
    int solve(int i , int j , string &target){
        if(j == target.size())
            return 1;
        if(i >= freq.size()) // we didn't return in the earlier statement, so j < target and we exhausted all indices of words[idx]
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = (1ll * freq[i][target[j] - 'a'] * solve(i + 1 , j + 1 , target)) % mod; // take the i'th character from any words[idx]
        ans = (ans + solve(i + 1 , j , target)) % mod; // don't take the i'th character.
        return dp[i][j] = ans;
    }
    int numWays(vector<string>& words, string target) {
        int n = words[0].size() , m = words.size(); 
        freq.resize(n , vector<int> (26));
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                freq[j][words[i][j] - 'a']++;
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , target);
    }   
};

/*
To construct string "target" , any character from words[i] can be chosen. Say, words[i][j] is chosen. Then all characters to the left of j including j(for all other words[i] too), can't be used any more.
So, we would want to go step by step, how each index can contribute to the answer. For each character in words[i] , we can either include that or don't. If we include that contribution would be (occurance of that character in that index i , at all other words[i]) times next sub-problem. But we don't want to count that for every index i and for every words[i], so it's precomputed and stored in freq. freq is same size words[0](all words[i] same len) and contains frequency of all character in alphabet.
*/