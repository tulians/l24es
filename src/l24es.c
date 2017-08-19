/* l24es - Main module and point of entry */

#include <time.h>
#include "l24es.h"

int main(int argc, char const ** argv) {
  ordering r = ROW;
  ordering c = COLUMN;
  int j = 256;
  l24es_matrix_t * m1 = createMatrix(j,j,r);
  l24es_matrix_t * m2 = createMatrix(j,j,c);
  float data1[j*j];// = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  float data2[j*j];// = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//  initMatrix(m1, data1);
//  initMatrix(m2, data2);
 
  int i;
  for(i = 0; i < j*j; i++) {
    data1[i] = i;
    data2[i] = i;
  }
  initMatrix(m1,data1);
  initMatrix(m2,data2);

  struct timespec gettime_now;
  clock_gettime(CLOCK_REALTIME, &gettime_now);
  long int start_time;
  long int time_difference;
  start_time = gettime_now.tv_nsec;  
  l24es_matrix_t * m3 = multiplyMatrices(m1, m2); 
  clock_gettime(CLOCK_REALTIME, &gettime_now);
  time_difference = gettime_now.tv_nsec - start_time;
  printf("%ld ns\n", time_difference);
  
  //printAsMatrix(m3);
  return 0;
}
