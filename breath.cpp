#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>pow;
    pow.push_back(1);
    for(int i=0;i<100005;i++){
        pow.push_back((pow.back()*2)%998244353);
    }
    int t;
    cin>>t;
    vector<vector<int>>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        int x=0, y=0;
        vector<int> ans(n);
        for(int j=0;j<n;j++){
            if(a[j]>a[x])x=j;
            if(b[j]>b[y])y=j;
            if(a[x]>=b[y]){
                printf("%ld ", (pow[a[x]]+pow[b[j-x]])%998244353);
            }else{
                printf("%ld ", (pow[b[y]]+pow[a[j-y]])%998244353);
            }
        }
        puts("");
    }

}