#include<stdio.h>
#include<stdlib.h>

void solve(){
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    if(n==2){
        if(a[1]-a[0]>1)
        {printf("YES\n");
        return;}
    }
    printf("NO\n");

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}