/* l24es - Main module and point of entry */

#include "l24es.h"

int main(int argc, char const ** argv) {
  l24es_matrix_t * m = createMatrix(2,3);
  printf("%d %d\n", m -> N, m -> M);
  float data[] = {1,3,2,4,6,5};
  initMatrix(m, data, 0);
  printAsMatrix(m);
  return 0;
}
