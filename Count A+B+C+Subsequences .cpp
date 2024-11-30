#include <bits/stdc++.h>
using namespace std;



int main(){
    string str = "abcabc";
    
    int a  = 0;
    int ab = 0;
    int abc = 0;
    
    for(auto &ch:str){
        if(ch == 'a'){
            
                a = 2*a+1;
            
        }
        else
        if(ch == 'b' ){
            
                ab = 2*ab + a;  
            
        }
        else
     
        {
            
                abc = 2*abc + ab;
            
        }
    }
    cout<<abc<<endl;
}
