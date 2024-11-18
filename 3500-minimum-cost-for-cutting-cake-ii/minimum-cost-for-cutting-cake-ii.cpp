typedef long long ll;
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.rbegin() , h.rend());
        sort(v.rbegin() , v.rend());
        int x = h.size() , y = v.size();
        ll ans = 0 , i = 0 , j = 0 , hP = 1 , vP = 1;
        while(i < x and j < y){
            if(h[i] >= v[j])
                ans += (vP * h[i++]) , hP++;
            else ans += (hP * v[j++]) , vP++;
        }
        while(i < x)
            ans += (vP * h[i++]);
        while(j < y)
            ans += (hP * v[j++]);
        return ans;
    }
};