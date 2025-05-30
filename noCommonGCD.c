#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d", &n);
        int *ans=(int*)malloc(n * sizeof(int));
        int *arr = (int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d", arr+j);
        }
        int isSame=1;

        for(int j=1;j<n;j++){
            if(arr[j]!=arr[0]){
                isSame=0;
                break;
            }
        }
        if(isSame){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int mx=arr[0];
        for(int j=1;j<n;j++){
            if(arr[j]>mx){
                mx=arr[j];
            }
        }
        for(int j=0;j<n;j++){
            if(arr[j]==mx){
                ans[j]=1;
            }else{
                ans[j]=2;
            }
        }
        for(int j=0;j<n;j++){
            printf("%d ", ans[j]);
        }
        printf("\n");

    }
}