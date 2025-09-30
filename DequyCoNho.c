#include<stdio.h>
#include<stdlib.h>

// Su dung de quy co nho tinh C
// O day dung mang 2 chieu de luu gia tri da tinh
/*
int C1(int n, int k, int **arr){
    // **arr la mang 2 chieu luu gia tri da tinh
    if (k==0 ||k==n){
        return 1;
    } 
    if(*(*(arr+n)+k) != -1){
        // co nghia la gia tri C(n,k) da duoc tinh
        return *(*(arr+n)+k);
    } 
    return C(n-1, k-1, arr) +C(n-1, k, arr);
}
*/
// Cach 2
int C(int n, int k){
    if (k==0 ||k==n){
        return 1;
    } 
    return C(n-1, k-1) +C(n-1, k);
}

long long D[100][100];

long long C_conho(int n, int k){
    if (k==0 ||k==n){
        return 1;
    }   
    if(D[n][k] != -1){
        return D[n][k];
    } else {
        D[n][k] = C_conho(n-1, k-1) + C_conho(n-1, k);
        return D[n][k];
    }
}

int main(){
    int n, k;
    scanf("%d %d",&n, &k);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            D[i][j] = -1;
        }
    }
    printf("%lld\n", C_conho(n, k));
    return 0;
}