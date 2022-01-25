class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){}
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>(_size-1)||index<0){
            return -1;
        }
        int val;
        ListNode* cur = _dummyHead->next;
        for(int i = 0;i<_size;i++){
            if(index == i){
                val=cur->val;
            }else{
                cur = cur->next;
            }
        }
        return val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* cur = new ListNode(val);
        cur->next = _dummyHead->next;
        _dummyHead->next=cur;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        _size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<=_size-1&&index>=0){
            ListNode* cur = _dummyHead;
            while(index--){
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            _size--;
        }
    }
    private:
        ListNode* _dummyHead;
        int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */