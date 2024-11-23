/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string ans;
    void solve(TreeNode* root , string s){
        if(not root)
            return;
        s = string(1 , root -> val + 'a') + s; // root এর char আগে দেওয়ার কারনে অটো রিভার্স হচ্ছে। 
        if(not root -> left and not root -> right)
            if(ans == "" or ans > s)
                ans = s;
        solve(root -> left , s);
        solve(root -> right , s);
    }
    string smallestFromLeaf(TreeNode* root) {
        solve(root , "");
        return ans;
    }
};
