#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d",&t);
    int *ans = (int *)malloc(t * sizeof(int));

    for(int i=0;i<t;i++){
        ans[i]=0;
        int n;
        scanf("%d",&n);
        int *arr = (int *)malloc(n * sizeof(int));
        int *isPresent = (int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d", &arr[j]);
            isPresent[j] = 1; // Initialize isPresent array
        }
        int lastPrestent = 0; // Track the last present element
        for(int j=1;j<n;j++){
            if(!(arr[j]>arr[lastPrestent]+1)){
                isPresent[j] = 0; // Mark as not present if condition fails
            
            }else{
                lastPrestent = j; // Update last present element
            }
        }

        for(int j=0;j<n;j++){
            ans[i] += isPresent[j]; // Count the number of present elements
        }
        
    }
    for(int i=0;i<t;i++){
        printf("%d\n", ans[i]);
    }
}