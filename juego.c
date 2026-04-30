//Logica del juego, movimiento de lasa piezas, rotacion, que pasa si toca suelo y demas

#include "juego.h"

//Colores
#define N 15 // Transparente (Fondo)
#define A 14 // Amarillo (O)
#define C 3  // Cian/Celeste (I)
#define V 2  // Verde(S)
#define R 4  // Rojo (Z)
#define M 5  // Magenta/Purpura (T)
#define B 1  // Azul (J)
#define L 6  // Marron/Naranja (L)

// Funcion que recorre la matriz y la llena con el color de fondo
void inicializarTablero(Tablero tablero) {
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            tablero[f][c] = N; // Llenamos de vacio (N=15) Transparente
        }
    }
}

//PIEZAS
// I
Pieza pieza_I = {
    {N, N, N, N},
    {C, C, C, C},
    {N, N, N, N},
    {N, N, N, N}
};
// O
Pieza pieza_O = {
    {N, N, N, N},
    {N, A, A, N},
    {N, A, A, N},
    {N, N, N, N}
};
// T
Pieza pieza_T = {
    {N, M, N, N},
    {M, M, M, N},
    {N, N, N, N},
    {N, N, N, N}
};
// S
Pieza pieza_S = {
    {N, V, V, N},
    {V, V, N, N},
    {N, N, N, N},
    {N, N, N, N}
};
// Z
Pieza pieza_Z = {
    {R, R, N, N},
    {N, R, R, N},
    {N, N, N, N},
    {N, N, N, N}
};
// J
Pieza pieza_J = {
    {B, N, N, N},
    {B, B, B, N},
    {N, N, N, N},
    {N, N, N, N}
};
// L
Pieza pieza_L = {
    {N, N, L, N},
    {L, L, L, N},
    {N, N, N, N},
    {N, N, N, N}
};

