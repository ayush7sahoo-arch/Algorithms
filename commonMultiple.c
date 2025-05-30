#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d", &t);
    int* ans= (int *)malloc(t * sizeof(int));
    for(int i=0;i<t;i++){
        ans[i] = 0; // Initialize answer array
    
        int n;
        scanf("%d",&n);
        int *arr = (int *)malloc(n * sizeof(int));
        int *visited = (int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d", &arr[j]);
            visited[j] = 0; // Initialize visited array
        }
        for(int j=0;j<n;j++){
            if(visited[arr[j]-1]==0){
                visited[arr[j]-1]=1;
            }
        }
        for(int j=0;j<n;j++){
            ans[i] += visited[j];
        }
        free(arr); // Free allocated memory for arr
        free(visited); // Free allocated memory for visited
    }
    for(int i=0;i<t;i++){
        printf("%d\n", ans[i]);
    }
    free(ans); // Free allocated memory for ans
}