class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1 , high = *min_element(ranks.begin() , ranks.end()) * 1ll * cars * cars , time , ans = 0;
        while(low <= high){
            time = low + (high - low) / 2;
    // check the sum of cars cleanable by all mechanic within mid time. If it's less then cars ok.
            long long totalCar = 0;
            for(int i : ranks){
                totalCar += (int)sqrt(time / i);
            }
            if(totalCar >= cars){
                ans = time;
                high = time - 1;
            }else low = time + 1;
        }
        return ans;
    }
};