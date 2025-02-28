//cdesensamblador.h

#ifndef _CDESENSAMBLADOR_H_
#define _CDESENSAMBLADOR_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include _CADENAS_H_
#include "cconfiguracion.h"

extern "C" int ComprobarInstruccion(int codop,int mdir1,int op1,
                                    int mdir2,int op2);

class CDesensamblador
{
    private :
        //Metodos auxiliares
        void FetchOperandos(CEntero16b &dir,int md1,CEntero16b &op1,
                            int md2,CEntero16b &op2);
        //Clases con las que interactua
        CConfiguracion *conf;
    public :
        //Constructor
        CDesensamblador(CConfiguracion *configuracion);
        //Metodos
        void Desensamblar(CEntero16b &dirinicio,CCadena &instruccion);
            //Desensambla una instruccion y actualiza la posicion
            //de memoria donde comienza la siguiente instruccion
            //En instruccion se almacena la instruccion desensamblada
};

#endif //_CDESENSAMBLADOR_H_
