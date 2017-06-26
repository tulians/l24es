/* l24es - Matrix module header file */

#include <stdlib.h>

typedef struct l24es_matrices {
  int N, M;
  float * matrix;
} l24es_matrix_t;

/* createMatrix
  Allocates space for a new matrix
  Inputs:
    - N, M: dimensions of a NxM matrix.
  Outputs:
    - Pointer to a new l24es_matrix_t instance.
*/
l24es_matrix_t * createMatrix(int, int);

/* initMatrix
  Fills an empty matrix with content.
  Inputs:
    - matrix: l24es_matrix_t empty matrix to fill.
    - data: list of values to fill the matrix with.
    - rowMajorOrdering: 1 indicates rowMajorOrdering and 0 columnMajorOrdering.
  Returns:
    No values are returned.
*/
void initMatrix(l24es_matrix_t *, float *, char);

/* printAsMatrix
  Prints to stdout the contents of the matrix.
  Inputs:
    - matrix: l24es_matrix_t to inspect.
  Returns:
    No values are returned.
*/
void printAsMatrix(l24es_matrix_t *);
