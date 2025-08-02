class Solution {
public:
    int solve(const string &s , int left , int right){  
        if(left == right)
            return 1;
        char a = s[left] , b = s[right];
        if(a != b)
            return right - left + 1;
        while(a == s[left] and left < right)
            left++;
        if(left == right)
            return 0;
        while(b == s[right] and left < right)
            right--;
        return solve(s , left , right);
    }
    int minimumLength(string s) {
        return solve(s , 0 , s.size() - 1);
    }
};