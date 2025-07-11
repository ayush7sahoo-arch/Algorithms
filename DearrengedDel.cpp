#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define vi(a,n) vector<int>a(n)
#define input(a) for(auto&i:(a))cin>>i
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
    vi(a,n);
    input(a);
    vector<int>b=a;
    sort(all(b));
    while(true){
        if(a.empty()){cout<<"NO\n";return;}

        int fixed=-1;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])continue;
            fixed=i;
            break;
        }
        if(fixed==-1){cout<<"YES\n"<<a.size()<<endl;for(auto i:a)cout<<i<<" ";cout<<endl;return;}
        a.erase(a.begin()+fixed);
        b.erase(b.begin()+fixed);

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