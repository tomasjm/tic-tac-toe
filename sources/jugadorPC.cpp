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
        if (tablero[1][1] == '-')
        {
            tablero[1][1] = '0';
            jugadas++;
            printf("CASO 1.1\n");
        }
        else if (tablero[0][0] == '-')
        {
            tablero[0][0] = 'O';
            jugadas++;
            printf("CASO 1.2\n");
        }
    }
    else
    {
        //significa que el X jugó 2 veces ya y podria ganar ante un mal movimiento

        if (jugadas == 1)
        {
            printf("CASO 2.0\n");
            for (int i = 0; i < 3; i++)
            {
                int conteofilas = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (tablero[i][j] == 'X')
                    {
                        conteofilas++;
                    }
                    if (j == 2 && conteofilas == 2)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (tablero[i][k] == '-')
                            {
                                tablero[i][k] = 'O';
                                break;
                                jugadas++;
                            }
                        }
                    }
                }
            }
        }
    }
}
