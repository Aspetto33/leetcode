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
    bool isSim(TreeNode* A,TreeNode* B){
        /*ÖÕÖ¹Ìõ¼þ*/
        if(A == NULL && B == NULL) return true;
        if(A == NULL && B) return false;
        if(A && B == NULL) return false;
        if(A->val != B->val) return false;

        return isSim(A->left,B->right) && isSim(A->right,B->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isSim(root->left,root->right);
    }
};