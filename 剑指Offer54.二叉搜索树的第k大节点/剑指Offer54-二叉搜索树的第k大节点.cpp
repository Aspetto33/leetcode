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
    vector<int> tmp;

    void travel(TreeNode* root){
        if(root == NULL) return;

        tmp.push_back(root->val);
        travel(root->left);
        travel(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        travel(root);
        sort(tmp.begin(),tmp.end());
        return tmp[tmp.size()-k];   
    }
};