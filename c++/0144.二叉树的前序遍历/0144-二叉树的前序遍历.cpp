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
    // void travelsal(TreeNode* cur,vector<int>& vec){
    //     if(cur==NULL) return;
    //     vec.push_back(cur->val);
    //     travelsal(cur->left,vec);
    //     travelsal(cur->right,vec);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> result;
        // travelsal(root,result);
        // return result;

        // 迭代法，使用栈
        stack<TreeNode*> stack;
        vector<int> result;
        if(root==NULL) return result;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* node = stack.top();
            result.push_back(node->val);
            stack.pop();
            if(node->right) stack.push(node->right);
            if(node->left) stack.push(node->left);
        }
        return result;
    }
};