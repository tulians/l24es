/* l24es - Threshold functions */
#include <stdlib.h>
#include <string.h>
#include "threshold.h"

float * hardSigmoid(float * value, int nElem) {
    int index;
    float * results = (float *) malloc(sizeof(float) * nElem);
    for(index = 0; index < nElem; index++) {
        if (value[index] >= 2.5) { results[index] = 1.0; }
        else if (value[index] <= -2.5) { results[index] = 0.0; }
        else { results[index] = (value[index] / 5) + 0.5; }
    }
    return results;
}

activationFunction_t setActivationFunction(char * activationFunctionName) {
    activationFunction_t afPtr;
    if (!strcmp(activationFunctionName, "hardSigmoid")) { afPtr = &hardSigmoid; }
    return afPtr;
}
