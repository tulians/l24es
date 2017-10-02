/* l24es - Neural network specific operations header */ 

#ifndef _OPS_H
#define _OPS_H

/* dotProduct
    Performs the dot product between a matrix and a vector.
    -->f()
        matrix
        vector
        numberOfMatrixElements: to make optimal use of for cycles. 
        nElem: number of matrix elements to multiply with each vector element.
    f()-->
        Resulting vector from the dot product. 
    Example:
        matrix: [[1, 2, 3],[4, 5, 6]] should be sent as => [1, 4, 2, 5, 3, 6]
        vector: [1, 2, 3]
        dp = [(1 * 1) + (2 * 2) + (3 * 3), (1 * 4) + (2 * 5), (3 * 6)] = [14, 32]
*/
float * dotProduct(float *, float *, int, int);

/* toAugmentedVector
    Appends a 1.0 in position [0] of a vector.
    -->f()
        vector
        vectorSize
    f()-->
        augmentedVector
*/
float * toAugmentedVector(float *, int);

#endif /* #ifndef _OPS_H_ */
