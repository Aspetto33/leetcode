#include<iostream>
#include<vector>
using namespace std;
void test_CompletePack(){
	vector<int> weight = {1,3,4};
	vector<int> value = {10,15,30};
	int bagSize = 4;
	vector<int> dp(bagSize+1,0);
	
	for(int i=0;i<weight.size();i++){
		for(int j = weight[i];j<=bagSize;j++){
			dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
		}
	}
	cout<<dp[bagSize]<<endl;
}

int main(){
	test_CompletePack();
}
