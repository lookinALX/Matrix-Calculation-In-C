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
        }
    }
    return m;
}

void print_matrix(Matrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        printf("{ ");
        for(int j = 0; j < matrix.columns; j++){
            printf("%.3lf ", *(matrix.data + i*matrix.columns + j));
        }
        printf("}\n");
    }
}

int save_to_file(char *filename, Matrix matrix){
    FILE *file;
    if ((file = fopen(filename, "w"))!= 0){
        for(int i = 0; i < matrix.rows; i++){
        fprintf(file,"{ ");
        for(int j = 0; j < matrix.columns; j++){
            fprintf(file, "%.3lf ", *(matrix.data + i*matrix.columns + j));
        }
        fprintf(file, "}\n");
    }
        fclose(file);
        return 0;
    } else {
        fclose(file);
        return 1;
    }
}

int main(){
    double data[2][2] = {
        {1,1},
        {2,2}
    };
    double* p = &data[0][0];
    Matrix m = create_matrix(2,2, p);

    print_matrix(m);
    save_to_file("saves.txt", m);

    free(m.data);

    return 0;
}