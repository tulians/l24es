/* l24es - Matrix module
  Definition of a matrix and its operations. All computations will be
  performed with floats for better accuracy.
*/

#include "matrix.h"

l24es_matrix_t * createMatrix(int N, int M) {
  l24es_matrix_t * newMatrix = (l24es_matrix_t *)malloc(sizeof(l24es_matrix_t));
  newMatrix -> N = N;
  newMatrix -> M = M;
  newMatrix -> matrix = (float *)malloc(sizeof(float) * (N * M));
  return newMatrix;
}

void initMatrix(l24es_matrix_t * matrix, float * data, char rowMajorOrdering) {
  int rows, columns, index;
  for(rows = 0; rows < matrix -> N; rows++) {
    for(columns = 0; columns < matrix -> M; columns++) {
      index = (rowMajorOrdering == 1 ? rows * matrix -> M + columns : rows + matrix -> N * columns);
      matrix -> matrix[index] = data[index];
    }
  }
}

void printAsMatrix(l24es_matrix_t * matrix) {
  int rows, columns;
  for(rows = 0; rows < matrix -> N; rows++) {
    for(columns = 0; columns < matrix -> M; columns++) {
      printf("%f\t", matrix -> matrix[rows * matrix -> M + columns]);
    }
    printf("\n");
  }
}
