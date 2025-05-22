class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> ans , st;
        while(head){
            while(st.size() and ans[st.back()] < head -> val){
                ans[st.back()] = head -> val;
                st.pop_back();
            }
            st.push_back(ans.size());// as answer stores every and all elements, we can safely use it's size as index.
            ans.push_back(head -> val); // answer stores value of linked list nodes until it is modified.
            head = head -> next;
        }
        for(int i : st)
            ans[i] = 0;
        return ans;
    }
};

/*
What a fascinating algorithm. Taken from lee.
If it were a array, we would maintain a decreasing stack, and whenever we found a greater element, all element in the stack should be changed to this greater element. 
But We are talking about a linked list. Even if we maintain a stack, we can't access elements using indices.
We need some kind of array to store the values of linked list according to their indices. We use ans array to do this trick for us, we make while traversing the linked list.
*/