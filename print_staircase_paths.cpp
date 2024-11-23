#include <iostream>
using namespace std;
void stairPath(int n,string str){
    if(n==0){
        cout<<str<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        int left = n-i;
        str+=to_string(i);
        stairPath(left,str);
        str.pop_back();
    }
}
int main() {
    int n = 4;
    string str;
    stairPath(n,str);
}
