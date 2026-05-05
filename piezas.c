//Piezas creacion, randomizador


#include <time.h>
#include <stdlib.h>
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

//PIEZAS
// I
Pieza pieza_I =
{
    {N, N, N, N},
    {C, C, C, C},
    {N, N, N, N},
    {N, N, N, N}
};
// O
Pieza pieza_O =
{
    {N, N, N, N},
    {N, A, A, N},
    {N, A, A, N},
    {N, N, N, N}
};
// T
Pieza pieza_T =
{
    {N, M, N, N},
    {M, M, M, N},
    {N, N, N, N},
    {N, N, N, N}
};
// S
Pieza pieza_S =
{
    {N, V, V, N},
    {V, V, N, N},
    {N, N, N, N},
    {N, N, N, N}
};
// Z
Pieza pieza_Z =
{
    {R, R, N, N},
    {N, R, R, N},
    {N, N, N, N},
    {N, N, N, N}
};
// J
Pieza pieza_J =
{
    {B, N, N, N},
    {B, B, B, N},
    {N, N, N, N},
    {N, N, N, N}
};
// L
Pieza pieza_L =
{
    {N, N, L, N},
    {L, L, L, N},
    {N, N, N, N},
    {N, N, N, N}
};

/*typedef struct {
    int vectorBolsa[7];//BOLSA DE VECTOR
    int ultimaPiezaEntregada;
    int bolsaVacia;//0 SI , 1 NO
} ControlBolsa;*/

//RANDOMIZADOR DE PIEZAS
void inicializar_Control_Bolsa(ControlBolsa *control)
{
    //Iniciamos La ultima pieza fuera de rango (piezasa entre 0 y 6)
    control->ultimaPiezaEntregada=-1;
    //Mezclamos la bolsa
    Mezclar_Bolsa(control);
}

void Mezclar_Bolsa(ControlBolsa *control)
{
    int piezas[7]= {0,1,2,3,4,5,6};
    int auxpieza,i,j;

    if(control->bolsaVacia==0)//control por si entramos aca sin terminar las piezas
    {

        //Mezclamos las piezas (7)
        for(i=0; i<7; i++)
        {
            j=rand()%(i+1);
            auxpieza= piezas[i];
            piezas[i]=piezas[j];
            piezas[j]=auxpieza;
        }
        //Evitamos que la primera pieza de la nueva bolsa sea igual a la ultima de la vieja bolsa
        if(piezas[0]==control->ultimaPiezaEntregada)
        {
            auxpieza=piezas[0];
            piezas[0]=piezas[6];
            piezas[6]=auxpieza;
        }
        //Copiamos vector en el vector de la estructura
        for(i=0; i<7; i++)
        {
            control->vectorBolsa[i]=piezas[i];
        }
        //Control de cantidad de piezas en el vector
        control->bolsaVacia=7;
    }
}

int obtener_Proxima_Pieza(ControlBolsa *control)
{
    int indice,piezaAEntregar;
    //Si no quedan piezas (contador en 0), mezclamos una nueva bolsa
    if (control->bolsaVacia==0)
    {
        Mezclar_Bolsa(control);
    }
    //Calculamos el Indice de pieza a entregar
    //Si bolsaVacia es 7, entregamos la posicion 0
    //Si bolsaVacia es 6, entregamos la posicion 1
    indice=7-control->bolsaVacia;
    piezaAEntregar=control->vectorBolsa[indice];

    //Actualizamos el estado para la proxima vez
    control->ultimaPiezaEntregada=piezaAEntregar;
    control->bolsaVacia--;//Restamos 1 al contador de piezas de la bolsa

    return piezaAEntregar;
}
