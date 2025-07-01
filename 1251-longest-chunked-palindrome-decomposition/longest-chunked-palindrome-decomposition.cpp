class Solution {
public:
    int mod = 1e9 + 9 , base = 199 , n;
    int solve(int left , int right , const string &s){
        if(left > right)
            return 0;
        if(left == right)
            return 1;
        long long prefix = 0 , suffix = 0 , power = 1;
        for(int i = 0 ; i <= (right - left) / 2 ; i++){
            prefix = (prefix * base + (s[left + i] - 'a' + 1)) % mod; // hash = hash * base + char
            suffix = (suffix + (s[right - i] - 'a' + 1) * power) % mod; // hash = hash + char * power or vice versa
            power = (power * base) % mod;
            if(prefix == suffix)
                if(s.substr(left , i + 1) == s.substr(right - i , i + 1))
                    return 2 + solve(left + i + 1 , right - i - 1 , s);
        }
        return 1;
    }
    int longestDecomposition(string text) {
        n = text.size();
        return solve(0 , n - 1 , text);
    }
};

/*
abc....abc
prefix = ( (0 * base + a) * base + b) * base + c 
       = a * base * base + b * base + c
suffix = c * 1 + b * 1 * base + a * 1 * base * base (every loop: power *= base)
       = a * base * base + b * base + c
So if prefix follows a certain hashing , suffix should use it reversed.
*/