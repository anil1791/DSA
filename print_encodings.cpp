#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, char> mp;
void permut(string str, string ans)
{
    if(str.empty()){
        cout<<ans<<endl;
        return;
    }
    string curr;
    string max = "26";
    for(int i=0;i<str.length();i++){
        curr += str[i];
        int num = stoi(curr);
        if(num>=1&&num<=26){
            string right = str.substr(i+1);
            permut(right,ans+mp[num]);
        }
        
    }
}

int main() {
    string str = "123";
    string ans;
    

    for (int i = 1; i <= 26; ++i) {
        mp[i] = 'a' + (i - 1);
    }
    permut(str, ans);
    
}
