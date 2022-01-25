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
    vector<vector<int>> result;
    vector<int> path;
    void travelsal(TreeNode* root,int targetSum){
        // 根节点为空
        if(root==NULL) return;
        path.push_back(root->val);
        targetSum-=root->val;
        // 找到叶子节点并且恰好此路径的和等于目标值
        if(!root->left&&!root->right&&targetSum==0) result.push_back(path);
        travelsal(root->left,targetSum);
        travelsal(root->right,targetSum);
        // 回溯
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        travelsal(root,targetSum);
        return result;
    }
};