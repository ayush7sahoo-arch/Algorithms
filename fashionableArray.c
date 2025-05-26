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
    int t;
    scanf("%d",&t);
    int* ans=(int*)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++){
        ans[i]=__INT32_MAX__;
        int n;
        scanf("%d",&n);
        int* arr=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf("%d",arr+j);
        }
        twoWayMergeSort(arr,n);
        for(int s=0;s<n;s++){
            for(int e=n-1;e>=s;e--){
                int op=(n-(e-s))-1;

                if((arr[s]+arr[e])%2==0 && op<ans[i]){
                    ans[i]=op;
                }

            }
        }


    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
}