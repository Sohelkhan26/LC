class Solution {
public:
    bool isPalindrome(string &a , int left , int right){
        cout << a << ' ' << left << ' ' << right << endl;
        for( ; left <= right ; left++ , right--)
            if(a[left] != a[right])
                return false;
        return true;
    }
    bool check(string &a , string &b){
        int n = a.size() , left = 0 , right = n - 1;
        while(left <= right and a[left] == b[right])
            left++ , right--;
        return isPalindrome(a , left , right) or isPalindrome(b , left , right);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a , b) or check(b , a);
    }
};