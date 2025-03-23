class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map <int,int> freq;
        for(int i : nums)
            freq[i]++;
        for(auto it : freq){
            if(it.second > 0){
                for(int i = k - 1 ; i >= 0 ; i--)
                    if((freq[it.first + i] -= freq[it.first]) < 0)
                        return false;
            }
        }
        return true;
    }
};