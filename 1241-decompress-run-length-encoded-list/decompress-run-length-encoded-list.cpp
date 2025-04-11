class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        for(int i = 0 ; 2 * i + 1 < n ; i++)
            for(int j = 0 ; j < nums[2 * i] ; j++)
                ans.push_back(nums[2 * i + 1]);
        return ans;
    }
};

/*
Don't be intimidated. So as the problem says.
*/