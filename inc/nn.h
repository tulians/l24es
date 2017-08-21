/* l24es - Neural networks header module  */

#ifndef _NN_H
#define _NN_H

#include "matrix.h"

typedef struct neuralNetwork {
    int inputsNumber, outputsNumber;
    int * unitsPerHiddenLayer;
    float * weights; 
    float * (*activationFunction)(float *, int);
} l24es_nn_t;

/* initializeNeuralNetwork
    inputsNumber: number of input nodes.
    outputsNumber: number of output nodes.
    unitsPerHiddenLayer: vector cointaining the number of hidden units per hidden layer.
    length: number of hidden layers.
    activationNumber: name of the activation function to use.    
 */
l24es_nn_t * initializeNeuralNetwork(int, int, int *, int, char *);

/* _getWeightsFromHiddenLayers
    unitsPerHiddenLayer: vector cointaining the number of hidden units per hidden layer.
    length: number of hidden layers.
    inputsNumber: number of input nodes.
    outputsNumber: number of output nodes.
 */
float * _getWeightsFromHiddenLayers(int *, int, int, int);

#endif /* _NN_H_ */
