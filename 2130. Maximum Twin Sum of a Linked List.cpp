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
// Reversing nodes -->
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* it1 = head;
        int n = 0;
        while (it1) {
            n++;
            it1 = it1->next;
        }

        it1 = head;
        ListNode* prev = nullptr;
        int result = 0;
        for (int i = 0; i <= (n / 2) - 1; i++) {
            prev = it1;
            it1 = it1->next;
        }

        prev->next = nullptr;

        ListNode* next;

        while (it1) {
            next = it1->next;
            it1->next = prev;
            prev = it1;
            it1 = next;
        }

        it1 = head;
        ListNode* it2 = prev;
        while(it1 && it2){
            result = max(result, it1->val + it2->val);
            it1 = it1->next;
            it2 = it2->next;
        }

        return result;
    }
};

// Stack -->
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         stack<int> nodeVals;
//         ListNode* it = head;
//         while (it) {
//             nodeVals.push(it->val);
//             it = it->next;
//         }
//         it = head;
//         int result = 0;
//         while (it) {
//             result = max(result, it->val + nodeVals.top());
//             nodeVals.pop();
//             it = it->next;
//         }
//         return result;
//     }
// };
