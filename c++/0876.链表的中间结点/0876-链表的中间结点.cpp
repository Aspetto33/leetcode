/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int listSize = 0;   //链表长度
        ListNode* cur = head;   //用空间换时间

        //计算链表长度
        while(cur!=NULL){
            cur = cur->next;
            listSize++;
        }
        
        cur = head;

        //使cur到达链表中间节点位置
        for(int i = 1;i<=listSize/2;i++){
                cur = cur->next;
            }
        return cur;
    }
};