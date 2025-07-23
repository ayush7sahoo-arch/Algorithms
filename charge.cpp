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
    int n,f,a,b;
    cin>>n>>f>>a>>b;
    vector<int>m(n);
    for(auto&i:m)cin>>i;
    int ch=0;
    int time=0;
    ch=min(b,m[0]*a);

    for(int i=0;i<n-1;i++){
        int wait=m[i+1]-m[i];
        ch+=min(wait*a,b);
    }
    // cout<<ch<<endl;
    if(ch>=f){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
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