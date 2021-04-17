/*C code By Nguyen Huu Nhan*/
/*Thuật toán sắp xếp nhanh*/
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
int findPivot(recordtype arr[], int i, int j){
	keytype firstkey;
	//keytype kieu int
	int k;
	k = i+1;
	firstkey = arr[i].key;
	while((k<=j) && (arr[k].key == firstkey)) k++;
	if(k>j) return -1;
	if(arr[k].key > firstkey) return k;
	return i;
}
int Partition(recordtype arr[], int i, int j, keytype pivot){
	int L,R;
	L = i;
	R = j;
	while(L<=R){
		while(arr[L].key < pivot) L++;
		while(arr[R].key >= pivot) R--;
		if(L<R)	swap(&arr[L],&arr[R]);
	}
	return L;
}
void quickSort(recordtype arr[], int i, int j){
	keytype pivot;
	int pivotindex,k;
	pivotindex = findPivot(arr,i,j);
	if(pivotindex != -1){
		pivot = arr[pivotindex].key;
		k = Partition(arr,i,j,pivot);
		quickSort(arr,i,k-1);
		quickSort(arr,k,j);
	}
}
int main(){
	printf("Danh sach cua ban co bao nhieu phan tu: ");
	int n,i,j;
	scanf("%d",&n);
	recordtype arr[n];
	printf("Nhap gia tri cac phan tu cua mang\n");
	readArr(arr,n);
	printf("Danh sach chua sap xep\n");
	printArr(arr,n);
	printf("\nDanh sach da sap xep\n");
	quickSort(arr,0,n-1);
	printArr(arr,n);
	return 0;
}