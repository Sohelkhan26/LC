class Solution {
public:
    vector<int> nums;
    void solve(TreeNode* root){
        if(not root)
            return;
        solve(root -> left);
        nums.push_back(root -> val);
        solve(root -> right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        solve(root);
        for(int &target : queries){
            auto it = lower_bound(nums.begin() , nums.end() , target);
            if(it != end(nums) and *it == target){
                ans.push_back({target , target});
                continue;
            }
            int Min = (it == nums.begin() ? -1 : *prev(it));
            int Max = (it == nums.end() ? -1 : *it);
            ans.push_back({Min , Max});
        }
        return ans;
    }
};
/*
lower_bound returns value >= target
points to end() if no value >= target i.e : all value < target
Special case: pointed value == target , then both Min = Max = target.
Min: largest value <= target
Max: smallest value >= target , directly returned by lower_bound. One catch though, if it == nums.end() then no such element.

Min is largest value < (== case covered by special cse) target.
So, it should be just the previous value as the array is sorted. Again check for nums.begin()
*/