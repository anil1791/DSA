#include <bits/stdc++.h>
using namespace std;
int unbounded_knapSack(int capacity, vector<int> &val, vector<int> &wt) {
    // code here
    
    vector<int>dp(capacity+1,0);
    
    for(int i=0;i<wt.size();i++){
        for(int j = 1;j<=capacity;j++){
            if(j>=wt[i])
                dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
        }
    }

    return dp[capacity];
}

int main(){
    vector<int>v{15,14,10,45,30};
    vector<int>a{2,5,1,3,4};
    cout << unbounded_knapSack(7,v,a)<<endl;
}
