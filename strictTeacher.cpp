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
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>ms(m);
    vector<int>qs(q);
    for(auto &i:ms)cin>>i;
    for(auto &i:qs)cin>>i;
    sort(all(ms));
    for(auto b:qs){
        int ans=0;
        if(b>ms[m-1]||b<ms[0]){
            if(b>ms[m-1])ans=n-ms[m-1];
            else ans=ms[0]-1;
        }else{
            int l=-1,r=-1,s=0,e=m-1;
            while(s<=e){
                int mid =(s+e)/2;
                if(ms[mid]>b){r=ms[mid];e=mid-1;}
                else s=mid+1;
            }
            s=0;e=m-1;
            while(s<=e){
                int mid =(s+e)/2;
                if(ms[mid]<b){l=ms[mid];s=mid+1;}
                else e=mid-1;
            }
            ans=(abs(r-l)-2)/2+1;
        }
        cout<<ans<<endl;
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