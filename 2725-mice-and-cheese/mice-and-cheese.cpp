class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0 , n = reward1.size();
        priority_queue <int> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(-(reward1[i] - reward2[i])); // add -ve to pq for efficient popping
            ans += reward2[i];
            if(pq.size() > k)
                pq.pop();
        }
        while(not pq.empty()) // we already fed the cheese to the second mouse, so difference is added only. Extra difference cheese can be fed, if we feed it to 1st mouse. However , difference can be made, we should take the smallest negative difference in that case(we must feed k cheese to 1st mice).
            ans -= pq.top() , pq.pop();
        return ans;
    }
};

/*
One cheese can't be eaten by both mice. 
First mice can eat 'k' cheese.
So, we gonna feed the second mice all the cheese. Out of which, 'k' smallest cheese will be fed to the first mouse.
*/