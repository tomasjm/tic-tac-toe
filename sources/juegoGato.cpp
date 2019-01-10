#include "../headers/juegoGato.h"
#include "../headers/jugadorPC.h"
#include <stdio.h>
#include <string.h>

//Variables
char tablero[3][3] = {
    {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
// Implementaciones
void iniciarUnJugador()
{
    printf("\n\nModo de juego: Un jugador \n\n");
    int turno = 0;
    imprimirTablero();
    while (turno < 9)
    {
        if (turno % 2 == 0)
        {
            int fila;
            int columna;
            printf("Juegas tu, como X:\n");
            scanf("%d,%d", &fila, &columna);
            if (tablero[fila - 1][columna - 1] == '-')
            {
                turno++;
                tablero[fila - 1][columna - 1] = 'X';
            }
            else
            {
                imprimirTablero();
                printf("No puedes jugar ahi! Selecciona otra posicion\n\n");
            }
        }
        else
        {
            jugar();
            turno++;
            imprimirTablero();
        }
    }
}
void iniciarDosJugadores()
{
    printf("\n\nModo de juego: Dos jugadores \n\n");
    int turno = 0;
    imprimirTablero();
    while (turno < 9)
    {
        int fila;
        int columna;
        printf("TURNO: %d\n", turno);
        if (turno % 2 != 0)
        {
            printf("Juega O:\n");
        }
        else
        {
            printf("Juega X:\n");
        }
        scanf("%d,%d", &fila, &columna);
        printf("%d   %d\n", fila, columna);
        printf("%c\n", tablero[fila - 1][columna - 1]);
        if (tablero[fila - 1][columna - 1] == '-')
        {
            if (turno % 2 != 0)
            {
                tablero[fila - 1][columna - 1] = 'O';
                turno++;
            }
            else
            {
                tablero[fila - 1][columna - 1] = 'X';
                turno++;
            }
            imprimirTablero();
        }
        else
        {
            imprimirTablero();
            printf("No puedes jugar ahi! Intentalo denuevo\n");
        }
        char ganador = comprobarGanador();
        if (ganador != '-')
        {
            printf("Gano %c\n", ganador);
            break;
        }
    }
    char ganador = comprobarGanador();
    if (turno == 9 && ganador == '-')
    {
        printf("Empate\n");
    }
}
void imprimirTablero()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                printf(" %c \n", tablero[i][j]);
            }
            else
            {
                printf(" %c |", tablero[i][j]);
            }
        }
        if (i != 2)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}
char comprobarGanador()
{
    // Filas
    for (int i = 0; i < 3; i++)
    {
        char anteriorJugada;
        int contador = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                anteriorJugada = tablero[i][j];
                contador++;
            }
            else
            {
                if (tablero[i][j] == anteriorJugada)
                {
                    contador++;
                }
                else
                {
                    contador--;
                }
            }
        }
        if (contador == 3)
        {
            return anteriorJugada;
            break;
        }
    }

    // Columnas
    for (int i = 0; i < 3; i++)
    {
        char anteriorJugada;
        int contador = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                anteriorJugada = tablero[j][i];
                contador++;
            }
            else
            {
                if (tablero[j][i] == anteriorJugada)
                {
                    contador++;
                }
                else
                {
                    contador--;
                }
            }
        }
        if (contador == 3)
        {
            return anteriorJugada;
            break;
        }
    }
    // diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != '-')
    {
        return tablero[0][0];
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != '-')
    {
        return tablero[0][2];
    }
    return '-';
}