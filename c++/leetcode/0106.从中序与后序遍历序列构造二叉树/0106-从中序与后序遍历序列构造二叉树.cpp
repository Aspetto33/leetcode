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
    TreeNode* travelsal(vector<int>& inorder,vector<int>& postorder){
        if(postorder.size()==0) return NULL;
        int mid = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(mid);
        // 如果root是叶子结点的话，直接返回
        if(inorder.size()==1) return root;
        int midSize;
        for(midSize=0;midSize<inorder.size();midSize++){
            if(inorder[midSize]==mid) break;
        }

        vector<int> leftinorder(inorder.begin(),inorder.begin()+midSize);
        vector<int> rightinorder(inorder.begin()+midSize+1,inorder.end());

        postorder.resize(postorder.size()-1);
        vector<int> leftpostorder(postorder.begin(),postorder.begin()+leftinorder.size());
        vector<int> rightpostorder(postorder.begin()+leftinorder.size(),postorder.end());

        root->left = travelsal(leftinorder,leftpostorder);
        root->right = travelsal(rightinorder,rightpostorder);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0) return NULL;
        return travelsal(inorder,postorder);
    }
};