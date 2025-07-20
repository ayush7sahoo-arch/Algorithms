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

typedef struct point{
    int id;
    int x;
    int y;
}point;

void solve(){
    int n;
    cin>>n;
    vector<point>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i+1;
    }
    vector<bool>xp(n+1);
    vector<bool>yp(n+1);

    vector<point>sortx=a;
    sort(all(sortx),[](point &a,point &b){return a.x<b.x;});

    for(int i=0;i<n/2;i++){
        xp[sortx[i].id]=false;
    }
    for(int i=n/2;i<n;i++){
        xp[sortx[i].id]=true;
    }

    vector<point>sorty=a;
    sort(all(sorty),[](point &a,point &b){return a.y<b.y;});

    for(int i=0;i<n/2;i++){
        yp[sorty[i].id]=false;
    }
    for(int i=n/2;i<n;i++){
        yp[sorty[i].id]=true;
    }

    vector<int>pp,mm,pm,mp;

    for(int i=0;i<n;i++){
        if(xp[a[i].id]){
            if(yp[a[i].id]){
                pp.pb(a[i].id);
            }else{
                pm.pb(a[i].id);
            }
        }else{
            if(yp[a[i].id]){
                mp.pb(a[i].id);
            }else{
                mm.pb(a[i].id);
            }
        }
    }

    for(int i=0;i<pp.size();i++){
        cout<<pp[i]<<" "<<mm[i]<<endl;
    }
    for(int i=0;i<pm.size();i++){
        cout<<pm[i]<<" "<<mp[i]<<endl;
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