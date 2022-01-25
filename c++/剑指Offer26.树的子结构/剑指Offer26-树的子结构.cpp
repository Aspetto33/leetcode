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
    /*
     *hasSubStructure�������������ҵ���B���ڵ���ͬ��A�ڵ����ڵ�λ��
     *Ȼ���������±Ƚ����������Ƿ���ͬ
     *��ֹ������������
     *һ��B������Ҷ�ӽڵ��˵��A��B����ͬ�Ľṹ
     *����A������Ҷ�ӽڵ��˵��A��Bû����ͬ�Ľṹ
     *���ǽڵ㴦��ֵ��ͬ������false
     *����ж�A��B�����������Ƿ����
    */
    bool hasSubStructure(TreeNode* A,TreeNode* B){
        //�������A��B���ȽϽṹ�Ƿ�һ�������������BΪ�գ�˵����ͬ������true
        if(B == NULL) return true;

        //���A�������գ�˵��B����A������������false
        if(A == NULL) return false;

        //���A�ڵ��ֵ������B�ڵ��ֵ������false
        if(A->val != B->val) return false;

        return hasSubStructure(A->left,B->left) && hasSubStructure(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //���A��B��һ��Ϊ�գ��򷵻�false
        if(A == NULL || B == NULL) return false;

        //��������Ǵ�A�ĸ��ڵ㿪ʼ��B�ṹ��ͬ�����ߴ�A�������������㿪ʼ��������A���������ڵ�
        return hasSubStructure(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};