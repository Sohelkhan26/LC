class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        head = new ListNode(-1 , head);
        unordered_map <int , ListNode*> prev;
        int sum = 0;
        ListNode *curr = head;
        while(curr){
            sum += curr -> val;
            if(prev.count(sum)){
                ListNode* start = prev[sum] -> next;
                int tempSum = sum;
                // Clean up intermediate prefix sums
                while (start != curr) {
                    tempSum += start -> val;
                    prev.erase(tempSum);
                    start = start -> next;
                }
                prev[sum] -> next = curr -> next;
            }else prev[sum] = curr;
            curr = curr -> next;
        }
        return head -> next;
    }
};

/*
When a same prefixSum was previously seen, that means intermediate subarray has sum = 0.
So, all nodes between prev[sum] and curr need to be deleted.
prev[sum] -> next = curr -> next is enough, but as these don't exist, their prefix sum should not exist too. So they need to be removed from map too.
*/