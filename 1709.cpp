#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;

#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x) 
#endif

void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto&i:a)cin>>i;
    for(auto&i:b)cin>>i;

    vector<pair<int,int>>ans;

    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){swap(a[j],a[j+1]);ans.pb(mp(1,j+1));}
        }
    }
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(b[j]>b[j+1]){swap(b[j],b[j+1]);ans.pb(mp(2,j+1));}
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            int j=i;
            swap(a[i],b[i]);
            ans.pb(mp(3,i+1));
            // while(i>0 && a[i]<a[i-1]){
            //     swap(a[i],a[i-1]);
            //     ans.pb(mp(1,i));
            //     i--;
            // }
            // while(j<n-1 && b[j]>b[j+1]){
            //     swap(b[j],b[j+1]);
            //     ans.pb(mp(2,j+1));
            //     j++;
            // }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.F<<" "<<i.S<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}