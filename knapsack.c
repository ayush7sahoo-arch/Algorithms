#include<stdio.h>
#include<stdlib.h>

typedef struct object{
    int value;
    int weight;
    float vpw;
}object;

typedef struct bag{
    int cap;
}bag;

int main(){
    int t;
    scanf("%d",&t);
    float *ans=(float*)malloc(sizeof(float)*t);

    for(int i=0;i<t;i++){
        ans[i]=0.0;
        int n,m;
        scanf("%d %d",&n,&m);
        bag *b=(bag*)malloc(sizeof(bag));
        b->cap=m;
        object* objects=(object*)malloc(sizeof(object)*n);
        for(int j=0;j<n;j++){
            scanf("%d",&(objects[j].value));
        }
        for(int j=0;j<n;j++){
            scanf("%d",&(objects[j].weight));
            objects[j].vpw=(float)objects[j].value/(float)objects[j].weight;
        }

        for(int j=n-1;j>0;j--){
            for(int k=0;k<j;k++){
                if(objects[k].vpw < objects[k+1].vpw){ // Sort in descending order
                    //swap
                    object temp;
                    temp = objects[k];
                    objects[k] = objects[k+1];
                    objects[k+1] = temp;
                }
            }
        }
        
        int j=0;
        while(b->cap>0){
            object obj=objects[j];
            if(obj.weight<=b->cap){
                b->cap-=obj.weight;
                ans[i]+=(float)obj.value;
            }else{
                ans[i]+=(float)b->cap*obj.vpw;
                b->cap=0;
            }
            j++;
        }

    }
    for(int i=0;i<t;i++){
        printf("%f\n",ans[i]);
    }
    

}
