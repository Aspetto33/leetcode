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
/*
二叉搜索树经过中序遍历后存在数组中是递增的，
因此可以利用这一点来求二叉搜索树的最小绝对差
*/
private:
    vector<int> result;
    void travelsal(TreeNode* root){
        if(root==NULL) return;
        //中序遍历：左中右
        travelsal(root->left);
        result.push_back(root->val);
        travelsal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        travelsal(root);
        //二叉搜索树至少有两个元素才能求差的绝对值
        if(result.size()<2) return 0;
        int res = INT_MAX;
        //因为要比较result[i]&result[i-1]因此i要从1开始，如果比较result[i]&result[i+1]则会越界
        for(int i=1;i<result.size();i++){
            res=min(res,result[i]-result[i-1]);
        }
        return res;
    }
};