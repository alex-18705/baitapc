#include <stdio.h>
#include<math.h>

int tongcaccanh(int a, int b, int c){
    int x = (a*b)/c;
    int y = (a*c)/b;
    int z = (b*c)/a;
    return 4*sqrt(x + y + z + 2* (a+b+c));
}

int xepdomino(int m, int n){
    return (int)(m*n)/2; // vi moi quan domino chiem 2x1 nhung lai co mxn o  
}

int xepgach(int m, int n, int a){
   return ((m+a-1)/a) * ((n+a-1)/a);
}
// con ech nhay

void Frog(int a, int b, int k){
    int pos = ((k + 1) / 2) * a - (k / 2) * b;
    printf("vi tri sau %d lan nhay la %d\n", k, pos);
}

// bai 5 515
// di tu O(o,o) den A(a,b) bang step s 
// intput: a, b, s
// output si possible -> afficher YES
// sinon -> afficher NO
void cachdi(int a, int b, int s){
    int minstep=abs(a)+abs(b);
    if(s>=minstep && (s-minstep)%2==0) {
            printf("YES");
    } else {
        printf("NO");
    }
}

// bai 6: MUA NUOC
// tinh so tien toi thieu khi mua n lit nuoc
// 1 lit co gia a brules
// 2 lit co gia b brules
// n = x*1 + y*2
long long minprix(long long n, int a, int b){
    long long total =0;
    if (b<2*a){
        return total = (n/2)*b+(n%2)*a;
    } else {
        return total = n*a;
    }
}

// bai 7: 1061A
// co so luong xu khong gioi han tu 1 -> n
// Nó được phép có nhiều đồng tiền có cùng giá trị trong tập hợp. Số lượng đồng xu
// tối thiểu cần thiết để có được tổng S là bao nhiêu?
// Input
// Dòng duy nhất của đầu vào chứa hai số nguyên n và S (1≤n≤100000, 1 ≤S≤10^9)
// Output
// In chính xác một số nguyên - số lượng xu tối thiểu cần thiết để có được tổng S

int minxu(int n, long long s){
    return (s+n-1)/ n ;
}

int main() {
    int a;
    long long b;
    scanf(" %d %lld", &a, &b);
    printf("so xu toi thieu la %d", minxu(a,b));
    return 0;
}