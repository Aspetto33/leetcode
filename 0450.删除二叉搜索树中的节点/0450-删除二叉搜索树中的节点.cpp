/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //��һ�������û���ҵ�key�������սڵ㴦����
        if(root==NULL) return root;
        if(root->val==key){
            //�ڶ�����������Һ��Ӷ�Ϊ�գ�����null
            if(root->left==NULL&&root->right==NULL) return NULL;
            //��������������Ӳ�Ϊ�գ��Һ���Ϊ�գ����Ӳ�λ����������
            else if(root->left!=NULL&&root->right==NULL) return root->left;
            //������������Һ��Ӳ�Ϊ�գ�����Ϊ�գ��Һ��Ӳ�λ�������Һ���
            else if(root->right!=NULL&&root->left==NULL) return root->right;
            //��������������Һ��Ӷ���Ϊ�գ���ʱӦ�ý������Ƶ��Һ��ӵ������棬�Һ��Ӳ�λ
            else{
                TreeNode* cur = root->right;
                while(cur->left!=NULL){
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        if(key>root->val) root->right = deleteNode(root->right,key);
        if(key<root->val) root->left = deleteNode(root->left,key);
        return root;
    }
};