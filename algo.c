#include<stdio.h>

long long puissance(int a, int n){
    if(n==0){
        return 1;
    }
    return (long long)a * puissance(a, n-1);

}

// la fonction factorielle

long long fact(int n){
    if(n==1) return 1;
    return (long long)n*fact(n-1);
}

//

float Un(int n){
    return (float)(1/(n*n));
}

float Vn(int n){
    if (n==1){
        return Un(1);
    }
    return Un(n)+Vn(n-1);
}


int main(){
    int a,n;
    printf("Nhap a va n: ");
    scanf("%d %d",&a, &n);
    printf("%lld\n", puissance(a,n));
    printf("fact %d la %lld\n", n, fact(n));
    return 0;
}