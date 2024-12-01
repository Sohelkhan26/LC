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
    int amountOfTime(TreeNode* root, int start) {
        int n = 1e5 + 1;
        vector<int> adj[n];
        function<void(TreeNode*)> createGraph = [&](TreeNode* root) -> void{
            if(not root)
                return;
            if(root -> left){
                adj[root -> val].push_back(root -> left -> val);
                adj[root -> left -> val].push_back(root -> val);
                createGraph(root -> left);
            }
            if(root -> right){
                adj[root -> val].push_back(root -> right -> val);
                adj[root -> right -> val].push_back(root -> val);
                createGraph(root -> right);
            }
        };
        createGraph(root);
        vector<bool> vis(n);
        queue <int> q;
        q.push(start);
        vis[start] = true;
        int time = -1;
        while(not q.empty()){
            int len = q.size();
            while(len--){
                int node = q.front();
                q.pop();
                for(int nei : adj[node]){
                    if(not vis[nei]){
                        q.push(nei);
                        vis[nei] = true;
                    }
                }
            }
            time++;
        }
        return time;
    }
};