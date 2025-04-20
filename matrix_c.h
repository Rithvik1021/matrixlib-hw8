#ifndef MATRIX_C_H
#define MATRIX_C_H

#include <stddef.h>

/*matrix*/
typedef struct {
    size_t numRows;
    size_t numCols;
    double *elements;
} MatrixC;

/* create/destroy */
int mat_create(MatrixC *matrix, size_t numRows, size_t numCols, double initVal);
void mat_destroy(MatrixC *matrix);

/* get/set one entry */
double mat_get(const MatrixC *matrix, size_t row, size_t col);
void mat_set(MatrixC *matrix, size_t row, size_t col, double value);

/*operations */
int mat_add (const MatrixC *A, const MatrixC *B, MatrixC *result);
int mat_scale (const MatrixC *src, double scalar, MatrixC *result);
int mat_transpose(const MatrixC *src, MatrixC *result);
int mat_mul (const MatrixC *A, const MatrixC *B, MatrixC *result);

int  mat_equals(const MatrixC *A, const MatrixC *B, double tol);
void mat_print (const MatrixC *matrix);

#endif
