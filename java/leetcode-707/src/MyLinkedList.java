class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val){
        this.val = val;
    }
}

public class MyLinkedList {
    int length; //链表长度
    ListNode dummyHead; //虚拟头节点

    //初始化
    public MyLinkedList() {
        length = 0;
        dummyHead = new ListNode(0);
    }

    public int get(int index) {
        if(index < 0 || index >= length)
            return -1;

        ListNode cur = dummyHead;
        for(int i=0;i<=index;i++){
            cur = cur.next;
        }
        return cur.val;
    }

    public void addAtHead(int val) {
        addAtIndex(0,val);
    }

    public void addAtTail(int val) {
        addAtIndex(length,val);
    }

    public void addAtIndex(int index, int val) {
        if(index > length)
            return;

        if(index < 0)
            index = 0;
        ListNode cur = dummyHead;
        ListNode newNode = new ListNode(val);

        for(int i = 0;i<index;i++){
            cur = cur.next;
        }
        newNode.next = cur.next;
        cur.next = newNode;
        length++;


    }

    public void deleteAtIndex(int index) {
        if(index<0 || index>=length)
            return;

        ListNode cur = dummyHead;
        for(int i=0;i<index;i++){
            cur = cur.next;
        }
        cur.next = cur.next.next;
        length--;
    }
}
