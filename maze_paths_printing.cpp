#include <bits/stdc++.h>
using namespace std;
void recur(string str,int i,int j,int m,int n)
{
    if(i==m-1&&j==n-1){
        cout<<str<<endl;
        return ;
    }
    if(i<m){
        str.push_back('v');
        recur(str,i+1,j,m,n);
        str.pop_back();
    }
    if(j<n){
        str.push_back('h');
        recur(str,i,j+1,m,n);
        str.pop_back();
    }
}

int main() {
    string str;
    recur(str,0,0,3,3);
}
