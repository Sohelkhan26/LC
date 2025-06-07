class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector <int> a(nums);
        sort(a.begin() , a.end());
        int groupNo = 0 , n = nums.size();
        unordered_map <int,int> group;
        unordered_map <int, queue <int> > groupToList;
        groupToList[groupNo].push(a[0]);
        group[a[0]] = groupNo;
        for(int i = 1 ; i < n ; i++){
            if(a[i] - a[i - 1] > limit)
                groupNo++;
            group[a[i]] = groupNo;
            groupToList[groupNo].push(a[i]);
        }
        for(int i = 0 ; i < n ; i++){
            int groupNo = group[nums[i]];
            nums[i] = groupToList[groupNo].front();
            groupToList[groupNo].pop();
        }
        return nums;
    }
};

/*
can swap elements if their absolute difference is <= limit.
make array lexicographically smallest possible.
if diff < 0 and abs(diff) <= limit , swapping them won't do any good. swap nums[i] , nums[j] such that nums[j] is smaller.
Brute force swapping is not gonna work.
wait a minute. count of swapping dont matter. 

out of all pos diff, take the element to the front that produce max diff . right? segment tree ?


9 8 6 5 4 3 limit = 2 
3 can be swapped with 9 even though their diff is > limit
8 9 6 5 4 3 swap(8 , 9)
6 9 8 5 4 3 swap(8 , 6) 
5 9 8 6 4 3 swap(5 , 6)
3 9 8 6 4 5 swap(5 , 3)
basically the whole array can be sorted. Swapping property is transitive.
intial group [9 , 8] , [6 , 5 , 4 , 3]
But 8 - 6 = 2 they are grouped togather.
Group numbers in nums. a number can be replaced with the smallest number in the same group. So simple but so elegant.
*/