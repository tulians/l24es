/* l24es - Main module and point of entry */

#include "l24es.h"

int main(int argc, char const ** argv) {
  ordering r = ROW;
  ordering c = COLUMN;
  l24es_matrix_t * m1 = createMatrix(3,3,r);
  l24es_matrix_t * m2 = createMatrix(3,4,c);
  float data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  float data2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  initMatrix(m1, data1);
  initMatrix(m2, data2);
  l24es_matrix_t * m3 = multiplyMatrices(m1, m2);
  printAsMatrix(m3);
  return 0;
}
