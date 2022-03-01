public class Solution {
    public class ListNode {
       int val;
       ListNode next;
       ListNode(int x) {
           val = x;
           next = null;
       }
   }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        if(headA == null || headB == null)
            return null;

        ListNode curA = headA;
        ListNode curB = headB;

        int lenA = 0;
        int lenB = 0;

        while(curA != null){
            lenA++;
            curA = curA.next;
        }
        curA = headA;

        while(curB != null){
            lenB++;
            curB = curB.next;
        }
        curB = headB;

        if(lenA > lenB){
            for(int i = 1;i<=lenA-lenB;i++){
                curA = curA.next;
            }
        }
        else{
            for(int i = 1;i<=lenB-lenA;i++){
                curB = curB.next;
            }
        }

        while (curA != null || curB != null){
            if(curA == curB)
                return curA;
            curA = curA.next;
            curB = curB.next;
        }
        return null;
    }
}
