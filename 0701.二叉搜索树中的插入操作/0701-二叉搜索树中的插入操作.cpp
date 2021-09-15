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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //��ֹ�����������ն����������ı������򣬵������пսڵ㽫�����
        if(root==NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        //�����������

        //����ֵС�ڸ��ڵ��ֵ��������������
        if(root->val>val) root->left = insertIntoBST(root->left,val);
        //����ֵ���ڸ�����ֵ��������������
        if(root->val<val) root->right = insertIntoBST(root->right,val);
        return root;
    }
};