#include <stdio.h>
#include <stdlib.h>

float* merge(float* A, int sizeA, float* B, int sizeB) {
    int sizeC = sizeA + sizeB;
    float aux;
    float* C = (float*)malloc((sizeA + sizeB) * sizeof(float));
    for(int i = 0; i < sizeA; i++){
        C[i] = A[i];
    }
    for(int i = 0; i < sizeB; i++){
        C[sizeA + i] = B[i];
    }
    for(int i = 0; i< sizeC - 1;i++){
        for(int j=0; j < sizeC - 1 - i;j++){
            if (C[j] >= C[j+1]){
                aux = C[j];
                C[j] = C[j+1];
                C[j+1] = aux;
            }
        }
    }
    return C;
}

int main() {
    /*
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    

    // */
    float a[5] = {4,5,6,7,8};
    float b[4] = {1,2,3,9};

    float* result = merge(a, 5, b, 4);

    printf("Result:");
    for(int i=0; i<9; i++) {
        printf("%f", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
