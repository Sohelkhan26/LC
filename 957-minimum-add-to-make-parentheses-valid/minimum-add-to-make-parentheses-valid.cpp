class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0 , right = 0;
        for(char c : s){
            if(c == '(')
                right++; // we need one closing bracket for this (
            else{
                right ? right-- : left++; // if we needed some amount of ')' earlier, then we need one less now as we found one. Else we need a '(' for this closing bracket ')'
            }
        }
        return left + right;
    }
};