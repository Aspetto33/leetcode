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
        int listSize = 0;   //������
        ListNode* cur = head;   //�ÿռ任ʱ��

        //����������
        while(cur!=NULL){
            cur = cur->next;
            listSize++;
        }
        
        cur = head;

        //ʹcur���������м�ڵ�λ��
        for(int i = 1;i<=listSize/2;i++){
                cur = cur->next;
            }
        return cur;
    }
};