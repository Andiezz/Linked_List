#include <stdio.h>

#define MAX 10000
int  a[MAX], n = 0;

void insert(int x, int p){
    if(p > n){
        p = n - 1;
    }
    for(int i = n - 1; i >= p; i--){
        a[i + 1] = a[i];
    }
    a[p] = x;
    n = n + 1;
}

void delete(int p){
    for(int i = p + 1; i < n; i++){
        a[i - 1] = a[i];
    }
    n = n - 1;
}

int retrieve(int p){
    return a[p];
}

void print(){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    insert(2, 0); print();
    insert(3, 1); print();
    delete(3); print();
    printf("%d\n", retrieve(0));
    return 0;
}

int locate(int x){
    for(int j = 0; j<n;j++){
        if(a[j]==x) return j;
    }
    return -1;
}
