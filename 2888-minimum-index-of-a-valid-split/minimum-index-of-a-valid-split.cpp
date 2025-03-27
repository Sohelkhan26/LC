class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map <int,int> mp;
        int maxF = -1 , dominant = -1 , n = nums.size();
        for(int i : nums)
            if(++mp[i] > maxF)
                maxF = mp[i] , dominant = i;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            cnt += nums[i] == dominant;
            if(cnt * 2 > i + 1 and (mp[nums[i]] - cnt) * 2 > (n - i - 1))
                return i;
        }
        return -1;
    }
};