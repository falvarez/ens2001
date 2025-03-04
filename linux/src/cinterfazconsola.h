//cinterfazconsola.h

#ifndef _CINTERFAZCONSOLA_H_
#define _CINTERFAZCONSOLA_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include _CADENAS_H_
#include "cconfiguracion.h"
#include "cdesensamblador.h"
#include "censamblador.h"
#include "cinterfazdisco.h"

extern "C" int ListarErrores(const char *nombrefichero);

class CInterfazConsola
{
    private :
        //Clases con las que se interactua
        CConfiguracion *conf;

        //Metodos auxiliares
        void ExtraerComando(char *entrada,char &comando,CCadena &parametro1,
                            CCadena &parametro2,int &nparametros);
        //Comandos
        int Ayuda(void);
        int Base(CCadena valor);
        int CargarMemoria(CCadena fichero);
        int Desensamblar(CCadena dir,CCadena num);
        int Ejecutar(void);
        int Ensamblar(CCadena fichero);
        int EscribirMemoria(CCadena direccion,CCadena valor);
        int EscribirRegistro(CCadena registro,CCadena valor);
        int EstadoSimulador(void);
        int GuardarMemoria(CCadena fichero);
        int IntercambiarComprobarPC(void);
        int IntercambiarComprobarPila(void);
        int IntercambiarModoPasoAPaso(void);
        int IntercambiarModoPila(void);
        int IntercambiarPararPuntosRuptura(void);
        int IntercambiarPuntoRuptura(CCadena direccion);
        int IntercambiarReiniciarRegistros(void);
        void LeerBancoRegistros(void);
        int LeerMemoria(CCadena direccion);
        int LeerRegistro(CCadena registro);
        int Salir(void);
        int VolcarBloqueMemoria(CCadena dir,CCadena num);
        int VolcarPila(CCadena num);

    public :
        //Constructor
        CInterfazConsola(CConfiguracion *configuracion);
        //Metodos
        int LeerComandos(void);
        int EnsamblarLineaComando(CCadena fichero);
		int EstadoInicialSimulador(void);        
};

#endif //_CINTERFAZCONSOLA_H_
