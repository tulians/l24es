/* l24es - Main module and point of entry */

#include "l24es.h"

int main(int argc, char const ** argv) {
  ordering o = ROW;
  ordering p = COLUMN;
  l24es_matrix_t * m1 = createMatrix(2,3,p);
  l24es_matrix_t * m2 = createMatrix(2,3,p);
  float data[] = {1,3,2,4,6,5};
  initMatrix(m1, data);
  initMatrix(m2, data);
  l24es_matrix_t * m3 = sumTwoMatrices(m1, m2);
  m3 = multiplyByScalar(m3, 2);
  printAsMatrix(m3);
  return 0;
}
