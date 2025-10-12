#include<stdio.h>
#include<math.h>

int max_of_four(int a, int b, int c, int d){
    int max =a;
    if(b>max){
        max = b;
    } 
    if(c>max){
        max=c;
    }
    if(d>max){
        max=d;
    }
    return max;
}
int abs(int a){
    if (a<=0){
        return -a;
    } else {
        return a;
    }
}
void update(int *a,int *b) {
    *a= *a + *b ;
    *b = abs(a-b);   
}

// cho mot day gom N so, hay tim phan tu lon thu  k voi k<=N

int maxk(int a[], int n){
    for(int i=0; i<n; i++){
        int j=i;
        for(int k=i+1; k<n; k++){
            if(a[k]>a[j]){
                j=k;
            }
        }
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    return a[0];

}


int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d ",maxk(a,n));
    return 0;
}