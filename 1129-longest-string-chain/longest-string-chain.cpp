class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size() , ans = INT_MIN;
        vector<int> dp(n , -1);
        unordered_map <string,int> wordIdx;
        for(int i = 0 ; i < n ; i++)
            wordIdx[words[i]] = i;
        function<int(int)> solve = [&](int i){
            if(dp[i] != -1)
                return dp[i];
            int longest = 1; // considering words[i] as predecessor
            string w = words[i];
            for(int j = 0 ; j < w.size() ; j++){
                string next = w.substr(0 , j) + w.substr(j + 1);
                if(wordIdx.find(next) != wordIdx.end())
                    longest = max(longest , 1 + solve(wordIdx[next])); // 1 is for the "next" string as predecessor
            }
            return dp[i] = longest;
        };
        for(int i = 0 ; i < n ; i++)
            ans = max(ans , solve(i));
        return ans;
    }
};
/*
Inserting character is troublesome, we have 16 possibilities(words[i].length)and 26 choices. Instead for every string "s", we can delete one by one character and determine how long word chain forms for this string "s".
We will go inverse way. "s" is the last string in the word chain.
bdca -> bca(del 'd') -> ba(del 'c') -> b(del 'a')
bdca -> bda(del 'c') -> bd(del 'a') deleting wrong character may end up in a shorter word chain, so for every character deleted consider the one which form longest word chain.
we don't know which string will form the longest chain, so we try every string as the last string, and calculate the answer. This will create sub problem, which may be solved more than once. So DP comes into play.
*/