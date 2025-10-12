#include<stdio.h>
#include<stdbool.h>

// GIAI BAI TOAN FIBONANCI BANG QUY HOACH DONG
#define Max 100
int a[1000];
int a1[1000];
int comp[1000];
int meme[1000];

// khai bao mang luu tru ket qua
int Fibonanci(int n){
    for (int i=0; i<n; i++) a[i]=-1;
    if(n<=2)
        return 1;
    if(a[n]!=0)
        return a[n];
    int res = Fibonanci(n-1)+Fibonanci(n-2);
    a[n]=res;
    return res;
}

int sum[Max] ={0};

int *tongmang(int a[], int n){
    int i=0;
    sum[0]=0;
    while(i<n){
        sum[i] = sum[i-1]+a[i];
        i++;
    }
    return sum;
}

// TIM TONG DAY CON LON NHAT BANG QUY HOACH DONG

int max(int a1, int b){
    return a1>b?a1:b;
}

// tim gia tri lon nhat trong mang
void max_mang(int a[], int n){
    int max=a[0];
    int last=0;
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max=a[i];
            last=i;
        }
    }
    printf("%d\n", max);
    int sum=0;
    int first=0;
    for(int j=last; j>=0; j--){
        sum+=a1[j];
        if(sum==max){
            first=j;
            break;
        }
    }
    for(int j=first; j<=last; j++){
        printf("%d ", a1[j]);
    }
}

int max_sum(int i){
    if(i==0){
        return a1[0];
    }
    if(comp[i]) return meme[i];
    int res= max(a1[i], a1[i] + max_sum(i-1));
    // meme[i] la noi luu tru ket qua cua cac day con
    meme[i]=res;
    // comp[i] la ham kiem tra xem da tinh chua
    comp[i]=1;
    return res; 
}

// truy ve bang de quy: in ra cac phan tu cua day con trong maxsum(i)
void trace(int i){
    if (i!=1 && meme[i]==a[i]+meme[i-1]){
        trace(i-1);
    }
    printf("%d",a[i]);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap mang: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }

    // Tính DP cho từng vị trí
    for (int i = 0; i < n; i++) {;
         printf("%d %d \n", i, max_sum(i));
    }

    max_mang(meme, n);
    return 0;
}