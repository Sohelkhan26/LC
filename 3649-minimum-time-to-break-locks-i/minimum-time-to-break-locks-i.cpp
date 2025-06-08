class Solution {
public:
    int findMinimumTime(vector<int>& s , int k) {
        sort(s.begin() , s.end());
        int ans = INT_MAX;
        do{
            int minute = 0 , x = 1;
            for(int &i : s)
                minute += (i + x - 1) / x , x += k;
            ans = min(ans , minute);
        }while(next_permutation(s.begin() , s.end())); // use do-while for TC s = [3]
        return ans;
    }
};