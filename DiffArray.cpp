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
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(auto&i:a)cin>>i;
    for(auto&i:b)cin>>i;
    sort(all(a));
    sort(all(b));

    int ans=0;
    int s1=0,s2=0,e1=n-1,e2=m-1;
    while(s1<=e1){
        int d1=abs(a[s1]-b[e2]);
        int d2=abs(a[e1]-b[s2]);

        if(d1>d2){
            ans+=d1;
            s1++;
            e2--;
        }else{
            ans+=d2;
            e1--;
            s2++;
        }

        
    }
    cout<<(ans)<<endl;
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