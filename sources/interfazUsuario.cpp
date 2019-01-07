#include "../headers/interfazUsuario.h"
#include <stdio.h>

void imprimirBienvenida()
{
    printf("--------------------------\n");
    printf("**************************\n");
    printf("--------------------------\n");
    printf("\n     BIENVENIDO     \n\n");
    printf("--------------------------\n");
    printf("**************************\n");
    printf("--------------------------\n");
}

void imprimirMenuPrincipal()
{
    printf("\nJuego gato desarrollado por Tomás J.\n\n");
    printf("Seleccione una opcion:\n");
    printf("1. Un jugador\n");
    printf("2. Dos jugadores\n");
}
void imprimirOpcionInvalida()
{
    printf("Selecciona una opcion valida por favor\n");
}

int pedirOpcion()
{
    int opc;
    scanf("%d", &opc);
    return opc;
}