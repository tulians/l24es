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
    -->f()
        nRows, nColumns: dimensions of a NxM matrix.
        ordering: 1 indicates rowMajorOrdering and 0 columnMajorOrdering.
    f()-->
        Pointer to a new l24es_matrix_t instance.
*/
l24es_matrix_t * createMatrix(int, int, char);

/* initMatrix
    Fills an empty matrix with content.
    -->f()
        matrix: l24es_matrix_t empty matrix to fill.
        data: list of values to fill the matrix with.
*/
void initMatrix(l24es_matrix_t *, float *);

/* printAsMatrix
    Prints to stdout the contents of the matrix.
    f()-->
        matrix: l24es_matrix_t to inspect.
*/
void printAsMatrix(l24es_matrix_t *);

/* sumTwoMatrices
    Sums two matrices with the same dimensions.
    -->f()
        m1, m2: matrices to sum with each other.
    f()-->
        l24es_matrix_t matrix with the sum of m1 and m2.
*/
l24es_matrix_t * sumTwoMatrices(l24es_matrix_t *, l24es_matrix_t *);

/* multiplyByScalar
    Multiplies the components of a matrix by a float value.
    -->f()
        matrix: matrix to multiply.
        value: multiplier.
    f()-->
        l24es_matrix_t matrix with the result of the multiplication.
*/
l24es_matrix_t * multiplyByScalar(l24es_matrix_t *, float);

/* transposeMatrix
    Transposes a given matrix inplace.
    -->f()
        matrix: matrix to transpose.
*/
void transposeMatrix(l24es_matrix_t *);

/* multiplyMatrices
    Performs the multiplication of two l24es_matrix_t matrices.
    -->f()
        m1, m2: multiplication operands.
    f()-->
        New matrix with the result of the multiplication.
*/
l24es_matrix_t * multiplyMatrices(l24es_matrix_t *, l24es_matrix_t *);

/* dotProduct
    Performs the dot product between a matrix and a vector.
    -->f()
        matrix
        vector
        numberOfMatrixElements: to make optimal use of for cycles. 
        nElem: number of matrix elements to multiply with each vector element.
    f()-->
        Resulting vector from the dot product. 
    Example:
        matrix: [[1, 2, 3],[4, 5, 6]] should be sent as => [1, 4, 2, 5, 3, 6]
        vector: [1, 2, 3]
        dp = [(1 * 1) + (2 * 2) + (3 * 3), (1 * 4) + (2 * 5), (3 * 6)] = [14, 32]
*/
float * dotProduct(float *, float *, int, int);

/* toAugmentedVector
    Appends a 1.0 in position [0] of a vector.
    -->f()
        vector
        vectorSize
    f()-->
        augmentedVector
*/
float * toAugmentedVector(float *, int);
#endif /* #ifndef _MATRIX_H_ */
