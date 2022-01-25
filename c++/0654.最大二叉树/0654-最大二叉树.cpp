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
    TreeNode* travelsal(vector<int>& nums){
        TreeNode* root = new TreeNode(0);
        if(nums.size()==1){
            root->val = nums[0];
            return root;
        }
        int delimiter=0;
        int max = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
                delimiter=i;
            }
        }
        root->val = max;
        
        if(delimiter>0){
            vector<int> leftSize(nums.begin(),nums.begin()+delimiter);
            root->left = travelsal(leftSize);
        }
        if(delimiter<(nums.size()-1)){
            vector<int> rightSize(nums.begin()+delimiter+1,nums.end());
            root->right = travelsal(rightSize);
        }
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return travelsal(nums);
    }
};