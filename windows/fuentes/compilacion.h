//compilacion.h

#ifndef _COMPILACION_H_
#define _COMPILACION_H_

//Para evitar el error Stack Overflow
#define YYMAXDEPTH 2000000

//VERSION GRAFICA WINDOWS
/*
#define _ENS2001_WINDOWS_
#define _CADENAS_H_ "cadenas_ansi.h"
#define TITULO "ENS2001 para Windows (32 bits)"
#define VERSION "1.0"
#define FECHA "Febrero 2003"
#define URL "http://usuarios.lycos.es/ens2001"
#define _IDIOMA_ESPANOL_
*/
//VERSION CONSOLA WINDOWS

#define _ENS2001_CONSOLA_
#define _CADENAS_H_ "cadenas_ascii.h"
#define TITULO "ENS2001 para consola Windows (32 bits)"
#define VERSION "1.0"
#define FECHA "Febrero 2003"
#define URL "http://usuarios.lycos.es/ens2001"
#define _IDIOMA_ESPANOL_

//VERSION LINUX
/*
#define _ENS2001_LINUX_
#define _CADENAS_H_ "cadenas_ascii.h"
#define TITULO "ENS2001 para GNU/Linux (32 bits)"
#define VERSION "1.0"
#define FECHA "Febrero 2003"
#define URL "http://usuarios.lycos.es/ens2001"
#define _IDIOMA_ESPANOL_
*/
#endif //_COMPILACION_H_
