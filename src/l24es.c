/* l24es - Main module and point of entry */

#include "l24es.h"

int main(int argc, char const ** argv) {
  ordering o = ROW;
  ordering p = COLUMN;
  l24es_matrix_t * m1 = createMatrix(6,4,p);
  l24es_matrix_t * m2 = createMatrix(6,4,p);
  float data[] = {1,3,2,4,6,5,10,11,12,9,8,7,1,3,2,4,6,5,10,11,12,9,8,7};
  initMatrix(m1, data);
  initMatrix(m2, data);
  l24es_matrix_t * m3 = sumTwoMatrices(m1, m2);
  m3 = multiplyByScalar(m3, 2);
  printf("\n");
  printAsMatrix(m3);
  m3 = transposeMatrix(m3);
  printf("\n");
  printAsMatrix(m3);
  return 0;
}
