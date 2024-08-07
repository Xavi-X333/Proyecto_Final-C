#include <stdio.h>
#include <string.h>

#define MAX_CANCIONES 100
#define MAX_AUTORES 10

typedef struct {
    char titulo[100];
    char album[100];
    int edicion;
} Cancion;

typedef struct {
    char nombre[100];
    char fecha_nacimiento[11]; 
    char origen[100];
    Cancion canciones[MAX_CANCIONES];
    int num_canciones;
} Autor;

Autor autores[MAX_AUTORES];
int num_autores = 0;

void agregarAutor() {
    if (num_autores < MAX_AUTORES) {
        Autor nuevoAutor;
        printf("Ingrese el nombre del autor: ");
        scanf("%s", nuevoAutor.nombre);
        printf("Ingrese la fecha de nacimiento (AAAA-MM-DD): ");
        scanf("%s", nuevoAutor.fecha_nacimiento);
        printf("Ingrese el origen del autor: ");
        scanf("%s", nuevoAutor.origen);
        nuevoAutor.num_canciones = 0;
        autores[num_autores++] = nuevoAutor;
        printf("Autor agregado exitosamente.\n");
    } else {
        printf("No se pueden agregar mas autores.\n");
    }
}

void agregarCancion() {
    char nombreAutor[100];
    printf("Ingrese el nombre del autor para agregar la cancion: ");
    scanf("%s", nombreAutor);
    
    for (int i = 0; i < num_autores; i++) {
        if (strcmp(autores[i].nombre, nombreAutor) == 0) {
            if (autores[i].num_canciones < MAX_CANCIONES) {
                Cancion nuevaCancion;
                printf("Ingrese el titulo de la cancion: ");
                scanf("%s", nuevaCancion.titulo);
                printf("Ingrese el album: ");
                scanf("%s", nuevaCancion.album);
                printf("Ingrese la edicion: ");
                scanf("%d", &nuevaCancion.edicion);
                autores[i].canciones[autores[i].num_canciones++] = nuevaCancion;
                printf("Cancion agregada exitosamente.\n");
            } else {
                printf("No se pueden agregar mas canciones para este autor.\n");
            }
            return;
        }
    }
    printf("Autor no encontrado.\n");
}

void mostrarDatos() {
    for (int i = 0; i < num_autores; i++) {
        printf("Autor: %s\n", autores[i].nombre);
        printf("Fecha de nacimiento: %s\n", autores[i].fecha_nacimiento);
        printf("Origen: %s\n", autores[i].origen);
        printf("Canciones:\n");
        for (int j = 0; j < autores[i].num_canciones; j++) {
            printf("  Titulo: %s, album: %s, Edicion: %d\n", 
                   autores[i].canciones[j].titulo, 
                   autores[i].canciones[j].album, 
                   autores[i].canciones[j].edicion);
        }
        printf("\n");
    }
}

int main() {
    int opcion;
    do {
        printf("Menu:\n");
        printf("1. Agregar autor\n");
        printf("2. Agregar cancion\n");
        printf("3. Mostrar datos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                agregarAutor();
                break;
            case 2:
                agregarCancion();
                break;
            case 3:
                mostrarDatos();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
    
    return 0;
}