//Hiểu theo ý nghĩa đơn giản số chính phương là số căn bậc 2 của nó là số tự nhiên
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("Nhap so de kiem tra: "); scanf("%d",&n);
    int temp = sqrt(n);
    if(temp*temp == n) printf("So %d la so chinh phuong",n);
    else printf("So %d khong phai la so chinh phuong",n);
    return 0;
}