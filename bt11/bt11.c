#include<stdio.h>
#include<math.h>

// bai 1 tim phan tu lon nhat va lon thu hai trong mang

void max12(int a[], int n){
    int max1 = -10000000;
    int max2=-10000000;
    for(int i=0; i<n; i++){
        if(a[i]>max1){
            max2= max1;
            max1=a[i];
        } else if (a[i]>max2 && a[i]!=max1){
            max2=a[i];
        }
    }
    printf("%d\n", max1);
    printf("%d\n", max2);
}

void sapxep(int *a, int *b){
    int tmp;
    tmp=*a;
    *a =*b;
    *b = tmp;
}

void max34(int a[], int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(a[j]>a[i]){
                sapxep(&a[j], &a[i]);
            }
        }
    }
    printf("%d %d ", a[0], a[1]);
}

// bai 2 dem so luong so nguyen to trong day so

int prime(int n){
    if(n<2){
        return 0;
    } else {
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0){
                return 0;
            }
        }
        return n>1;
    }
}

int soluongsonguyento(int a[], int n){
    int count=0;
    for(int i=0; i<n; i++){
        if(prime(a[i])){
            count ++;
        }
    }
    return count;
}

// bai 3 dem va liet ke cac so thuan nghich trong day so vua nhap

int checksnt(int n){
    int original=n;
    int tmp=0;
    while(n>0){
        tmp = tmp*10 + n%10;
        n /=10;
    }
    if(tmp==original){
        return 1;
    } else {
        return 0;
    }
}

void soluongsothuannghich(int a[], int n){
    int count =0;
    for(int i=0; i<n; i++){
        if(checksnt(a[i])){
            printf("%d ",a[i]);
            count ++;
        }
    }
    printf("\n %d", count);
}

// bai4 so luong so chan, so le
void sochansole(int a[], int n){
    int count1=0;
    int count2=0;
    for(int i=0; i<n; i++){
        if(a[i]%2==0){
            count1++;
        } else {
            count2 ++;
        }
    }
    printf("%d %d ", count1, count2);
}


// thuat toán sàng số nguyên tố
// phai tao duoc mot mang chua [n+1] phan tu voi n la test case lon nhat ma de cho
int prime1[1000001];

void sieve(){
    // coi tat ca cac so tu 0 cho toi n la so nguyen to
    // prime[i]=1 thi la so nguyen to
    // prime[i]=0 thi khong la so nguyen to
    for(int i=0; i<1000000; i++){
        prime1[i]=1;
    }
    // loai 0 va 1
    prime1[0]=prime1[1]=0;
    for(int i=2; i<1000; i++){
        //neu i la so nguyen to
        if(prime1[i]){
            for(int j=i*i; j<=1000000; j+=i){
                prime1[j]=0;
            }
        }
    }
}

// bai uoc nguyen to nho nhat cua 1 so
// cách 1
void uocsonguyentonhonhat(){
    int t,n;
    scanf("%d", &t);
    sieve();
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            if(i==1){
                printf("1 ");
            } else {
                for(int j=2; j<=i; j++){
                if(i%j==0){
                    if(prime1[j]){
                        printf("%d ", j);
                        break;
                    }
                }
            }
            }
        }
    }
}
// cách 2
// ở đây prime[i]: lưu ước số nguyên tố nhỏ nhất
int prime2[1000001];
void sang(){
    for(int i=1; i<=1000000; i++){
        prime2[i]=i;
    }
    for(int i=2; i<=sqrt(1000001); i++){
        if(prime2[i]){
            for(int j=i*i; j<=1000001; j+=i){
                if(prime2[j]==j){ // de loai bo bot cac truong hop lap lai so
                    prime2[j]=i; // cac boi cua i se co uoc nguyen to la i
                }
            }
        }
    }
}

// kiem tra so chinh phuong
int pt(int n){
    while(n!=1){
        int count =0;
        int tmp = prime2[n]; // thua so nguyen to nho nhat cua n
        while(n%tmp==0){
            count ++;
            n /= tmp;
        }
        if (count %2 ==0){
            return 1;
        } else {
            return 0;
        }
    }
}

int checksochinhphuong(int n){
    return pt(n);
}

// bai toan kiem tra cac so nguyen to voi x trong mang n;
int ucln(int a, int b){
    if(b==0){
        return a;
    }
    return ucln(b,a%b);
}

int sntvoix( int n, int x){
    return ucln(n,x);
}

// dem cac uoc la so nguyen to cua mot so
int demuocnguyento1(int n){
    int count=0;
    for(int i=0; i<n; i++){
        if(n%i==0){
            ++count;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n!=1){
        count++;
    }
    return count;
}

// cho n va p la snt, tim x lon nhat de n! % p^x == 0;

int xlonnhat1(int n, int p){
    int count=0;
    for(int i=p;i<=n;i+=p){
        int tmp=i;
        while(tmp%p==0){
            count++;
            tmp/=p;
        }
    }
    return count;
}

int xlonnhat2(int n, int p){
    int ans=0;
    for(int i=0; i<=n; i*=p){
        ans += n/i;
    }
    return ans;
}

// dem luong chu so 0 o duoi cua n! => dme so bac cua 5

int chusokhong(int n){
    int count=0;
    for(int i=5; i<=n; i*=5){
        count += n/i;
    }
    return count;
}

void nhap(){
    int n, x;
    sieve();
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for(int i=0; i<n; i++){
        if(sntvoix(a[i], x)==1){
            printf("%d ", a[i]);
        }
    }
}
int main(){
    nhap();
    return 0;
}