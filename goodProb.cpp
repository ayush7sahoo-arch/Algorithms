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
    int n,l,r,k;
    cin>>n>>l>>r>>k;

    if(n%2!=0){
        cout<<l<<"\n";
        return;}
    

    if(n==2){
        cout<<-1<<"\n";
        return;
    }

    int w=1LL<<(64-__builtin_clzll(l));


    if(w>r){
        cout<<-1<<"\n";
    }else{
        if(k<=n-2){
            cout<<l<<"\n";
        }else{
            cout<<w<<"\n";
        }
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