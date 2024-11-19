class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(char c : s)
            if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
                count++;
        return count > 0;
    }
};