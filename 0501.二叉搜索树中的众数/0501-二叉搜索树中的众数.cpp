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
 先将元素遍历存放在数组中，然后将元素及其出现的次数存放在map中，以key和value的形式，
 然后vector<pair<int,int>> vect<map.begin(),map.end()>,然后将map的value进行排序，最后将vect
 的第一个元素的key存放在result中，然后从i=1循环遍历看是否有vect【i】。second==vect【0】.second
 如果有则存放进去，否则跳出循环
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
    //拼接类型的value按照递减排序
    bool static cmp(const pair<int,int>& v1,const pair<int,int>& v2){
        return v1.second>v2.second;

    }
public:
    vector<int> findMode(TreeNode* root) {
        travelsal(root);
        unordered_map<int,int> map;
        vector<int> result;
        //在map中记录下元素及其出现的次数
        for(int i=0;i<vec.size();i++){
            map[vec[i]]++;
        }
        //拼接map的key及其value值，将其放在数组中
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