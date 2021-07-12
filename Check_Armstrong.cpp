#include <stdio.h>
#include <math.h>
int Count(int n){
    int count = 0;
    while (n > 0){
        n /= 10;
        ++count;
    }
    return count;
}
bool IsArmstrong(int n){
    int number = Count(n);
    int temp = n, sum = 0, last;
    while (temp > 0){
        last = temp % 10; // lấy chữ số cuối cùng
        temp /= 10;       // bỏ chữ số cuối cùng
        sum += pow(last, number);
    }
    if(sum == n) return true;
    return false;
}
int main(){
    int n;
    printf("Nhap 1 so de kiem tra: "); scanf("%d",&n);
    if(IsArmstrong(n)) printf("So %d la so armstrong !",n);
    else printf("So %d khong phai la so amrstrong !",n);
    return 0;
}