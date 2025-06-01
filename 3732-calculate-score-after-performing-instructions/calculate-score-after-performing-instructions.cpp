class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ans = 0;
        int i = 0 , n = values.size();
        unordered_set <int> vis;
        while(i >= 0 and i < n){
            if(vis.contains(i))
                break;
            vis.insert(i);
            if(instructions[i] == "add")
                ans += 1ll * values[i++];
            else i += values[i];
        }
        return ans;
    }
};