#include <bits/stdc++.h>
using namespace std;

void coinChange(vector<int>coins,int sum){
    vector<int>dp(sum+1,0);
    dp[0]=1;
    for(int i=0;i<coins.size();i++)
    {
        for(int j=coins[i];j<=sum;j++){
            dp[j]=dp[j]+dp[j-coins[i]];
        }
    }
    for(int x:dp){
        cout<<x<<" ";
    }cout<<endl;
}

int main() {
    vector<int>v{2,3,5};
    coinChange(v,7);
}
