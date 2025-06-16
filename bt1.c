#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define pi 3.14

long long expression(int n){
    return (long long)(pow(n,3) + 3*pow(n,2) + n + 1);
}

float cv(int n){
    return (float)(2*pi*n);
}

float dt(int n){
    return (float)(pi*pow(n, 2));
}

float distance_euclid(int x1, int y1, int x2, int y2){
    return (float)(sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)));
}

unsigned long long sum(int n){
    unsigned long long s=0;
    for(int i=1; i<=n; i++){
        s+=i;
    }
    return s;
}

unsigned long long sum2(int n){
    unsigned long long s=0;
    for(int i=1; i<=n; i++){
        s+=(unsigned long long)i*i;
    }
    return s;
}

float tong3(int n){
    float s=0;
    for(int i=1; i<=n; i++){
        s+= (float)1/(i*(i+1));
    }
    return s;
}

unsigned long long tong4(int n) {
    unsigned long long s = 0;
    for (int i = 2; i <= n; i++) {
        s += (double) pow(2,i);  // 2^i
    }
    return s; 
}

// so lon nhat chia het cho b khong vuot qua a
int chiahet(int a, int b){
    if (a<b){
        return 0;
    } else {
        return a - (a%b);
    }

}

// so chia het cho b nho nhat va lon hon hoac bang a
int chiahet2(int a, int b){
    int r = a % b;
    if (r == 0) {
        return a;  // a đã chia hết cho b
    } else {
        return a + (b - r);  // tìm số tiếp theo chia hết cho b
    }
}

// in ra so ngay cua thang
bool namnhuan(int n){
    if ( n % 400 == 0 || (n%4==0 && n%100!=0)){
        return 1;
    } else {
        return 0;
    }
}

void ngaythang(int t, int n){
    if((t>=1 && t<=12) && (n >=0)){
        if (t==1 || t==3|| t==5|| t==7|| t==11){
            printf("%d", 31);
        } else if(t==2){
            if(namnhuan(n)){
                printf("%d", 29);
            } else {
                printf("%d", 28);
            }
        } else {
            printf("%d", 30);
        }
    } else {
        printf("INVALID");
    }
}

// kiem tra in thuong
void kitu(char c){
    if (c >= 65 && c<= 90){
        printf("YES");
    } else {
        printf("NO");
    }
}

// chuyen doi ngay sang thang, nam, ngay
int main(){
    char c;
    scanf("%c",&c);
    kitu(c);
    return 0;
}