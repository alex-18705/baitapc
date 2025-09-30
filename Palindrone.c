#include<stdio.h>
#include<string.h>

//Palindrone la bai toan kiem tra xau doi xung

int isPalindrone(char str[], char *left, char *right){
    if (*left != *right){
        return 0;
    } if(left >= right) {
        return 1;
    }
    return isPalindrone(str, left+1, right-1);
}

// Countpath dem so duong di tu toa do (i,j) den (m,n)
int countPath(int i, int j, int m, int n){
    if (i==m && j==n){
        return 1;
    } else {
        if (i>m || j>n){
            return 0;
        } else {
            return countPath(i+1, j, m, n) + countPath(i, j+1, m, n) + countPath(i+1, j+1, m, n);
        }
    }
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", countPath(1, 1, m, n));
    return 0;
}