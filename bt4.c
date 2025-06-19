#include <stdio.h>
#include<math.h>


// bai 1
/* 
bai 1 tim so dep
Một số được coi là thuần nguyên tố nếu nó là số nguyên tố, tất cả các chữ số là
nguyên tố và tổng chữ số của nó cũng là một số nguyên tố. Bài toán đặt ra là đếm
xem trong một đoạn giữa hai số nguyên cho trước có bao nhiêu số thuần nguyên tố.
INPUT
23 199
OUTPUT
1
*/
int checksnt(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int chusonguyento(int n){
    while(n>0){
       int k = n%10;
       if(!checksnt(k)){
        return 0;
       } 
       n /=10;
    }
    return 1;
}

int tongchusonguyento(int n){
    int sum=0;
    while (n!=0)
    {
        sum = sum + n%10;
        n /=10;
    }
    if(checksnt(sum)){
        return 1;
    } else {
        return 0;
    }
}

int sothuannguyento(int n){
    if(checksnt(n) && chusonguyento(n) && tongchusonguyento(n)){
        return 1;
    } 
    return 0;
}

void sodep(int m, int n){
    int count=0;
    for(int i= m; i<=n; i++){
        if(sothuannguyento(i)){
            count++;
        }
    }
    printf("%d", count);
}

// bai 2
/*
Bài 2.Tìm số hoàn hảo trong đoạn cho trước.
Viết chương trình cho phép nhập vào hai số nguyên dương và tìm tất cả các số
hoàn hảo(là số có tổng các ước số nhỏ hơn nó bằng chính nó) (nếu không tồn tại số nào thì in ra 0)
INPUT
1 100
OUTPUT
6 28
*/
int tonguoc(int n){
    int sum=0;
    for(int i=1; i<n;i++){
        if(n%i==0){
            sum += i;
        }
    }
    return sum;
}

int sohoanhao(int n){
    if(tonguoc(n)==n){
        return 1;
    }
    return 0;
}

void sohoanhaotrongdoan(int n, int m){
    for(int i=n; i<=m; i++){
        if(sohoanhao(i)){
            printf("%d \n", i);
        }
    }
}

// bai 3
/*
Bài 3. Số tăng giảm
Một số được gọi là số tăng giảm nếu số đó có các chữ số thỏa mãn hoặc tăng
dần, hoặc giảm dần từ trái qua phải.
Hãy đếm các số nguyên tố là số tăng giảm với số chữ số cho trước
INPUT
2
OUTPUT
20

chu so tang hoac giam tu trai qua phai
dem cac so nguyen to la so tang giam voi so co n chu so
*/

// Kiểm tra chữ số tăng hoặc giảm dần
int checktanggiam(int n) {
    int digits[20];
    int len = 0;

    // Lưu các chữ số vào mảng từ phải sang trái
    while (n > 0) {
        digits[len++] = n % 10;
        n /= 10;
    }

    // Đảo ngược mảng để có thứ tự từ trái sang phải
    for (int i = 0; i < len / 2; i++) {
        int temp = digits[i];
        digits[i] = digits[len - 1 - i];
        digits[len - 1 - i] = temp;
    }

    int isIncreasing = 1;
    int isDecreasing = 1;

    for (int i = 0; i < len - 1; i++) {
        if (digits[i] < digits[i + 1]) {
            isDecreasing = 0;
        }
        if (digits[i] > digits[i + 1]) {
            isIncreasing = 0;
        }
    }

    return isIncreasing || isDecreasing;
}
// Đếm số nguyên tố có chữ số tăng hoặc giảm
void sotanggiam(int n){
    int min =(int) pow(10, n - 1);
    int max = (int)pow(10, n) - 1;
    int count = 0;
    for (int i = min; i <= max; i++) {
        if (checksnt(i) && checktanggiam(i)) {
            count++;
        }
    }
    printf("%d", count);
}

// bai 4
/*
Một số được coi là đẹp nếu nó là số nguyên tố và tổng chữ số là một số trong
dãy Fibonaci. Viết chương trình liệt kê trong một đoạn giữa hai số nguyên cho
trước có bao nhiêu số đẹp như vậy
INPUT
2 50
OUTPUT
2 3 5 11 17 23 41
*/

int fibo(long long n){
   //2 so fibonacci f0 va f1
   if(n == 0 || n == 1){
      return 1;
   }
   long long fn1 = 1, fn2 = 0, fn;
   //sinh ra so fibonacci tu f2 toi f92
   for(int i = 2; i <= 92; i++){
      fn = fn1 + fn2;
      if(fn == n){
         return 1;
      }
      //dich fn1 fn2 sang 2 gia tri tiep theo
      fn2 = fn1;
      fn1 = fn;
   }
   return 0;
}

int tongchuso(int n){
    int sum=0;
    while (n!=0)
    {
        sum = sum + n%10;
        n /=10;
    }
    return sum;
}

void sodep4(int n, int m){
    for (int i=n; i<=m; i++){
        int tong=tongchuso(i);
        if(checksnt(i) && fibo(tong)){
            printf("%d ", i);
        } 
    }
}

// phan tich so nguyen thanh thua so nguyen to


 void thuasnt(int n){
     int i =2;
     while(n>1){
        if(n%i==0 && checksnt(i)){
            printf("%d ", i);
            n = n/i;
        } else {
            i++;
        }
    }
}

// bai 7
/*
Một số được coi là đẹp nếu nó là số thuận nghịch và có ít nhất 3 ước số
nguyên tố khác nhau. Viết chương trình in ra các số đẹp như vậy trong một đoạn
giữa hai số nguyên cho trước
INPUT
2 100
OUTPUT
*/

int sothuannghich(int n){
    int k = 0;
    int temp=n;
    while(n>0){
        k = k*10 + n%10;
        n /=10;
    }
    if(k == temp) {
        return 1;
    } else {
        return 0;
    }
}

int souoc(int n){
    int count =0;
    for(int i=2; i<=n; i++){
        if(n%i==0 && checksnt(i)){
            count++;
        }
    }
    return count++;
}

void sodep7(int a, int b){
    for(int i=a; i<=b; i++){
       if(sothuannghich(i) && (souoc(i) >=3)){
            printf("%d ", i);
       }
    }
}

// bai 8
/*
Một số được coi là đẹp nếu nếu nó có tính chất thuận nghịch và tổng chữ số
chia hết cho 10. Bài toán đặt ra là cho trước số chữ số. Hãy đếm xem có bao nhiêu
số đẹp với số chữ số như vậy
INPUT
2
OUTPUT
1
*/
int tongchusochia10(int n){
    int sum=0;
    while(n>0){
        sum += n%10;
        n /=10;
    }
    if (sum % 10 == 0){
        return 1;
    } else {
        return 0;
    }
}

void sodep8(int n){
    int min=pow(10,n-1);
    int max = pow(10, n)-1;
    int count=0;
    for(int i=min; i<=max; i++){
        if(sothuannghich(i) && tongchusochia10(i)){
            count++;
        }
    }
    printf("%d", count);
}

// bai 11
/*
Viết chương trình cho phép nhập vào hai số nguyên dương và tìm tất cả các
số Strong (là số có tổng giai thừa các chữ số bằng chính nó) nằm trong khoảng đó
(nếu không tồn tại số nào thì in ra 0)
INPUT
1 1000
OUTPUT
1 2 145
*/

int giaithua(int n){
    int k=1;
    for(int i=1; i<=n; i++){
        k *=i;
    }
    return k;
}

int tongchusogiaithua(int n){
    int sum=0;
    while(n>0){
        sum += giaithua(n%10);
        n/=10;
    }
    return sum;
}

void strong(int a, int b){
    for(int i=a; i<=b; i++){
        if(tongchusogiaithua(i) == i){
            printf("%d ", i);
        }
    }
}

// bai 12 so loc phat
/*
Một số được gọi là “lộc phát” nếu chỉ có các chữ số 0,6,8. Nhập vào một số
nguyên dương không quá 9 chữ số, hãy kiểm tra xem đó có phải số lộc phát hay
không. Nếu đúng in ra 1, sai in ra 0
INPUT
6068
OUTPUT
1
*/
int solocphat(int n){
    while(n>0){
        int k = n%10;
        if (k !=0 && k!=6 && k!=8){
            return 0;
        }
        n /=10;
    }
    return 1;
}
int main() {
    int n, m;
    //scanf("%d %d", &n, &m);
    scanf("%d", &n);
    //strong(n, m);
    if(solocphat(n)){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}