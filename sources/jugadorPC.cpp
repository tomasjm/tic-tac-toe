#include "../headers/jugadorPC.h"
#include "../headers/juegoGato.h"
#include <stdio.h>
#include <string.h>

int jugadas = 0;

void jugar()
{
    printf("\nJUGADAS: %d", jugadas);
    if (jugadas == 0)
    {
        primeraJugada();
    }
    else if (jugadas != 0) //significa que el X jugó 2 veces ya y podria ganar ante un mal movimiento
    {
        if (bloquear() != 1)
        {
            printf("dale pelotudo juga bien");
        }
    }
}

int primeraJugada()
{
    if (tablero[1][1] == '-')
    {
        tablero[1][1] = 'O';
        jugadas++;
        printf("CASO 1.1\n");
    }
    else if (tablero[0][0] == '-')
    {
        tablero[0][0] = 'O';
        jugadas++;
        printf("CASO 1.2\n");
    }
    return 1;
}
int bloquear()
{
    // VAMOS A COMPROBAR FILA POR FILA DE ARRIBA HACIA ABAJO
    for (int i = 0; i < 3; i++)
    {
        /*
                    Se seguira esta logica:
                    - Contamos fila por fila, si en una fila encontramos al menos 2 jugadas de X, tendremos 2 posibilidades,
                    que el X gane en la siguiente jugada o que nosotros hayamos jugado antes y este no pueda ganar.
                */
        int conteoJugadaEnemiga = 0; // Este es el contador, si dentro de una fila llegamos a encontrar 2 jugadas, verificaremos que haya un espacio vacio y jugaremos ahi.
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j] == 'X')
            {
                conteoJugadaEnemiga++;
            }
            if (j == 2 && conteoJugadaEnemiga == 2) // Si llegamos al final de la fila, y el contador esta en 2, significa que hay 2 jugadas enemigas y hay que responder (en caso de que haya alguna casilla vacia)
            {
                for (int k = 0; k < 3; k++) // Aca vamos a buscar casilla por casilla en la misma fila si es que hay algun espacio vacio
                {
                    if (tablero[i][k] == '-') // Se encontro espacio vacio
                    {
                        tablero[i][k] = 'O'; // Jugamos ahi.
                        jugadas++;
                        return 1;
                        break; // Nos salimos del ciclo por que ya jugamos.
                    }
                }
            }
        }
    }

    // Vamos a comprobar las columnas
    for (int i = 0; i < 3; i++)
    {
        /*
                    Se seguira esta logica:
                    - Contamos columna por columna, si en una columna encontramos al menos 2 jugadas de X, tendremos 2 posibilidades,
                    que el X gane en la siguiente jugada o que nosotros hayamos jugado antes y este no pueda ganar.
                */
        int conteoJugadaEnemiga = 0; // Este es el contador, si dentro de una columna llegamos a encontrar 2 jugadas, verificaremos que haya un espacio vacio y jugaremos ahi.
        for (int j = 0; j < 3; j++)
        {
            if (tablero[j][i] == 'X')
            {
                conteoJugadaEnemiga++;
            }
            if (j == 2 && conteoJugadaEnemiga == 2) // Si llegamos al final de la columna, y el contador esta en 2, significa que hay 2 jugadas enemigas y hay que responder (en caso de que haya alguna casilla vacia)
            {
                for (int k = 0; k < 3; k++) // Aca vamos a buscar casilla por casilla en la misma columna si es que hay algun espacio vacio
                {
                    if (tablero[k][i] == '-') // Se encontro espacio vacio
                    {
                        tablero[k][i] = 'O'; // Jugamos ahi.
                        jugadas++;
                        return 1;
                        break; // Nos salimos del ciclo por que ya jugamos.
                    }
                }
            }
        }
    }

    // Diagonales
    int conteoD1 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][i] == 'X')
        {
            conteoD1++;
        }
        if (conteoD1 == 2)
        {
            for (int k = 0; k < 3; k++)
            {
                if (tablero[k][k] == '-')
                {
                    tablero[k][k] = 'O';
                    jugadas++;
                    return 1;
                    break;
                }
            }
        }
    }

    int conteoD2 = 0;
    for (int i = 2; i > 0; i--)
    {
        if (tablero[2 - i][i] == 'X')
        {
            conteoD2++;
        }
        if (conteoD2 == 2)
        {
            for (int k = 0; k < 3; k++)
            {
                if (tablero[2 - k][k] == '-')
                {
                    tablero[2 - k][k] = 'O';
                    jugadas++;
                    return 1;
                    break;
                }
            }
        }
    }
    return 0;
}
