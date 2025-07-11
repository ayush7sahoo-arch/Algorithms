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
const int INF = -1e18;

#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x) 
#endif

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int>dp(5,INF);
    dp[0]=0;

    string tar="narek";

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        vector<int>nextdp=dp;
        int cost=0;
        for(auto c:s)if(c=='n'||c=='a'||c=='r'||c=='e'||c=='k')cost++;

        for(int start=0;start<5;start++){
            if(dp[start]==INF)continue;

            int cur=start;
            int comp=0;

            for(auto c:s){
                if(c==tar[cur])cur++;
                if(cur==5)cur=0,comp++;
            }

            int end=cur;

            int change=10*comp-cost;
            int newscore=dp[start]+change;

            nextdp[end]=max(newscore,nextdp[end]);

            
        }
        dp=nextdp;

    }

    int maxscore=0;
    for(auto i:dp)maxscore=max(maxscore,i);
    cout<<maxscore<<endl;

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