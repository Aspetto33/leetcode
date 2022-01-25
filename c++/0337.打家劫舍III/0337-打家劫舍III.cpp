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
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0],result[1]);
    }

    vector<int> robTree(TreeNode* cur){
        //���鳤��Ϊ2���±�Ϊ0��ʾ��ǰ�ڵ�͵ʱ��õ����Ǯ�����±�Ϊ1��ʾ��ǰ�ڵ㲻͵��õ����Ǯ��
        if(cur==NULL) return vector<int> {0,0};

        //�ݹ������ӽڵ�
        vector<int> left = robTree(cur->left);

        //�ݹ����Һ��ӽڵ�
        vector<int> right = robTree(cur->right);

        //͵��ǰ�ڵ�
        int result1 = cur->val + left[1] + right[1];

        //��͵��ǰ�ڵ�ʱ��Ҫ�������Һ��ӽڵ�͵���߲�͵�ĸ���õ�Ǯ������
        int result2 = max(left[0],left[1])+max(right[0],right[1]); 

        return {result1,result2};
    }
};