//centradasalida.h VERSION WINDOWS

#ifndef _CENTRADASALIDA_H_
#define _CENTRADASALIDA_H_

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
#include "ctprocesador.h"

class CEntradaSalida
{
	private :
		//Clases con las que se interactua
		CConfiguracion *conf;
                CTProcesador *thread_procesador;
	public :
		//Constructor
		CEntradaSalida(CConfiguracion *configuracion);

                void EscribirHilo(CTProcesador *hilo);
		//Metodos
		int Leer(CEntero16b &entero);
		int Leer(char &caracter);
		int Leer(CCadena &cadena);
		
		int Escribir(CEntero16b entero);
		int Escribir(char caracter);
		int Escribir(CCadena cadena);	
};
#endif //_CENTRADASALIDA_H_
