/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* cur = head;
        while(cur){
            Node* copyNode = new Node(cur->val);
            copyNode->next = cur->next;
            cur->next = copyNode;
            cur = cur->next->next;
        }

        cur = head;
        while(cur){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        Node* copyHead = head->next;
        cur = head;
        Node* curCopy = head->next;
        while(cur){
            cur->next = cur->next->next;
            cur = cur->next;

            if(copyHead->next){
                copyHead->next = copyHead->next->next;
                copyHead = copyHead->next;
            }
        }
        return curCopy;
    }
};