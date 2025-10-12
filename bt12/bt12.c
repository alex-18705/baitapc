#include<stdio.h>
#include<limits.h>
#include "bt12.h"
#include<math.h>
#include<stdlib.h>
// nhap mang
void nhap(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    doanchuatatcapt(a,n);
}
// bai 1 tim 3 so lon nhat trong mang
void basolonnhat(int a[], int n){
    int max1, max2, max3;
    for(int i=0; i<n; i++){
        if(a[i]>max1){
            max3=max2;
            max2=max1;
            max1=a[i];
        }
        if (a[i]!=max1 && a[i]>max2){
            max3=max2;
            max2=a[i];
        } 
        if(a[i]>max3 && a[i]!=max1 && a[i]!=max2){
            max3=a[i];
        }
    }
    printf("%d %d %d", max1, max2, max3);
}

// bai 2 liet ke cac phan tu trong mang co it nhat 2 phan tu khac lon hon no
void haisolonhon(int a[], int n){
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if( j!=i && a[j]>a[i]){
                count ++;
            }
        }
        if(count>=2){
            printf("%d ", a[i]);
        } 
    }
}

// bai 3 tim 3 so nho nhat trong mang
void basonhonhat(int a[], int n){
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    for(int i=0; i<n; i++){
        if(a[i]<min1){
            min3=min2;
            min2=min1;
            min1=a[i];
        } else if(a[i]<min2 ){
            min3=min2;
            min2=a[i];
        } else if(a[i]<min3){
            min3=a[i];
        }
    }
    printf("%d %d %d ", min1, min2, min3);
}

// bai 4 hai so lon nhat trong mang, truong hop khong co so thu 2 in ra -1
void haisolonnhat(int a[], int n){
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for(int i=0; i<n; i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        if (a[i]>max2 && a[i]!=max1){
            max2=a[i];
        }
    }
    if(max1!=max2){
        printf("%d %d", max1, max2);
    } else if(max2==INT_MIN) {
        printf("%d -1", max1);
    }
}

// bai 5 tim so dep ( la so chi chua ca 1 va 9 trong so do)
void sodep(int a[], int n){
    int count=0;
    for(int i=0; i<n; i++){
        int count1=0, count9=0;
        int t=a[i];
        while(t>0){
            int tmp= t%10;
            if(tmp==1){
                count1++;
            }
            if (tmp==9){
                count9++;
            }
            t/=10;
        }
        if (count1!=0 && count9!=0){
            count ++;
        }
    }
    printf("%d", count);
}

// bai 6 tim vi tri so chan cuoi cung, neu khong co in ra -1
void sochancuoicung(int a[], int n){
    int vt=0;
    for(int i=0; i<n; i++){
        if (a[i]%2==0){
            vt=i;
        }
    }
    printf("%d", vt);
}

// bai 8 cho 1 mang va 1 ptu x, tim phan tu trong mang sao cho cach xa x nhat
void phantucachxanhat(int a[], int n, int x){
    int res=a[0];
    int tmp = -10000;
    for(int i=0; i<n; i++){
        int d = abs(a[i]-x);
        if(d> tmp){
            tmp=d;
            res = a[i];
        }
    }
    printf("%d", res);
}

// bai 9 tim doan [a, b] chua tat ca phan tu trong mang
void doanchuatatcapt(int a[], int n){
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    printf("%d %d", min, max );
}