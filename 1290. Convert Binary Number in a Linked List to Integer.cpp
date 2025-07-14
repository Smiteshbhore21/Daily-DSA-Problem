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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = (ans << 1) | head->val;
            head = head->next;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         vector<int> binary;
//         while (head) {
//             binary.push_back(head->val);
//             head = head->next;
//         }
//         int ans = 0;
//         int n = binary.size(), pw = 0;
//         for (int i = n-1; i >= 0; i--) {
//             ans += ((1 << pw) * binary[i]);
//             pw++;
//         }
//         return ans;
//     }
// };
