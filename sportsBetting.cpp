#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

string solve(){
    int n;
    cin>>n;
    vector<pair<ll,int>>p;
    vector<int>test(n);
    for(int i=0;i<n;i++){
        cin>>test[i];
    }
    sort(test.begin(),test.end());

    for(int i=0;i<n;i++){
        if(i==0){
            p.push_back({test[i],1});
            continue;
        }
        if(p.back().first==test[i]){
            p.back().second++;
        }else{
            p.push_back({test[i],1});
        }
    }
    int temp=p[0].first;
    bool firstFound=false;
    for(int i=0;i<p.size();i++){
        if(p[i].second>=4){
            return "YES";
        }
        if(p[i].second>1 && !firstFound){
            temp=p[i].first;
            firstFound=true;
            continue;
        }
        if(firstFound){
            if(p[i].first==temp+1){
                if(p[i].second>1)return "YES";
                
            }else{
                if(p[i].second<2) firstFound=false;
            }
            temp=p[i].first;
        }
    }
    return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}