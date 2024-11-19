class Solution {
public:
    int maxOperations(string s) {
        int ans = 0 , one = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1')one++;
            else{
                int prev = i;
                while(s[i] == '0')
                    i++;
                if(i > prev)
                    i--;
                ans += one;
            }
        }
        return ans;
    }
};