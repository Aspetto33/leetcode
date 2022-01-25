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
    TreeNode* travelsal(vector<int>& nums,int left,int right){
        //终止条件
        if(left>right) return NULL;
        //防止数据越界
        int mid = left+((right-left)/2);
        //二叉搜索树中序遍历后的数组为递增数组，所以根结点的值在数组的中间位置
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = travelsal(nums,left,mid-1);
        root->right = travelsal(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = travelsal(nums,0,nums.size()-1);
        return root;

    }
};