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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = nullptr;

        ListNode* cur = head;

        while(cur){
            ListNode* t = cur->next;
            cur->next = tmp;
            tmp = cur;
            cur = t;
        }
        return tmp;
    }
};