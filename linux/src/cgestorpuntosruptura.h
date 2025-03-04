//cgestorpuntosruptura.h

#ifndef _CGESTORPUNTOSRUPTURA_H_
#define _CGESTORPUNTOSRUPTURA_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
#include "centero16b.h"

class CGestorPuntosRuptura
{
    private:
        //Atributos
        bool direcciones[MAXINT+1];
        //Clases con las que interactura
        CConfiguracion *conf;

    public:
        //Constructor
        CGestorPuntosRuptura(CConfiguracion *configuracion);
        //Metodos
        int Consultar(CEntero16b direccion);
            //Devuelve 1 si el punto de ruptura esta activado
            //y 0 si no lo esta
        int Intercambiar(CEntero16b direccion);
            //Cambia el estado del punto de ruptura entre activado
            //y desactivado
        void Reiniciar(void);
            //Anula todos los puntos de ruptura existentes
};

#endif //_CGESTORPUNTOSRUPTURA_H_
