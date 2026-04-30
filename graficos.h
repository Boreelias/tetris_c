//Funciones para dibujar los bloques con GBT

#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED

#include "juego.h"

//tamaño segun resolucion 128x128
#define TAM_BLOQUE 5  // Tamaño de cada celda en pixeles es 4x4 el bloque, sobra 1 para la sombra y que no sea una mancha de color
#define MARGEN_X 39   // Centrado horizontal (128-50)/2 =39 desplazamos los 39 pixele para centrar el tablereo
#define MARGEN_Y 4    // Margen superior para que no pegue al borde y podamos crear la pieza nueva en el tablero

//Prototipo renderiza el tablero en pantalla
void dibujarTablero(Tablero tablero);

#endif // GRAFICOS_H_INCLUDED
