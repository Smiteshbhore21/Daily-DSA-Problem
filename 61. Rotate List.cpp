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
    int count(ListNode* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int n = count(head);

        if (n == 0)
            return head;

        k = k % n;

        if (k == 0)
            return head;

        int steps = n - k;
        ListNode* temp = head;
        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        temp = newHead;
        while (temp && temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        return newHead;
    }
};
