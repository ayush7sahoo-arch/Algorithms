#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define ll long long

bool isPerfect(ll n){
    ll temp=sqrt(n);
    if(temp*temp==n)return true;
    return false;
}

void solve(){
    ll n;
    cin>>n;
    if(n==1 || isPerfect(n*(n+1)/2)){cout<<-1<<endl;return;
    }
    vector<ll>a(n);
    ll s=0;
    for(ll i=0;i<n;i++){
        a[i]=i+1;
    }
    for(ll i=0;i<n;i++){
        s+=a[i];
        if(isPerfect(s)){
            //swap
            ll temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
            s++;
        }
    }
    //print the ans
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}