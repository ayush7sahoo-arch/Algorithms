#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>list(m);
        vector<int>known(k);
        for(int i=0;i<m;i++){
            cin>>list[i];
        }
        for(int i=0;i<k;i++){
            cin>>known[i];
        }
        if(n==k){
            for(int i=0;i<m;i++){
                cout<<"1";
            }
        }else{
            vector<bool>canBeSolved(n+1,false);
            for(int i=0;i<k;i++){
                canBeSolved[known[i]]=true;
            }
            string ans="";
            for(int i=0;i<m;i++){
                if(canBeSolved[list[i]]==false){
                    if(k>=n-1)ans+="1";
                    else ans+="0";
                    
                }else{
                    if(k-1>=n-1)ans+="1";
                    else ans+="0";
                }
            }
            cout<<ans;

        }
        cout<<endl;
    }
}