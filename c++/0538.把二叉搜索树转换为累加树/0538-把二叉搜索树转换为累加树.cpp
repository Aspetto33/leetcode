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
    int pre;
    void travelsal(TreeNode* root){
        //��ֹ����
        if(root==NULL) return;
        //��
        travelsal(root->right);
        //�У�����һ��ָ������¼ǰһ������ֵ
        root->val+= pre;
        pre = root->val;
        //��
        travelsal(root->left);

    }
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        travelsal(root);
        return root;
    }
};