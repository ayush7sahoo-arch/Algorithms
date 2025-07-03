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
    int n,k;
    cin>>n>>k;
    int sum=0,m=0;
    vector<int>c(n);
    for(auto &i:c){cin>>i;sum+=i;m=max(m,i);}
    bool allSame=false;
    for(int i=0;i<n-1;i++){
        if(c[i]!=c[i+1])allSame=false;
    }
    int ans=0;
    int r=m-sum%m,last=sum%m,rows=sum/m;
    if(allSame){
        ans=rows;
    }else if(r<=k){
        k-=r;ans=++rows;
        if(rows+k/m<=n){ans=rows+k/m;}
        else{ans=n;}
    }else{
        for(int i=rows;i>=1;i--){
            if(i-sum%i<=k||sum%i==0 || i==1){ans=i;break;}
            // last+=m;
        }
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