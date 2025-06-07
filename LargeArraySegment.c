#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int t;
    scanf("%d",&t);
    int *ans=(int*)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++){
        long long n,k;
        long long x;
        scanf("%d",&n);
        scanf("%d",&k);
        scanf("%lld",&x);
        int *arr=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        // int count=0;
        long long sum=0;
        // int round=1;
        for(int j=n-1;j>=0;j--){
            sum+=arr[j];
        }
        int round=(x + sum - 1) / sum;
        int count=0;
        long long tot=round*sum;
        int j=0;;
        while(tot>=x && j<n){
            count++;
            tot-=arr[j];
            j++;
        }


        if(round>k || k*sum<x){
            ans[i]=0;
            free(arr);
        }else{
        ans[i]=(k-round)*n+count;
        free(arr);}
    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
    free(ans);
    return 0;
}