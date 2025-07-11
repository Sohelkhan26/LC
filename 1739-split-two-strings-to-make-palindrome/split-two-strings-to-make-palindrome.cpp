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

/*
Given two strings, fix a index and split both strings at that index
Find if pref(a) + suff(b) or pref(b) + suff(a) forms palindrome or not.
Match prefix and suffix of both strings as long as possible.
After that if middle part of any string is palindrome, we can add that to 
that string's prefix/suffix and split there. (do this for a|b and b|a)
a = "abcxcxef"
b = "efgeaoga"
ef match for both string, left = 1 , right = 6
Middle part of string 'a' is palindrome, so we can add that to the suffix of 'a'
So, we can split both at index 1
*/