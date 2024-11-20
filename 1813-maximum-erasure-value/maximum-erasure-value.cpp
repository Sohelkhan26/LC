/*
Maintain a set to keep track of number unique elements and a window for sum. If the current number creates duplicacy erase from set until it doesn't (it's the only element) and don't forget to update the window sum.
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0 , n = nums.size() , window = 0;
        unordered_set <int> count;
        for(int left = 0 , right = 0 ; right < n ; right++){
            while(count.contains(nums[right])){
                count.erase(nums[left]);
                window -= nums[left++];
            }
            count.insert(nums[right]);
            window += nums[right];
            ans = max(ans , window);
        }
        return ans;
    }
};