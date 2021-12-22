/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL) return root;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);

        return root;
    }
};