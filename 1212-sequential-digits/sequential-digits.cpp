class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1 ; i < 10 ; i++){
            int n = i;
            int lastDigit = i;
            while(n <= high and lastDigit < 9){
                n = (n * 10) + ++lastDigit;
                if(low <= n and n <= high)
                    ans.push_back(n);
            }
        }
        sort(ans.begin() , ans.end());
        return ans; 
    }
};