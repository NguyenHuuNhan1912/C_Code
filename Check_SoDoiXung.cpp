#include <stdio.h>
#include <string.h>
 
//Hàm kiểm tra đầu vào có hợp lệ hay không
bool IsNumber(char s[], int n){
    if(n == 0) return false;
    if(s[0] == '0') return false;
    for(int i = 0; i < n;i++){
        if(s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}
int main(){
    char s[100];
    printf("Nhap so can kiem tra: "); gets(s);
    int n = strlen(s);

    //Nếu người dùng không nhập dãy số thì thoát chương trình
    if(IsNumber(s, n) == false){
        printf("\nBan nhap sai dinh dang!");
        return 0;
    }

    bool test = true;
    int i = 0, j = n - 1;
    while(i < j){
        if(s[i] != s[j]){
            test = false;
            break;
        }
        else{
            ++i; // Tăng đầu(so sánh với kí tự giảm cuối)
            --j; // Giảm cuối(so sánh với kí tự tăng đầu)
        }
    }
    if(test == true) printf("%s la so doi xung", s);
    else printf("%s khong la so doi xung", s);
        
}