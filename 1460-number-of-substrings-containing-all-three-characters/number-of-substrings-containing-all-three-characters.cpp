class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size() , ans = 0 , count[] = {0 , 0 , 0};
        for(int left = 0 , right = 0 ; right < n ; right++){
            count[s[right] - 'a']++;
            while(count[0] and count[1] and count[2]){
                ans += n - right;
                count[s[left++] - 'a']--;
            }
        }
        return ans;
    }
};
/*
When we have one of (a & b & c) then , for each char added later results in a valid substring. future valid substring = remaining character + 1
So, whenever we have a valid substring we precompute possible valid substring in later and add to the answer and shift the window to the right(shrink the window).
*/