#include "../headers/juegoGato.h"
#include "../headers/jugadorPC.h"
#include <stdio.h>
#include <string.h>

//Variables
char tablero[3][3] = {
    {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
// Implementaciones

/*
* Nombre de la funcion: iniciarUnJugador.
* Tipo de funcion: void
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Esta funcion es la encargada de iniciar el juego de un jugador
*              alternando las jugadas de acuerdo al transcurso de la partida, practicamente es
*              la estructura o "moderador" de la partida de un jugador, pues, asigna la jugada
*              respectiva al jugador o al computador según el turno, además de comprobar al ganador o
*              asignar el empate de acuerdo a la situación.
*              
*/
void iniciarUnJugador()
{
    printf("\n\nModo de juego: Un jugador \n\n");
    int turno = 0;
    imprimirTablero();
    printf("\n\nIngresa con el formato fila,columna \n\n");
    while (turno < 9)
    {
        if (turno % 2 == 0)
        {
            int fila;
            int columna;
            printf("Jugador X, ingrese su jugada:\n");
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
        char ganador = comprobarGanador();
        if (ganador != '-')
        {
            printf("Gano %c\n", ganador);
            break;
        }
    }
}

/*
* Nombre de la funcion: iniciarDosJugadores.
* Tipo de funcion: void
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Esta funcion es la encargada de iniciar el juego de dos jugadores
*              alternando las jugadas de acuerdo al transcurso de la partida, practicamente es
*              la estructura o "moderador" de la partida de dos jugadores, pues, asigna la jugada
*              respectiva al jugador X u O según el turno que les corresponda, 
*              además de comprobar al ganador o asignar el empate de acuerdo a la situación.
*              
*/
void iniciarDosJugadores()
{
    printf("\n\nModo de juego: Dos jugadores \n\n");
    int turno = 0;
    imprimirTablero();
    printf("\n\nIngresa con el formato fila,columna \n\n");
    while (turno < 9)
    {
        int fila;
        int columna;
        if (turno % 2 != 0)
        {
            printf("Juega O:\n");
        }
        else
        {
            printf("Juega X:\n");
        }
        scanf("%d,%d", &fila, &columna);
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
/*
* Nombre de la funcion: imprimirTablero.
* Tipo de funcion: void
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Funcion sencilla encargada de por pantalla el tablero con el diseño
*              adecuado y jugadas respectivas cada vez que sea llamada.
*              
*/
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
/*
* Nombre de la funcion: comprobarGanador.
* Tipo de funcion: char
* Parametros: -
* Dato de retorno: 'X', 'O', '-'.
* Descripcion: Esta funcion es la encargada de determinar al ganador y retornarlo.
*              Cada vez que es llamada evalua filas, columnas y diagonales para encontrar
*              tres jugadas seguidas de un mismo jugador, es decir, con un contador,
*              evalua por fila, columna o diagonal si es que se encuentran las 3 casillas ocupadas,
*              por un mismo jugador. En caso de que el contador llegue a 3 y la casillas ocupadas no sean
*              el char '-', inmediatamente se retornará al jugador ya sea 'X' u 'O'.
*              Por lo tanto si retorna 'X', significa que gana X. Si retorna 'O', gana O.
*              Si retorna '-', no hay ganador.
*              
*/
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
    //diagonales
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