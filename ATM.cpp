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
/*/*Nhan hai so nguyen lon*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char value[100]; //Chuoi gia tri
} bigint ;
int sign(bigint X){
	int val = atoi(X.value);
	if(val>0) return 1;
	else if(val<0) return -1;
	else if(val==0)	return 0;
}
int abs(bigint X){
	int val = atoi(X.value);
	val = abs(val);
	return val;
}
bigint intToBigInt(int key){
	bigint k;
	itoa(key,k.value,10);
	return k;
}
bigint left(bigint X, int k){
	char s[100];
	strncpy(s,X.value,k);
	strcpy(X.value,s);
	return X;
}
bigint right(bigint X, int k){
	strcpy(X.value,strrev(X.value));
	char s[100];
	strncpy(s,X.value,k);
	strcpy(X.value,s);
	strcpy(X.value,strrev(X.value));
	return X;
}
bigint sub(bigint M, bigint N){
	int keyM = atoi(M.value);
	int keyN = atoi(N.value);
	int result = keyM - keyN;//kieu so nguyen
	bigint k;
	itoa(result,k.value,10);
	return k;
}
bigint mult(bigint X, bigint Y, int n) {
	bigint m1,m2,m3,A,B,C,D;
	bigint MUL;
	//Luu dau
	int s = sign(X) * sign(Y);
	//Bat dau xu ly
	int x = abs(X); //Chuyen gia tri cua X tu bigint thanh int
	int y = abs(Y); //Chuyen gia tri cua Y ...
	s = sign(X) * sign(Y); //Tim dau cua ket qua
	if (n == 1) { //Neu gia tri cua X,Y: 0 < X,Y < 9)
		int mul = x * y * s;
		MUL = intToBigInt(mul); //Chuyen gia tri cua Int sang bigint
		return MUL;
	}
	// Neu n khac 1
	A = left(X,n/2);
	B = right(X,n/2);
	C = left(Y,n/2);
	D = right(Y,n/2);
	m1 = mult(A,C,n/2);
	m2 = mult(sub(A,B),sub(D,C),n/2);
	m3 = mult(B,D,n/2);
	
	int keym1 = atoi(m1.value);
	int keym2 = atoi(m2.value);
	int keym3 = atoi(m3.value);
	int keyA = atoi(A.value);
	int keyB = atoi(B.value);
	int keyC = atoi(C.value);
	int keyD = atoi(D.value);
	
	int result = (s*(keym1*pow(10,n)+(keym1+keym2+keym3)*pow(10,n/2)+keym3));
	itoa(result,MUL.value,10);
	return MUL;
}
int main(){
	bigint X;
	bigint Y;
	int arr[7];
	printf("Nhap so nguyen thu 1: "); gets(X.value);
	printf("Nhap so nguyen thu 2: "); gets(Y.value);
	int len = strlen(X.value);
	int n = len;
	printf("Tich hai so nguyen lon la: %s",mult(X,Y,n));
	return 0;
}*/
