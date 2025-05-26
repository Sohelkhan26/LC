class Solution {
public:
    int longestPalindrome(string s, string t) {
        int n = s.size() , m = t.size() , ans = 0;
        auto palindrome = [&](string s){
            for(int i = 0 , j = s.size() - 1 ; i <= j ; i++ , j--)
                if(s[i] != s[j])    
                    return false;
            return true;
        };
        for(int i = 0 ; i < n ; i++){
            for(int l = 0 ; l <= n - i ; l++){
                for(int j = 0 ; j < m ; j++){
                    for(int ll = 0 ; ll <= m - j ; ll++){
                        string temp = s.substr(i , l) + t.substr(j , ll);
                        if(palindrome(temp))
                            ans = max(ans , (int)temp.size());
                    }
                }
            }
        }
        return ans;
    }
};