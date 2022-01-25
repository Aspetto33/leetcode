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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* cur = head;
        int countSize = 0;

        while(cur){
            cur = cur->next;
            countSize++;
        }
        cout<<countSize<<endl;
        cur = head;
        for(int i = 0;i<countSize-k;i++){
            cur = cur->next;
        }
        return cur;
    }
};