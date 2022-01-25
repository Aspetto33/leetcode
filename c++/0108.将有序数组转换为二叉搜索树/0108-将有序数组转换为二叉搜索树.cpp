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
        //��ֹ����
        if(left>right) return NULL;
        //��ֹ����Խ��
        int mid = left+((right-left)/2);
        //������������������������Ϊ�������飬���Ը�����ֵ��������м�λ��
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