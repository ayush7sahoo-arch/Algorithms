#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>c(n+1);
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    int l=-1,r=-1;
    int left=0,right=0;
    int len=0;
    for(int i=0;i<n;i++){
        if(c[a[i]]==1 ){

            if(l==-1 && r==-1){
            l=i+1;r=i+1;}
            else if(r==i){
                r=i+1;
            }

            if(r-l+1>len && l!=-1&& r!=-1){left=l;right=r;len=r-l+1;}
            
        }else{
            l=-1;r=-1;
        }

    }

    if(len==0){
        cout<<0<<endl;
    }else{
        cout<<left<<" "<<right<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}