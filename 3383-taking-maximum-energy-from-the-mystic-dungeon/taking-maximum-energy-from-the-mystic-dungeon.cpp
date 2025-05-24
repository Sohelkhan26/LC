class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        for(int i = n - k - 1 ; i >= 0 ; i--)
            energy[i] += energy[i + k];
        return *max_element(energy.begin() , energy.end());
    }
};

/*
Can start from any index, end goal is n - 1 index or higher.
Starting from any index is important. We can start from n - k and max energy is energy[i] + energy[i + k]
or start from n - 2 * k , then ans = sum([n - 2 * k , n])
for(int i = 0 ; i < n - k ; i++)
    energy[i] += energy[i + k];
If we start the loop from the beginning of the array, we can't simulate this process, It double counts for starting points and indices that come after it.
If we start from i , i + k accumulate energy[i] and again when after some time in loop we reach i + k, it propagates energy[i] and energy[i + k] basically two starting point (i and i + k).
*/