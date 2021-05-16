//cprocesador.h

#ifndef _CPROCESADOR_H_
#define _CPROCESADOR_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
#include "cinstruccion.h"
#include "cgestorinstrucciones.h"

extern "C" int ComprobarInstruccion(int codop,int mdir1,int op1,
                                    int mdir2,int op2);

class CProcesador
{
    private:
        //Clases con las que interactua
        CConfiguracion *conf;
        //Funciones Auxiliares
        void FetchInstruccion(CEntero16b &codop);
        void FetchOperandos(int md1,int &op1,int md2,int &op2);
        CEntero16b contadordeprograma; //PC manejado internamente

    public:
        //Constructor
        CProcesador(CConfiguracion *configuracion);
        //Metodos
        int Ejecutar(void);
            //Ejecuta el programa contenido en memoria
            //a partir de la direccion indicada por PC
        int EjecutarPaso(void);
            //Ejecuta una instruccion del programa contenido
            //en memoria a partir de la direccion indicada por PC
};

#endif //_CPROCESADOR_H_
