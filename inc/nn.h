#ifndef _NN_H
#define _NN_H

#include "matrix.h"

typedef struct neuralNetwork {
    int inputsNumber, hiddenLayersNumber, hiddenUnitsNumber, weightsNumber, outputsNumber;
    l24es_matrix_t inputLayer;
    l24es_matrix_t hiddenLayers;
    l24es_matrix_t outputLayer; 
    l24es_matrix_t weights;
} l24es_nn;

l24es_nn * initializeNeuralNetwork(int, int, int, int, int, 
                l24es_matrix_t, l24es_matrix_t, l24es_matrix_t, l24es_matrix_t);

#endif /* _NN_H_ */
