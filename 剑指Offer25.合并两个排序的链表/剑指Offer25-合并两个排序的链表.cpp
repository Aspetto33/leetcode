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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* l = new ListNode(0);
        ListNode* curl = l;
        while(cur1&&cur2){
            if(cur1->val<=cur2->val){
                curl->next = cur1;
                curl = curl->next;
                cur1 = cur1->next;
            }else{
                curl->next = cur2;
                curl = curl->next;
                cur2 = cur2->next;
            }
        }

        if(cur1){
            while(cur1){
                curl->next = cur1;
                curl = curl->next;
                cur1 = cur1->next;
            }
        }
        if(cur2){
            while(cur2){
                curl->next = cur2;
                curl = curl->next;
                cur2 = cur2->next;
            }
        }
        return l->next;
    }
};