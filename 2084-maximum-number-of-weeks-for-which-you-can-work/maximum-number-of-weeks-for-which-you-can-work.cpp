class Solution {
public:
    #define all(a) a.begin() , a.end()
    long long numberOfWeeks(vector<int>& nums) {
        long long total = accumulate(all(nums) , 0ll) , mx = *max_element(all(nums)) , 
        rest = total - mx;
        if(mx > total / 2)
            return 2 * rest + 1;
        return total;
    }
};

/*
Think like this: There n items, nums[i] represents the count of i'th item. 
Place them in such manner so that no adjacent items is same. Longest such sequence is the desired answer.
Say there are m indices to place the items. m = total = sum(nums) 
Be greedy, highest count item is placed at odd or even index and other items should be in between. If one item has high frequency , > m / 2 then some of them are bound to be adjacent. There sum of other items is "rest" , then there are "rest + 1" holes that can be filled by the highest frequency item. Highest frequencey item can be placed in between and each item is counted so 2 * rest(because of problem statement).

If there is no such high frequency item, then all of them can be placed non-adjacently beause there is no restriction on the length "m".
*/