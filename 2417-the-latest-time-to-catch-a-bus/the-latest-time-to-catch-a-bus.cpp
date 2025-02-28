class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        unordered_set <int> pass(passengers.begin() , passengers.end());
        int n = passengers.size() , ans , p = 0;
        sort(buses.begin() , buses.end());
        sort(passengers.begin() , passengers.end());
        for(int bus : buses){
            int avail = capacity;
            while(p < n and passengers[p] <= bus and avail > 0)
                avail-- , p++;
            ans = avail > 0 ? bus : passengers[p - 1];
            while(pass.contains(ans)) // It should be inside the for loop.
                ans--;
        }
        return ans;
    }
};

/*
Observations:
input not sorted, early passengers get on bus, bus and passengers values are unique(not sure why this is an leverage).
Select latest time not colliding with any existing passengers that will ensure you a bus seat.
Problem mentions latest time, hint to binary search.
*/