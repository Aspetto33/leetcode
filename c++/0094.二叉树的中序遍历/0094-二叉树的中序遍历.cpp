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
    //     travelsal(cur->left,vec);
    //     vec.push_back(cur->val);
    //     travelsal(cur->right,vec);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> result;
        // travelsal(root,result);
        // return result;

        // 迭代法，使用栈
        stack<TreeNode*> stack;
        vector<int> result;
        TreeNode* cur = root;
        while(cur!=NULL||!stack.empty()){
            if(cur!=NULL){
                stack.push(cur);
                cur=cur->left;
            }else{
                cur = stack.top();
                stack.pop();
                result.push_back(cur->val);
                cur = cur->right;

            }
        }
        return result;
    }
};