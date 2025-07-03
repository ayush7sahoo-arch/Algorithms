#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;



int main() {
    int t;
    cin>>t;
    while(t--){
        long long k,a,b,x,y;
        cin>>k>>a>>b>>x>>y;
        int p1=0,p2=0;
        int m=0;

        if(k>=a){
            p1=(k-a)/x+1;
            int t=k-(p1*x);
            if(t>=b){
                p2=(t-b)/y+1;
                m=max(m,p1+p2);
            }else{
                m=max(m,p1);
            }
        }
        if(k>=b){
            p2=(k-b)/y+1;
            int t=k-(p2*y);
            if(t>=a){
                p1=(t-a)/x+1;
                m=max(m,p1+p2);
            }else{
                m=max(m,p2);
            }
        }
        cout<<m<<endl;
    }    
}

