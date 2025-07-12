class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set <long long> ans;
        int base = 109 , mod = 1e9 + 9 , n = text.size();

        vector <long long> prefix(n + 1) , power(n + 1 , 1);

        for(int i = 0 ; i < n ; i++){
            prefix[i + 1] = (prefix[i] * base + (text[i] - 'a' + 1)) % mod; 
            power[i + 1] = (power[i] * base) % mod;
        }

        auto hash = [&](int left , int right){ // right - left is actually length of the string
            return (prefix[right] - (prefix[left] * power[right - left]) % mod + mod) % mod;
        };
/*
We don't want to calculate hash for every new substring, that will be same as storing the whole string. 
So we use prefix rolling hash.
Sliding window rolling hash. When we have to remove leftmost character from the hash, we have subtract that characters contribution right? It was (s[left] + 1) * power
power = base ^ (length of the window) Same was done here.
*/
        for(int len = 1 ; len <= n / 2 ; len++){
            int count = 0;
            for(int left = 0 , right = len ; left + len < n ; left++ , right++){
                count = (text[left] == text[right] ? count + 1 : 0);
                if(count == len){
                    ans.insert(hash(left , left + len)); // instead of storing the whole string store the hash for better runtime.
                    count--; // not count = 0, think for aaaa
                }
            }
        } 
        return ans.size();
    }
};

/*
Prefix rolling hash, hard to wrap my head around it.
*/