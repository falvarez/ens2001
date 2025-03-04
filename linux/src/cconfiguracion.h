//cconfiguracion.h
#ifndef _CCONFIGURACION_H_
#define _CCONFIGURACION_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cmemoria.h"
#include "cbancoregistros.h"
#include "cprocesador.h"
#include "cgestorpuntosruptura.h"

class CConfiguracion
{
    private:
        //Atributos
        CMemoria *memoria;
        CBancoRegistros *registros;
        CProcesador *procesador;
        CGestorPuntosRuptura *gestorpuntosruptura;
        CEntradaSalida *entradasalida;

        int modoejecucion;
        int modopila;
        int mododepuracion;
        int basenumerica;
        int comprobarpc;
        int comprobarpila;
        int reiniciarregistros;
        
        CCadena directorioactual;

        //Metodos auxiliares
        int ActualizarParametro(char *variable,char *valor);

    public:
        //Constructor
        CConfiguracion(void);
        //Metodos de acceso a los atributos
        int ModoEjecucion(void);
        void EscribirModoEjecucion(int valor);

        int ModoPila(void);
        void EscribirModoPila(int valor);

        int ModoDepuracion(void);
        void EscribirModoDepuracion(int valor);

        int BaseNumerica(void);
        void EscribirBaseNumerica(int valor);

        int ComprobarPC(void);
        void EscribirComprobarPC(int valor);

        int ComprobarPila(void);
        void EscribirComprobarPila(int valor);

        int ReiniciarRegistros(void);
        void EscribirReiniciarRegistros(int valor);
        
        CCadena DirectorioActual(void);
        void EscribirDirectorioActual(CCadena valor);

        void EscribirMemoria(CMemoria *mem);
        CMemoria *Memoria(void);

        void EscribirBancoRegistros(CBancoRegistros *regs);
        CBancoRegistros *BancoRegistros(void);

        void EscribirProcesador(CProcesador *proc);
        CProcesador *Procesador(void);

        void EscribirGestorPuntosRuptura(CGestorPuntosRuptura *gpr);
        CGestorPuntosRuptura *GestorPuntosRuptura(void);

        void EscribirEntradaSalida(CEntradaSalida *es);
        CEntradaSalida *EntradaSalida(void);
        
        //Metodos
        int CargarConfiguracion(void);
            //Devuelve 0 si se ha cargado el fichero
            //ens2001.cfg y es correcto
            //Devuelve -1 en caso contrario
        int GuardarConfiguracion(void);
            //Devuelve 0 si se ha grabado el fichero
            //ens2001.cfg correctamente
            //Devuelve -1 si hubo algun problema al guardar
            //el fichero
};

#endif //_CCONFIGURACION_H_
