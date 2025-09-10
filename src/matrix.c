#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct MatrixInterface
{
    Matrix mat;
    float *data;
} MatrixInterface;

static Matrix *matrix_alloc(size_t m, size_t n, void *(*alloc)(size_t))
{
    MatrixInterface *matInt = (MatrixInterface *)malloc(sizeof(*matInt));
    *(size_t *)(&matInt->mat.m) = m;
    *(size_t *)(&matInt->mat.n) = n;
    matInt->data = (float *)alloc(sizeof(*matInt->data) * m * n);

    return &matInt->mat;
}

Matrix *matrix_create(size_t m, size_t n)
{
    return matrix_alloc(m, n, &malloc);
}

void matrix_free(Matrix **mat)
{
    if (mat == NULL || *mat == NULL)
        return;
    MatrixInterface *matInt = (MatrixInterface *)*mat;
    free(matInt->data);
    free(*mat);
    *mat = NULL;
}

float matrix_get(Matrix *mat, size_t i, size_t j)
{
    MatrixInterface *matInt = (MatrixInterface *)mat;
    return matInt->data[i * mat->n + j];
}

Matrix *matrix_ones(size_t m, size_t n)
{
    Matrix *mat = matrix_zeros(m, n);
    for (size_t i = 0; i < mat->m; i++)
    {
        for (size_t j = 0; j < mat->n; j++)
        {
            matrix_set(mat, i, j, 1.f);
        }
    }
    return mat;
}

void matrix_print(Matrix *mat)
{
    if (mat == NULL)
        return;
    printf("Matrix(%ld, %ld) =\n", mat->m, mat->n);
    printf("[\n");
    for (size_t i = 0; i < mat->m; i++)
    {
        printf("   [");
        for (size_t j = 0; j < mat->n; j++)
        {
            if (j == 0)
                printf("%g", matrix_get(mat, i, j));
            else
                printf(", %g", matrix_get(mat, i, j));
        }
        printf("]\n");
    }
    printf("]\n");
}

void matrix_set(Matrix *mat, size_t i, size_t j, float value)
{
    MatrixInterface *matInt = (MatrixInterface *)mat;
    matInt->data[i * mat->n + j] = value;
}

void *alloc(size_t size)
{
    return calloc(1, size);
}

Matrix *matrix_zeros(size_t m, size_t n)
{
    return matrix_alloc(m, n, &alloc);
}