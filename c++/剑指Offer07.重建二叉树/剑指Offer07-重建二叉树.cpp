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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;

        int preorder_root = preorder[0];
        TreeNode* root = new TreeNode(preorder_root);

        auto root_index = find(inorder.begin(),inorder.end(),*preorder.begin());

        vector<int> ileft(inorder.begin(),root_index);
        vector<int> iright(root_index+1,inorder.end());
        int leftSize = ileft.size();

        vector<int> pleft(preorder.begin()+1,preorder.begin()+leftSize+1);
        vector<int> pright(preorder.begin()+leftSize+1,preorder.end());

        root->left = buildTree(pleft,ileft);
        root->right = buildTree(pright,iright);

        return root;
        
    }
};