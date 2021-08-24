#include <stdio.h>
#include <unistd.h>
#include <windows.h>
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
int main(){

	FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8;
	f1=fopen("mother.txt","r+");
    f2=fopen("father.txt","r+");
    f3=fopen("myngoc.txt","r+");
    f4=fopen("huunhan.txt","r+");
    f5=fopen("fml.txt","r+");
    f6=fopen("mother2.txt","r+");
    f7=fopen("ngocut.txt","r+");
    f8=fopen("lover.txt","r+");
    char readname[100];
    textColor(5);
    char name[100] = "yes";
    bool read=true;
    while(read){
        printf("\nDo you love your family ?\n");
        printf("\nYour answer: ");
        gets(readname);
        if(strcmp(readname,name)!=0){
            printf("\n..............NO NO NO NO................\n");
            printf("\nNhap lai\n");
        }
        else{
            read = false;
        }
        
    }
    system("cls");
    int key=10;
    char c = '%';
    for(int i=1;i<=10;i++){
        textColor(i);
        printf("\n.....................Loading %d%c....................\n",key,c);
        key+=10;
        sleep(1);
    }
    system("cls");
	while(!feof(f1)){
		char c;
		fscanf(f1,"%c",&c);
        textColor(5);
		printf("%c",c);
	}
    fclose(f1);
    printf("\n");
    while(!feof(f2)){
		char c1;
		fscanf(f2,"%c",&c1);
        textColor(2);
		printf("%c",c1);
	}
    fclose(f2);
    printf("\n");
    while(!feof(f3)){
		char c2;
		fscanf(f3,"%c",&c2);
        textColor(3);
		printf("%c",c2);
	}
    fclose(f3);
    printf("\n");
    while(!feof(f4)){
		char c3;
		fscanf(f4,"%c",&c3);
        textColor(1);
		printf("%c",c3);
	}
    fclose(f4);
    printf("\n");
    while(!feof(f5)){
		char c4;
		fscanf(f5,"%c",&c4);
        textColor(6);
		printf("%c",c4);
	}
    fclose(f5);
    printf("\n");
    while(!feof(f6)){
		char c5;
		fscanf(f6,"%c",&c5);
        textColor(9);
		printf("%c",c5);
	}
    fclose(f6);
    printf("\n");
    while(!feof(f7)){
		char c6;
		fscanf(f7,"%c",&c6);
        textColor(5);
		printf("%c",c6);
	}
    fclose(f7);
    printf("\n");
     while(!feof(f8)){
		char c7;
		fscanf(f8,"%c",&c7);
        textColor(2);
		printf("%c",c7);
	}
    fclose(f8);
    printf("\n");
	return 0;
}
