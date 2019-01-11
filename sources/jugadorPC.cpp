/* 
* Explicacion Lógica del juego de la computadora.
* 
* La computadora seguirá un algoritmo bastante simple.
* Caso primera jugada dos opciones ordenadas por importancia:
* 1) Jugar en el centro si es que está disponible.
* 2) Jugar en cualquier esquina.
* Si la primera no se cumple, pues, jugará en alguna esquina.
*
* Llegando a la segunda jugada del PC, significa que el enemigo ya jugó 2 veces, puesto que
* el enemigo siempre comenzará a jugar, por lo tanto,
* para la segunda y el resto de jugadas, seguira los siguientes pasos por importancia:
* 1) Ganar
* 2) Bloquear jugada enemiga
* 3) Jugar en cualquier casilla disponible
* Acá pasa lo mismo, si no se puede ganar, buscará alguna forma de bloquear alguna casilla amenazadora.
* Si no puede ganar, ni bloquear, jugará en cualquier casilla para generar más jugadas de éxito.
*
* Estos pasos seguirá hasta el final de la partida, de esta manera el algoritmo solo debería ganar
* o empatar, no debería perder.
*
* En cada función se explicó un poco más detallado que validaciones se realizan
* para ejecutar los pasos anteriormente mencionados
*/

#include "../headers/jugadorPC.h"
#include "../headers/juegoGato.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int jugadas = 0; // Variable utilizada para diferenciar la primera jugada de las otras a por venir.

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
    // En algunas jugadas, debido a la aleatoriedad se genera una pequeña demora,
    // por lo tanto para evitar confusión, se imprime este mensaje.
    printf("Computadora pensando...\n");
    if (jugadas == 0) // en caso de que sea la primera jugada del PC.
    {
        primeraJugada(); // se ejecuta la primera jugada del PC.
    }
    else if (jugadas != 0) //significa que el X jugó 2 veces ya y este podria ganarnos ante un mal movimiento
    {
        if (ganar() != 1) // Si tenemos la posibilidad de ganar, pues, ganamos
        {
            if (bloquear() != 1) // Si no tuvimos la posibilidad de ganar, pues, bloqueamos al otro jugador.
            {
                if (jugarAleatorio() != 1) // Si no podemos hacer ninguna de las anteriores, se juega aleatoriamente.
                {
                    printf("\nCASO DESCONOCIDO\n"); // no se deberia llegar a este print
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
        Contamos fila por fila, si en una fila encontramos al menos 2 jugadas de X, tendremos 2 posibilidades,
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

/*
* Nombre de la funcion: ganar.
* Tipo de funcion: int
* Parametros: -
* Dato de retorno: 0 o 1, enteros.
* Descripcion: En esta funcion evaluamos ciertas condiciones para realizar una jugada ganadora,
*              sigue una logica bastante simple, pues, si se tiene la posibilidad de ganar, obviamente,
*              realizará la jugada ganadora y finalizará la partida.
*              En caso de que juegue, devolverá un 1 y significa que la partida finalizó con la victoria.
*              De caso contrario, devolverá un 0.
*/
int ganar()
{
    /*
        La logica que sigue este proceso es muy similar al del proceso de bloquear,
        en este caso, se busca por fila, columna y diagonales si es que se han jugado 2 veces.
        Claro está que hay un inconveniente, y es que si hay al menos 1 jugada enemiga, significa
        que ya no podremos ganar en esta fila, columna o diagonal.
        Por lo tanto el proceso es así, cada jugada del PC vale 1 punto, cada jugada enemiga vale -100 puntos absolutos.
        Si se llega a 2 puntos, es por que podemos ganar ya que el caracter '-' no se considera como nada.
        Estos puntos se separan por filas, columnas y diagonales.

        Es decir si tenemos una fila: O | - | O : significa que tenemos 2 puntos y podemos ganar.
        Si tenemos: O | - | - : tenemos 1 punto y no podemos ganar.
        SI tenemos X | O | O : tendremos -100 puntos y no podremos ganar.
    */
    // filas
    for (int i = 0; i < 3; i++)
    {
        // iniciamos el contador
        int contadorJugPC = 0;
        for (int j = 0; j < 3; j++)
        {
            // si encontramos la jugada O, sumamos un punto.
            if (tablero[i][j] == 'O')
            {
                contadorJugPC++;
            }
            // si encontramos una jugada X, tendremos -100
            else if (tablero[i][j] == 'X')
            {
                contadorJugPC = -100;
            }
            // Si finalizamos la evaluacion y tenemos 2 puntos, significa que podremos ganar.
            if (j == 2 && contadorJugPC == 2)
            {
                // Buscamos en la misma fila la casilla que permite ganar la partida
                for (int k = 0; k < 3; k++)
                {
                    // Se encuentra dicha casilla
                    if (tablero[i][k] == '-')
                    {
                        // jugamos y ganamos
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

    /* Sigue la misma logica pero para las columnas */
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
    /* misma logica anterior */
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

/*
* Nombre de la funcion: bloquear.
* Tipo de funcion: int
* Parametros: -
* Dato de retorno: 0 o 1, enteros.
* Descripcion:  Esta funcion se ejecuta cuando el programa no puede ganar ni bloquear alguna jugada enemiga.
*               Las 2 opciones anteriormente mencionadas son las mejores jugadas disponibles, pero al no haber
*               ninguna, pues, se realiza una jugada aleatoria en cualquiera de las casillas disponibles restantes.
*               Como se genera la fila y columna por aleatoriedad, se puede demorar en jugar en alguna casilla, sobre todo
*               si hay pocas disponibles.
*/
int jugarAleatorio()
{
    bool jugado = false; // validacion para entrar en un loop
    do
    {
        srand(time(0)); // aplicamos seed
        int fila = rand() % 3;
        srand(time(0)); // renovamos la seed para que no salga el mismo numero, sin embargo, se pueden repetir
        int columna = rand() % 3;
        // Si la casilla aleatoria está disponible, se juega.
        if (tablero[fila][columna] == '-')
        {
            tablero[fila][columna] = 'O';
            jugado = true; // se sale del loop
            jugadas++;
            return 1;
        }
    } while (!jugado); //mientras no haya jugado, seguirá generando posibles jugadas.
    return 0;
}