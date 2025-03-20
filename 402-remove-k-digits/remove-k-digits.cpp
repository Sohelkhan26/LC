class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        if(k >= num.size())
            return "0";
        for(char c : num){
            while(not ans.empty() and ans.back() > c and k){
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while(k--)
            ans.pop_back();
        int firstNonZero = ans.find_first_not_of('0'); // returns the index of the first char that doesn't match the argument passed. -1 means, all chars are 0
        return firstNonZero == -1 ? "0" : ans.substr(firstNonZero);
    }
};

/*
Greedy based solution. At each step, we make a locally optimal choice keeping the smallest possible digit with the aim of achieving overall optimal solution.
By prioritizing smaller digits for Most Significant Places(left most positions) it's ensured that the resulting number is minimized.
*/