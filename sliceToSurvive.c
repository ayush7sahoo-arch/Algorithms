#include<stdio.h>
#include<stdlib.h>

#define int long long
#define min(a,b) a<b?a:b

int cut(int n){
    int c=0;
    while(n>1){
        n=(n-1)/2+1;
        c++;
    }
    return c;
}

void solve(){
    int n,m,a,b;
    scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
    int hor=min(1+cut(m)+cut(n-a+1),1+cut(m)+cut(a));
    int ver=min(1+cut(n)+cut(m-b+1),1+cut(n)+cut(b));
    printf("%lld\n",min(hor,ver));
}

int main(){
    int t;
    scanf("%lld",&t);
    while (t--){
        solve();
    }
    
}