#include <stdio.h>

#include "headers/interfazUsuario.h"
#include "headers/juegoGato.h"
#include "headers/jugadorPC.h"

/* ----------------------------------------
        ATENCION ATENCION ATENCION
   ----------------------------------------

   El programa utiliza una funcion limpiarPantalla() que se encuentra en
   los archivos de interfazUsuario, en caso de por alguna razon, durante la
   ejecucion del programa no se limpie la pantalla y aparezca un error, por favor
   seguir las instrucciones que se dejaron en la funcion limpiarPantalla() en el archivo cpp.     
*/

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
    limpiarPantalla();
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
            limpiarPantalla();
            imprimirMenuPrincipal();
            imprimirOpcionInvalida();
            break;
        }
    }

    return 0;
}