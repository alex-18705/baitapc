#include<stdio.h>
#include<stdbool.h>

#define MAX 100
// VIET CHUONG TRINH NHAN SO NGUYEN BANG PHUONG PHAP CHIA DE TRI
int n;
int x[MAX]={0}, y[MAX]={0}, result[2*MAX]={0};

void khoitaomang(){
    printf("Nhap so x: ");
    for(int i=0; i<n; i++){
        scanf("%d", &x[i]);
    }
    printf("Nhap so y: ");
    for(int i=0; i<n; i++){
        scanf("%d", &y[i]);
    }
}

void nhanso(int x[], int y[],int result[],int xstart, int ystart, int len){
    if(len==1){
        result[0]=x[xstart]*y[ystart];
        return;
    } else {
        // Tao mang con de luu ket qua
        int m=len/2;
        int z0[2*MAX] = {0}; // xL * yL
        int z1[2*MAX] = {0}; // xL * yR
        int z2[2*MAX] = {0}; // xR * yL
        int z3[2*MAX] = {0}; // xR * yR
        nhanso(x,y,z0, xstart, ystart, m);
        nhanso(x,y,z1, xstart, ystart+m, m);
        nhanso(x,y,z2, xstart+m, ystart, m);
        nhanso(x,y,z3, xstart+m, ystart+m, m);
        // Gop ket qua lai vao result[];
        // result = z0*10(2*m) + (z1+z2)*10^m + z3
        for(int i=0; i<2*m; i++){
            result[i+2*m] += z0[i];
        }
        // Gộp (z1 + z2) vào result ở vị trí half
        for (int i = 0; i < 2 * m; i++) {
            result[i + m] += z1[i] + z2[i];
        }

        // Gộp z3 vào result ở vị trí 0
        for (int i = 0; i < 2 * m; i++) {
            result[i] += z3[i];
        }

        // Chuẩn hóa kết quả (xử lý số dư > 9)
        for (int i = 0; i < 2 * len; i++) {
            if (result[i] >= 10) {
                result[i + 1] += result[i] / 10;
                result[i] %= 10;
            }
        }
    }   
}

int main(){

    printf("nhap n: ");
    scanf("%d",&n);
    khoitaomang();
    nhanso(x,y,result,0,0,n);
    // in ket qua va loai bo so 0
    int start=2*n-1;
    while(start>0 && result[start]==0){
        start--;
    }
    for(int i=start; i>=0; i--){
        printf("%d",result[i]);
    }
    printf("\n");
    return 0;
}