//cinterfazdisco.h

#ifndef _CINTERFAZDISCO_H_
#define _CINTERFAZDISCO_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cmemoria.h"

class CInterfazDisco
{
    private :
        //Clases con las que interactua
        CConfiguracion *conf;

    public :
        //Constructor
        CInterfazDisco(CConfiguracion *configuracion);
        int VolcarDiscoAMemoria(CCadena fichero);
        int VolcarMemoriaADisco(CCadena fichero);
};

#endif //_CINTERFAZDISCO_H_
