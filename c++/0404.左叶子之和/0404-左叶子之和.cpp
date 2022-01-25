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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int midSize = 0;
        if(root->left!=NULL&&root->left->left==NULL&&root->left->right==NULL){
            midSize = root->left->val;
        }
        int leftSize=sumOfLeftLeaves(root->left);
        int rightSize = sumOfLeftLeaves(root->right);
        int sum = midSize+leftSize+rightSize;
        return sum;

    }
};