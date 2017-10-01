#ifndef _THRESHOLD_H
#define _THRESHOLD_H

typedef float * (*activationFunction_t)(float *, int);

/* Activation functions */
float * hardSigmoid(float *, int);
float * fastSigmoid(float *, int);

/* setActivationFunction
    Returns a pointer to an activation function.
    -->f()
        activationFunctionName: string with the name of the given activation function.
    f()-->
        af_ptr: pointer to the activation function definition.
 */
activationFunction_t setActivationFunction(const char *);

#endif /* #ifndef _THRESHOLD_H_ */
