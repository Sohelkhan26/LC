class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for(int i = n / 2 - 1 ; i >= 0 ; i--){
            int left = 2 * i + 1 , right = 2 * i + 2; // cost[i] -> cost of (i + 1)th node
            ans += abs(cost[left] - cost[right]);
            cost[i] += max(cost[left] , cost[right]); // Increment cost if pathSum differs, not if node value differs.
            // modifying the cost array to store pathSum difference actually.
        }
        return ans;
    }
};
/*
Only allowed to increment. So make the smaller value equal to bigger value.
Start from 2nd last level and increment the smaller value, if children hass diff > 0.
Also store the diff in some way, because we are interested in pathSum. Suppose left child is smaller and right child is bigger, along the path left child may have extra (right - left) value making the pathSum equal. Then we don't need to change any node's value because ultimately pathSum is equal. As we move up we store the difference so that we don't make unnecessary changes.
*/