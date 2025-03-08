class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX , white = 0 , n = blocks.size();
        for(int left = 0 , right = 0 ; right < n ; right++){
            white += blocks[right] == 'W';
            if(right - left + 1 > k)
                white -= blocks[left++] == 'W';
            if(right - left + 1 == k)
                ans = min(ans , white);
        }
        return ans;
    }
};