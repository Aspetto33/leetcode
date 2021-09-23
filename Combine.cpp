#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;	//��¼���ս������һ�����߶������
vector<int> path;	//��¼�������
void backtracking(int n,int k,int startIndex){
	//һ����ݷ���ֵ��Ϊvoid��������Ҫ��һ�����ϴ�С��n��Ҫȡ��������k�Լ���¼���ĸ��ط���ʼȡ��startIndex
	
	//������ֹ����������path�����Ԫ�ص���kʱ�����ݽ���
	if(path.size()==k){
		result.push_back(path);
		return;
	}
	//��������߼�����startIndexλ�ÿ�ʼѭ����n��Ȼ�����
	for(int i=startIndex;i<=n;i++){
		path.push_back(i);
		backtracking(n,k,i+1);
		path.pop_back();
	}
}
vector<vector<int>> combine(int n,int k){
	int startIndex = 1;
	backtracking(n,k,startIndex);
	return result;
}

int main(){
	int n = 4,k=2;
	vector<vector<int>> result;
	result = combine(4,2);
	for(int i=0;i<result.size();i++){
		cout<<"[";
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<",";
		}
		cout<<"]";
	}
	std::cout<<std::endl;
}
