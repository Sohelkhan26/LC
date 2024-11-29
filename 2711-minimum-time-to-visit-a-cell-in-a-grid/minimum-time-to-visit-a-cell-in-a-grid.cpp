class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 and grid[1][0] > 1)
            return -1;
        priority_queue <vector<int> , vector<vector<int>> , greater<> > pq;
        int n = grid.size() , m = grid[0].size();
        pq.push({0 , 0 , 0});
        grid[0][0] = -1;
        while(not pq.empty()){
            auto it = pq.top(); pq.pop();
            int time = it[0] , i = it[1] , j = it[2];
            if(i == n - 1 and j == m - 1)
                return time;
            for(auto &[di , dj] : vector<pair<int,int>> {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}}){
                int newi = i + di , newj = j + dj;
                if(min(newi , newj) >= 0 and newi < n and newj < m and grid[newi][newj] != -1){
                    int wait = (grid[newi][newj] - time) % 2 == 0;
                    pq.push({max(grid[newi][newj] + wait , time + 1) , newi , newj});
                    grid[newi][newj] = -1;
                }
            }
        }
        return -1;
    }
};
/*
প্রথম দেখায় মনে হয় যে Dijkstra কিন্তু দুইটা edge case আছে। প্রবলেমে বলা আছে প্রতি ইউনিট টাইমে এডজাসেন্ট সেলে মুভ করতেই হবে। তাছাড়া কোন উপায় নাই। (০ , ০) সেল থেকে যদি ডানে বা নিচে মুভ করা না যায় তাহলে -১ । এই একটা কেসেই -১ রিটার্ন করতে হবে। তাছাড়া বাকি যেকোন গ্রিড এর ক্ষেত্রে bottom-right এ পৌছানো যাবে। 
কারণ তখন অবশ্যই কমেপক্ষে একটা সেল মুভ করতে পারবো , এবং এর পর যদি একটাও সেলে মুভ করা না যায় তাহলে current cell এবং previous cell আসা যাওয়া করতে হবে যতক্ষন না neighbouring unvisited cell এ না যাওয়া যাচ্ছে। unvisited কথাটা জরুরী।এখানে দুইটা কেস হতে পারেঃ 
Let's say time for target cell is 4 and current time is 2, difference = 2 (even).
Move to prev cell, time = 3
Move to curr cell, time = 4
Move to target cell, time = 5.
Hence we reach target cell with time: target cell time + 1 when difference between target cell time and curr cell time is even.
Let's say time for target cell is 5 and current time is 2, difference = 3 (odd).
Move to prev cell, time = 3
Move to curr cell, time = 4
Move to target cell, time = 5.
Hence we reach target cell with time: target cell time when difference between target cell time and curr cell time is odd. (Copied)
*/