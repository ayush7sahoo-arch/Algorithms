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
    // Check for malloc failure for ans
    if (ans == NULL) {
        fprintf(stderr, "Memory allocation failed for ans\n");
        return 1; // Indicate an error
    }

    for(int i=0;i<t;i++){
        int n,m;
        scanf("%d %d",&n,&m);

        // This bag struct is largely unnecessary as 'm' directly represents capacity.
        // It's also allocated inside the loop, which is fine but could be simpler.
        bag *b=(bag*)malloc(sizeof(bag));
        // Check for malloc failure for b
        if (b == NULL) {
            fprintf(stderr, "Memory allocation failed for bag\n");
            // Free previously allocated memory before exiting
            free(ans);
            return 1;
        }
        b->cap=m;

        object* objects=(object*)malloc(sizeof(object)*n);
        // Check for malloc failure for objects
        if (objects == NULL) {
            fprintf(stderr, "Memory allocation failed for objects\n");
            free(b);
            free(ans);
            return 1;
        }

        // Initialize ans[i] to 0 before accumulation
        ans[i] = 0.0f; // CRITICAL FIX: You need to initialize the accumulator

        for(int j=0;j<n;j++){
            scanf("%d",&(objects[j].value));
        }
        for(int j=0;j<n;j++){
            scanf("%d",&(objects[j].weight));
            // Handle division by zero for weight
            if (objects[j].weight == 0) {
                // Decide how to handle this. For fractional knapsack,
                // an item with 0 weight typically means infinite vpw or can't be taken.
                // Here, it would lead to a division by zero error.
                // A common approach is to treat it as a special case or assign a very high vpw.
                // For simplicity, let's assume valid weights for now, but it's a real-world concern.
                fprintf(stderr, "Error: Object weight cannot be zero (object %d)\n", j);
                // Clean up and exit or handle gracefully
                free(objects);
                free(b);
                free(ans);
                return 1;
            }
            objects[j].vpw=(float)objects[j].value/(float)objects[j].weight;
        }

        // Bubble sort implementation
        // This is a correct implementation of bubble sort, but it's inefficient for large N.
        // For N=10^5, N^2 (10^10) operations will be too slow.
        // Consider using qsort from stdlib.h for better performance (O(N log N)).
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
        
        int j=0; // Renaming 'j' to 'obj_idx' for clarity could be helpful
        while(b->cap > 0 && j < n){ // Add check for j < n to prevent out-of-bounds access
            object obj=objects[j]; // Consider using a pointer: object *obj = &objects[j];
                                  // This avoids copying the struct.

            if(obj.weight <= b->cap){
                b->cap-=obj.weight;
                ans[i]+=(float)obj.value;
            }else{
                ans[i]+=(float)b->cap*obj.vpw;
                b->cap=0; // Bag is full
            }
            j++; // Move to the next object
        }

        // Free memory allocated within the loop
        free(objects);
        free(b);
    }

    for(int i=0;i<t;i++){
        printf("%f\n",ans[i]);
    }
    
    // Free memory allocated before the loop
    free(ans);

    return 0; // Indicate successful execution
}