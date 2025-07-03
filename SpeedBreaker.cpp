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
    vector<int>city(n);
    int minIdx=-1,minVal=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>city[i];
        if(city[i]<minVal){minVal=city[i];minIdx=i;}
    }

    int s=minIdx,e=minIdx;
    vector<bool>visited(n,false);
    int time=1;
    int ans=1;
    visited[minIdx]=true;
    while(true){
        
        time++;
        if(time<=minVal){
            ans++;
        }
        if(s>0 && e<n-1){
            if(city[s-1]<time || city[e+1]<time)break;
            if(city[s-1]>city[e+1]){
                visited[++e]=true;
            }else{
                visited[--s]=true;
            }
        }else if(s==0 && e==n-1){
            break;
        }else if(s==0){
            if(city[e+1]<time)break;
            visited[++e]=true;
        }else if(e==n-1){
            if(city[s-1]<time)break;
            visited[--s]=true;
        }
    }

    for(auto i:visited){
        if(i==false){
            cout<<0<<endl;
            return;
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