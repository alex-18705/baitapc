#include<stdio.h>

int binarysearch(int a[], int l, int r, int x){
    int m = l + (r-l)/2;
    if(a[m]==x){
        return 1;
    } else {
        if(x<a[m]){
            return binarysearch(a,l,m-1, x);
        } else 
        return binarysearch(a,m+1,r,x);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d \n", *(a+i));
    }
    int x;
    scanf("%d", &x);
    if(binarysearch(a,0,n,x)){
        printf("YES");
    } 
        printf("NO");
    return 0;
}