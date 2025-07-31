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
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n,0);
    for(int i=y-1;i<x;i++)a[i]=1;
    bool flag=true;
    for(int i=y-2;i>=0;i--){
        flag?a[i]=-1:a[i]=1;
        flag=!flag;
    }
    flag=true;
    for(int i=x;i<n;i++){
        flag?a[i]=-1:a[i]=1;
        flag=!flag;
    }
    for(auto i:a)cout<<i<<" ";
    cout<<endl;
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