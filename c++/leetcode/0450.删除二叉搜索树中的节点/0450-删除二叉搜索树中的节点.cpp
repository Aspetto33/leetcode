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
        //第一种情况：没有找到key遍历到空节点处返回
        if(root==NULL) return root;
        if(root->val==key){
            //第二种情况，左右孩子都为空，返回null
            if(root->left==NULL&&root->right==NULL) return NULL;
            //第三种情况：左孩子不为空，右孩子为空，左孩子补位，返回左孩子
            else if(root->left!=NULL&&root->right==NULL) return root->left;
            //第四种情况：右孩子不为空，左孩子为空，右孩子补位，返回右孩子
            else if(root->right!=NULL&&root->left==NULL) return root->right;
            //第五种情况：左右孩子都不为空，此时应该将左孩子移到右孩子的最左面，右孩子补位
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