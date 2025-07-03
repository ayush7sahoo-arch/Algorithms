#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x,y;
        cin>>x>>y;
        int m=min(x,y);
        cout<<(n%m?n/m+1:n/m)<<endl;
    }
}