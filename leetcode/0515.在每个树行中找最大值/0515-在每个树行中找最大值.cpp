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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> result;
        if(root!=NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            int max = INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                if(node->val>max) max = node->val;
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(max);
        }
        return result;
    }
};