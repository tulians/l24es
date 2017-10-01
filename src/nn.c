/* l24es - Neural networks module */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nn.h"
#include "threshold.h"
#include "matrix.h"
#include "utils.h"

float * _getWeightsFromLayers(int * unitsPerLayer, int length) {
    int numberOfWeights = 0;
    int index; 
    for (index = 1; index < length; index++) {
        numberOfWeights += unitsPerLayer[index] * (unitsPerLayer[index - 1] + 1);
    }
    float * weights = (float*)malloc(sizeof(float) * numberOfWeights);
    srand(time(NULL));
    for (index = 0; index < numberOfWeights; index++) {
        weights[index] = (float)rand() / (float)(RAND_MAX);
    }
    return weights;  
}

l24es_nn_t * initializeNeuralNetwork(int * unitsPerLayer, int length, 
                                     const char * activationFunction) {
    l24es_nn_t * neuralNetwork = (l24es_nn_t *)malloc(sizeof(l24es_nn_t));
    neuralNetwork -> unitsPerLayer = unitsPerLayer;
    neuralNetwork -> numberOfLayers = length;
    neuralNetwork -> weights = _getWeightsFromLayers(unitsPerLayer, length);    
    neuralNetwork -> activationFunction = setActivationFunction(activationFunction);
    return neuralNetwork;
}


float * feedforwardRun(l24es_nn_t * neuralNetwork, float * inputs) {
    int offset, layerIndex, numberOfWeights, maxHiddenUnits, numberOfOutputs;
    /* Get the maximum number of units among the hidden layers ... */
    maxHiddenUnits = 0;
    for (layerIndex = 1; layerIndex < neuralNetwork -> numberOfLayers - 1; layerIndex++) {
        if (neuralNetwork -> unitsPerLayer[layerIndex] > maxHiddenUnits) {
            maxHiddenUnits = neuralNetwork -> unitsPerLayer[layerIndex]; 
        }
    }
    numberOfOutputs = neuralNetwork -> unitsPerLayer[layerIndex];
    /* ... and initialize the intermediate outputs with that value as size. */
    float * intermediateOutputs = (float *)malloc(sizeof(float) * maxHiddenUnits);
    float * output = (float *)malloc(sizeof(float) * numberOfOutputs);
    offset = 0;
    int intermediateOutputsLength;
    intermediateOutputs = inputs;
    for (layerIndex = 1; layerIndex < neuralNetwork -> numberOfLayers; layerIndex++) {
        intermediateOutputsLength = __arrayLength(intermediateOutputs);
        intermediateOutputs = toAugmentedVector(intermediateOutputs, 
                                                intermediateOutputsLength);
        numberOfWeights = (neuralNetwork -> unitsPerLayer[layerIndex - 1] + 1) * 
                           neuralNetwork -> unitsPerLayer[layerIndex];
        intermediateOutputs = dotProduct((neuralNetwork -> weights) + offset,
                                         intermediateOutputs,
                                         numberOfWeights,
                                         numberOfWeights / (intermediateOutputsLength + 1));
        intermediateOutputs = neuralNetwork -> activationFunction(intermediateOutputs,
                                                                  intermediateOutputsLength + 1);
        offset += numberOfWeights;
    }
    int outputIndex;
    for (outputIndex = 0; outputIndex < numberOfOutputs; outputIndex++) {
        output[outputIndex] = intermediateOutputs[outputIndex];
    }
    free(intermediateOutputs);
    return output;
}
