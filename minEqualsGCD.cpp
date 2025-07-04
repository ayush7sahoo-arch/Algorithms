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
    cin>>n;
    vector<pair<int,int>>a(n,mp(0,0));
    int mi=INT_MAX,c1=0;
    for(auto &i:a){cin>>i.F;mi=min(mi,i.F);if(i.F==1)c1++;}
    if(c1==1){

        
    }else{
    int c=0;
    for(auto&i:a){
        if(i.F%mi==0){
            i.S=1;
            i.F=i.F/mi;

        }
    }

    for(auto i:a){
        if((i.F%mi!=0 || i.F==1)&& i.S==1)c++;
    }

    if(c>=2)cout<<"YES\n";
    else cout<<"NO\n";

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