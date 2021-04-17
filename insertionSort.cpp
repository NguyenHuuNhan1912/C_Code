/*C code By Nguyen Huu Nhan*/
/*Thuật toán sắp xếp chèn */
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
void insertionSort(recordtype arr[], int n){
	int i,j;
	for(i=1;i<=n-1;i++){
		j=i;
		while((j>0) && (arr[j].key < arr[j-1].key)){
			swap(&arr[j],&arr[j-1]);
			j--;
		}
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
	insertionSort(arr,n);
	printArr(arr,n);
	return 0;
}