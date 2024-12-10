class Solution {
public:
    bool valid(string &s , int mid){
        vector<int> count(26);
        for(int left = 0 , right = 0 ; right < s.size() ; right++){
            while(s[left] != s[right])left++;// left will point to the begining of special string
            if(right - left + 1 >= mid) // For every new same character encountered we will have one more specail substring. aa -> aaa
                count[s[right] - 'a']++;
            if(count[s[right] - 'a'] >= 3)
                return true;
        }
        return false;
    }
    int maximumLength(string s) {
        int n = s.size() , low = 1 , high = n , mid , ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(valid(s , mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans;
    }
};

/*
Very good problem. The helper function for binary search is very impressive.
Input :
Find a string in 's' so that it contains only one character and it appears in 's' more than two times. And make the length of the string as long as possible(Maximize the length of the string).
Maximization problems ? Think of Binary Search.
If a string is valid then all the strings with smaller length is also valid.
Definition of valid: string with one unique char and appears in 's' more than 2
aaaaaaa
aaaa -> this is valid. It appears 4 times and has only 'a'
all string with smallers legnth will also be valid.
aa -> appears 6 times.
Thus monotonic in nature and binary search will work fine.
*/