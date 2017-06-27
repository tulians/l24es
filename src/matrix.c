/* l24es - Matrix module
  Definition of a matrix and its operations. All computations will be
  performed with floats for better accuracy.
*/
#include <stdio.h>
#include "matrix.h"

l24es_matrix_t * createMatrix(int nRows, int nColumns, char order) {
  l24es_matrix_t * newMatrix = (l24es_matrix_t *)malloc(sizeof(l24es_matrix_t));
  newMatrix -> nRows = nRows;
  newMatrix -> nColumns = nColumns;
  newMatrix -> order = order;
  newMatrix -> matrix = (float *)malloc(sizeof(float) * (nRows * nColumns));
  return newMatrix;
}

void initMatrix(l24es_matrix_t * matrix, float * data) {
  int rows, columns;
  if(matrix -> order == ROW) {
    for(rows = 0; rows < matrix -> nRows; rows++) {
      for(columns = 0; columns < matrix -> nColumns; columns++) {
        matrix -> matrix[rows * matrix -> nColumns + columns] = data[rows * matrix -> nColumns + columns];
      }
    }
  } else {
    for(rows = 0; rows < matrix -> nRows; rows++) {
      for(columns = 0; columns < matrix -> nColumns; columns++) {
        matrix -> matrix[rows + matrix -> nRows * columns] = data[rows + matrix -> nRows * columns];
      }
    }
  }
}

void printAsMatrix(l24es_matrix_t * matrix) {
  if (matrix != NULL) {
    int rows, columns;
    for(rows = 0; rows < matrix -> nRows; rows++) {
      for(columns = 0; columns < matrix -> nColumns; columns++) {
        printf("%f\t", matrix -> matrix[rows * matrix -> nColumns + columns]);
      }
      printf("\n");
    }
  }
}

l24es_matrix_t * sumTwoMatrices(l24es_matrix_t * m1, l24es_matrix_t * m2) {
  if ((m1 -> nRows == m2 -> nRows) && (m1 -> nColumns == m2 -> nColumns) && (m1 -> order == m2 -> order)) {
    l24es_matrix_t * result = createMatrix(m1 -> nRows, m1 -> nColumns, m1 -> order);
    int nElemIndex = m1 -> nRows * m1 -> nColumns;
    while(nElemIndex--) {
      result -> matrix[nElemIndex] = m1 -> matrix[nElemIndex] + m2 -> matrix[nElemIndex];
    }
    return result;
  } else {
    /* TODO(tulians): define custom error messages. */
    return NULL;
  }
}

l24es_matrix_t * multiplyByScalar(l24es_matrix_t * matrix, float value) {
  if (matrix != NULL) {
    int index;
    l24es_matrix_t * result = createMatrix(matrix -> nRows, matrix -> nColumns, matrix -> order);
    for(index = 0; index < result -> nRows * result -> nColumns; index++) {
      result -> matrix[index] = matrix -> matrix[index] * value;
    }
    return result;
  } else {
    /* TODO(tulians): define custom error messages. */
    return NULL;
  }
}
