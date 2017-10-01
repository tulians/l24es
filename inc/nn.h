/* l24es - Neural networks header module  */

#ifndef _NN_H
#define _NN_H

#include "matrix.h"
#include "threshold.h"

typedef struct neuralNetwork {
    int * unitsPerLayer;
    int numberOfLayers;
    float * weights;
    activationFunction_t activationFunction; 
} l24es_nn_t;

/* initializeNeuralNetwork
    Basic initialization of the neural network.
    -->f()
        unitsPerLayer: vector cointaining the number of units per layer.
        length: number of layers.
        activationFunction: name of the activation function to use.
    f()-->
        neuralNetwork: initialized neural network structure.    
 */
l24es_nn_t * initializeNeuralNetwork(int *, int, const char *);

/* _getWeightsFromLayers
    Generates the network's weights using random values.
     -->f()
        unitsPerLayer: vector cointaining the number of units per layer.
        length: number of hidden layers.
    f()-->
        weights: weights vector initialized with random numbers.
 */
float * _getWeightsFromLayers(int *, int);

/* feedforwardRun
    Computes the neural network output given an input.
    -->f()
        neuralNetwork
        inputs
    f()-->
        neural network results vector
*/
float * feedforwardRun(l24es_nn_t *, float *);

#endif /* _NN_H_ */
