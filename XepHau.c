#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int a[100];
int m,n,count=0;

// Bai toan xep hau
// doi hoi cac quan hau nam khac dong va khac cot
/*
    Phan tich thuat toan
    bai toan cho {a1,...,an} la cac  toa do vi tri co the nhan cua quan hau
    => neu chi can liet ke hoan vi = cac quan hau se nham khac cot
    kiem tra khac duong cheo la |ai-aj| != |i-j|
*/

void ghinhan(){
    count++;
    for(int i=1; i<=n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
} 

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