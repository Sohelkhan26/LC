class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map <pair<int,int>,int> freq;
        long long ans = 0;
        for(auto it : rectangles){
            int w = it[0] , h = it[1];
            int div = __gcd(w , h);
            ans += freq[{w / div , h / div}]++;
        }
        return ans;
    }
};

/*
Using double data type compromises precision.
To find out the ratio, numerator and denominator both are devided by __gcd(w , h).
Instead of storing the ratio directly in the map , store these instead for beater precision.
*/