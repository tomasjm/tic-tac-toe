/* Universidad de La Frontera
* Ingeniería Civil Electrónica
*
* ICC-202 PROGRAMACION DE COMPUTADORES
*
* Tarea 3
*
* Autor: 
* Tomás Jiménez. (t.jimenez03@ufromail.cl)
*
*
* Fecha: 11/01/2019
*
* Juego tic-tac-toe
* Este programa representa al juego tic-tac-toe o también llamado gato, cuenta con dos modalidades
* para poder jugar, las cuales son el modo de un jugador y dos jugadores.
* En el caso de un jugador, pues, juega un usuario contra la computadora, en este caso, la computadora
* sigue un algoritmo simple pero efectivo, donde practicamente no podrás ganarle.
* En el caso de dos jugadores, pueden jugar dos jugadores valga la redundancia, los dos jugadores tendrán
* turnos alternos para no producir una doble jugada.
* Siempre comenzará a jugar X en ambos casos, donde X representa al usuario en el caso de la modalidad
* de un jugador.
* Solo se puede jugar una partida por ejecución.
*/

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