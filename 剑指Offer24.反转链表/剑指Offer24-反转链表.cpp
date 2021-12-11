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
        ListNode* cur = head;   //快指针指向head
        ListNode* pre = nullptr;    //慢指针，指向head前面一个空节点

        //cur不为空的情况下进行循环，改变指针方向
        while(cur){
            ListNode* tmp = cur->next;  //保存cur下一个节点的指针
            cur->next = pre;    //cur指针改变方向
            pre = cur;  //pre移动到cur处
            cur = tmp;  //cur移动到下一个节点处
        }
        return pre;

    }
};