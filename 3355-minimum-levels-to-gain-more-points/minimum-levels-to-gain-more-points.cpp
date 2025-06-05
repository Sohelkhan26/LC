class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size() , total = 0 , alice = 0;
        for(int &i : possible)
            total += (i == 0 ? -1 : 1);
        for(int i = 0 ; i < n - 1 ; i++){
            alice += (possible[i] == 0 ? -1 : 1);
            if(alice > (total - alice))
                return i + 1;
        }
        return -1;
    }
};