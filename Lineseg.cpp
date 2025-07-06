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
    cin >> n;

    long long px,py,qx,qy;
    cin >>px>>py>>qx>>qy;

    long long total= 0;
    long long maxmove=0;
    for(int i=0;i<n;i++){
        long long cur;
        cin >> cur;
        total+=cur;
        if (cur>maxmove){
            maxmove=cur;
        }
    }

    long long dx=px-qx;
    long long dy=py-qy;
    long long distsq=dx*dx+dy*dy;
    long long maxdistsq=total*total;
    long long mindistsq=max(0LL,2*maxmove-total);
    mindistsq*=mindistsq;

    if(mindistsq<=distsq && distsq<=maxdistsq){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
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