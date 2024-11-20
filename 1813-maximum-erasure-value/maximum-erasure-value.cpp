class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0 , n = nums.size() , window = 0;
        unordered_map <int , int> count;
        for(int left = 0 , right = 0 ; right < n ; right++){
            if(count.contains(nums[right])){
                while(left <= count[nums[right]]){
                    count.erase(nums[left]);
                    window -= nums[left++];
                }
            }
            count[nums[right]] = right;
            window += nums[right];
            ans = max(ans , window);
        }
        return ans;
    }
};