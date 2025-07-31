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
    int n,c;
    cin>>n>>c;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    int ans=0;
    sort(all(a));
    
    while(!a.empty()){
        auto it=lower_bound(all(a),c);
        if(*it==c){
            a.erase(it);
            for(auto& i:a){
                    i*=2;
                }
        }else{
            if(it==a.begin()){
                break;
            }else{
                it--;
                a.erase(it);
                for(auto& i:a){
                    i*=2;
                }
            }
        }
    }
    cout<<a.size()<<endl;

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