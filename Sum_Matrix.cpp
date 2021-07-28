#include <stdio.h>
void read_row_column(int *r, int *c){
    printf("\nNhap so hang cua ma tran: "); scanf("%d",&(*r));
    printf("\nNhap so cot cua ma tran: "); scanf("%d",&(*c));
}
void read_matrix(int mt1[19][12], int r, int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("\nNhap phan tu [%d][%d]: ",i,j);
            scanf("%d",&mt1[i][j]);
        }
    }
}
void sum_matrix(int mt1[19][12], int mt2[19][12], int mtkq[19][12], int r, int c){
    int i,j;
     for(i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mtkq[i][j] = mt1[i][j]+ mt2[i][j];
        }
    }
}
void print_matrix(int mt[19][12], int r, int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",mt[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int row,column;
    int matrix_1[19][12],matrix_2[19][12],matrix_result[19][12];
    read_row_column(&row,&column);

    printf("\nNhap cac phan tu cua ma tran thu 1\n");
    read_matrix(matrix_1,row,column);

    printf("\nNhap cac phan tu cua ma tran thu 2\n");
    read_matrix(matrix_2,row,column);

    printf("\nMa tran thu 1\n");
    print_matrix(matrix_1,row,column);

    printf("\nMa tran thu 2\n");
    print_matrix(matrix_2,row,column);

    printf("\nMa tran ket qua\n");
    sum_matrix(matrix_1,matrix_2,matrix_result,row,column);
    print_matrix(matrix_result,row,column);

    return 0;
}