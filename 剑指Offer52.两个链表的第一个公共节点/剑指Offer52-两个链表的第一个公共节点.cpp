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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;

        int sizeA = 0;
        int sizeB = 0;

        while(curA){
            curA = curA->next;
            sizeA++;
        }
        while(curB){
            curB = curB->next;
            sizeB++;
        }

        curA = headA;
        curB = headB;

        if(sizeA>sizeB){
            for(int i = 0;i<sizeA-sizeB;i++){
                curA = curA->next;
            }
        }
        else if(sizeA<sizeB){
            for(int i = 0;i<sizeB-sizeA;i++){
                curB = curB->next;
            }
        }
        else{

        }

        while(curA&&curB){
            if(curA == curB){
                return curA;
            }else{
                curA = curA->next;
                curB = curB->next;
            }
        }
        return NULL;
    }
};