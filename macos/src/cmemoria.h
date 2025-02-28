// cmemoria.h

#ifndef _CMEMORIA_H_
#define _CMEMORIA_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"

class CMemoria
{
    private:
        //Atributos
        CEntero16b celdas[MAXINT+1];
        //Clases con las que se interactua
        CConfiguracion *conf;

    public:
        //Constructor
        CMemoria(CConfiguracion *configuracion);
            //Inicializa todas las posiciones de memoria a cero
        //Metodos
        void Escribir(CEntero16b direccion,CEntero16b valor);
            //Escribe un valor en una direccion de memoria
            //direccion: direccion entero
            //valor: valor numerico a introducir en memoria
        void Leer(CEntero16b direccion,CEntero16b &valor);
            //Lee el valor contenido en una direccion de memoria
            //direccion: direccion entero
            //valor: valor numerico que se recupera de memoria
        void Reiniciar(void);
};

#endif //_CMEMORIA_H_
