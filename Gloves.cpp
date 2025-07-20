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
    int n,k;
    cin>>n>>k;
    vector<int>l(n);
    vector<int>r(n);
    for(auto&i:l)cin>>i;
    for(auto&i:r)cin>>i;
    vector<int>maxa(n);
    vector<int>mina(n);
    int ans=0;

    for(int i=0;i<n;i++){
        maxa[i]=max(l[i],r[i]);
        ans+=maxa[i];
        mina[i]=min(l[i],r[i]);

    }
    sort(all(mina));
    for(int i=0;i<k-1;i++){
        ans+=mina[n-1-i];
    }
    
    cout<<ans+1<<endl;

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