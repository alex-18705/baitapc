#include<stdio.h>
#include<math.h>

int somu(int x, int y){
    int s = 1;
    for(int i=1; i<=y; i++){
        s *=x;
    }
    return s;
}

// dem so luong chu so n
int demchuso(int n){
    int count = 0;
    while( n!=0){
        count ++;
        n /=10 ;
    }
    return count;
}

// tong cac chu so
int tongchuso(int n){
    int sum = 0;
    int t;
    while( n!=0){
        t = n%10;
        sum +=t;
        n /=10 ;
    }
    return sum;
}

// tong chu so chan, tong chu so le
void tongchanle(int n){
    int sum1 = 0;
    int sum2 = 0;
    int t;
    while( n!=0){
        t = n%10;
        if(t%2==0){
            sum1 +=t;
        } else {
            sum2 +=t;
        }
        n /=10 ;
    }
    printf("%d %d", sum1, sum2);
}

int demchusochan(int n){
    int count = 0;
    int t;
    while( n!=0){
        int t = n%10;
        if (t % 2 == 0){
            count ++;
        }
        n /=10 ;
    }
    return count;
}

int demchusole(int n){
    int count = 0;
    int t;
    while( n!=0){
        int t = n%10;
        if (t % 2 != 0){
            count ++;
        }
        n /=10 ;
    }
    return count;
}

// so dep khi so luong so chan = so le
void checksodep(int n){
    int t = demchusochan(n)-demchusole(n);
    if ( t == 0){
        printf("YES");
    } else {
        printf("NO");
    }
}

int checksnt(int n){
    int count = 0;
    for (int i=2; i <= sqrt(n); i++){
        if (n % i == 0){
            count ++;
        }
    }
    if (count != 0){
        //printf("NO");
        return 0;
    } else if (count == 0){
        //printf("YES");
         return 1;
    }
}


// Cho số nguyên dương n biểu diễn n dưới dạng tổng của các số nguyên tố
//sao cho số lượng số hạng trong tổng là lớn nhất.
// output la so luong so hang lon nhat va bieu dien n duoi dang tong cac so ngt
void tongsnt(int n){
    int count=0;
    if (n%2 == 0 ){
        count = n/2;
        printf("%d \n", count);
        for (int j = 0; j<count; j++){
            printf("%d ", 2);
        }
    } else {
        count = (n-3)/2;
        printf("%d \n", count+1);
        for(int j = 1; j< count; j++){
            printf("%d ",2);
        }
        printf("%d", 3);
    }
}


int main(){
    int n; 
    scanf("%d", &n);
    tongsnt(n);
    return 0;
}