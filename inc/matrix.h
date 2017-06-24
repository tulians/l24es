/* l24es - Matrix module header file */

#include <stdlib.h>

typedef struct l24es_matrices {
  int N, M;
  float * matrix;
} l24es_matrix_t;

/* initMatrix
   Allocates space for a new matrix
   Inputs:
   - N, M: dimensions of a NxM matrix.
   Outputs:
   - Pointer to a new l24es_matrix_t instance.
*/
l24es_matrix_t * initMatrix(int, int);
