/*C code By Nguyen Huu Nhan*/
/*Thuật toán sắp xếp vun đống */
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
void PushDown(recordtype arr[], int begin, int end){
    int r=begin;
    int last=(end-1)/2;
    while(r<=last){
        int L=2*r+1;
        int R;
        if(end==2*r+1){
            R=2*r+1;
        }
        else R=2*r+2;
        int Left=arr[L].key;
        int Right=arr[R].key;
        int key=arr[r].key;
        if(key<Left && Left>=Right){
            swap(&arr[r],&arr[L]);
            r=L;
        }
        else if(key<Right && Right>Left){
            swap(&arr[r],&arr[R]);
            r=R;
        }
        else r=end;
    }
}
void heapSort(recordtype arr[], int n){
    int i;
    for(i=(n-2)/2;i>=0;i--){
        PushDown(arr,i,n-1);
    }
    for(i=n-1;i>=2;i--){
        swap(&arr[0],&arr[i]);
        PushDown(arr,0,i-1);
    }
    swap(&arr[0],&arr[1]);
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
	heapSort(arr,n);
	printArr(arr,n);
	return 0;
}