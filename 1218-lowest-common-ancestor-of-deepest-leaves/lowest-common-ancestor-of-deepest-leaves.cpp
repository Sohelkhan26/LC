class Solution {
public:
    pair<TreeNode*,int> solve(TreeNode* root , int depth){
        if(not root)
            return {nullptr , 1};
        auto left = solve(root -> left , depth + 1);
        auto right = solve(root -> right , depth + 1);
        if(left.second < right.second)
            return {right.first , right.second + 1};
        if(left.second > right.second)
            return {left.first , left.second + 1};
        return {root , left.second + 1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root , 0).first;
    }
};