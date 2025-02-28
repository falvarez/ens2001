/*funcionesauxiliares.h*/

#ifndef _FUNCIONESAUXILIARES_H_
#define _FUNCIONESAUXILIARES_H_

#include "compilacion.h"
#include "definiciones.h"
#include "defsc.h"

#include "gestionerrores.h"
int ComprobarOperando(int mdir,int op);
int ComprobarInstruccion(int codop,int mdir1,int op1,int mdir2,int op2);
    /*Comprueba que los operandos se ajustan a los modos de direccionamiento
      permitidos para cada instruccion.*/
char *CopiarCadena(char *origen,int caracteres);
int Decimal(char *entrada,int bits);
    /*Devuelve el valor decimal de la cadena decimal introducida,
      si es representable en complemento a 2 con el numero de bits
      indicado, si no devuelve -1.
      Si el numero de bits indicado es menor que 1, devuelve -2.*/
char *EnteroACadena(int entero,int base);
    /*Reserva por si misma espacio en memoria con malloc*/
int EsPalabraReservada(const char *identificador);
int Hexadecimal(char *entrada,int bits);
    /*Devuelve el valor decimal de la cadena hexadecimal introducida,
      si es representable en complemento a 2 con el numero de bits
      indicado, si no devuelve -1.
      Si el numero de bits indicado es menor que 1, devuelve -2.
      Las cadenas hexadecimales son de la forma "Ox....".*/
int LiberarListaTokens(void);
char *ConsultarToken(int num);
    /*Devuelve el token num de la lista.
      Si num=0, devuelve el ultimo*/
int NuevoToken(char *token);
void ListarTokens(void);

#endif /*_FUNCIONESAUXILIARES_H_*/
