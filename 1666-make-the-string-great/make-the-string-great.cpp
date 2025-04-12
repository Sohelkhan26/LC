class Solution {
public:
    string makeGood(string s) {
        string good;
        for(char &c : s){
            if(not good.empty() and abs(good.back() - c) == 32) // Diff between uppercase and lowercase 32 for each character
                good.pop_back();
            else
                good.push_back(c);
        }
        return good;
    }
};