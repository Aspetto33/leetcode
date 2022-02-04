public class Solution {
    public static void main(String[] args) {

    }

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lengthA = 0;
        int lengthB = 0;

        ListNode curA = headA;
        ListNode curB = headB;

        while(curA != null){
            lengthA++;
            curA = curA.next;
        }
        curA = headA;

        while(curB != null){
            lengthB++;
            curB = curB.next;
        }
        curB = headB;

        if(lengthA > lengthB){
            for(int i = 1;i<=lengthA-lengthB;i++){
                curA = curA.next;
            }
            while(curA != null && curB != null){
                if(curA == curB){
                    return curA;
                }
                curA = curA.next;
                curB = curB.next;
            }
        }
        else if(lengthA < lengthB){
            for(int i = 1;i<=lengthB-lengthA;i++){
                curB = curB.next;
            }
            while(curA != null && curB != null){
                if(curA == curB){
                    return curB;
                }
                curA = curA.next;
                curB = curB.next;
            }
        }
        else{
            while(curA != null && curB != null){
                if(curA == curB){
                    return curA;
                }
                curA = curA.next;
                curB = curB.next;
            }
        }
        return null;
    }
}
