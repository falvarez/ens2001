//Definiciones e includes para la parte C++

#ifndef _DEFSCPP_H_
#define _DEFSCPP_H_

#include "compilacion.h"

// Modelo de Clases

class CConfiguracion;
class CEntero16b;
class CMemoria;
class CBancoRegistros;
class CProcesador;
class CGestorInstrucciones;
class CInstruccion;
class CEntradaSalida;
class CCadena;

class CInterfazDisco;
class CDesensamblador;
class CEnsamblador;
class CGestorPuntosRuptura;

class CEnsamblador;

#ifdef _ENS2001_WINDOWS_

class CTProcesador;

class TfrmPrincipal;
class TfrmMemoria;
class TfrmRegistros;
class TfrmPila;
class TfrmFuente;
class TfrmValorRegistro;
class TfrmValorMemoria;
class TfrmConsolaEjecucion;
class TfrmConfiguracion;

#endif

// Librerias utilizadas

#include "centero16b.h"
#include "ccadena.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

#ifdef _ENS2001_WINDOWS_

#include <conio.h>
#include <dir.h>

#endif
#ifdef _ENS2001_CONSOLA_

#include <conio.h>
#include <dir.h>

#endif
#ifdef _ENS2001_LINUX_

#include <new>
#include <ctype.h>
#include <exception>

class runtime_error
{
    public:
        runtime_error(char *cad){};
        runtime_error(void){};
};

#endif

using namespace std;

#endif //_DEFSCPP_H_
