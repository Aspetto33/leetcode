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
 /*
 �Ƚ�Ԫ�ر�������������У�Ȼ��Ԫ�ؼ�����ֵĴ��������map�У���key��value����ʽ��
 Ȼ��vector<pair<int,int>> vect<map.begin(),map.end()>,Ȼ��map��value�����������vect
 �ĵ�һ��Ԫ�ص�key�����result�У�Ȼ���i=1ѭ���������Ƿ���vect��i����second==vect��0��.second
 ��������Ž�ȥ����������ѭ��
 */
class Solution {
private:
    vector<int> vec;
    void travelsal(TreeNode* root){
        if(root==NULL) return;
        travelsal(root->left);
        vec.push_back(root->val);
        travelsal(root->right);
    }
    //ƴ�����͵�value���յݼ�����
    bool static cmp(const pair<int,int>& v1,const pair<int,int>& v2){
        return v1.second>v2.second;

    }
public:
    vector<int> findMode(TreeNode* root) {
        travelsal(root);
        unordered_map<int,int> map;
        vector<int> result;
        //��map�м�¼��Ԫ�ؼ�����ֵĴ���
        for(int i=0;i<vec.size();i++){
            map[vec[i]]++;
        }
        //ƴ��map��key����valueֵ���������������
        vector<pair<int,int>> vect(map.begin(),map.end());
        sort(vect.begin(),vect.end(),cmp);
        result.push_back(vect[0].first);
        for(int i=1;i<vect.size();i++){
            if(vect[i].second==vect[0].second){
                result.push_back(vect[i].first);
            }else{
                break;
            }
        }
        return result;
    }
};