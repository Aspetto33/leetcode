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
    int Size(TreeNode* cur){
        if(cur==NULL) return 0;
        int leftSize = Size(cur->left);
        if(leftSize==-1) return -1;
        int rightSize = Size(cur->right);
        if(rightSize==-1) return -1;
        int result;
        if(abs(leftSize-rightSize)>1){
            result = -1;
        }else{
            result = 1+max(leftSize,rightSize);
        }
        return result;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int size = Size(root);
        if(size==-1){
            return false;
        }
        return true;
    }
};