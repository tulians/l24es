/* l24es - Neural networks header module  */

#ifndef _NN_H
#define _NN_H

#include "matrix.h"
#include "threshold.h"

typedef struct neuralNetwork {
    int inputsNumber, outputsNumber;
    int * unitsPerHiddenLayer;
    float * weights;
    activationFunction_t activationFunction; 
} l24es_nn_t;

/* initializeNeuralNetwork
    Inputs:
        inputsNumber: number of input nodes.
        outputsNumber: number of output nodes.
        unitsPerHiddenLayer: vector cointaining the number of hidden units per hidden layer.
        length: number of hidden layers.
        activationNumber: name of the activation function to use.
    Outputs:
        neuralNetwork: initialized neural network structure.    
 */
l24es_nn_t * initializeNeuralNetwork(int, int, int *, int, const char *);

/* _getWeightsFromHiddenLayers
    Inputs:
        unitsPerHiddenLayer: vector cointaining the number of hidden units per hidden layer.
        length: number of hidden layers.
        inputsNumber: number of input nodes.
        outputsNumber: number of output nodes.
    Outputs:
        weights: weights vector initialized with random numbers.
 */
float * _getWeightsFromHiddenLayers(int *, int, int, int);

#endif /* _NN_H_ */
