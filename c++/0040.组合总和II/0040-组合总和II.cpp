class Solution {
public:
    vector<int> path;   //��¼��ǰ�������������
    vector<vector<int>> result; //��¼���ս��

    void backtracking(vector<int>& candidates,int target,int startIndex,vector<bool>& used){
        //��targetС��0ʱ������ϵĺʹ���targetʱ��������ֹ
        if(target<0){
            return;
        }
        //��target����0��ʱ�򣬽���ǰ�������������push�����ս��������
        if(target==0){
            result.push_back(path);
            return;
        }
        //�������candidates���飬����ݹ顣
        for(int i = startIndex;i<candidates.size();i++){
            //ȥ��
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1] ==false){
                continue;
            }
            path.push_back(candidates[i]);
            target-=candidates[i];
            used[i] = true;
            backtracking(candidates,target,i+1,used);
            used[i] = false;
            target+=candidates[i];  //target����
            path.pop_back();    //path����
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
         //����
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,used);
        return result;
    }
};