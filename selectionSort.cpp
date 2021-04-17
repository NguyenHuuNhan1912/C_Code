/*C code By Nguyen Huu Nhan*/
/*Thuật toán sắp xếp chọn*/
#include <stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void readArr(recordtype arr[], int n){
	for(int i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&(arr[i].key));
	}
}
void printArr(recordtype arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i].key);
	}
}
void swap(recordtype *x, recordtype *y){
	recordtype temp = *x;
				*x=*y;
				*y=temp;
}
void selectionSort(recordtype arr[], int n){
	int i,j,lowindex;
	keytype lowkey;
	for(i=0;i<n-1;i++){
		lowkey = arr[i].key;
		lowindex = i;
		for(j=i+1;j<n;j++){
			if(arr[j].key < lowkey){
				lowkey = arr[j].key;
				lowindex = j;
			}
		}
		swap(&arr[i],&arr[lowindex]);
	}
}
int main(){
	printf("Danh sach cua ban co bao nhieu phan tu: ");
	int n;
	scanf("%d",&n);
	recordtype arr[n];
	printf("Nhap gia tri cac phan tu cua mang\n");
	readArr(arr,n);
	printf("Danh sach chua sap xep\n");
	printArr(arr,n);
	printf("\nDanh sach da sap xep\n");
	selectionSort(arr,n);
	printArr(arr,n);
	return 0;
}
