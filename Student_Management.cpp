//Chương trình quản lý sinh viên

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

/*
- Struct ngày tháng năm sinh(giống với class Date trong Java)
- Lập trình c(hướng thủ tục) tương tác qua lại bởi các struct
- Lập trình Java(hướng đối tượng) tương tác qua lại giữa các class
*/
typedef struct{
	int day;
	int month;
	int year;
}Date;

//tạo struct môn học
typedef struct{
	char tenhp[50];
	int sotc;
	float diemhp;
}subject;

//tạo struct sinh viên
typedef struct{
	char fullname[50];
	char mssv[50];
	Date ngaysinh;
	char major[50];
	int shp;
	subject hp[50];
}student;

//Hàm đổi màu chữ thuộc thư viện <windows.h>
void textColor(WORD color){ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//Hàm nhập 1 sinh viên
void read_student(student *sv){
	printf("\nNhap ten sinh vien: "); fflush(stdin); gets((*sv).fullname);
	printf("\nNhap ma so sinh vien: "); fflush(stdin); gets((*sv).mssv);
	printf("\nNhap ngay thang nam sinh\n"); fflush(stdin);
	printf("\nNhap ngay: "); fflush(stdin); scanf("%d",&(*sv).ngaysinh.day);
	printf("\nNhap thang: "); fflush(stdin); scanf("%d",&(*sv).ngaysinh.month);
	printf("\nNhap nam: "); fflush(stdin); scanf("%d",&(*sv).ngaysinh.year);
	printf("\nNhap chuyen nganh: "); fflush(stdin); gets((*sv).major);
	printf("\nHoc ki nay sinh vien %s hoc bao nhieu hoc phan: ",(*sv).fullname); fflush(stdin); scanf("%d",&(*sv).shp);
	printf("\nNhap thong tin cac hoc phan\n");
	for(int i=0;i<sv->shp;i++){
		printf("\nNhap thong tin hoc phan thu %d\n",(i+1));
		printf("\nNhap ten hoc phan: "); fflush(stdin); gets((*sv).hp[i].tenhp);
		printf("\nNhap so tin chi: "); fflush(stdin); scanf("%d",&(*sv).hp[i].sotc);
		printf("\nNhap diem cua hoc phan: "); fflush(stdin); scanf("%f",&(*sv).hp[i].diemhp);
	}
}

//Hàm gán sinh viên vào phần tử mảng(mỗi phần tử mảng là 1 sinh viên) thông qua con trỏ(pointer)
void read(student arr[], int n){
	for(int i=0;i<n;i++){
		printf("\nNhap thong tin sinh vien thu %d\n",(i+1));
		read_student(&arr[i]);
	}
}

//Hàm in 1 sinh viên
void print_student(student sv){
	printf("\nHo ten sinh vien: %s\n",sv.fullname);
	printf("\nMa so sinh vien: %s\n",sv.mssv);
	printf("\nNgay thang nam sinh: %02d/%02d/%04d\n",sv.ngaysinh.day,sv.ngaysinh.month,sv.ngaysinh.year);
	printf("\nChuyen nganh: %s\n",sv.major);
	printf("\nHoc ki nay sinh vien %s hoc %d hoc phan\n",sv.fullname,sv.shp);
	for(int i =0;i<sv.shp;i++){
		printf("\nThong tin hoc phan thu %d\n",(i+1));
		printf("\nTen hoc phan: %s\n",sv.hp[i].tenhp);
		printf("\nSo tin chi: %d\n",sv.hp[i].sotc);
		printf("\nDiem cua hoc phan: %f\n",sv.hp[i].diemhp);
	}
}

//Hàm in toàn bộ sinh viên
void print(student arr[], int n){
	for(int i=0;i<n;i++){
		textColor(10);
		printf("\n------------------------------------\n");
		printf("\nThong tin sinh vien thu %d\n",(i+1));
		print_student(arr[i]);
		printf("\n------------------------------------\n");
	}
	textColor(15);	
}

//Hàm đổi điểm 1 sinh viên
void doidiem_student(student *sv){
    for(int i=0;i<sv->shp;i++){
        if(sv->hp[i].diemhp>=9 && sv->hp[i].diemhp<=10) sv->hp[i].diemhp=4;
        else if( sv->hp[i].diemhp>=8 &&  sv->hp[i].diemhp<9) sv->hp[i].diemhp=3.5;
        else if(sv->hp[i].diemhp>=7 && sv->hp[i].diemhp<8) sv->hp[i].diemhp=3;
        else if(sv->hp[i].diemhp>=6.5 && sv->hp[i].diemhp<7) sv->hp[i].diemhp=2.5;
        else if(sv->hp[i].diemhp>=5.5 && sv->hp[i].diemhp<6.5) sv->hp[i].diemhp=2;
        else if(sv->hp[i].diemhp>=5 && sv->hp[i].diemhp<5.5) sv->hp[i].diemhp=1.5;
        else if(sv->hp[i].diemhp>=4 && sv->hp[i].diemhp<5) sv->hp[i].diemhp=1;
        else  sv->hp[i].diemhp=0;
    }
}

//Hàm đổi điểm toàn bộ sinh viên
void doiDiem(student arr[], int n){
    for(int i=0;i<n;i++){
        doidiem_student(&arr[i]);
    }
}

//Hàm tính điểm tích lũy trong học kì
float tich_Luy(student sv){
    float total=0;
    float k=0;
    for(int i=0;i<sv.shp;i++){
        total = total + (sv.hp[i].diemhp * sv.hp[i].sotc);
        k= k + sv.hp[i].sotc;
    }
    return total/k;
}

//Hàm xếp loại
void xepLoai(float p[], int index){
    if(p[index]>= 3.6 && p[index]<=4) printf("Xuat sac\n");
	else if(p[index]>= 3.2 && p[index]<3.6) printf("Gioi\n");
	else if(p[index]>= 2.5 && p[index]<3.2) printf("Kha\n");
	else if(p[index]>= 2 && p[index]<2.5) printf("Trung binh\n");
	else if(p[index]>= 1 && p[index]<2) printf("Trung binh yeu\n");
	else printf("Kem\n");
}

//Hàm xuất kết quả 
void ketQua(student arr[], int n, float p[]){
	int index;
    for(int i=0;i<n;i++){
    	textColor(10);
    	index=i;
    	printf("\n--------------------------------------------------------------\n");
        printf("\nDiem trung binh tich luy trong hoc ki cua sinh vien %s la: %.3f\n",arr[i].fullname,tich_Luy(arr[i]));
        p[index]=tich_Luy(arr[i]);
        printf("\nLoai: "); xepLoai(p,index);
        printf("\n--------------------------------------------------------------\n");
    }
    textColor(15);
}

//Thực thi
int main(){
	FILE *f1;
	int n,key;
	bool daNhap = false;
	printf("\nDanh sach ban co bao nhieu sinh vien: "); scanf("%d",&n);
	student sv, arr[n];

	//mảng p là mảng lưu các điểm tích lũy của sinh viên
	float p[n];

	//Mở file với mục đích ghi dữ liệu vào file
	f1=fopen("D://Student_Management.txt","w");
	
	while(1){
		system("cls");
		printf("**************************************************************\n");
		printf("**                   Student Management                     **\n");
		printf("**             1. Nhap thong tin ca nhan va diem so         **\n");
		printf("**             2. Xuat thong tin vua nhap                   **\n");
		printf("**             3. Tinh diem TB va xep loai                  **\n");
        printf("**             4. Xuat thong tin va diem so ra FILE         **\n");
		printf("**             5. Thoat chuong trinh                        **\n");
		printf("**************************************************************\n");
		printf("\nNhap su lua chon cua ban: "); scanf("%d",&key);
		switch(key){
			case 1:{
				system("cls");
                printf("Ban da chon chuc nang nhap thong tin ca nhan va diem so\n"); 
                read(arr,n);
                daNhap=true;
                printf("\nBan da nhap thanh cong\n");
                printf("\nAn phim bat ki de tiep tuc chuong trinh\n");
                getch();
				break;
			}
			case 2:{
				if(daNhap){
                    system("cls");
                    printf("\nBan da chon chuc nang xuat thong tin vua nhap\n");
                    print(arr,n);
                    daNhap=true;
                    printf("\nBan da xuat thanh cong thong tin vua nhap\n");    
                    printf("\nAn phim bat ki de tiep tuc chuong trinh\n");
                    getch();
                    break;
                }
			}
			case 3:{
				if(daNhap){
                    system("cls");
                    printf("\nBan da chon chuc nang tinh diem va xep loai\n");
                    doiDiem(arr,n);
                    ketQua(arr,n,p);
                    daNhap=true;
                    printf("\nBan da tinh diem va xep loai sinh vien thanh cong\n");
                    printf("\nAn phim bat ki de tiep tuc chuong trinh\n");
                    getch();
                    break;
                }
			}
			case 4:{
				if(daNhap){
                    system("cls");
                    printf("Ban da chon chuc nang xuat ra FILE thong tin va ket qua cua sinh vien\n");
                    for(int i=0;i<n;i++){
                        fprintf(f1,"------------------------------------------\n");
                        fprintf(f1,"Thong tin sinh vien thu %d\n",i+1);
                        fprintf(f1,"Ten: %s\n",arr[i].fullname);
                        fprintf(f1,"Ma so sinh vien: %s\n",arr[i].mssv);
                        fprintf(f1,"Ngay thang nam sinh: %02d/%02d/%02d\n",arr[i].ngaysinh.day,arr[i].ngaysinh.month,arr[i].ngaysinh.year);
                        fprintf(f1,"Nganh hoc: %s\n",arr[i].major);
                        fprintf(f1,"Diem trung binh tich luy trong hoc ki: %.3f\n",p[i]);
                        fprintf(f1,"------------------------------------------\n");  
                    }
                    daNhap=true;
                    fclose(f1);
					textColor(10);
                    printf("\nBan da xuat FILE thanh cong\n");
                    textColor(15);
                    printf("\nAn phim bat ki de tiep tuc chuong trinh\n");
                    getch();
                    break;
                }
			}
			case 5:{
				if(daNhap){
                    system("cls");
                    textColor(10);
                    printf("\nBan da chon chuc nang thoat chuong trinh\n");
                    textColor(15);
                    printf("\nAn phim bat ki de thoat chuong trinh\n");
                    getch();
                    return 0;
                }
                else{
                    system("cls");
                    printf("\nBan chua nhap thong tin !\n");
                    printf("\nAn phim 0 de thoat chuong trinh hoac phim 1 roi enter de tro lai va nhap thong tin\n");
                    int k;
                    printf("\nLua chon cua ban la: ");
                    scanf("%d",&k);
                    if(k==0) return 0;
                    else{getch();break;}
                }
			}
			default:
                system("cls");
                printf("\nKhong co chuc nang so %d\n",key);
                printf ("\nAn phim bat ki de lua chon lai chuc nang phu hop voi chuong trinh\n");
                getch();
                break;
		}
	}
	return 0;
}