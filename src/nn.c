/* l24es - Neural networks module */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nn.h"
#include "threshold.h"

float * _getWeightsFromHiddenLayers(int * unitsPerHiddenLayer, int length, 
                                    int inputsNumber, int outputsNumber) {
    int numberOfWeights = ((unitsPerHiddenLayer[0] * (inputsNumber + 1)) 
                        + ((unitsPerHiddenLayer[length - 1] + 1) * outputsNumber));
    int index; 
    for (index = 1; index < length; index++) {
        numberOfWeights += unitsPerHiddenLayer[index] 
                        * (unitsPerHiddenLayer[index - 1] + 1);
    }
    float * weights = (float*)malloc(sizeof(float) * numberOfWeights);
    srand(time(NULL));
    for (index = 0; index < numberOfWeights; index++) {
        weights[index] = (float)rand() / (float)(RAND_MAX);
    }
    return weights;  
}

l24es_nn_t * initializeNeuralNetwork(int inputsNumber, int outputsNumber, 
                                     int * unitsPerHiddenLayer, int length, 
                                     const char * activationFunction) {
    l24es_nn_t * neuralNetwork = (l24es_nn_t *)malloc(sizeof(l24es_nn_t));
    neuralNetwork -> inputsNumber = inputsNumber;
    neuralNetwork -> outputsNumber = outputsNumber;
    neuralNetwork -> unitsPerHiddenLayer = unitsPerHiddenLayer;
    neuralNetwork -> weights = _getWeightsFromHiddenLayers(unitsPerHiddenLayer, length, 
                                                           inputsNumber, outputsNumber);    
    neuralNetwork -> activationFunction = setActivationFunction(activationFunction);
    return neuralNetwork;
}

/* PLACEHOLDER */
float * feedforwardRun(l24es_nn_t * neuralNetwork, float * inputs) {
    return NULL;
}
