class Solution {
public:
    int K;
    int dp[12][12][12][20][2][2]; // max digit 10 , all of them can be odd or even. rem < k <= 20 constraint
    int solve(string &s , int i , int even , int odd , int rem , bool edge , bool zero){
        if(i == s.size())
            return (even == odd and rem == 0) ? 1 : 0;
        if(dp[i][even][odd][rem][edge][zero] != -1)
            return dp[i][even][odd][rem][edge][zero];
        int limit = (edge ? s[i] - '0' : 9) , ans = 0;
        for(int digit = 0 ; digit <= limit ; digit++){
            bool newAllZero = zero && (digit == 0) ,  // edge case for all digit 0
            newEdge = edge && (digit == (s[i] - '0'));
            int newEven = (newAllZero ? even : even + (digit % 2 == 0)) // more than one 0, don't count as even
            , newOdd = odd + (digit % 2);
            int newRem = (rem * 10 + digit) % K;
            ans += solve(s , i + 1 , newEven , newOdd , newRem , newEdge , newAllZero);
        }
        return dp[i][even][odd][rem][edge][zero] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        K = k;
        memset(dp , -1 , sizeof(dp));
        string r = to_string(high) , l = to_string(low - 1);
        int a = solve(r , 0 , 0 , 0 , 0 , 1 , 1);
        memset(dp , -1 , sizeof(dp));
        int b = solve(l , 0 , 0 , 0 , 0 , 1 , 1);
        return a - b;
    }
};

/*
Digit Dp:
Edge case : number contains all 0 , keep track of remainder.
If the current digit inserted is 0 and all previous digits too, then even Count remains the same.
(a + b) % mod = a % mod + b % mod
A≡r(mod K) means A=K⋅q+r for some integer q. Then, multiply both sides by 10: 10⋅A=10⋅(K⋅q+r)=K⋅(10q)+10r.
Now, add a digit B: 10⋅A+B=K⋅(10q)+10r+B. So, 10⋅A+B≡10r+B(modK). The term K⋅(10q) is divisible by K, so it disappears modulo K. 
The final result is 10⋅A+B≡10r+B(modK). 
This means you can update the remainder incrementally like this: new_rem=(old_rem⋅10+next_digit)%K.
*/