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

int cal(string s){
    int score=0;
    vector<bool>found(5,false);
    vector<bool>visited(s.length(),false);
    for(int i=0;i<s.length();i++){
        if(!found[1]){
            if(s[i]=='n');
        }else if(!found[2]){

        }else if(!found[3]){
            
        }else if(!found[4]){
            
        }else if(!found[5]){
            
        }else{

        }

    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string>q(n);
    for(auto &i:q)cin>>i;
    int score=0;
    string s="";
    for(int i=0;i<n;i++){
        s=q[i];
        for(int j=i+1;j<n;j++){
            s+=q[j];
        }
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