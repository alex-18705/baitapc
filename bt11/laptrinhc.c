#include<stdio.h>
#include<math.h>
// bai tap 1: so spenic duoc phan tich thanh 3 so nguyen to khac nhau
int spenic(int n){
    int res=0;
    for(int i=2; i<=n; i++){
        int cnt=0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        if(cnt>=2){
            return 0;
        } 
        if (cnt==1) ++res;
    }
    if(n!=1){
        ++res;
    }
    return res=3;
}

// bai 9 buoi 11
int solonnhat(int a[],int n){
    int max=-1000000;
    int tmp=0;
    for(int i=0; i<n; i++){
        if(a[i]>=max){
            max=a[i];
            tmp=i;
        }
    }
    return tmp;
}

int sonhonhat(int a[],int n){
    int tmp=0;
    int min=1000000;
    for(int i=0; i<n; i++){
        if(a[i]<=min){
            min=a[i];
            tmp=i;
        }
    }
    return tmp;
}

// bai 11 buoi 11
int min(int a, int b){
    if(a>=b){
        return b;
    } else {
        return a;
    }
}

int max(int a, int b){
    if(a>=b){
        return a;
    } else {
        return b;
    }
}
void thanhpho(int a[], int n){
    for(int i = 0; i < n; i++){
        int mini, maxi;

        if(i == 0){
            mini = abs(a[1] - a[0]);
            maxi = abs(a[n - 1] - a[0]);
        } else if(i == n - 1){
            mini = abs(a[n - 1] - a[n - 2]);
            maxi = abs(a[n - 1] - a[0]);
        } else {
            mini = min(abs(a[i] - a[i - 1]), abs(a[i + 1] - a[i]));
            maxi = max(abs(a[i] - a[0]), abs(a[n - 1] - a[i]));
        }

        printf("%d %d\n", mini, maxi);
    }
}

// bai 12 buoi 11
int thoitien(int a[], int n) {
    int cnt25 = 0, cnt50 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 25) {
            cnt25++;
        } else if (a[i] == 50) {
            if (cnt25 == 0) return 0;
            cnt25--;
            cnt50++;
        } else if (a[i] == 100) {
            if (cnt50 > 0 && cnt25 > 0) {
                cnt50--;
                cnt25--;
            } else if (cnt25 >= 3) {
                cnt25 -= 3;
            } else {
                return 0;
            }
        }
    }

    return 1;
}

// bai 13 buoi 11
int dem(int a[], int n){
    int tmp=0;
    int i=0;
    while(n--){
        if(a[i]==1){
            tmp++;
        }
        i++;
    }
    if(tmp<2){
        return 0;
    } else {
        return 1;
    }
}

// bai 14, tim phan tu xuat hien nhieu nhat trong mang, in ra so tim duoc va so lan xuat hien
int xuathien(int a[], int n){
    int vt; // luu vi tri cua so do
    int count=0; // dem so lan xuat hien
    int max=0;
    for(int i=0; i<n;i++){
        int tmp=a[i];
        for(int j=i; j<n; j++){
            if (tmp=a[j]{
                count++;
            })
        }
        if(count>max){
            max = count;
            vt=i;
        }
    }
    printf("%d %d", a[vt], count);
}
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    if(thoitien(a,n)) printf("YES");
    else printf("NO");
    return 0;
}