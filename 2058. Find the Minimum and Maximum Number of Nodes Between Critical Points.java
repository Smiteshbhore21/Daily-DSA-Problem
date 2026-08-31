/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode prev = new ListNode();
        ListNode curr = head;
        int i = 1;

        int firstCritPoint = 0;
        int prevCritPoint = 0;
        int lastCritPoint = 0;

        int[] result = { Integer.MAX_VALUE, -1 };

        prev = curr;
        curr = curr.next;

        while (curr.next != null) {
            if (isCriticalPoint(prev.val, curr.val, curr.next.val)) {

                if (prevCritPoint == 0) {
                    firstCritPoint = i;
                } else {
                    result[0] = Math.min(result[0], i - prevCritPoint);
                }

                prevCritPoint = i;
            }
            prev = curr;
            curr = curr.next;
            i++;
        }


        if (result[0] == Integer.MAX_VALUE)
            return new int[]{-1, -1};

        result[1] = prevCritPoint - firstCritPoint;

        return result;
    }

    boolean isCriticalPoint(int prev, int curr, int next) {
        return (curr > prev && curr > next) || (curr < prev && curr < next);
    }
}
