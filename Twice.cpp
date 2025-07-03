#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>count(n+1,0);
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            count[temp]+=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=(count[i]/2);
        }
        cout<<ans<<endl;
    }
}