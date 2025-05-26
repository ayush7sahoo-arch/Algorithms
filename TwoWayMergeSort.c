#include<stdio.h>
#include<stdlib.h>

int* merge(int*arr1,int*arr2,int m,int n){
    int x=m+n;
    int* arr=(int*)malloc(sizeof(int)*(x));
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            arr[k++]=arr2[j++];
        }
    }
    while(i<m){
        arr[k++]=arr1[i++];
    }
    while(j<n){
        arr[k++]=arr2[j++];
    }
    return arr;

}

void twoWayMergeSort(int *arr,int n){
    
    int s=1;
    while(s<n){
    for(int i=0,j=i+s;i<n&&j<n;i+=2*s,j+=2*s){
        int* arr1=arr+i;
        int* arr2=arr+j;
        
        int n1=i+s<=n?s:n-i;
        int n2=j+s<=n?s:n-j;

        int*a=merge(arr1,arr2,n1,n2);
        for(int k=i;k<n1+n2+i;k++){
            arr[k]=a[k-i];
        }

    }
    s*=2;
}
}

int main(){

    int n;
    scanf("%d",&n);

    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    twoWayMergeSort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}