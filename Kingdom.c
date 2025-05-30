#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int pos;
}Node;

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int *arr = (int *)malloc(n * sizeof(int));
        int *dist= (int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d", arr+j);
        }
        for(int j=0;j<n;j++){
            dist[j] = 0;
        }
        


    }
}