/*gestionmemoria.h*/

#ifndef _GESTIONMEMORIA_H_
#define _GESTIONMEMORIA_H_

#include "compilacion.h"
#include "definiciones.h"
#include "defsc.h"

int EscribirMemoria(int direccion,int valor);
    /*Da valor a una posicion de memoria.
      Tanto direccion como valor deben estar en el rango
      0..65535.
      Devuelve 0 si la operacion fue correcta.
      Devuelve -1 si alguno de los parametros no es correcto.*/
int InicializarMemoria(void);
    /*Pone a cero todas las posiciones de memoria.
      Pone a cero el limite superior del codigo, y a 65535
      el inferior (para que se actualicen correctamente cuando
      se comience a insertar codigo).*/
int LeerMemoria(int direccion);
    /*Devuelve el contenido de una posicion de memoria.
      Devuelve -1 si la direccion no esta en el rango permitido,
      0..65535.*/
int VolcarMemoria(char *nombrefichero,int *inicio,int *fin);
    /*Vuelca el contenido de la memoria en el fichero
      especificado, y devuelve en los parametros inicio
      y fin los limites actuales del codigo.
      Devuelve 0 si la operacion fue correcta.
      Devuelve -1 si se produjo algun error al grabar
      el archivo.*/

#endif /*_GESTIONMEMORIA_H_*/
