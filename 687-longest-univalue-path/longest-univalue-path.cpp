class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root , int parent){
        if(not root)
            return 0;
        int left = dfs(root -> left , root -> val);
        int right = dfs(root -> right , root -> val);
        ans = max(ans , left + right); // sometimes only left/right subtree contains largest path, then the other subtree will return 0.
        return root -> val == parent ? max(left , right) + 1 : 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(not root)
            return 0;
        dfs(root , -1);
        return ans;
    }
};

/*
There could be two types of path:
path only contained on the left / right subtree.
Path extended through the both trees. Parallel to x axis for imagination?
How to account for that? Problem arises when a parallel path is considered as only left or right path for it's ancestor.
In the editorial they used a global variable. Seems like directly returning the dfs function can't be done.
*/