/*
Apellido: Gallardo, Elias
DNI: 43574421
Entrega: Sí/No

Apellido: Lazarte, Yaco Neyen
DNI: 40731532
Entrega: Sí/No

Apellido: Taboada, Priscila
DNI: 39986743
Entrega: Sí/No

*/

//EL BUCLE DEL JUEGO

#include <stdio.h>
#include "../GBT/gbt.h"
#include "juego.h"
#include "graficos.h"
#define ANCHO_VENTANA 128
#define ALTO_VENTANA 128
#define CANT_COLORES 16

tGBT_ColorRGB paletaCGA[CANT_COLORES] = {

    /// 0-15: Colores CGA (16 colores)
    {0x00, 0x00, 0x00}, // 0:   Negro
    {0x00, 0x00, 0xAA}, // 1:   Azul
    {0x00, 0xAA, 0x00}, // 2:   Verde
    {0x00, 0xAA, 0xAA}, // 3:   Cian
    {0xAA, 0x00, 0x00}, // 4:   Rojo
    {0xAA, 0x00, 0xAA}, // 5:   Magenta
    {0xAA, 0x55, 0x00}, // 6:   Marron
    {0xAA, 0xAA, 0xAA}, // 7:   Gris claro
    {0x55, 0x55, 0x55}, // 8:   Gris oscuro
    {0x55, 0x55, 0xFF}, // 9:   Azul brillante
    {0x55, 0xFF, 0x55}, // 10:  Verde brillante
    {0x55, 0xFF, 0xFF}, // 11:  Cian brillante
    {0xFF, 0x55, 0x55}, // 12:  Rojo brillante
    {0xFF, 0x55, 0xFF}, // 13:  Magenta brillante
    {0xFF, 0xFF, 0x55}, // 14:  Amarillo
    {0xFF, 0xFF, 0xFF}  // 15:  Usado como transparente por GBT
};

int main() {
    //Inicializacion de la biblioteca grafica GBT
    gbt_iniciar();
    //Creacion de la ventana (Nombre Ventana, Ancho, Alto, Escala)
    gbt_crear_ventana("Tetris C", ANCHO_VENTANA, ALTO_VENTANA, 7);

    //Aplicacion de la paleta de colores por defecto (CGA/VGA)
    //Se usa NULL para que la libreria cargue sus colores base
    gbt_aplicar_paleta(paletaCGA, CANT_COLORES, 0);

    //Declaracion e inicializacion del tablero logico
    Tablero miTablero;
    inicializarTablero(miTablero);

    /*COPIA DE TEMPORIZADOR

    tGBT_Temporizador *temporizador = gbt_temporizador_crear(1.0);
    if (!temporizador) {
        fprintf(stderr, "Error al crear el temporizador para los dibujos: %s\n", gbt_obtener_log());
        return -1;
    }*/

    // QUEDA RANDOMIZADOR DE PIEZA, CONTROLAR EL SACAR TODAS LAS PIEZAS 1,2,3,4,5,6,7,8 Y VOLVER A EMPEZAR

    int corriendo = 1;
    while (corriendo) {
        gbt_procesar_entrada();
        if (gbt_tecla_presionada(GBTK_ESCAPE)) corriendo = 0;

        gbt_borrar_backbuffer(0); // Limpiar pantalla (negro)

        dibujarTablero(miTablero); // Dibujar el estado actual

        gbt_volcar_backbuffer(); //Envia a pantalla lo dibujado
        gbt_esperar(16); // Aproximadamente 60 FPS
    }


    gbt_destruir_ventana();
    gbt_cerrar();
    return 0;
}
