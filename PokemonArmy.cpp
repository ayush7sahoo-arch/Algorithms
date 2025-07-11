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
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    if(n==1){cout<<a[0]<<endl;return;}
    vector<int>idx;

    int p=0,v=0;
    if(a[0]>a[1])idx.push_back(0);
    for(int i=1;i<n-1;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1])idx.push_back(i);
        if(a[i]<a[i-1]&&a[i]<a[i+1])idx.push_back(i);
    }
    idx.push_back(n-1);


    int ans=0;
    for(int i=0;i+1<idx.size();i+=2){
        ans+=(a[idx[i]]-a[idx[i+1]]);
    }
    ans+=a[idx.back()];



    cout<<ans<<endl;

    // for(auto i:idx)cout<<i<<" ";
    // cout<<endl;

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