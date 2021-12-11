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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode(0); //��¼���ս������������ͷ�ڵ�
        ListNode* cur = result; //��¼���ָ�������

        //��������1������2
        while(list1!=NULL && list2!=NULL){

            //�������1��ǰ�ڵ��ֵС������2��������1��ǰ����ֵ�����������
            if(list1->val<=list2->val){
                cur->next = list1;
                list1 = list1->next; 
                cur = cur->next;

            //��֮��������2��ǰ����ֵ�����������
            }else{
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        
        //ѭ���������ܻ���һ������û�б����꣬����ٽ����жϣ���ʣ��ڵ㸳���������
        if(list1!=NULL){
            while(list1!=NULL){
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            }
        }

        if(list2!=NULL){
            while(list2!=NULL){
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }

        return result->next;
    }
};