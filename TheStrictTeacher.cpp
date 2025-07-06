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
    int n,m,q;
    cin>>n>>m>>q;
    int m1,m2;
    cin>>m1>>m2;
    int a;
    cin>>a;
    int ans=0;
    if(a<min(m1,m2))ans=min(m1,m2)-1;
    else if(a>max(m1,m2))ans=n-max(m1,m2);
    else{
        ans=(abs(m2-m1)-2)/2+1;
    }
    cout<<ans<<endl;
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