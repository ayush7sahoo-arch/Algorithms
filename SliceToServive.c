#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int t;
    scanf("%d",&t);
    int *ans=(int*)malloc(sizeof(int)*t);
    for(int i=0;i<t;i++){
        int n,m,a,b;
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%d",&a);
        scanf("%d",&b);
        int turns=0;
        while(!(m==1 && n==1)){
            
            int r=(m-b)*n;
            int l=(m*n)-r-n;
            int u=(n-a)*m;
            int d=(m*n)-u-m;

            int toCut;
            if(r>=l && r>=u && r>=d){
                toCut=r;
            }else if(l>=u && l>=d){
                toCut=l;
            }else if(u>=d){
                toCut=u;
            }else{
                toCut=d;
            }

            if(toCut==r){
                m=b;
                a=floor((float)(n)/2.0);
                b=floor((float)(m)/2.0);
            }
            else if(toCut==l){
                m=1+m-b;
                a=floor((float)(n)/2.0);
                b=floor((float)(m)/2.0);
            }
            else if(toCut==u){
                n=a;
                a=floor((float)(n)/2.0);
                b=floor((float)(m)/2.0);
            }
            else if(toCut==d){
                n=1+n-a;
                a=floor((float)(n)/2.0);
                b=floor((float)(m)/2.0);

            }
            turns++;
        }
        ans[i]=turns;

    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
}