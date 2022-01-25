#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;	//记录最终结果，即一个或者多个集合
vector<int> path;	//记录单个结果
void backtracking(int n,int k,int startIndex){
	//一般回溯返回值都为void，参数需要有一个集合大小的n，要取几个数的k以及记录从哪个地方开始取的startIndex
	
	//回溯终止条件，即当path里面的元素等于k时，回溯结束
	if(path.size()==k){
		result.push_back(path);
		return;
	}
	//单层回溯逻辑，从startIndex位置开始循环到n，然后回溯
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
