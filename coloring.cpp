#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    long long ways=0;

    if(n-1>=2){
        long long k=0;
        int target=a[n-1];
        int i=0;
        int j = n - 2;
        while(i<j){
            if((long long)a[i]+a[j]>target){
                k+=(j-i);
                j--;
            } else{
                i++;
            }
        }
        ways+=k;
    }

    for(int l= n-2;l>=2;l--){
        long long target=max((long long)a[l],(long long)a[n-1]-a[l]);
        
        long long k=0;
        int i=0;
        int j=l-1;
        while(i<j){
            if((long long)a[i]+a[j]>target){
                k+=(j-i);
                j--;
            }else{
                i++;
            }
        }
        ways+=k;
    }

    cout<<ways<<"\n";
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}