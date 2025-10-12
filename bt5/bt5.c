#include "bt5.h"
#include<stdio.h>

// bai 2
/*
Viết chương trình C cho phép nhập vào một số n bất kỳ, tìm và in ra chữ số
đầu tiên và cuối cùng của n.
INPUT
1234
OUTPUT
1 4
*/
int sochuso(int n){
    int count=0;
    while(n>0){
        count ++;
        n /=10;
    }
    return count;
}
void sodauvacuoi(int n){
    int a[n];
    int k=sochuso(n);
    int i=0;
    while(n>0){
        a[i]=n%10;
        i++;
        n/=10;
    }
    printf("%d %d ", a[k-1], a[0]);
}
