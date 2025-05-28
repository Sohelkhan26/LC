class Solution {
public:
    vector<int> tree;
    void build(int i , int low , int high , vector<int> &a){
        if(low == high){
            tree[i] = a[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * i + 1 , low , mid , a);
        build(2 * i + 2 , mid + 1 , high , a);
        tree[i] = max(tree[2 * i + 1] , tree[2 * i + 2]);
    }
    void update(int treeIdx , int low , int high , int i , int val){
        if(low == high){
            tree[treeIdx] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(i <= mid)
            update(2 * treeIdx + 1 , low , mid , i , val);
        else update(2 * treeIdx + 2 , mid + 1 , high , i , val);
        tree[treeIdx] = max(tree[2 * treeIdx + 1] , tree[2 * treeIdx + 2]);
    }
    int findMax(int i , int low , int high , int left , int right){
        if (right < low || high < left) 
            return 0;
        if (low >= left && high <= right) 
            return tree[i];
        int mid = low + (high - low) / 2;
        int l = findMax(2 * i + 1 , low , mid , left , right);
        int r = findMax(2 * i + 2 , mid + 1 , high , left , right);
        return max(l , r);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size() , unplaced = 0;
        tree.resize(4 * n);
        build(0 , 0 , n - 1 , baskets);
        for(int &f : fruits){
            int low = 0 , high = n - 1 , mid , free = -1;
            while(low <= high){
                mid = low + (high - low) / 2;
                if(findMax(0 , 0 , n - 1 , 0 , mid) >= f){
                    free = mid;
                    high = mid - 1;
                }else low = mid + 1;
            }
            if(free != -1)
                update(0 , 0 , n - 1 , free , 0);
            else unplaced++;
        }
        return unplaced;
    }
};