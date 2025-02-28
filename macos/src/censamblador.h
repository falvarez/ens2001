//censamblador.h

#ifndef _CENSAMBLADOR_H_
#define _CENSAMBLADOR_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
#include "ens_tab.h"

extern "C" int Ens(const char *fichero,int *lineas,
                   int *codigoinicio,int *codigofin);

class CEnsamblador
{
    private :
        //Clases con las que interactua
        CConfiguracion *conf;
    public :
        //Constructor
        CEnsamblador(CConfiguracion *configuracion);
        //Metodos
        int Ensamblar(CCadena fichero,int &lineas);
            //Sirve de interfaz con el ensamblador generado por 
            //Flex y Bison.
            //Devuelve el resultado del proceso de ensamblado, que puede
            //ser:
            //   0 si se genero codigo
	    //	-1 si no se genero codigo
	    //	-2 si hubo algun error al leer el fichero
	    //	-3 si hubo algun error al escribir el fichero memoria.tmp
	    //	-4 si hubo algun error al volcar el fichero errores.tmp
	    //  -5 si hubo algun error al generar el fichero fuente.tmp
};

#endif //_CENSAMBLADOR_H_
