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
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0],result[1]);
    }

    vector<int> robTree(TreeNode* cur){
        //数组长度为2，下标为0表示当前节点偷时获得的最大钱数，下标为1表示当前节点不偷获得的最大钱数
        if(cur==NULL) return vector<int> {0,0};

        //递归求左孩子节点
        vector<int> left = robTree(cur->left);

        //递归求右孩子节点
        vector<int> right = robTree(cur->right);

        //偷当前节点
        int result1 = cur->val + left[1] + right[1];

        //不偷当前节点时，要考虑左右孩子节点偷或者不偷哪个获得的钱数更多
        int result2 = max(left[0],left[1])+max(right[0],right[1]); 

        return {result1,result2};
    }
};