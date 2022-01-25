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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()){
            vector<int> path;
            for(int i = que.size();i>0;i--){
                TreeNode* node = que.front();
                que.pop();
                path.push_back(node->val);

                
                if(node->right) que.push(node->right);
                if(node->left) que.push(node->left);
            }
            if(result.size()%2 == 0) reverse(path.begin(),path.end());
            result.push_back(path);
        }
        return result;
    }
};