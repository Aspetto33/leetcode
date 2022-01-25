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
        //终止条件，即按照二叉搜索树的遍历规则，当遇见有空节点将其插入
        if(root==NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        //单层遍历规则

        //插入值小于根节点的值，则搜索左子树
        if(root->val>val) root->left = insertIntoBST(root->left,val);
        //插入值大于根结点的值，则搜索右子树
        if(root->val<val) root->right = insertIntoBST(root->right,val);
        return root;
    }
};