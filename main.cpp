#include <stdio.h>

#include "headers/interfazUsuario.h"
#include "headers/juegoGato.h"
#include "headers/jugadorPC.h"

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