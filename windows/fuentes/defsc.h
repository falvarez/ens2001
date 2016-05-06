/*Definiciones e includes para la parte C*/
#ifndef _DEFSC_H_
#define _DEFSC_H_

/*Librerias utilizadas*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Tipos de datos*/
typedef struct Instruccion{
        int codop;
        int mdir1;
        int op1;
        char *etiqueta1;
        int longitud1;
        int mdir2;
        int op2;
        char *etiqueta2;
        int longitud2;};

typedef struct EntradaTablaEtiquetas{
        char *etiqueta;
        int valor;};

typedef struct EntradaTablaConfiguracion{
        char *etiqueta;
        int posicion;
        int desplazamiento;
        int mododireccionamiento;
        int linea;};
        
typedef struct Error{
        int codigo;
        char *descripcion;
        int linea;
        char *token;
        struct Error *siguiente;};

/*Bloques de Memoria*/

#define BLOQ_TETIQ      4096 /*Tabla de etiquetas*/
#define BLOQ_TCNF       4096 /*Tabla de configuracion*/

#endif /*_DEFSC_H_S*/
