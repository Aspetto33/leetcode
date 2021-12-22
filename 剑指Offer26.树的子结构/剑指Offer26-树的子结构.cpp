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
     *hasSubStructure函数作用是先找到和B根节点相同的A节点所在的位置
     *然后依次向下比较左、右子树是否都相同
     *终止条件有三个：
     *一是B遍历到叶子节点后，说明A和B有相同的结构
     *二是A遍历到叶子节点后，说明A和B没有相同的结构
     *三是节点处的值不同，返回false
     *最后判断A和B的左右子树是否都相等
    */
    bool hasSubStructure(TreeNode* A,TreeNode* B){
        //先序遍历A和B，比较结构是否一样，如果遍历后B为空，说明相同，返回true
        if(B == NULL) return true;

        //如果A遍历到空，说明B不是A的子树，返回false
        if(A == NULL) return false;

        //如果A节点的值不等于B节点的值，返回false
        if(A->val != B->val) return false;

        return hasSubStructure(A->left,B->left) && hasSubStructure(A->right,B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //如果A或B有一个为空，则返回false
        if(A == NULL || B == NULL) return false;

        //可能情况是从A的根节点开始和B结构相同，或者从A的左子树根几点开始，或者是A右子树根节点
        return hasSubStructure(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};