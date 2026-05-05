#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "piezas.h"

//Dimensiones del tablero de Tetris
#define FILAS 24 //20 altura + 4 para la creacion de los tetrominos
#define COLUMNAS 10
#define TAM_PIEZA 4


//Declaracion del tablero como matriz y de la pieza como matriz
typedef int Tablero[FILAS][COLUMNAS];


//Portotipo funcion para el tablero
void inicializar_Tablero(Tablero matrizTablero);


//Prototipos de funciones de Movimiento
/*
int verificar_Colision(Tablero tablero, pieza, posicionx, posiciony);
void caer_Pieza(ControlBolsa *bolsa, pieza, x, y, Tablero tablero);*/



#endif //JUEGO_H_INCLUDED
