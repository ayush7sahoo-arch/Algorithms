#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int>ans(t);
    for(int j=0;j<t;j++){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int pst=0;
        for(int i=0;i<n;i++){
            if(b[i]!=-1)pst++;
        }
        if(pst==0){
            int min=a[0];
            int max=a[0];
            for(int i=0;i<n;i++){
                if(a[i]>max)max=a[i];
                if(a[i]<min)min=a[i];
            }
            // cout<<k+min+1-max<<"*"<<endl;
            ans[j]=k+min+1-max;
        }else{
            bool issame=true;
            int sum=0;
            for(int i=0;i<n;i++){
                if(b[i]!=-1){
                    sum=a[i]+b[i];
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(b[i]!=-1 && sum!=a[i]+b[i]){
                    issame=false;
                    break;
                }
            }
            if(issame){bool ispos=true;
                for(int i=0;i<n;i++){
                    if(b[i]==-1){
                        if(sum-a[i]>k || sum-a[i]<0){
                            // cout<<0<<"*"<<endl;
                            ans[j]=0;
                            ispos=false;
                            break;
                        }
                    }
                }
                if(ispos==true){
                    ans[j]=1;
                }
            }else{
                // cout<<0<<"*"<<endl;
                ans[j]=0;
            }
        }
    }
    for(int i=0;i<t;i++)
    std::cout<<ans[i]<<endl;
}