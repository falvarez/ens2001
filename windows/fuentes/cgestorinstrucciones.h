//cgestorinstrucciones.h

#ifndef _CGESTORINSTRUCCIONES_H
#define _CGESTORINSTRUCCIONES_H

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cinstruccion.h"
#include "cconfiguracion.h"

class CGestorInstrucciones
{
    private:
        //Clases con las que se interactua
        CConfiguracion *conf;
    public:
        //Constructor
        CGestorInstrucciones(CConfiguracion *configuracion);

        //Metodos
        CInstruccion *ObtenerInstruccion(int codop,int md1,int op1,
                                         int md2,int op2);
            //Construye el objeto correspondiente segun el codigo de operacion,
            //y le pasa los modos de direccionamiento y operandos como
            //parametro
            //Devuelve un puntero a la instruccion ejecutable
            //Si el codigo de operacion no existe, devuelve NULL

};

#endif //_CGESTORINSTRUCCIONES_H_
