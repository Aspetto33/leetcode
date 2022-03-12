import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {
    public ListNode sortList(ListNode head) {
        List<Integer> list = new ArrayList<>();

        ListNode cur = head;
        while(cur != null){
            list.add(cur.val);
            cur = cur.next;
        }

        Collections.sort(list);

        ListNode dummyNode = new ListNode();
        cur = dummyNode;
        for(int i : list){
            ListNode node = new ListNode(i);
            cur.next = node;
            cur = cur.next;
        }

        return dummyNode.next;
    }
    public class ListNode {
       int val;
       ListNode next;
       ListNode() {}
       ListNode(int val) { this.val = val; }
       ListNode(int val, ListNode next) { this.val = val; this.next = next; }
   }
}
