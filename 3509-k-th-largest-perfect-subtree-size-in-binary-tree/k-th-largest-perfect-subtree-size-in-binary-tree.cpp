/*
nth_element পুরো ভেকটরকে সর্ট করে না। শুধু k - 1 এলিমেন্ট সর্টেড এরে তে যে জায়গায় থাকার কথা সে জায়গায় থাকবে। টাইম কম্পেলক্সিটি কম। 
*/
class Solution {
public:
    vector<int> sizes;
    int solve(TreeNode* root){
        if(not root)
            return 0;
        int left = solve(root -> left) , right = solve(root -> right);
        if(left == right and left >= 0){
            sizes.push_back(left + right + 1);
            return left + right + 1;
        }
        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root);
        if(sizes.size() < k)
            return -1;
        nth_element(sizes.begin() , sizes.begin() + k - 1 , sizes.end() , greater{} );
        return sizes[k - 1];
    }
};