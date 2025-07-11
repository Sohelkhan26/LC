class Solution {
public:
    struct Node{
        unordered_map <int,Node*> child;
    } *root , *curr;
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size() , ans = 0;
        root = new Node();
        for(int i = 0 ; i < n ; i++){
            curr = root;
            int count = 0;
            for(int j = i ; j < n ; j++){
                count += (nums[j] % p == 0);
                if(count > k)
                    break;
                if(curr -> child[nums[j]] == nullptr)
                    ans++ , curr -> child[nums[j]] = new Node();
                curr = curr -> child[nums[j]];
            }
        }
        return ans;
    }
};

/*
Given an array. two integers p & k
Count number of distinct subarrays that have count(element % p == 0) <= k
Sliding window can't handle duplicacy.
This solution uses Trie. I didn't know trie can be used like this.
For every subarray, we start inserting it into the Trie. Each Trie node is an element of nums array.
Even if a single element is not present in the Trie, we have found a new distinct subarray.
Trie works because all subarray that has count(nums[i] % p == 0) must be <= k
So, smaller prefix must be present in Trie.
*/