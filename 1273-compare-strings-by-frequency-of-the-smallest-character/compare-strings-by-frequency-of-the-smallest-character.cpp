class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [&](string &s){
            vector <int> count(26);
            for(char &c : s)
                count[c - 'a']++;
            for(int &i : count)
                if(i > 0)
                    return i;
            return -1;
        }; 
        vector <int> ans(11) , result;
        for(string &s : words)
            for(int i = f(s) - 1 ; i >= 0 ; i--) // this words will be counted for f(query) < f(s)
                ans[i]++;
        for(string &s : queries)
            result.push_back(ans[f(s)]);
        return result;
    }
};

/*
Binary search is easy. O(n) is harder.
each string length is at most 11
So, f(words) can be at most 11
We can calculate answer for each possible query.
ans[j] stores count(words[i]) such that f(words[i]) > j
*/