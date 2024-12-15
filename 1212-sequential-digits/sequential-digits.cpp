class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue <int> q;
        vector<int> ans;
        for(int i = 1 ; i < 10 ; i++)
            q.push(i);
        while(not q.empty()){
            int n = q.front();
            q.pop();
            if(low <= n and n <= high){
                ans.push_back(n);
            }
            if(n > high)
                continue;
            int lastDigit = n % 10;
            if(lastDigit < 9) // if we add 10 it will break the sequence. i.e : 9 + 10 = 19
                q.push(n * 10 + (lastDigit + 1));
        }
        return ans;
    }
};

/*
It's such a good problem. It can't be solved using brute force.
Making it into a graph problem is outstanding. 
*/