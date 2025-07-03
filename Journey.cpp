#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while((t--)){
        int n;
        cin>>n;
        vector<int>a(3);
        int sum=0;
        for(int i=0;i<3;i++){cin>>a[i];sum+=a[i];}
        int ans=(n/sum)*3;
        sum=n-n%sum;
        for(int i=0;i<3;i++){
            if(sum<n){
                sum+=a[i];
                ans+=1;
            }
        }
        cout<<ans<<endl;

    }
}