#include<iostream>
#include<vector>
using namespace std;
void test_2_problem2(){
	vector<int> weight = {1,3,4};
	vector<int> value = {15,20,30};
	int bagWeight = 4;
	vector<int> dp(bagWeight+1,0);	//�����м�ֵ��ʼ��Ϊ0
	//������Ʒ
	for(int i = 0;i<weight.size();i++){	
		//�����������
		for(int j=bagWeight;j>=weight[i];j--){
			dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
		}	
	}
	cout<<dp[bagWeight]<<endl;
	
	
}

int main(){
	test_2_problem2();
}
