#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<vector<int>>ans(t);
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<int>temp(n);
        for(int j=0;j<n;j++){
            if(j<k){
                temp[j]=j+1;
            }else{
                temp[j]=k+n-j;
            }
        }
        ans[i]=temp;
        
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}