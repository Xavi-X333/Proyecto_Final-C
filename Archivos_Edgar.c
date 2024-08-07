// Archivos - Edgar

// Realizar un programa que pida el ingreso de 10 nombres los guarde dentro del archivo y posteriormente los muestre ordenados en pantalla de A a Z

#include <stdio.h>
int main() {
    FILE *fp;
    char nombre[30];
    fp = fopen("Nombres.txt", "w");
    for (int i = 1; i <= 10; i++) {
        printf("Ingrese su nombre: >");
        scanf("%s", &nombre);
        fprintf(fp, "%s\n", nombre);
    }
    fclose(fp);

    
    return 0;
}
