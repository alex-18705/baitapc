#include<stdio.h>
#include <stdlib.h>
#include<math.h>

// dem uoc cua n giai thua
// tim bac cua p trong n giai thua 
int degree(int n, int p){
    int ans =0;
    for(int i=p ; i<=n; i+=p){
        int tmp=i;
        while(tmp%p==0){
            ++ans;
            tmp/=p;
        }
    }
    return ans;
}

int degree2(int n, int p){
    int ans = 0;
    for(int i=p; i<=n; i*=p){
        ans = n/i;
    }
    return ans;
}

// tinh tong boi chung nho nhat cua a va b
int gcd(int a, int b){
    if(b==0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}
int lcm(int a, int b){
    if (a==0 || b==0){
        return 0 ;
    } else {
        return (a/gcd(a,b))*b;

    }
}

void mangdaonguoc(int a[], int i){
    if(i<0){
        return ;
    } 
    printf("%d",a[i]);
    mangdaonguoc(a, i-1);
}

// dem chu so phan biet
 int demChuSoPhanBiet(int a[], int n) {
    int u[10] = {0};  // Mảng đánh dấu các chữ số từ 0 đến 9
    for (int i = 0; i < n; i++) {
        int tmp = abs(a[i]);  // 
        if (tmp == 0) {
            u[0] = 1;  // Trường hợp đặc biệt nếu a[i] == 0
        } else {
            while (tmp > 0) {
                int digit = tmp % 10;
                u[digit] = 1;
                tmp /= 10;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        count+=u[i];
    }

    return count;
}

// bai 12 kiem tra xem mang coc chua toan so am
int kiemtrasoam(int a[], int n){
    for(int i=0; i<=n; i++){
        if (a[i]<0){
            return 0;
        }
    }
    return 1;
}

// bai 13 tim so lon nhat trong mang 1 chieu

int maxmang(int a[], int n){
    int max=a[0];
    for(int i=0;  i<n; i++){
        if (a[i]>max){
            max=a[i];
        }
    }
    return max;
}

// bai 15 kiem tra mang doi xung
int mangdoixung(int a[], int n){
    for(int i=0; i<n; i++){
        if(a[i]!=a[n-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d",mangdoixung(a, n));
    return 0;
}