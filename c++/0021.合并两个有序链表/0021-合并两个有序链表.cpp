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
        ListNode* result = new ListNode(0); //记录最终结果的链表，虚拟头节点
        ListNode* cur = result; //记录结果指针的链表

        //遍历链表1和链表2
        while(list1!=NULL && list2!=NULL){

            //如果链表1当前节点的值小于链表2，则将链表1当前结点的值赋给结果链表
            if(list1->val<=list2->val){
                cur->next = list1;
                list1 = list1->next; 
                cur = cur->next;

            //反之，则将链表2当前结点的值赋给结果链表
            }else{
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        
        //循环结束可能会有一个链表没有遍历完，因此再进行判断，将剩余节点赋给结果链表
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