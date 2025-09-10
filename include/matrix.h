#ifndef matrix_h
#define matrix_h

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Matrix
    {
        const size_t m;
        const size_t n;
    } Matrix;

    Matrix *matrix_create(size_t m, size_t n);
    void matrix_free(Matrix **mat);
    float matrix_get(Matrix *mat, size_t i, size_t j);
    Matrix *matrix_ones(size_t m, size_t n);
    void matrix_print(Matrix *mat);
    void matrix_set(Matrix *mat, size_t i, size_t j, float value);
    Matrix *matrix_zeros(size_t m, size_t n);

#ifdef __cplusplus
}
#endif

#endif