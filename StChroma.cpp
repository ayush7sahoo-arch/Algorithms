#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>ans(n);
        if(x<n){
            ans[n-1]=x;
            int c=0;
            for(int i=0;i<n-1;i++,c++){
            if(c==x)c++;
            ans[i]=c;
            
        }
        }else{
            ans[n-1]=n-1;
            int c=0;
            for(int i=0;i<n-1;i++,c++){
            if(c==x)c++;
            ans[i]=c;
        }
        }
        
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;


    }

}