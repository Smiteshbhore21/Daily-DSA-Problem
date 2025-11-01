/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for (int& num : nums) {
            st.insert(num);
        }
        ListNode* prev = new ListNode();
        ListNode* curr = head;
        while (curr) {
            if (st.count(curr->val)) {
                if (prev->next == NULL) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    head = curr;
                    // delete temp;
                } else {
                    prev->next = curr->next;
                    ListNode* temp = curr;
                    curr = prev->next;
                    // delete temp;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
