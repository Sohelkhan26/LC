class Solution {
public:
    int solve(int i , vector <int> &cookie , vector <int> &child){
        if(i == cookie.size())
            return *max_element(child.begin() , child.end());
        int ans = INT_MAX;
        for(int j = 0 ; j < child.size() ; j++){
            child[j] += cookie[i];
            ans = min(ans , solve(i + 1 , cookie , child));
            child[j] -= cookie[i];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector <int> child(k);
        return solve(0 , cookies , child);
    }
};