#include <stdio.h>

#include "headers/interfazUsuario.h"
#include "headers/juegoGato.h"
#include "headers/jugadorPC.h"

/*
* Nombre de la funcion: main.
* Tipo de funcion: int
* Parametros: -
* Dato de retorno: 0.
* Descripcion: Funcion main del programa, se encarga de imprimir la bienvenida para
*              luego imprimir el menu principal y pedir una opcion de seleccion, en donde,
*              segun la opcion seleccionada, utilizando un switch, ejecutará cierto modo de juego.
*              
*              
*/
int main()
{
    imprimirBienvenida();
    imprimirMenuPrincipal();
    bool estado = true;
    while (estado)
    {
        int opc = pedirOpcion();
        switch (opc)
        {
        case 1:
            estado = false;
            iniciarUnJugador();
            break;
        case 2:
            estado = false;
            iniciarDosJugadores();
            break;
        default:
            imprimirOpcionInvalida();
            break;
        }
    }

    return 0;
}