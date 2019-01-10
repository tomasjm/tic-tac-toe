#include "../headers/interfazUsuario.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Nombre de la funcion: imprimirBienvenida.
* Tipo de funcion: void
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Esta funcion se encarga de imprimir el primer mensaje del programa, es decir,
*              imprime el mensaje de bienvenida con algunos detalles.
*              
*/
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

/*
* Nombre de la funcion: imprimirMenuPrincipal.
* Tipo de funcion: void
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Esta funcion se encarga de imprimir el menu principal del juego, en donde,
*              tendrás que elegir entre 2 opciones, un jugador o dos jugadores. 
*              
*/
void imprimirMenuPrincipal()
{
    printf("\nJuego gato desarrollado por Tomás J.\n\n");
    printf("Seleccione una opcion:\n");
    printf("1. Un jugador\n");
    printf("2. Dos jugadores\n");
}
/*
* Nombre de la funcion: imprimirOpcionInvalida.
* Tipo de funcion: void
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Esta funcion se encarga de imprimir un mensaje de error al elegir mal una opcion.
*              
*/
void imprimirOpcionInvalida()
{
    printf("\nSelecciona una opcion valida por favor\n");
}
/*
* Nombre de la funcion: pedirOpcion.
* Tipo de funcion: int
* Parametros: -
* Dato de retorno: int opc.
* Descripcion: Esta funcion se encarga de leer un numero ingresado por el usuario, especificamente
*              la opcion que pide el menu principal, puede retornar cualquier numero ingresado.
*              
*/
int pedirOpcion()
{
    int opc;
    scanf("%d", &opc);
    return opc;
}

void limpiarPantalla()
{
    /*
        CLEAR: LINUX
        CLS: WINDOWS
        EN CASO DE QUE NO FUNCIONE, COMENTAR AMBAS LINEAS POR FAVOR
    */
    system("clear");
    //system("cls");
}