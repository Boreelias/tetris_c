//Logica del juego, movimiento de las piezas, rotacion, que pasa si toca suelo y demas

#include "juego.h"

// Funcion que recorre la matriz y la llena con el color de fondo
void inicializar_Tablero(Tablero tablero)
{
    int f,c;
    for (f=0; f<FILAS; f++)
    {
        for (c=0; c<COLUMNAS; c++)
        {
            if(f==4 && c==0)//COLOREAMOS EL PRIMER BLOQUE ARRIBA A LA IZQUIERDA DE ROJO
                tablero[f][c]=4;
            else
                tablero[f][c]=14;//AMARILLO TODO EL TABLERO


        }
    }
}

//CAIDA DE PIEZAS Y COLISIONES, HACER FUNCIONES
/*
int verificar_Colision(Tablero tablero, pieza, posicionx, posiciony);
void caer_Pieza(ControlBolsa *bolsa, pieza, x, y, Tablero tablero);*/
