class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int ans = 0 , count = 0 , n = s.size() , i = 0;
        while(s[i] == 0)
            i++ , count++;
        ans = max(ans , count);
        for(; i < n ; i++)
            if(s[i])
                ans = max(ans , (count + 1) / 2) , count = 0;
            else count++;
        ans = max(ans , count);
        return ans;
    }
};