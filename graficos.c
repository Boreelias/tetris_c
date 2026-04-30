//Usar funciones de la biblioteca para mostrar bloques en pantalla


#include "graficos.h"
#include "../GBT/gbt.h"

void dibujarTablero(Tablero tablero) {
    int f, c;

    // Recorremos desde la fila 4 (las primeras 4 son del margen y para crear la pieza en el tablero)
    for (f = 4; f < FILAS; f++) {
        for (c = 0; c < COLUMNAS; c++) {

            // Si la celda no es transparente (color 15)
            if (tablero[f][c] != 15) {

                /* Calculamos la esquina superior izquierda del bloque
                   CALCULO DE POSICION EN PANTALLA:
                   xBase: Margen izquierdo + (columna actual * tamaño del bloque)
                   yBase: Margen superior + ((fila - 4) * tamaño del bloque)
                   Restamos 4 a la fila para que la fila 4 de la matriz sea la 0 en pantalla
                */
                int xBase = MARGEN_X + (c * TAM_BLOQUE);
                int yBase = MARGEN_Y + ((f - 4) * TAM_BLOQUE);

                /* DIBUJO DEL BLOQUE
                   Pintamos pixel por pixel un cuadrado de 4x4. Como el TAM_BLOQUE es 5, queda 1 pixel de margen para que no sea una mancha lisa */
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        gbt_dibujar_pixel(xBase + i, yBase + j, tablero[f][c]);
                    }
                }
            }
        }
    }
}
