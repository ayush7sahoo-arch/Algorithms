#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        vector<bool>pst(k+1,false);
        for(int i=0;i<k;i++){
            int temp;
            cin>>temp;
            pst[temp]=true;
        }
        int nxm=k-2;
        int n=0,m=0;
        for(int i=1;i<=nxm;i++){
            if(nxm%i==0 && pst[i] && pst[nxm/i]){
                n=i,m=nxm/i;
            }
        }
        cout<<n<<" "<<m<<endl;
    }
}