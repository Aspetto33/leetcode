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
        
        //当cur为空时说明已经越过叶子节点，返回
        if(cur == NULL) return;

        //遍历左子树
        dfs(cur->left);

        //根节点
        if(pre) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;

        //遍历右子树
        dfs(cur->right);
    } 
};