//centradasalida.h

#ifndef _CENTRADASALIDA_H_
#define _CENTRADASALIDA_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#include "ctprocesador.h"
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"

class CEntradaSalida
{
    private:
        //Clases con las que se interactua
        CConfiguracion *conf;

#ifdef _ENS2001_WINDOWS_
	CTProcesador *thread_procesador;
#endif
#ifdef _ENS2001_CONSOLA_
        bool LeerEntrada(CCadena &entrada);
#endif
#ifdef _ENS2001_MACOS_
	bool LeerEntrada(CCadena &entrada);
#endif
        
    public:
        //Constructor
        CEntradaSalida(CConfiguracion *configuracion);
        
#ifdef _ENS2001_WINDOWS_
	void EscribirHilo(CTProcesador *hilo);
#endif
        //Metodos
        int Leer(CEntero16b &entero);
        int Leer(char &caracter);
        int Leer(CCadena &cadena);

        int Escribir(CEntero16b entero);
        int Escribir(char caracter);
        int Escribir(CCadena cadena);
};

#endif //_CENTRADASALIDA_H_
