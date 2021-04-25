/*Phan tich va thiet ke thuat toan*/
/*Bai toan rut tien ATM*/
#include <stdio.h>
void ATM_Algorithm(int MG[], int result[], int n){
    while(1){
        if (n == 0) break;
        if (n >= MG[0]){
            n -= MG[0];
            result[0] +=1;
        }
        else if ((n < MG[0]) && (n >= MG[1])){
            n -= MG[1];
            result[1] +=1;
        }
        else if ((n < MG[1]) && (n >= MG[2])){
            n -= MG[2];
            result[2] +=1;
        }
        else if ((n<MG[2]) && (n>=MG[3])){
            n -= MG[3];
            result[3] +=1;
        }
        else if((n<MG[3]) && (n>=MG[4])){
            n -= MG[4];
            result[4] +=1;
        }
        else if((n<MG[4]) && (n>=MG[5])){
            n -= MG[5];
            result[5] +=1;
        }
        else if((n<MG[5]) && (n>=MG[6])){
            n -= MG[6];
            result[6] +=1;
        }
        else if((n<MG[6]) && (n>=MG[7])){
            n -= MG[7];
            result[7] +=1;
        }
        else if((n<MG[7]) && (n>=MG[8])){
            n -= MG[8];
            result[8] +=1;
        }
    }
}
int countATM(int result[]){
    int total;
    for(int i=0;i<9;i++){
        total += result[i];
    }
    return total;
}
void print_ATM(int MG[], int result[], int n){
	for(int i =0;i<9;i++){
        printf("So to %d: %d\n",MG[i],result[i]);
    }
}
int main(){
    int n;
    printf("Nhap so tien can rut: ");
    scanf("%d", &n);
    int result[9] = {0,0,0,0,0,0,0,0,0};
    int MG[9] = {500000,200000,100000,50000,20000,10000,5000,2000,1000};
    ATM_Algorithm(MG,result,n);
    printf("\nTong so to tien ma cay ATM tra cho ban la: %d\n\n",countATM(result));
    print_ATM(MG,result,n);
    return 0;
}
