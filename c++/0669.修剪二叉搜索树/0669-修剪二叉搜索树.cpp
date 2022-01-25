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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return root;
        //如果root的值小于low，则在右子树寻找大于low的值
        if(root->val<low){
            TreeNode* right = trimBST(root->right,low,high);
            return right;
        }
        //如果root的值大于high，则在左子树寻找小于high的值
        if(root->val>high){
            TreeNode* left = trimBST(root->left,low,high);
            return left;
        }
        //将不符合规则的节点剪去
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        return root;
    }
};