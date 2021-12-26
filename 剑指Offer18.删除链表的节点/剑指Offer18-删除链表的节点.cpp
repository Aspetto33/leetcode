/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fastIndex = head;
        ListNode* slowIndex = dummy;
        while(fastIndex){
            if(fastIndex->val == val){
                slowIndex->next = slowIndex->next->next;
                break;
            }else{
                fastIndex = fastIndex->next;
                slowIndex = slowIndex->next;
            }
        }
        return dummy->next;
    }
};