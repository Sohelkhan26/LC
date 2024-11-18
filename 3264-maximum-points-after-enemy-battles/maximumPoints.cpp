class Solution {
public:
    long long maximumPoints(vector<int>& e , int energy) {
        int mn = *min_element(e.begin() , e.end());
        long long totalEnergy = accumulate(e.begin() , e.end() , 0ll) - mn + energy;
        if(energy < mn)
            return 0;
        return totalEnergy / mn;
    }
};
