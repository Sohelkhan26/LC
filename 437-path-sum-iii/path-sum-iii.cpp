class Solution {
public:
    unordered_map <long long,int> prev;
    int target , ans = 0;
    void solve(TreeNode* root , long long pathSum){ 
        if(not root)
            return;
        if(prev.contains(pathSum - target))
            ans += prev[pathSum - target];
        prev[pathSum]++;
        if(root -> left)
            solve(root -> left , pathSum + root -> left -> val);
        if(root -> right)
            solve(root -> right , pathSum + root -> right -> val);
        prev[pathSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prev[0] = 1;
        target = targetSum;
        if(not root)
            return 0;
        solve(root , 1ll * root -> val);
        return ans;
    }
};

/*
Same as this problem. 
https://leetcode.com/problems/subarray-sum-equals-k/
But in this problem you have to ensure pathSum through a path.
*/