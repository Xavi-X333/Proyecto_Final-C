/*Memoria Dinamica - Natalia

Realizar un programa que le pregunte al usuario cuantos datos desea ingresar a una agenda y con funciones agregar la cantidad de contactos que desee: Idenrificador, nombre y telefono*/
#include <stdio.h>
#include <stdlib.h>
int cantidad();
typedef struct
{
    int id;
    char nombre[20];
    float telefono;
}Agenda;

int main()
{
    Agenda *puntero;
    int canti=cantidad();
    puntero=malloc(canti*sizeof(Agenda));
    ingreso(puntero,canti);
    mostrar(puntero,canti);
}

int cantidad()
{
    int cantidad;
    printf("Ingrese la cantidad de contactos que desea ingresar\n>>");
    scanf("%d",&cantidad);
    return cantidad;
}
void ingreso(Agenda *puntero, int canti);

void ingreso(Agenda *puntero, int canti)
{
    int i;
    for (i=0;i<canti;i++)
    {
        printf("Ingrese el id del contacto %d\n>>",i+1);
        scanf("%d",&puntero[i].id);
        printf("Ingrese el nombre del contacto\n>>");
        scanf("%s",&puntero[i].nombre);
        printf("Ingrese el telefono del contacto\n>>");
        scanf("%f",&puntero[i].telefono);
    }
}

void mostrar(Agenda *puntero, int canti)
{
    int i;
    printf("lista de pcontacto\n");
    for (i=0;i<canti;i++)
    {
        printf("Producto no.%d\n",i+1);
        printf("id del contacto: %d\n",puntero[i].id);
        printf("nombre del contacto: %s\n",puntero[i].nombre);
        printf("telefono del contacto: %.2f\n",puntero[i].telefono);
    }
    free(puntero);
}
