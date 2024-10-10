#include <stdio.h>
#include <stdlib.h>


int len(char* s) {
    int length = 0;
    while (s[length] != '\0'){
        length++;
    }
    return length;
}
char* longest(char* v[], int size) {
    char* longestChar = v[0];
    for(int i = 0;i < size; i++){
        for (int j=0;j< size - i;j++){
            if(len(v[j]) > len(longestChar)){
                longestChar = v[j];
            }
        }
    }
    return longestChar;
}

char* superConcatenate(char* v[], int size) {
    int totalSize = 0;
    int resIndex = 0;
    for (int i=0;i<size;i++){
        totalSize += len(v[i]); // Saco la longitud total necesaria
    }
    char* res = (char*) malloc(sizeof(char) * totalSize);
    for (int i=0;i<size;i++){
        char* strActual = v[i];
        for(int j = 0; strActual[j] != '\0'; j++, resIndex++){
            res[resIndex] = strActual[j];
        }
    }

    return res;
}

char* superConcatenateWithSep(char* v[], int size, char* s) {
    int totalSize = 0;
    int resIndex = 0;
    for (int i=0;i<size;i++){
        totalSize += len(v[i]); // Saco la longitud total necesaria
    }
    totalSize += len(s) * (size -1);
    char* res = (char*) malloc(sizeof(char) * (totalSize));
    for (int i=0;i<size;i++){
        char* strActual = v[i];
        for(int j = 0; strActual[j] != '\0'; j++, resIndex++){
            res[resIndex] = strActual[j]; // Loop para añadir el string actual al resultado.
        }
        if (i < size - 1) {
            for (int k = 0; s[k] != '\0'; k++, resIndex++) {
                res[resIndex] = s[k];
            }
        }
    }

    return res;
}

int main() {
    /*
    

    // */
    char* v[5] = {"hola", "cosmo", "va", "el", "dia"};

    char* l = longest(v, 5);

    printf("El string mas largo es: \"%s\"\n", l);

    char* sc = superConcatenate(v, 5);

    printf("El arreglo de string super concatenado es: \"%s\"\n", sc);

    char* scs = superConcatenateWithSep(v, 5, "...");

    printf("El arreglo de string super concatenado con separadores es: \"%s\"\n", scs);

    free(sc);
    free(scs);
    return 0;
}
