#include <stdio.h>
#include <math.h>

bool check_prime(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    
    //Kiểm tra không sử dụng hàm
    int n,count=0;
    printf("Nhap 1 so de kiem tra: "); scanf("%d",&n);
    if(n<2) printf("So %d khong phai la so nguyen to",n);
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) count++;
    }
    if(count==0) printf("So %d la so nguyen to",n);
    else printf("So %d khong phai la so nguyen to",n);

    /*Sử dụng hàm
    if(check_prime(n)) printf("So %d la so nguyen to",n);
    else printf("So %d la so nguyen to",n);*/

    //Chỉ sử dụng 1 trong 2 cách để run code
    return 0;
}
