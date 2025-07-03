#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];

        set<int>possPrices;
        for(int i=0;i<n;i++){
            possPrices.insert(a[i]);
            possPrices.insert(b[i]);
        }
        sort(possPrices.begin(),possPrices.end());
        int maxprofit=0;
        for(auto price:possPrices){
            int pc=0,nc=0;
            for(int i=0;i<n;i++){
                if(price<=a[i])pc++;
                else if(price<=b[i])nc++;
            }
            if(nc<=k){
                int tot=pc+nc;
                int prof=tot*price;
                maxprofit=max(prof,maxprofit);
            }
        }
        cout<<maxprofit<<endl;
    }
    
}