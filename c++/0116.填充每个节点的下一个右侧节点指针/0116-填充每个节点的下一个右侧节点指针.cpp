/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //如果root是空的，直接返回空
        if(root == NULL) return NULL;

        //如果root的左节点不是空的，令左节点的next指针指向右节点
        if(root->left!=NULL){
            root->left->next = root->right;

            //如果root的next指针不是空，即root右边还有节点，令root右节点的next指向旁边左节点
            if(root->next!=NULL){
                root->right->next = root->next->left;
            }
        }

        //递归左子树
        connect(root->left);

        //递归右子树
        connect(root->right);

        return root;
    }
};