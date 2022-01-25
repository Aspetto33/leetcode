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
        //终止条件
        if(root==NULL) return;
        //右
        travelsal(root->right);
        //中，声明一个指针来记录前一个结点的值
        root->val+= pre;
        pre = root->val;
        //左
        travelsal(root->left);

    }
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        travelsal(root);
        return root;
    }
};