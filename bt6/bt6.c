#include<stdio.h>

// bai 1
// co n nhan vien va can chon ra l truong nhom
// so nhan vien con lai la n-l
// phai chia deu cho l truong nhom => n-l % l =0;
int kiemtrauoc(int n, int l){
    if(n%l == 0){
        return 1;
    } else {
        return 0;
    }
}
int Fata(int n){
    int temps=0;
    for(int i=1; i<n; i++){
        if (kiemtrauoc(n-i, i)){
            temps++;
        }
    }
    return temps;
}

// bai 2
/*
Polycarp có n xu và muốn chia hết cho 3 chị em: Alice (a xu), Barbara (b xu), Cerene (c xu), sao cho sau khi chia, cả ba đều có số xu bằng nhau
nếu Polycarp đưa A xu cho Alice, B xu cho Barbara và
C xu cho Cerene (A + B + C = n), thì a + A = b + B = c + C

Input
Dòng đầu tiên của đầu vào chứa một số nguyên t (1≤t≤10^4) - số lượng trường hợp
kiểm tra.
Các dòng t tiếp theo mô tả các trường hợp thử nghiệm. Mỗi trường hợp thử nghiệm
được đưa ra trên một dòng mới và bao gồm bốn số nguyên cách nhau không gian a,
b, c và n (1≤a, b, c, n≤10^8) - số lượng tiền Alice có, số lượng tiền Barbara có, số
lượng tiền mà Cerene có và số lượng tiền mà Polycarp có.

Output
Đối với mỗi trường hợp thử nghiệm, hãy in "YES" nếu Polycarp có thể phân phối
tất cả n xu giữa các chị em của mình và "NO" nếu không

nhap t so lan kiem tra
nhap vao a , b , c, n
kiem tra xem co bo A,B,C nao thoa man A+a=B+b=C+c
A+B+C = n;

*/

void Polycarp(int a, int b, int c, int n){
    if((a+b+c+n)%3!=0){
        printf("NO");
        return;
    }
    int A = (a+b+c+n)/3 -a;
    int B = (a+b+c+n)/3 -b;
    int C = (a+b+c+n)/3 -c;
    if (A>=0 && B>=0 && C>=0){
        printf("YES");
    } else {
        printf("NO");
    }
}

/*
Có hai người chơi: Mahmoud và Ehab, lần lượt chơi, Mahmoud chơi trước.

Trò chơi bắt đầu với số nguyên dương n.

Ở mỗi lượt:

Người chơi chọn số nguyên a thỏa mãn 1 ≤ a ≤ n

Trừ a khỏi n → n = n - a
chi duoc chon cac so tu 1 toi n, roi sau do cap nhap n-a

Mahmoud chỉ được chọn số chẵn

Ehab chỉ được chọn số lẻ

Nếu người chơi không chọn được số nào hợp lệ → thua
*/
void MahmoudetEhab(int n){
    if (n%2== 0){
        printf("Mahmoud");
    } else {
        printf("Ehab");
    }
}

void Generosity(int c1, int c2, int c3, int c4, int c5){
    int sum=c1+c2+c3+c4+c5;
    if (sum == 0 || sum % 5 != 0) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", sum / 5);
    }
}

// ki chu so i, i =2, 3, 5, 6.
// vi du so 256 co 1 chu so 2, 1 so 5, 1 so 6
int min(int a, int b){
    if (a>b){
        return b;
    } else {
        return a;
    }
}
void Anton(int a, int b, int c, int d){
    int count256 = min(a, min(c,d));
    a -=count256;
    int count32 = min(a, b);
    printf("%d", 256*count256+32*count32);
}

    int a1, a2, a3;
    int b1, b2, b3;
    int n;
void nhap(){
    scanf("%d %d %d",&a1,&a2, &a3);
    scanf("%d %d %d",&b1,&b2, &b3);
    scanf("%d", &n);
}

void huychuong() {
    nhap();
    int sum1 = a1 + a2 + a3;
    int sum2 = b1 + b2 + b3;

    int cup_shelves = (sum1 + 4) / 5;
    int medal_shelves = (sum2 + 9) / 10;

    if (cup_shelves + medal_shelves <= n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

// bai 8, tim so gio con lai truoc tet
int Nammoi(int a, int b){
    if(a==0 && b==0){
        return 0;
    } else {
        return (23-a)*60+(60-b);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    int a[t], b[t];
    for(int i=0; i<t; i++){
        scanf("%d %d",&a[i], &b[i]);
    }
    for(int i=0; i<t; i++){
        printf("%d \n", Nammoi(a[i], b[i]));
    }
    return 0;
}