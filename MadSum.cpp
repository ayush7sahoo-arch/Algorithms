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
    vector<int>a(n);
    int s=0;
    for(auto&i:a){cin>>i;s+=i;}
    int ans=s;s=0;
    vector<bool>vis(200001,false);
    a[0]=0;vis[a[0]]=true;
    for(int i=1;i<n;i++){
        if(!vis[a[i]]){vis[a[i]]=true;a[i]=a[i-1];}
        else{
            if(a[i]<a[i-1])a[i]=a[i-1];
        }
        ans+=a[i];
    }
    vector<bool>_vis(200001,false);
    _vis[a[0]]=true;
    for(int i=1;i<n;i++){
        if(!_vis[a[i]]){_vis[a[i]]=true;a[i]=a[i-1];}
        else{
            if(a[i]<a[i-1])a[i]=a[i-1];
        }
        ans+=a[i];
        s+=a[i];
    }

    for(int i=n-1;i>=0;i--){
        ans+=(s-a[i]);
        s-=a[i];
    }
    
    cout<<ans<<endl;

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