#include<stdio.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d",&t);
    int* ans=(int *)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++){
        int jars;
        scanf("%d",&jars);
        int rawMaterial=jars*4;
        ans[i]=rawMaterial/2;
    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
    free(ans);
    return 0;
}