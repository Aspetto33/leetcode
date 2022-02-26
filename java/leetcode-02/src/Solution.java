public class Solution {
    public class ListNode {
       int val;
       ListNode next;
       ListNode() {}
       ListNode(int val) { this.val = val; }
       ListNode(int val, ListNode next) { this.val = val; this.next = next; }
   }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        while(l1 != null){
            s1.append(l1.val);
            l1 = l1.next;
        }

        while(l2 != null){
            s2.append(l2.val);
            l2 = l2.next;
        }

        s1.reverse();
        s2.reverse();

        int i1 = Integer.getInteger(s1.toString());
        int i2 = Integer.getInteger(s2.toString());

        int i = i1 + i2;
        StringBuilder s = new StringBuilder();
        s.append(i);
        s.reverse();

        ListNode l = new ListNode();

        while ()
    }
}
