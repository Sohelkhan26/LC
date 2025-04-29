class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector <int> prefix = {0};
        vector <bool> ans;
        for(char &c : s)
            prefix.push_back(prefix.back() xor (1 << (c - 'a')));
        for(auto &q : queries){
            int left = q[0] , right = q[1] , k = q[2];
            int oddCount = __builtin_popcount(prefix[right + 1] xor prefix[left]);
            ans.push_back(oddCount / 2 <= k);
        }
        return ans;
    }
};

/*
Such an elegant problem.
Substring can rearranged and atmost "k" characters can be replaced.
There can be at most 1 odd occurance of any character. Other should be replaced to form palindrome.
We are only interested in the odd/even state of each character in the substring.And there is only 26 characters. Can be represented by a mask.
Xor toggles the parity. To avoid recomputing we pre calculated odd count character [0..i]
Substring odd count state can be calculated efficintly by "pref[right] xor pref[left - 1]"
Used a dummy value in the prefix to account for RTE or Index out of bounds error.
left can be 0. So, we shifted every thing to the right by 1 position.
If we didn't do that the logic should be like this: prefix[right] xor (left > 0 ? prefix[left - 1] : 0);
Everything else should be the same.
*/ 