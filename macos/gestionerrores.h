/*gestionerrores.h*/
#ifndef _GESTIONERRORES_H_
#define _GESTIONERRORES_H_

#include "compilacion.h"
#include "definiciones.h"
#include "defsc.h"
#include _CADENAS_H_
#include "funcionesauxiliares.h"

int InformarError(int codigo,int linea,char *token);
    /*Inserta un error por linea. Si ya hay uno lo descarta.
      Inserta los errores ordenados por linea.
      Añade la descripcion correspondiente al error.
      Devuelve 0 si la entrada se anoto correctamente.
      Devuelve -1 si hubo algun problema de asignacion de memoria.*/
void InicializarListaErrores(void);
    /*Inicializa el espacio para almacenar la lista de errores.*/
void LiberarListaErrores(void);
    /*Libera el espacio ocupado por la lista de errores.*/
int ListarErrores(char *nombrefichero);
    /*Abre el fichero de errores y lo saca por consola.
      Devuelve 0 si todo ha ido bien.
      Devuelve -1 si no pudo abrir el fichero.*/
int VolcarFicheroErrores(char *nombrefichero);
    /*Vuelca la lista de errores en el fichero indicado.
      Devuelve 0 si todo ha ido bien.
      Devuelve -1 si no se pudo crear el fichero.*/

#endif /*_GESTIONERRORES_H_*/
