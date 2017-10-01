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
    int uphl[] = {2, 2, 1};
    const char * af = "fastSigmoid";
    l24es_nn_t * nn = initializeNeuralNetwork(uphl, __arrayLength(uphl), af);

    float v[] = {0.9, 1.2, 3.1};
    float * r = feedforwardRun(nn, v);
    return 0;
}
