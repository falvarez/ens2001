//centradasalida.cpp VERSION WINDOWS
#include "centradasalida.h"

//Constructor
CEntradaSalida::CEntradaSalida(CConfiguracion *configuracion)
{
	conf=configuracion;
	conf->EscribirEntradaSalida(this);
	return;
}

//Metodos
int CEntradaSalida::Leer(CEntero16b &entero)
{	
	//Si lee un entero no valido, recoge un valor 0
        thread_procesador->Leer(entero);
	return EJ_SIGUIENTE;
}

int CEntradaSalida::Leer(char &caracter)
{
        thread_procesador->Leer(caracter);
	return EJ_SIGUIENTE;
}

int CEntradaSalida::Leer(CCadena &cadena)
{
        thread_procesador->Leer(cadena);
     	return EJ_SIGUIENTE;
}

int CEntradaSalida::Escribir(CEntero16b entero)
{
        thread_procesador->Escribir(entero);
	return EJ_SIGUIENTE;
}

int CEntradaSalida::Escribir(char caracter)
{
        thread_procesador->Escribir(caracter);
	return EJ_SIGUIENTE;
}

int CEntradaSalida::Escribir(CCadena cadena)
{
        thread_procesador->Escribir(cadena);
	return EJ_SIGUIENTE;
}

void CEntradaSalida::EscribirHilo(CTProcesador *hilo)
{
        thread_procesador=hilo;
}
