#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct{
	char TenTien[25];
	int MG,PA;
}Tien;
Tien * ReadFile(int*n){
	FILE *f;
	f=fopen("ATM.INP", "r");
	Tien *dslt;
	dslt = (Tien*)malloc(sizeof(Tien));
	int i = 0;
	while (!feof(f)){
		fscanf(f,"%d",&dslt[i].MG);
		fgets(dslt[i].TenTien,25,f);
		dslt[i].TenTien[strlen(dslt[i].TenTien)-1]='\0';
		dslt[i].PA = 0;
		i++;
		dslt = (Tien*)realloc(dslt,sizeof(Tien)*(i+1));
	}
	*n=i;
	fclose(f);
	return dslt;
}
void swap(Tien *x, Tien *y){
	Tien temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void BS(Tien dslt[], int n){
	int i,j;
	for(i = 0; i <= n-2;i++)
		for(j = n-1;j >= i+1;j--)
			if(dslt[j].MG > dslt[j-1].MG)
				swap(&dslt[j], &dslt[j-1]);
}
void InDS(Tien *dslt, int n, int TienCanRut){
	int i;
	int TongTienTra = 0;
	int TienKhongTra = 0;
	printf("|---|-------------------------|---------|---------|----------|\n");
	printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n","STT","Loai Tien","Menh gia","So to","Thanh tien");
	printf("|---|-------------------------|---------|---------|----------|\n");
	for(i = 0; i < n-1; i++){
	//		if()
		printf("|%-3d",i);
		printf("|%-25s", dslt[i].TenTien);
		printf("|%-9d", dslt[i].MG);
		printf("|%-9d", dslt[i].PA);
		printf("|%-10d|\n", dslt[i].MG*dslt[i].PA);
		TongTienTra = TongTienTra + dslt[i].PA*dslt[i].MG;
	}
	printf("|---|-------------------------|---------|---------|----------|\n");
	printf("So tien can rut = %d\n", TienCanRut);
	printf("So tien da tra = %d\n",TongTienTra);
	TienKhongTra = TienCanRut - TongTienTra;
	printf("So tien khong tra = %d\n",TienKhongTra);
}
void Greedy(Tien *dslt,int n,int TienCanRut){
	int i = 0;
	while(i < n && TienCanRut > 0){
		dslt[i].PA = TienCanRut / dslt[i].MG;
		TienCanRut = TienCanRut - dslt[i].PA * dslt[i].MG;
		i++;
	}
}

int main() {
	int n;
	int TienCanRut;
	printf("Nhap so tien can rut: ");
	scanf("%d",&TienCanRut);
	if(TienCanRut < 1000){
		printf("\n----- KHONG RUT DUOC -----");
		return 0;
	}
	else {
	Tien *dslt;
	dslt = ReadFile(&n);
	BS(dslt,n);
	Greedy(dslt,n,TienCanRut);
	InDS(dslt,n,TienCanRut);
	free(dslt);
	}
	
	return 0;
}
