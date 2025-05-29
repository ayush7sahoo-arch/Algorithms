#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);
    int* ans=(int*)malloc(sizeof(int)*t);

    for(int i=0;i<t;i++){
        int n, m, a, b;
        scanf("%d %d %d %d", &n, &m, &a, &b);
        int turns = max(a - 1, n - a) + max(b - 1, m - b);
        ans[i]=turns;
    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
