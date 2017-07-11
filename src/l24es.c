/* l24es - Main module and point of entry */

#include "l24es.h"

int main(int argc, char const ** argv) {
  ordering r = ROW;
  ordering c = COLUMN;
  l24es_matrix_t * m1 = createMatrix(2,3,r);
  l24es_matrix_t * m2 = createMatrix(3,3,r);
  float data[] = {0, 1, 2, 3, 4, 5};
  initMatrix(m1, data);
//  initMatrix(m2, data);
//  l24es_matrix_t * m3 = sumTwoMatrices(m1, m2);
//  m3 = multiplyByScalar(m3, 2);
//  printf("\n");
  printAsMatrix(m1);
//  transposeMatrix(m1);
  transposeMatrix(m1);
  printf("\n");
  printAsMatrix(m1);
  return 0;
}
