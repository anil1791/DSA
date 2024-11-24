#include <bits/stdc++.h>
using namespace std;

void coinChangePermutations(vector<int>coins,int sum){
    vector<int>dp(sum+1,0);
    dp[0]=1;
    for(int j=0;j<=sum;j++){
        for(int i=0;i<coins.size();i++)
        {
            if(j>=coins[i]){
                dp[j]=dp[j]+dp[j-coins[i]];
            }
        }
            
    }
    
    for(int x:dp){
        cout<<x<<" ";
    }cout<<endl;
}

int main() {
    vector<int>v{2,3,5,6};
    coinChangePermutations(v,10);
}
