// ens2001.cpp (programa principal modo consola)
#ifndef _ENS2001_CPP_
#define _ENS2001_CPP_

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include _CADENAS_H_

#include "cprocesador.h"
#include "cmemoria.h"
#include "cbancoregistros.h"
#include "cconfiguracion.h"
#include "centradasalida.h"
#include "cgestorpuntosruptura.h"
#include "cinterfazconsola.h"

int main(int argc,char *argv[])
{
    try
    {
        CConfiguracion *conf=new CConfiguracion;
        CMemoria *m=new CMemoria(conf);
        CBancoRegistros *b=new CBancoRegistros(conf);
        CProcesador *p=new CProcesador(conf);
        CEntradaSalida *es=new CEntradaSalida(conf);
        CGestorPuntosRuptura *gpr=new CGestorPuntosRuptura(conf);
        CInterfazConsola *ifaz=new CInterfazConsola(conf);

        cout<<TITULO<<endl;
        cout<<S_CADENA_094<<VERSION<<" - "<<FECHA<<endl;
        cout<<URL<<endl<<endl;
        
        if(conf->CargarConfiguracion()!=0)
        {
            //Se usaron las opciones por defecto
            cout<<"Fichero de configuracion (ens2001.cfg) ";
            cout<<"no encontrado o erroneo"<<endl;
            cout<<"Se usaran las opciones por defecto"<<endl;
        }
        else
        {
            cout<<"Fichero de configuracion (ens2001.cfg) ";
            cout<<"cargado con exito"<<endl;
        }
        cout<<endl;
        ifaz->EstadoInicialSimulador();

        b->Reiniciar();
        m->Reiniciar();

        if (argc>1)
        {
            //El primer argumento es el nombre de fichero
            //que ensamblaremos directamente
            ifaz->EnsamblarLineaComando(argv[1]);
        }
        ifaz->LeerComandos();

        delete(ifaz);
        delete(gpr);
        delete(es);
        delete(p);
        delete(b);
        delete(m);
        delete(conf);

        //Eliminamos los posibles archivos temporales que se hayan
        //creado
        remove(FICHERO_TEMPORAL_FUENTE); //Codigo fuente
        remove(FICHERO_TEMPORAL_MEMORIA); //Imagen de memoria
        remove(FICHERO_TEMPORAL_ERRORES); //Listado de errores

        return 0;
    }
    catch(bad_alloc)
    {
        cerr<<"ERROR: Al reservar espacio dinamico"<<endl;
        return -1;
    }
    catch(runtime_error)
    {
        cerr<<"ERROR: En tiempo de ejecucion no contemplado"<<endl;
        return -1;
    }
}

#endif //_ENS2001_CPP_
