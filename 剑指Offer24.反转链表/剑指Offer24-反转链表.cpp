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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;   //��ָ��ָ��head
        ListNode* pre = nullptr;    //��ָ�룬ָ��headǰ��һ���սڵ�

        //cur��Ϊ�յ�����½���ѭ�����ı�ָ�뷽��
        while(cur){
            ListNode* tmp = cur->next;  //����cur��һ���ڵ��ָ��
            cur->next = pre;    //curָ��ı䷽��
            pre = cur;  //pre�ƶ���cur��
            cur = tmp;  //cur�ƶ�����һ���ڵ㴦
        }
        return pre;

    }
};