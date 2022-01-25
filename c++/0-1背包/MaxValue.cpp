#include<iostream>
#include<vector>
using namespace std;

void test_2_problem1(){
	vector<int> weight = {1,3,4};
	vector<int> value = {15,20,30};
	int maxBagWeight = 4;
	
	//初始化
	vector<vector<int>> dp(weight.size(),vector<int>(maxBagWeight+1,0));
	for(int j = weight[0];j<maxBagWeight;j++){
		dp[0][j] = value[0];
	}
	
	//循环寻找最大值
	for(int i = 1;i<weight.size();i++){	//遍历物品
		for(int j=0;j<=maxBagWeight;j++){	//遍历重量
			if(weight[i]>j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
		}
	}
	cout<<dp[weight.size()-1][maxBagWeight]<<endl;
	
}

int main(){
	test_2_problem1();
}
