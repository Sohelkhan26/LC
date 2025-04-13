class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0 , n = answers.size();
        unordered_map <int,int> freq;
        for(int &i : answers){
            freq[i]++;
            if(freq[i] >= (i + 1))
                ans += (i + 1) , freq[i] -= (i + 1);
        }
        for(auto &[n , cnt] : freq)
            if(cnt)
                ans += (n + 1);
        return ans;
    }
};