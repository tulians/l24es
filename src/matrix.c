/* l24es - Matrix module */
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "message.h"

int nElem, elemIndex;
char * errorMessage;

l24es_matrix_t * createMatrix(int nRows, int nColumns, char order) {
    l24es_matrix_t * newMatrix = (l24es_matrix_t *)malloc(sizeof(l24es_matrix_t));
    newMatrix -> nRows = nRows;
    newMatrix -> nColumns = nColumns;
    newMatrix -> order = order;
    newMatrix -> matrix = (float *)malloc(sizeof(float) * (nRows * nColumns));
    return newMatrix;
}

void initMatrix(l24es_matrix_t * matrix, float * data) {
    int rows, columns;
    if(matrix -> order == ROW) {
        for(rows = 0; rows < matrix -> nRows; rows++) {
            for(columns = 0; columns < matrix -> nColumns; columns++) {
                matrix -> matrix[rows * matrix -> nColumns + columns] = data[rows * matrix -> nColumns + columns];
            }
        }
    } else {
        for(rows = 0; rows < matrix -> nRows; rows++) {
            for(columns = 0; columns < matrix -> nColumns; columns++) {
                matrix -> matrix[rows + matrix -> nRows * columns] = data[rows + matrix -> nRows * columns];
            }
        }
    }
}

void printAsMatrix(l24es_matrix_t * matrix) {
    if (matrix) {
        int rows, columns;
        printf("Matrix information:\n");
        printf("- Number of rows: %d\n", matrix -> nRows);
        printf("- Number of column: %d\n", matrix -> nColumns);
        printf("- Ordering: %s\n", matrix -> order == ROW ? "ROW-MAJOR" : "COLUMN-MAJOR");
        printf("Content:\n");
        for(rows = 0; rows < matrix -> nRows; rows++) {
            for(columns = 0; columns < matrix -> nColumns; columns++) {
                printf("[%d,%d]: %f\t", rows, columns, matrix -> matrix[rows * matrix -> nColumns + columns]);
            }
            printf("\n");
        }
    }
}

l24es_matrix_t * sumTwoMatrices(l24es_matrix_t * m1, l24es_matrix_t * m2) {
    if ((m1 -> nRows == m2 -> nRows) && (m1 -> nColumns == m2 -> nColumns) && (m1 -> order == m2 -> order)) {
        l24es_matrix_t * result = createMatrix(m1 -> nRows, m1 -> nColumns, m1 -> order);
        nElem = m1 -> nRows * m1 -> nColumns;
        for(elemIndex = 0; elemIndex < nElem; elemIndex++) {
            result -> matrix[elemIndex] = m1 -> matrix[elemIndex] + m2 -> matrix[elemIndex];
        }   
        return result;
    } else {
        errorMessage = createErrorMessage("[sumTwoMatrices] Could not perform matrix sum because of parameters mismatch or null matrix.");
        printf("\n%s\n", errorMessage);
        return NULL;
    }
}

l24es_matrix_t * multiplyByScalar(l24es_matrix_t * matrix, float value) {
    if (matrix) {
        l24es_matrix_t * result = createMatrix(matrix -> nRows, matrix -> nColumns, matrix -> order);
        nElem = matrix -> nRows * matrix -> nColumns;
        for(elemIndex = 0; elemIndex < nElem; elemIndex++) {
           result -> matrix[elemIndex] = matrix -> matrix[elemIndex] * value;
        }
        return result;
    } else {
        errorMessage = createErrorMessage("[multiplyByScalar] Could not perform scalar multiplication because of NULL input matrix.");
        printf("\n%s\n", errorMessage);
        return NULL;
    }
}

void _printAsBinary(int number) {
    while (number) {
        if (number & 1) { printf("1"); }
        else { printf("0"); }
        number >>= 1;
    }
    printf("\n");
}

void transposeMatrix(l24es_matrix_t * matrix) {
    if (matrix) {
        int index, internalIndex, checked;
        float previousValue;
        nElem = matrix -> nRows * matrix -> nColumns;
        /* Initialize vector of transposed indexes. */
        int * transposedIndexes = (int *)malloc(sizeof(int) * nElem);
        for (index = 0; index < nElem - 1; index++) {
            transposedIndexes[index] = ((matrix -> nRows * index) - ((nElem - 1) * (index / matrix -> nColumns))) % (nElem - 1);
        }
        transposedIndexes[index] = index;

        checked = 0;
        for (index = 1; index < nElem - 1; index++) {
            internalIndex = index;
            if (checked & (1 << index)) {
                continue;
            } else {
                previousValue = matrix -> matrix[index];
                do {
                    checked |= 1 << transposedIndexes[internalIndex];
                    swap(previousValue, matrix -> matrix[transposedIndexes[internalIndex]]);
                    internalIndex = transposedIndexes[internalIndex];
                } while(internalIndex != index);
            }
        }
        /* Reestructurate matrix. */
        swap(matrix -> nRows, matrix -> nColumns);
        free(transposedIndexes);
    } else {
        errorMessage = createErrorMessage("[transposeMatrix] Could not perform matrix transpose because of NULL input matrix.");
        printf("\n%s\n", errorMessage);
    }
}

l24es_matrix_t * multiplyMatrices(l24es_matrix_t * m1, l24es_matrix_t * m2) {
    if (m1 -> nColumns == m2 -> nRows) {
        l24es_matrix_t * result = createMatrix(m1 -> nRows, m2 -> nColumns, m1 -> order);
        transposeMatrix(m2);
        int rowsIndexM1, rowsIndexM2, element, resultIndex;
        resultIndex = 0;
        for (rowsIndexM1 = 0; rowsIndexM1 < m1 -> nRows; rowsIndexM1++) {
            for (rowsIndexM2 = 0; rowsIndexM2 < m2 -> nRows; rowsIndexM2++) {
                result -> matrix[resultIndex] = 0;
                for (element = 0; element < m1 -> nColumns; element++) {
                    result -> matrix[resultIndex] += (m1 -> matrix[(rowsIndexM1 * m1 -> nColumns) + element]) * (m2 -> matrix[(rowsIndexM2 * m2 -> nColumns) + element]);
                }
                resultIndex++;
            }
        }
        return result;
    } else {
        errorMessage = createErrorMessage("[multiplyMatrices] Could not perform matrix multiplication because of NULL input matrices or parameters mismatch.");
        printf("\n%s\n", errorMessage);
        return NULL;
    }
}


float * dotProduct(float * matrix, float * vector, int numberOfMatrixElements, int nElem) {
    int matrixIndex, vectorIndex;
    float * result = (float *)malloc(sizeof(float) * nElem);
    for (matrixIndex = 0, vectorIndex = 0; matrixIndex < numberOfMatrixElements; matrixIndex++) {
        result[matrixIndex % nElem] += matrix[matrixIndex] * vector[vectorIndex];
        if (matrixIndex > (nElem * vectorIndex)) { vectorIndex++; }
    }
    return result;
}
