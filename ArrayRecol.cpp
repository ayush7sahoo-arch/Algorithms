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
    vector<int>a(n);
    int s=0;
    for(auto&i:a){cin>>i;}
    vector<int> b=a;
    sort(all(a));
    for(int i=0;i<k+1;i++){
        s+=a[n-i-1];
    }
    int ans=0;
    if(k>=2){
        ans=s;
    }else{
        int m1=0;
        for(int i=1;i<n-1;i++){
            m1=max(m1,b[i]);
        }
        ans=max(m1+max(b[0],b[n-1]),b[0]+b[n-1]);
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