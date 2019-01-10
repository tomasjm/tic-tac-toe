#include "../headers/jugadorPC.h"
#include "../headers/juegoGato.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int jugadas = 0;
/*
* Nombre de la funcion: jugar.
* Tipo de funcion: void
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Es la funcion principal de la computadora, es la que determina que acciones se tomarán
*              según el turno del juego. Es la función que establece un orden "lógico" de las jugadas
*              basadas en la estrategia planteada anteriormente.
*              
*              
*/
void jugar()
{
    printf("Computadora pensando...\n");
    if (jugadas == 0)
    {
        primeraJugada();
    }
    else if (jugadas != 0) //significa que el X jugó 2 veces ya y podria ganar ante un mal movimiento
    {
        if (ganar() != 1)
        {
            if (bloquear() != 1)
            {
                if (jugarAleatorio() != 1)
                {
                    printf("\nCASO DESCONOCIDO\n");
                }
            }
        }
    }
}
/*
* Nombre de la funcion: primeraJugada.
* Tipo de funcion: void.
* Parametros: -
* Dato de retorno: no retorna.
* Descripcion: Esta funcion es la encargada de determinar la primera jugada de la computadora:
*              - Como el centro es la casilla más fuerte, si es que esta no está ocupada, la ocupará.
*              - Si el centro está ocupado, jugará en [0][0].
*              
*/
void primeraJugada()
{
    // Si el centro está disponible, jugará ahi.
    if (tablero[1][1] == '-')
    {
        tablero[1][1] = 'O';
        jugadas++;
    }
    // Si el centro no está disponible, jugará en CUALQUIERA de las 4 ESQUINAS.
    else
    {

        /*
            Se usará la funcion rand que nos devuelve un numero aleatorio dentro de un rango.
            Eso si, esta funcion utiliza un seed, que en su documentacion indica que es utilizada
            para generar la aleatoriedad en su algoritmo, es decir, bajo un mismo seed, generará el mismo numero,
            es por eso que si llamamos a rand() directamente, nos enviará el mismo numero en cada ejecucion.
            Para establecer el seed, se llama a la funcion srand y se le pasa en un parametro, por convenio,
            los programadores utilizan la funcion time(0) que nos devuelve el tiempo del sistema en segundos, en cambio,
            si no se coloca el 0, nos devuelve el tiempo con un formato de puntero, es decir, como parametro se le deberia
            entregar un puntero.
        */
        srand(time(0)); // SEED DE ALEATORIEDAD QUE REQUIERE LA FUNCION RAND()
        /*
            Tambien rand funciona en rangos: rand() % 100 funciona en rangos de 0-99, es decir, rangos de 100 elementos.
            Si quieres correr este rango, le sumas o restas una cantidad definida.
            EJ: rand() % 100 + 1: utiliza rango 1-100.
            Por eso se utiliza aca abajo rand() % 4 + 1: rango 1-4 que enumeran las 4 esquinas existentes.
        */
        int esquina = rand() % 4 + 1;
        switch (esquina)
        {
        case 1:
            tablero[0][0] = 'O';
            break;
        case 2:
            tablero[0][2] = 'O';
            break;
        case 3:
            tablero[2][0] = '0';
            break;
        case 4:
            tablero[2][2] = 'O';
            break;
        }

        jugadas++;
    }
}

/*
* Nombre de la funcion: bloquear.
* Tipo de funcion: int
* Parametros: -
* Dato de retorno: 0 o 1, enteros.
* Descripcion: Esta funcion está encargada de buscar las jugadas de amenaza del jugador, es decir,
*              aquellas jugadas en una casilla especifica que pueden ganar la partida, por lo tanto, 
*              al encontrarlas, las bloqueará jugando en aquella casilla.
*              Si bloquea alguna, devolverá un 1.
*              Si no bloquea, devuelve un 0.
*/

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
    // Siguen la misma logica que las anteriores, si el contador llega a 2, buscará algun lugar para bloquear
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

int ganar()
{
    // filas
    for (int i = 0; i < 3; i++)
    {
        int contadorJugPC = 0;
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j] == 'O')
            {
                contadorJugPC++;
            }
            else if (tablero[i][j] == 'X')
            {
                contadorJugPC = -100;
            }
            if (j == 2 && contadorJugPC == 2)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (tablero[i][k] == '-')
                    {
                        tablero[i][k] = 'O';
                        jugadas++;
                        return 1;
                        break;
                    }
                }
            }
        }
    }

    // columnas
    for (int i = 0; i < 3; i++)
    {
        int contadorJugPC = 0;
        for (int j = 0; j < 3; j++)
        {
            if (tablero[j][i] == 'O')
            {
                contadorJugPC++;
            }
            else if (tablero[j][i] == 'X')
            {
                contadorJugPC = -100;
            }
            if (j == 2 && contadorJugPC == 2)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (tablero[k][i] == '-')
                    {
                        tablero[k][i] = 'O';
                        jugadas++;
                        return 1;
                        break;
                    }
                }
            }
        }
    }
    // diagonales
    int conteoJugD1 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][i] == 'O')
        {
            conteoJugD1++;
        }
        else if (tablero[i][i] == 'X')
        {
            conteoJugD1 = -100;
        }
        if (i == 2 && conteoJugD1 == 2)
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
    int conteoJugD2 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tablero[2 - i][i] == 'O')
        {
            conteoJugD2++;
        }
        else if (tablero[2 - i][i] == 'X')
        {
            conteoJugD2 = -100;
        }
        if (i == 2 && conteoJugD2 == 2)
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

int jugarAleatorio()
{
    bool jugado = false;
    do
    {
        srand(time(0));
        int fila = rand() % 3;
        srand(time(0));
        int columna = rand() % 3;
        if (tablero[fila][columna] == '-')
        {
            tablero[fila][columna] = 'O';
            jugado = true;
            jugadas++;
            return 1;
        }
    } while (!jugado);
    return 0;
}