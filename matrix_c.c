// matrix_c.c
#include "matrix_c.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* helper func for 1D index from row/col */
static size_t idx(const MatrixC *matrix, size_t row, size_t col) {
    return row * matrix->numCols + col;
}

/* create matrix, all entries = initVal */
int mat_create(MatrixC *matrix, size_t numRows, size_t numCols, double initVal) {
    if (!matrix || numRows == 0 || numCols == 0) return -1;
    matrix->numRows = numRows;
    matrix->numCols = numCols;
    matrix->elements= calloc(numRows * numCols, sizeof(double));
    if (!matrix->elements) return -1;
    if (initVal != 0.0) {
        size_t n = numRows * numCols;
        for (size_t i = 0; i < n; ++i)
            matrix->elements[i] = initVal;
    }
    return 0;
}

/* destroy*/
void mat_destroy(MatrixC *matrix) {
    if (!matrix) return;
    free(matrix->elements);
    matrix->elements = NULL;
    matrix->numRows = 0;
    matrix->numCols = 0;
}

/* read one entry */
double mat_get(const MatrixC *matrix, size_t row, size_t col) {
    return matrix->elements[idx(matrix, row, col)];
}

/* write one entry */
void mat_set(MatrixC *matrix, size_t row, size_t col, double value) {
    matrix->elements[idx(matrix, row, col)] = value;
}

/* A + B */
int mat_add(const MatrixC *A, const MatrixC *B, MatrixC *result) {
    if (!A || !B || !result) return -1;
    if (A->numRows != B->numRows || A->numCols != B->numCols) return -1;
    mat_create(result, A->numRows, A->numCols, 0.0);
    size_t n = A->numRows * A->numCols;
    for (size_t i = 0; i < n; ++i)
        result->elements[i] = A->elements[i] + B->elements[i];
    return 0;
}

/* scalar * src */
int mat_scale(const MatrixC *src, double scalar, MatrixC *result) {
    if (!src || !result) return -1;
    mat_create(result, src->numRows, src->numCols, 0.0);
    size_t n = src->numRows * src->numCols;
    for (size_t i = 0; i < n; ++i)
        result->elements[i] = src->elements[i] * scalar;
    return 0;
}

/* transpose(src) */
int mat_transpose(const MatrixC *src, MatrixC *result) {
    if (!src || !result) return -1;
    mat_create(result, src->numCols, src->numRows, 0.0);
    for (size_t r = 0; r < src->numRows; ++r)
        for (size_t c =0; c < src->numCols; ++c)
            result->elements[idx(result, c, r)] = src->elements[idx(src, r, c)];
    return 0;
}

/*A * B */
int mat_mul(const MatrixC *A, const MatrixC *B, MatrixC *result) {
    if (!A || !B || !result) return -1;
    if (A->numCols != B->numRows) return -1;
    mat_create(result, A->numRows, B->numCols, 0.0);
    for (size_t r = 0; r < A->numRows; ++r) {
        for (size_t k = 0; k < A->numCols; ++k) {
            double v = mat_get(A, r, k);
            for (size_t c = 0; c < B->numCols; ++c)
                result->elements[idx(result, r, c)] += v * mat_get(B, k, c);
        }
    }
    return 0;
}

/* return 1 if equal, else 0 */
int mat_equals(const MatrixC *A, const MatrixC *B, double tol) {
    if (!A || !B) return 0;
    if (A->numRows != B->numRows || A->numCols != B->numCols) return  0;
    size_t n = A->numRows * A->numCols;
    for (size_t i = 0; i < n; ++i) {
        if (fabs(A->elements[i]- B->elements[i]) > tol)
            return 0;
    }
    return 1;
}

/* print*/
void mat_print(const MatrixC *matrix) {
    if (!matrix) return;
    for (size_t r = 0; r< matrix->numRows; ++r) {
        printf("[ ");
        for (size_t c = 0; c < matrix->numCols; ++c) {
            printf("%.0f ", mat_get(matrix, r, c));
        }
        printf("]\n");
    }
}
