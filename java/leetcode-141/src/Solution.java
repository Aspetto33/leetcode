public class Solution {
    public boolean hasCycle(ListNode head) {

        //如果没有节点或者只有一个节点，不会有环
        if(head == null || head.next == null)
            return false;

        ListNode slow = head;   //慢指针
        ListNode fast = head.next;  //快指针

        while(fast != slow){
            if(fast == null || fast.next == null)
                return false;

            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
    class ListNode {
       int val;
       ListNode next;
       ListNode(int x) {
           val = x;
           next = null;
       }
   }
}
