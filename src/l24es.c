/* l24es - Main module and point of entry */
/* System libraries */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/* Project specific libraries */
#include "l24es.h"
#include "matrix.h"
#include "nn.h"
#include "message.h"
#include "threshold.h"
#include "utils.h"

int main(int argc, char const ** argv) {  
    int inputs = 2;
    int outputs = 1;
    int uphl[] = {2};
    char * af = "hardSigmoid";
    l24es_nn_t * nn = initializeNeuralNetwork(inputs, outputs, uphl, __arrayLength(uphl), af);

    int i;
    for (i = 0; i < 9; i++) {
        printf("%f\n", nn -> weights[i]);
    }

    float a[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};

    float * t = nn -> activationFunction(a, 11);
    printf("\n\n");
    for (i = 0; i < 11; i++) {
        printf("%f\n", t[i]);
    }
        /*
  ordering r = ROW;
  ordering c = COLUMN;
  int j = 256;
  l24es_matrix_t * m1 = createMatrix(j,j,r);
  l24es_matrix_t * m2 = createMatrix(j,j,r);
  float data1[j*j];// = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  float data2[j*j];// = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
 
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

  l24es_nn_t * nn = initializeNeuralNetwork(1,1,1,1,1,m1,m1,m1,m1);    
  printf("%d\n", &(nn -> weights));*/
//  printAsMatrix(m3);
  return 0;
}
