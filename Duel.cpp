#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<string>ans(t);
    int k=1;
    for(int i=0;i<t;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int mg=min(a,c);
        int mf=min(b,d);
        if(mg>mf && mg!=mf){
            ans[i]="Gellyfish";
    }else{
        ans[i]="Flower";
        }
        if(mg==mf){
            
            ans[i]="Gellyfish";
        }
    }
    

for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}