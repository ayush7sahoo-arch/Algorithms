#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll calMin(int k,int n){
    return k+n-1;
}

ll calMax(int k,int n){
    return k*(k+1)/2+(n-k)*k;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    if(n==1){
        if(m==1){
            cout<< 1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    ll root=-1;
    // bin search for root
    ll s=1,e=n;
    while(s<=e){
        ll mid=s+(e-s)/2;
        if(m>=calMin(mid,n) && m<=calMax(mid,n))
        root=mid;break;
        if(m<calMin(mid,n)){
            e=mid-1;
        }
        if(m>calMax(mid,n)){
            s=mid+1;
        }
    }
    if(root==-1){
        cout<<-1<<endl;
        return;
    }
    cout<<root<<endl;

    ll ex=m-calMin(root,n);

    vector<bool>con(n+1);
    con[root]=true;

    if(root!=1){
        cout<<root<<" "<<1<<endl;
    }

    for(ll i=n;i>=2;i--){
        if(con[i])continue;
        ll gain=min(root,i)-1;
        if(ex>=gain){
            cout<<root<<" "<<i<<endl;
            ex-=gain;
            con[i]=true;
        }else{
            con[i]=true;
            cout<<1<<" "<<i<<endl;
        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}