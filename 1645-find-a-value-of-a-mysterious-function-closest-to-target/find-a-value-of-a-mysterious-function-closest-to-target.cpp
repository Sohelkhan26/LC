class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set <int> prev; 
        int ans = INT_MAX;
        for(int &n : arr){
            unordered_set <int> curr = {n};
            for(const int &p : prev) 
                curr.insert(p & n); 
            for(const int &i : curr)
                ans = min(ans , abs(target - i));
            swap(prev , curr);
        }
        return ans;
    }
};