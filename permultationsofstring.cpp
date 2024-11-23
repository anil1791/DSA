#include <bits/stdc++.h>
using namespace std;
void permut(string str, string ans)
{
    if(str.empty()){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        string left = str.substr(0,i);
        string right = str.substr(i+1);
        string curr = left + right;
        permut(curr,ans+ch);
    }
    
}

int main() {
    string str = "abc";
    string ans;
    permut(str, ans);
}
