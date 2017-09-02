/* l24es - Matrix module header */

#ifndef _MATRIX_H
#define _MATRIX_H

#include <string.h>

#define swap(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
   } while(0)

typedef enum matrixOrdering {
    ROW,
    COLUMN
} ordering;

typedef struct l24es_matrices {
    int nRows, nColumns;
    ordering order;
    float * matrix;
} l24es_matrix_t;

/* createMatrix
    Allocates space for a new matrix
    Inputs:
        nRows, nColumns: dimensions of a NxM matrix.
        ordering: 1 indicates rowMajorOrdering and 0 columnMajorOrdering.
    Outputs:
        Pointer to a new l24es_matrix_t instance.
*/
l24es_matrix_t * createMatrix(int, int, char);

/* initMatrix
    Fills an empty matrix with content.
    Inputs:
        matrix: l24es_matrix_t empty matrix to fill.
        data: list of values to fill the matrix with.
    Returns:
        No values are returned.
*/
void initMatrix(l24es_matrix_t *, float *);

/* printAsMatrix
    Prints to stdout the contents of the matrix.
    Inputs:
        matrix: l24es_matrix_t to inspect.
    Returns:
        No values are returned.
*/
void printAsMatrix(l24es_matrix_t *);

/* sumTwoMatrices
    Sums two matrices with the same dimensions.
    Inputs:
        m1, m2: matrices to sum with each other.
    Returns:
        l24es_matrix_t matrix with the sum of m1 and m2.
*/
l24es_matrix_t * sumTwoMatrices(l24es_matrix_t *, l24es_matrix_t *);

/* multiplyByScalar
    Multiplies the components of a matrix by a float value.
    Inputs:
        matrix: matrix to multiply.
        value: multiplier.
    Returns:
        l24es_matrix_t matrix with the result of the multiplication.
*/
l24es_matrix_t * multiplyByScalar(l24es_matrix_t *, float);

/* transposeMatrix
    Transposes a given matrix inplace.
    Inputs:
        matrix: matrix to transpose.
    Returns:
        No value is returned.
*/
void transposeMatrix(l24es_matrix_t *);

/* multiplyMatrices
    Performs the multiplication of two l24es_matrix_t matrices.
    Inputs:
        m1, m2: multiplication operands.
    Returns:
        New matrix with the result of the multiplication.
*/
l24es_matrix_t * multiplyMatrices(l24es_matrix_t *, l24es_matrix_t *);

#endif /* #ifndef _MATRIX_H_ */
