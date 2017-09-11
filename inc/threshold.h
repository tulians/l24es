#ifndef _THRESHOLD_H
#define _THRESHOLD_H

typedef float * (*activationFunction_t)(float *, int);

/* Activation functions */
float * hardSigmoid(float *, int);
float * fastSigmoid(float *, int);

/* setActivationFunction
    Inputs:
        activationFunctionName: string with the name of the given activation function.
    Outputs:
        af_ptr: pointer to the activation function definition.
 */
activationFunction_t setActivationFunction(const char *);

#endif /* #ifndef _THRESHOLD_H_ */
