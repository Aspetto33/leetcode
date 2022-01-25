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
        //���root�ǿյģ�ֱ�ӷ��ؿ�
        if(root == NULL) return NULL;

        //���root����ڵ㲻�ǿյģ�����ڵ��nextָ��ָ���ҽڵ�
        if(root->left!=NULL){
            root->left->next = root->right;

            //���root��nextָ�벻�ǿգ���root�ұ߻��нڵ㣬��root�ҽڵ��nextָ���Ա���ڵ�
            if(root->next!=NULL){
                root->right->next = root->next->left;
            }
        }

        //�ݹ�������
        connect(root->left);

        //�ݹ�������
        connect(root->right);

        return root;
    }
};