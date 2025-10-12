#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>

int a[100];
int n,m, count=0;
// TIM TAT CA CAC XAU NHI PHAN CO DO DAI N BANG THUAT TOAN QUAY LUI

void ghinhan(){
    count++;
    for(int i=1; i<=n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void in(int k, int n){ // bit thu k
    for (int i=0; i<=1; i++){
        a[k]=i;
        if (k==n){
            ghinhan(n);
        } else {
            in(k+1, n);
        }
    }
}


// Liet ke toan bo tap con m phan tu trong tap hop n phan tu ( liet ke to hop chap m cua n )
void Try(int i, int start){
    // i la vi tri can chon phan tu thu i
    // start la phan tu bat dau co the chon
    // j la cac phan tu co the chon o vi tri thu i
    for(int j=start; j<=n-m+i; j++){
        a[i]=j;
        if (i==m){
            // truong hop da chon duoc m phan tu
            ghinhan(m);
        }
        else Try(i+1, j+1);
    }
}


// Liet ke cac hoan vi cua m phan tu trong tap hop n phan tu

bool check(int v, int k){
    for(int i=1; i<k; i++){
        if (a[i]==v) return false;
    }
    return true;
}

void Try2(int i){
    for(int j=1; j<=n; j++){
        if(check(j, i)){
            a[i]=j;
            if (i==m) ghinhan(m);
            else Try2(i+1);
        }
    }
}




// Bai toan xep hau
// doi hoi cac quan hau nam khac dong va khac cot
/*
    Phan tich thuat toan
    bai toan cho {a1,...,an} la cac  toa do vi tri co the nhan cua quan hau
    => neu chi can liet ke hoan vi = cac quan hau se nham khac cot
    kiem tra khac duong cheo la |ai-aj| != |i-j|
*/
bool kiemtraduongcheo(int j, int k){
    // kiem tra xem true neu quan hau thu k co the dat duoc o o (k,j)
    for(int i=1; i<=k-1; i++){
        if(j==a[i] || fabs(j-a[i]) == k-i){
            return false;
        }
    }
    return true;
}
void Try3(int k){ // xac dinh quan hau thu i nam o cot thu i
    // n cot : 1, 2,....,n
    // cot j: j!= a[j], voi j chay tu 1->k
    // khong cung duong cheo thi j-a[i] != k-i voi i thuoc tu 1...k
    for(int j=1; j<=n; j++){
        if(kiemtraduongcheo(j, k)){
            a[k]=j;
            if(k==n){
                ghinhan();
            }
            else Try3(k+1);
        }
    }
}

int main(){
    printf("nhap n va m: ");
    scanf("%d",&n);
    Try3(1);
    if(count == 0 ){
        printf("khong ton tai cach xep quan hau nao thoa man dk cua de bai tren");
    }
    return 0;
}