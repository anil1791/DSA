#include <bits/stdc++.h>
using namespace std;

int countPaths(int n,vector<int>&dp){
    if(n==0) return 1;
    
    if(dp[n]!=-1)return dp[n];
    
    int paths = 0;
    for(int i=1;i<=n;i++){
        int left = (n-i);
        paths+=countPaths(left,dp);
    }
    return dp[n] = paths;
}

int main() {
    int n=4;
    vector<int>dp(n+1,-1);
    cout<<countPaths(n,dp)<<endl;
}
