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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>> que;
        int depth = 0;
        if(root) que.emplace(root,1);
        while(!que.empty()){
            TreeNode* node = que.front().first;
            depth = que.front().second;
            que.pop();
            if(node->left==NULL&&node->right==NULL) return depth;
            if(node->left) que.emplace(node->left,depth+1);
            if(node->right) que.emplace(node->right,depth+1);
        }
        return depth;
    }
};