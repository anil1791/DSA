#include <bits/stdc++.h>
using namespace std;
void paths(string str,int i,int j, int m,int n)
{
    if(i==m-1&&j==n-1){
        cout<<str<<endl;
        return ;
    }
    for(int k=1;k<=m-i;k++){
        str.push_back('v');
        str+=std::to_string(k);
        paths(str,i+k,j,m,n);
        str.pop_back();
        str.pop_back();
    }
    for(int k=1;k<=n-j;k++){
        str.push_back('h');
        str+=std::to_string(k);
        paths(str,i,j+k,m,n);
        str.pop_back();
        str.pop_back();
    }
    for(int k=1;k<=min(n-j,m-i);k++){
        str.push_back('d');
        str+=std::to_string(k);
        paths(str,i+k,j+k,m,n);
        str.pop_back();
        str.pop_back();
    }
}
int main() {
    string str;
    paths(str,0,0,3,3);
}
