#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar_palabras(char palabra[][20], int cantidad){
    char temp[100];
    for (int i = 0; i<cantidad;i++) {
        for (int j = 0;j<cantidad;j++) {
            if (strcmp(palabra[j], palabra[i])>0) {
                strcpy(temp, palabra[j]);
                strcpy(palabra[j], palabra[i]);
                strcpy(palabra[i], temp);
            }
        }
    }
}

int main() {
    FILE *fp;
    char palabra[100][20];
    int cantidad = 0;

    fp = fopen("nombres.txt", "r");
    if (fp == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    while (fscanf(fp, "%s", palabra[cantidad]) != EOF) {
        cantidad++;
    }
    fclose(fp);

    ordenar_palabras(palabra, cantidad);

    printf("\nPalabras ordenadas alfabéticamente:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s\n", palabra[i]);
    }

    return 0;
}