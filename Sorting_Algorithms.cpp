#include <stdio.h>
typedef struct{
	int key;
	float otherkey;
}data;
void readData(data arr[], int *pn){
	FILE *f = fopen("dayso.inp","r");
	fscanf(f,"%d",&(*pn));
	for(int i=0;i<*pn;i++){
		fscanf(f,"%d",&arr[i].key);
	}
}
void printData(data arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i].key);
	}
}
void swap(data *a, data *b){
	data temp = *a;
		*a = *b;
		*b = temp;
}
void selectionSort(data arr[], int n){
	int i,j,count,min;
	for(i=0;i<n-1;i++){
		min = arr[i].key;
		count = i;
		for(j=i+1;j<n;j++){
			if(arr[j].key<min){
				min = arr[j].key;
				count = j;
			}
		}
		swap(&arr[i],&arr[count]);
	}
}
void insertionSort(data arr[], int n){
	int i,j;
	for(i=1;i<n;i++){
		j = i;
		while((j>0) && (arr[j].key<arr[j-1].key)){
			swap(&arr[j],&arr[j-1]);
			j--;
		}
	}
}
void bubbleSort(data arr[], int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=n-1;j>=i+1;j--){
			if(arr[j].key < arr[j-1].key){
				swap(&arr[j],&arr[j-1]);
			}
		}
	}
}
int findPivot(data arr[], int i, int j){
	int firstkey = arr[i].key;
	int k = i+1;
	while((k<=j) && (arr[k].key == firstkey))	k++;
	if(k>j) return -1;
	if(arr[k].key > firstkey) return k;//bien the thi sua lai la return i;
	return i;//bien the thi sua lai return k;
}
int partition(data arr[], int i, int j, int pivot){
	int L = i;
	int R = j;
	while(L<=R){
		while(arr[L].key < pivot ) L++;//bien the thi sua lai la >
		while(arr[R].key >= pivot) R--;//bien the thi sua lai la <=
		if (L <R) swap (& arr [L], & arr [R]);
	}
	return L;
}
void quickSort(data arr[], int i, int j){
	int pivot,pivotindex,k;
	pivotindex = findPivot(arr,i,j);
	if(pivotindex != -1){
		pivot = arr[pivotindex].key;
		k = partition(arr,i,j,pivot);
		quickSort(arr,i,k-1);
		quickSort(arr,k,j);
	} 
}
int main(){
	data arr[100];
	int n;
	readData(arr,&n);
	printf("So phan tu cua file la: %d",n);
	printf("\nThuat toan sap xep chon\n");
	printf("\nDu lieu chua sap xep\n");
	printData(arr,n);
	printf("\nDu lieu da sap xep\n");
	//selectionSort(arr,n);
	//insertionSort(arr,n);
	//bubbleSort(arr,n);
	quickSort(arr,0,n-1); 
	printData(arr,n);
	return 0;
}
// lay file o day: https://drive.google.com/file/d/1wtCR1eJLJ-cWo_hwswkN8TSp5_STKWu7/view?usp=sharing
