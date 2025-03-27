class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans = {first};
        int prev = first;
        for(int i : encoded)    
            ans.push_back(prev xor i) , prev ^= i;
        return ans;
    }
};