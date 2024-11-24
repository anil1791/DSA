#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&arr,int row,int col)
{
    int m=arr.size();
    int n= arr.size();
    for(int i=0;i<m;i++)
    {
        if(arr[i][col]==1||arr[row][i] ==1)
        return false;
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(arr[i][j]==1)return false;
    }
    for(int i=row+1,j=col+1;i<m&&j<n;i++,j++){
        if(arr[i][j]==1)return false;
    }
    for(int i=row+1,j=col-1;i<m&&j>=0;i++,j--){
        if(arr[i][j] == 1)return false;
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
       
        if(arr[i][j]==1)return false;
    }
    return true;
}

void print(std::vector<vector<int>>&arr,int row,string path){
    
    if(row == arr.size()){
        cout<<path<<endl;
        return;
    }
    
    for(int i=0;i<arr.size();i++){
        if(isSafe(arr,row,i)){
            arr[row][i] = 1;
            print(arr,row+1,path+to_string(row) + ","+ to_string(i)+" - ");
            arr[row][i] = 0;
        }
    }
}

int main() {
    std::vector<vector<int>>arr(4,vector<int>(4,0)) ;
    string path;
    print(arr,0,path);
    
}
