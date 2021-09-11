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
    void travelsal(TreeNode* cur,vector<int>& path,vector<string>& result){
        path.push_back(cur->val);
        // ÖÕÖ¹Ìõ¼þ
        if(cur->left==NULL&&cur->right==NULL){
            string sPath;
            for(int i=0;i<path.size()-1;i++){
                sPath +=to_string(path[i]);
                sPath +="->";
            }
            sPath +=to_string(path[path.size()-1]);
            result.push_back(sPath);
            return;
        }
        if(cur->left){
            travelsal(cur->left,path,result);
            path.pop_back();//»ØËÝ
        }
        if(cur->right){
            travelsal(cur->right,path,result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        if(root==NULL) return result;
        travelsal(root,path,result);
        return result;
    }
};