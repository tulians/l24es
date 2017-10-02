/* l24es - Neural network specific operations module */
#include <stdlib.h>

float * dotProduct(float * matrix, float * vector, int numberOfMatrixElements, int nElem) {
    int matrixIndex, vectorIndex;
    float * result = (float *)malloc(sizeof(float) * nElem);
    for (matrixIndex = 0, vectorIndex = 0; matrixIndex < numberOfMatrixElements; matrixIndex++) {
        result[matrixIndex % nElem] += matrix[matrixIndex] * vector[vectorIndex];
        if (matrixIndex > (nElem * vectorIndex)) { vectorIndex++; }
    }
    return result;
}

float * toAugmentedVector(float * vector, int vectorSize) {
    int index;
    float * augmentedVector = (float *)malloc((sizeof(float) * vectorSize) + 1);
    augmentedVector[0] = 1.0;
    for (index = 0; index < vectorSize; index++) {
        augmentedVector[index + 1] = vector[index];
    }
    return augmentedVector;
}
