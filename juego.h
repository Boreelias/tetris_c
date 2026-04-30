//MATRICES DE PIEZAS Y TETROMINOS
#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
//Dimensiones del tablero de Tetris
#define FILAS 24 //20 altura + 4 para la creacion de los tetrominos
#define COLUMNAS 10
#define TAM_PIEZA 4

//Declaracion del tablero como matriz y de la pieza como matriz
typedef int Tablero[FILAS][COLUMNAS];
typedef int Pieza[TAM_PIEZA][TAM_PIEZA];


//Portotipo funcion para el tablero
void inicializarTablero(Tablero acavaeltableromatriz);


#endif //JUEGO_H_INCLUDED
