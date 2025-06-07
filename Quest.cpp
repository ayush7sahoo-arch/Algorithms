#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int>ans(t);
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<int>b(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        // int maxa=a[0],maxaIdx=0;
        // int maxb=b[0],maxbIdx=0;
        // for(int j=0;j<min(n,k);j++){
        //     if(a[j]>maxa){
        //         maxa=a[j];
        //         maxaIdx=j;
        //     }
        //     if(b[j]>maxb){
        //         maxb=b[j];
        //         maxbIdx=j;
        //     }
        // }
        // if(maxaIdx>maxbIdx ){
        //     if(maxa>maxb){

        //     }
        // }

        int maxb=b[0];
        int q=0;
        for(int j=0;j<min(k,n)&& q<k;j++){
            if(j==0){
                ans[i]+=a[j];
                q++;
            }else{
                ans[i]+=max(a[j],maxb);
                if(max(a[j],maxb)==maxb && maxb!=a[j]){
                    j--;q++;
                }else{
                maxb=b[j]>maxb?b[j]:maxb;
                q++;}
            }
        }
        while(q<k){
            ans[i]+=maxb;
            q++;
        }


    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}