/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        dfs(root);

        head->left = pre;
        pre->right = head;

        return head;

    }
private:
    Node* pre;
    Node* head;

    void dfs(Node* cur){
        
        //��curΪ��ʱ˵���Ѿ�Խ��Ҷ�ӽڵ㣬����
        if(cur == NULL) return;

        //����������
        dfs(cur->left);

        //���ڵ�
        if(pre) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;

        //����������
        dfs(cur->right);
    } 
};