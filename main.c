#include <stdio.h>
#include <malloc.h>

typedef struct Matrix{
    int columns;
    int rows;
    double* data;
} Matrix;

Matrix create_matrix(int columns, int rows, double *content){
    Matrix m;
    m.columns = columns;
    m.rows = rows;
    m.data = (double*)malloc(columns*rows * sizeof(double));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            *(m.data + i*columns + j) = *(content + i*columns + j);
            printf("%lf ", *(m.data + i*columns + j));
        }
    }
    return m;
}



int main(){
    double data[2][2] = {
        {1,1},
        {2,2}
    };
    double* p = &data[0][0];
    Matrix m = create_matrix(2,2, p);

    printf("\n%lf\n", *(m.data + 0));
    printf("%lf\n", *(m.data + 1));
    printf("%lf\n", *(m.data + 2));
    printf("%lf\n", *(m.data + 3));

    free(m.data);

    return 0;
}