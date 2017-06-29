/* l24es - Matrix module header file */

#include <stdlib.h>

typedef enum ordering {
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
    l24es_matrix_t matrix with the sum of m1 an m2.
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
  Transposes a given matrix and returns a new one with the result.
  Inputs:
    matrix: matrix to transpose.
  Returns:
    l24es_matrix_t transposed matrix.
*/
l24es_matrix_t * transposeMatrix(l24es_matrix_t *);
