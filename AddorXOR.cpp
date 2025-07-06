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
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    int cost=0;
    if(a>b){
        if(a%2==0)cost=-1;
        else if(b==a-1)cost=y;
        else cost=-1;
    }else if(a<b){
        while(a!=b){
            if(a%2==0){
                a++;
                cost+=min(x,y);
            }else{
                a++;
                cost+=x;
            }
        }
    }else{
        cost=0;
    }
    cout<<cost<<endl;
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