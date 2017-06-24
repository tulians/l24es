/* l24es - Matrix module
 *
 *  Definition of a matrix and its operations. All computations will be
 *  performed with floats for better accuracy.
 *
 */

#include <stdio.h>
#include "matrix.h"

l24es_matrix_t * initMatrix(int N, int M) {
  l24es_matrix_t * newMatrix = (l24es_matrix_t *)malloc(sizeof(l24es_matrix_t));
  newMatrix -> N = N;
  newMatrix -> M = M;
  newMatrix -> matrix = (float *)malloc(sizeof(float) * (N * M));
  return newMatrix;
}

int main(int argc, char const *argv[]) {
  l24es_matrix_t * m = initMatrix(2,3);
  printf("%d\n", m -> M);
  return 0;
}
