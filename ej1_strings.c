#include <stdio.h>
#include <stdlib.h>

int len(char* s) {
    int length = 0;
    while (s[length] != '\0'){
        length++;
    }
    return length;
}

char* copy(char* s) {
    int length = len(s) + 1;
    char* copy = (char*) malloc (sizeof(char) * length);
    for(int i = 0; i < length; i++){
        copy[i] = s[i];
    }
    return copy;
    // poner longitud + 1 en el ciclo de asignación byte a byte para tener en cuenta el caracter nulo
}

void replaceChar(char* s, char old, char new) {
    int size = len(s) + 1;
    for (int i = 0; i < size; i++){
        if (s[i] == old){
            s[i] = new;
        }
    }
}

char* concatenate(char* s1, char* s2) {
    int lenS1 = len(s1);
    int lenS2 = len(s2);
    int newLen = lenS1 + lenS2 + 1;
    char* res = (char*) malloc(sizeof(char) * newLen);
    
    for (int i = 0; i < lenS1; i++) {
        res[i] = s1[i];
    }
    for (int i = 0; i < lenS2; i++) {
        res[lenS1 + i] = s2[i];
    }
    return res;
}

int main() {
    /*
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    
    
    free(concat);

    // */
    char* s1 = "Ramon";
    char* s2 = "Ricardo";

    printf("El string \"%s\" mide %i\n",s1, len(s1));
    printf("El string \"%s\" mide %i\n",s2, len(s2));

    char* copyS1 = copy(s1);
    char* copyS2 = copy(s2);

    printf("El string \"%s\" es una copia de  %s\n",copyS1, s1);
    printf("El string \"%s\" es una copia de  %s\n",copyS2, s2);
    replaceChar(copyS1, 'a', 'o');
    replaceChar(copyS2, 'R', 'T');

    printf("Sobre el string \"%s\" remplazo 'a' por 'o': %s\n",s1, copyS1);
    printf("Sobre el string \"%s\" remplazo 'R' por 'T': %s\n",s2, copyS2);
    printf("Concateno \"%s\" con \"%s\":",copyS1, copyS2);

    char* concat = concatenate(copyS1, copyS2);

    printf(" \"%s\"\n",concat);
}
