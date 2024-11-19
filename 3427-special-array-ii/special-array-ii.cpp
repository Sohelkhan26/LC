class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> special;
        int n = nums.size() , left , right;
        for(left = 0 , right = 1 ; right < n ; right++){
            if(nums[right] % 2 == nums[right - 1] % 2){
                special.push_back({left , right - 1});
                left = right;
            }
        }
        special.push_back({left , right});
        vector<bool> ans;
        for(auto it : queries){
            int left = it[0] , right = it[1];
            int i = upper_bound(special.begin() , special.end() , vector<int>{left , INT_MAX}) - special.begin();
            if(--i >= 0){
                if(special[i][1] >= right)
                    ans.push_back(true);
                else ans.push_back(false);
            }
        }
        return ans;
    }
};