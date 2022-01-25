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
    vector<int> path;
    vector<vector<int>> result;

    void backtrack(TreeNode* root,int target){
        
        if(root == NULL) return;

        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(root->val == target){
                result.push_back(path);
            }
        }
        else{
            backtrack(root->left,target-root->val);
            backtrack(root->right,target-root->val);
        }

        //»ØËÝ
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        backtrack(root,target);
        return result;
    }
};