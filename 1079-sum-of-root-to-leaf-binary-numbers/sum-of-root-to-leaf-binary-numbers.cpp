class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root , vector<int> path){
        if(not root)
            return;
        path.push_back(root -> val);
        if(not root -> left and not root -> right){
            int n = path.size();
            for(int i = 0 ; i < n ; i++)
                if(path[i])
                    ans += (1 << (n - i - 1));
            return;
        }
        dfs(root -> left , path); 
        dfs(root -> right , path);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> path;
        dfs(root , path);
        return ans;
    }
};