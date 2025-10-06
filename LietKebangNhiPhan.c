#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// bai toan liet ke hoan vi chap m cua n bang nhi phan
int a[100];
int m,n;

void in(){
    int count=0;
    for(int i=0; i<n; i++){
        if(a[i]==1){
            count++;
        }
    }
    if (count==m){
        for(int i=0; i<n; i++){
            if(a[i]==1){
                // in ra gia tri tuong ung
                printf("%d ", i+1); 
            }
        }
        printf("\n");
    }
}


void try(int pos){
    if(pos==n){
        // neu da du phan tu thu m roi
        in();
        return;
    } 
    a[pos]=1;
    try(pos+1);
    // Tại mỗi bước, ta thử tất cả các khả năng, và sau mỗi lựa chọn, ta phải quay lại trạng thái cũ để thử lựa chọn khác.
    a[pos]=0;
    try(pos+1);
}

int main(){
    scanf("%d%d",&n, &m);
    try(0);
}