// test_c.c
#include "matrix_c.h"
#include <stdio.h>

int main(void) {
    MatrixC A, B, C, tmp1, tmp2, prod, D, expected;

    /* A = [6 4; 8 3] */
    mat_create(&A, 2, 2, 0.0);
    mat_set(&A, 0, 0, 6);  mat_set(&A, 0, 1, 4);
    mat_set(&A, 1, 0, 8);  mat_set(&A, 1, 1, 3);

    /* B = [1 2 3; 4 5 6] */
    mat_create(&B, 2, 3, 0.0);
    mat_set(&B, 0, 0, 1);  mat_set(&B, 0, 1, 2);  mat_set(&B, 0, 2, 3);
    mat_set(&B, 1, 0, 4);  mat_set(&B, 1, 1, 5);  mat_set(&B, 1, 2, 6);

    /* C = [2 4 6; 1 3 5] */
    mat_create(&C, 2, 3, 0.0);
    mat_set(&C, 0, 0, 2);  mat_set(&C, 0, 1, 4);  mat_set(&C, 0, 2, 6);
    mat_set(&C, 1, 0, 1);  mat_set(&C, 1, 1, 3);  mat_set(&C, 1, 2, 5);

    /* D = A + (3 * B) * C^T */
    mat_scale    (&B, 3.0,  &tmp1);
    mat_transpose(&C,       &tmp2);
    mat_mul      (&tmp1, &tmp2, &prod);
    mat_add      (&A,   &prod,   &D);

    puts("D =");
    mat_print(&D);

    /* expected = [90 70; 200 150] */
    mat_create(&expected, 2, 2, 0.0);
    mat_set(&expected, 0, 0, 90);  mat_set(&expected, 0, 1, 70);
    mat_set(&expected, 1, 0, 200); mat_set(&expected, 1, 1, 150);

    int ok = mat_equals(&D, &expected, 1e-9);

    /*destroy */
    mat_destroy(&A);
    mat_destroy(&B);
    mat_destroy(&C);
    mat_destroy(&tmp1);
    mat_destroy(&tmp2);
    mat_destroy(&prod);
    mat_destroy(&D);
    mat_destroy(&expected);

    return ok ? 0 : 1;
}
