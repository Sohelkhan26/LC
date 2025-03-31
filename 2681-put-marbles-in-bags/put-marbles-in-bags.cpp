class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans = 0 , maxScore = 0 , minScore = 0 , n = weights.size();
        vector <int> splits;
        for(int i = 0 ; i < n - 1 ; i++)
            splits.push_back(weights[i] + weights[i + 1]);
        sort(splits.begin() , splits.end());
        n = splits.size();
        for(int i = 0 ; i < k - 1 ; i++)
            maxScore += splits[n - 1 - i] , minScore += splits[i];
        return maxScore - minScore;
    }
};

/*
Very important observation is, we can't shuffle the array and different non-contiguous elements into same bag.Each bag should contains contiguous elements only and all marbles should be distributed.
And this is not a DP problem.
To split them into k different bags, we just need to put k−1 bars in the gaps of the marbles. That being said, we have n−1 gaps, and we put k−1 bars there. When we put a bar after i-th marble, the score of such distribution would increase by weights[i]+weights[i+1]
*/