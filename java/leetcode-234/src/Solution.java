import java.util.Stack;

public class Solution {
    public boolean isPalindrome(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        ListNode cur = head;

        while(cur != null){
            stack.push(cur);
            cur = cur.next;
        }

        cur = head;
        while(cur != null){
            if(cur != stack.pop())
                return false;
            cur = cur.next;
        }
        return true;
    }
    public class ListNode {
       int val;
       ListNode next;
       ListNode() {}
       ListNode(int val) { this.val = val; }
       ListNode(int val, ListNode next) { this.val = val; this.next = next; }
   }
}
