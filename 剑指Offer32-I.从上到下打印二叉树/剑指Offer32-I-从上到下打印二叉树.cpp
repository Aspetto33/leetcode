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
    vector<int> levelOrder(TreeNode* root) {

        vector<int> result;

        if(root == NULL) return result;
        
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            result.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        return result;
    }
};