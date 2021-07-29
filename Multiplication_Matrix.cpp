#include <stdio.h>
#define idx 50
//Nhap ma tran
void read_matrix(int a[][idx], int *r, int *c){
    printf("\nNhap so hang cua ma tran: "); scanf("%d",&(*r));
    printf("\nNhap so cot cua ma tran: "); scanf("%d",&(*c));
    int i,j;
    for(i=0;i<*r;i++){
        for(j=0;j<*c;j++){
            printf("\nNhap phan tu o vi tri [%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

//In ma tran
void print_matrix(int b[][idx], int r, int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}

//Tinh tich hai ma tran
void  multiplication_matrix(int mta[][idx], int mtb[][idx], int mtkq[][idx], int m, int n, int k){
    int i,j,l;
    for(i=0;i<m;i++){
        for(j=0;j<k;j++){
            for(l=0;l<n;l++){
                mtkq[i][j] += mta[i][l] * mtb[l][j];
            }
        }
    }
}

int main(){
    
    int matrix_a[idx][idx],matrix_b[idx][idx],matrix_c[idx][idx];
    int row_a,column_a,row_b,column_b;

    printf("\nNhap ma tran A\n");
    read_matrix(matrix_a,&row_a,&column_a);

    printf("\nNhap ma tran B\n");
    read_matrix(matrix_b,&row_b,&column_b);

    printf("\nMa tran A\n");
    print_matrix(matrix_a,row_a,column_a);
    
    printf("\nMa tran B\n");
    print_matrix(matrix_b,row_b,column_b);

    if(column_a != row_b){
        printf("\nHai ma tran khong kha tich --> Khong the nhan 2 ma tran");
        return 0;
    }
    
    printf("\nTich ma tran A va B\n");
    multiplication_matrix(matrix_a,matrix_b,matrix_c,row_a,column_a,column_b);
    print_matrix(matrix_c,row_a,column_b);

    return 0;
}