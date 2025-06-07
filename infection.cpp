#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<pair<int, int>> ans;
    for(int i=0;i<t;i++){
        int n,m,l,r;
        cin>>n>>m>>l>>r;
        
        int _r=floor((float)r*(float)m/(float)n);
        int _l=floor((float)l*(float)m/(float)n);
        
        ans.push_back({_l, _r});
    }
    for(auto& p : ans){
        cout << p.first << " " << p.second << endl;
    }
}