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

int fact(int k,int n){
    int ans=n/k;
    return ans-(n%k==0);
}
int factr(int k,int n){
    int ans=n/k;
    return ans;
}

int fuck(int n,int l,int r){
    return factr(n,r)-fact(n,l);
}

void solve(){
    int l,r;
    cin>>l>>r;

    int ans=fuck(2,l,r)+fuck(3,l,r)+fuck(5,l,r)+fuck(7,l,r)-fuck(6,l,r)-fuck(10,l,r)-fuck(14,l,r)-fuck(15,l,r)-fuck(21,l,r)-fuck(35,l,r)+fuck(30,l,r)+fuck(70,l,r)+fuck(105,l,r)+fuck(42,l,r)-fuck(210,l,r);
    cout<<(r-l+1)-ans<<endl;
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