class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v;
        for(int i = 0 ; i < n ; i++)
            v.push_back({nums1[i] , i});
        sort(v.begin() , v.end());
        long long pref = 0;
        vector <long long> ans(n);
        priority_queue <int> pq;
        for(int left = 0 , right = 0 ; right < n ; right++){
            int i = v[right].second; // current element
            while(left < right and nums1[i] > nums1[v[left].second]){
                int j = v[left].second;
                pq.push(-nums2[j]);
                pref += nums2[j];
                if(pq.size() > k)
                    pref += pq.top() , pq.pop();
                left++;
            }
            ans[i] = pref;
        }
        return ans;
    }
};

/*
There is a motherfucking edge case. There could be some equal numbers in nums1
after sorting every number before i'th index in not ensured to be < nums1[i] and until we go to a later index k , nums[k] > nums[j] we can't include these middle elements in the prefix.
nums1 = [2,4,5,5,5,6]
left pointer should halt at nums1[2] for index i = 2,3,4

so maintain a k size pq for previous elements. but handle case when previous element is == current element.
*/