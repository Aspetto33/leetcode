public class Solution {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public static void main(String[] args) {
        ListNode head  = null;
        Solution solution = new Solution();
        ListNode listNode = solution.removeNthFromEnd(head, 1);
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null)
            return head;

        ListNode cur = head;
        int length = 0;

        while(cur != null){
            length++;
            cur = cur.next;
        }

        //1.只有一个节点并且删除此节点
        //2.删除第一个节点
        if((length == 1 && n == 1) || length - n == 0)
            return head.next;

        //普通情况
        cur = head;
        for(int i = 1;i < length-n;i++ ){
            cur = cur.next;
        }
        cur.next = cur.next.next;

        return head;
    }
}
