#include "matrix.h"

int main(void)
{
    Matrix *mat = matrix_zeros(4, 5);
    matrix_print(mat);
    matrix_free(&mat);

    Matrix *ones = matrix_ones(4, 5);
    matrix_print(ones);
    matrix_free(&ones);

    return 0;
}