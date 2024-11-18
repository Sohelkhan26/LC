class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size() , window = 0 , start = 1 , end = k;
        vector<int> ans(n);
        if(k < 0)
            start = n - abs(k) , end = n - 1; // for prev k elements
        window = accumulate(code.begin() + start , code.begin() + end + 1 , 0); // end is not inclusive
        for(int i = 0 ; i < n ; i++){
            ans[i] = window;
            window += code[++end % n];
            window -= code[start++ % n];
        }
        return ans;
    }
};