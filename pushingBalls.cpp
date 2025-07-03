#include<iostream>
#include<vector>
using namespace std;

bool upcheck(vector<string>box,int i,int j){
    for(int k=i-1;k>=0;k--){
        if(box[k][j]=='0')return false;
    }
    return true;
}
bool leftcheck(vector<string>box,int i,int j){
    for(int k=j-1;k>=0;k--){
        if(box[i][k]=='0')return false;
    }
    return true;
}

string solve(){
    int n,m;
    cin>>n>>m;
    vector<string>box(n);
    for(auto &i:box)cin>>i;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(!leftcheck(box,i,j) && !upcheck(box,i,j)&& box[i][j]=='1')return "NO";
        }
    }
    return "YES";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}