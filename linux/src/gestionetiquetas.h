/*gestionetiquetas.h*/

#ifndef _GESTIONETIQUETAS_H_
#define _GESTIONETIQUETAS_H_

#include "compilacion.h"
#include "definiciones.h"
#include "defsc.h"
#include "gestionerrores.h"
#include "gestionmemoria.h"

/*TABLA DE ETIQUETAS*/
int ConsultarEtiqueta(char *etiqueta,int *valor);
    /*Devuelve el valor de la etiqueta si esta definida.
      El valor estara comprendido entre 0 y 65535.
      Devuelve -1 si la etiqueta no esta definida.*/
int DarValorEtiqueta(const char *etiqueta,int valor);
    /*Modifica el valor de la etiqueta indicada.
      Devuelve 0 si el valor de la etiqueta se almaceno correctamente.
      Devuelve -1 si la etiqueta no existe en la tabla.
      Devuelve -2 si el valor introducido no esta en el rango 0..65535.*/
int GuardarEtiqueta(const char *etiqueta,int valor);
    /*Crea una nueva entrada en la tabla de etiquetas.
      Devuelve 0 si la etiqueta se almaceno correctamente.
      Devuelve -1 si hubo algun problema de asignacion de memoria.
      Devuelve -2 si la etiqueta ya existia.
      Devuelve -3 si el identificador corresponde con una palabra reservada.
      (No se pueden redefinir etiquetas).
      Devuelve -4 si el valor introducido no esta en el rango 0..65535.*/
void InicializarTablaEtiquetas(void);
    /*Inicializa el espacio donde se almacena la tabla de etiquetas.*/
void LiberarTablaEtiquetas(void);
    /*Libera el espacio ocupado por la tabla de etiquetas.*/

/*TABLA DE CONFIGURACION*/
int EscribirTablaConfiguracion(const char *etiqueta,int posicion,
                               int desplazamiento,int mododireccionamiento,
                               int linea);
    /*Crea una nueva entrada en la tabla de configuracion.
      Devuelve 0 si la entrada se anoto correctamente.
      Devuelve -1 si hubo algun problema de asignacion de memoria.
      No se comprueba la correccion de los parametros.*/                      
void InicializarTablaConfiguracion(void);
    /*Inicializa el espacio donde se almacena la tabla de configuracion*/
void LiberarTablaConfiguracion(void);
    /*Libera el espacio ocupado por la tabla de configuracion*/
int RevisarTablaConfiguracion(void);
    /*Recorre la tabla de configuracion, y va actualizando las entradas
      en la memoria. Si encuentra algun error, informa directamente al
      gestor de errores.
      Devuelve 0 si no se encontro ningun error.
      Devuelve -1 si se encontro algun error.*/

/*DEPURACION*/
int ListaEtiquetas(void);
    /*Vuelca por pantalla la tabla de etiquetas*/
int ListaTablaConfiguracion(void);
    /*Vuelca por pantalla la tabla de configuracion*/

#endif /*_GESTIONETIQUETAS_H_*/
