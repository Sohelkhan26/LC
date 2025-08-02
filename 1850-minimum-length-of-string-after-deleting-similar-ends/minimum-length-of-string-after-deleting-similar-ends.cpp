class Solution {
public:
    int minimumLength(string s) {
        int left = 0 , n = s.size() , right = n - 1;
        while(left < right and s[left] == s[right]){
            char c = s[left];
            while(left <= right and s[left] == c)
                left++;
            while(left <= right and s[right] == c)
                right--;
        }
        return right - left + 1;
    }
};