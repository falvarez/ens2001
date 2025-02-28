//cconfiguracion.cpp
#include "cconfiguracion.h"
//---------------------------------------------------------------------------
int CConfiguracion::ActualizarParametro(char *variable,char *valor)
{
    if(strcmp(variable,"ModoEjecucion")==0)
    {
        if(strcmp(valor,"NORMAL")==0)
        {
            EscribirModoEjecucion(ME_NORMAL);
        }
        else if(strcmp(valor,"PASOAPASO")==0)
        {
            EscribirModoEjecucion(ME_PASOAPASO);
        }
        else
        {
            //Valor incorrecto
            return -1;
        }
        return 0;
    }
    if(strcmp(variable,"ModoPila")==0)
    {
        if(strcmp(valor,"CRECIENTE")==0)
        {
            EscribirModoPila(PILA_CRECIENTE);
        }
        else if(strcmp(valor,"DECRECIENTE")==0)
        {
            EscribirModoPila(PILA_DECRECIENTE);
        }
        else
        {
            //Valor incorrecto
            return -1;
        }
        return 0;
    }
    if(strcmp(variable,"ModoDepuracion")==0)
    {
        if(strcmp(valor,"SI")==0)
        {
            EscribirModoDepuracion(SI);
        }
        else if(strcmp(valor,"NO")==0)
        {
            EscribirModoDepuracion(NO);
        }
        else
        {
            //Valor incorrecto
            return -1;
        }
        return 0;
    }
    if(strcmp(variable,"BaseNumerica")==0)
    {
        if(strcmp(valor,"DECIMAL")==0)
        {
            EscribirBaseNumerica(10);
        }
        else if(strcmp(valor,"HEXADECIMAL")==0)
        {
            EscribirBaseNumerica(16);
        }
        else
        {
            //Valor incorrecto
            return -1;
        }
        return 0;
    }
    if(strcmp(variable,"ComprobarPC")==0)
    {
        if(strcmp(valor,"SI")==0)
        {
            EscribirComprobarPC(SI);
        }
        else if(strcmp(valor,"NO")==0)
        {
            EscribirComprobarPC(NO);
        }
        else
        {
            //Valor incorrecto
            return -1;
        }
        return 0;
    }
    if(strcmp(variable,"ComprobarPila")==0)
    {
        if(strcmp(valor,"SI")==0)
        {
            EscribirComprobarPila(SI);
        }
        else if(strcmp(valor,"NO")==0)
        {
            EscribirComprobarPila(NO);
        }
        else
        {
            //Valor incorrecto
            return -1;
        }
        return 0;
    }
    if(strcmp(variable,"ReiniciarRegistros")==0)
    {
        if(strcmp(valor,"SI")==0)
        {
            EscribirReiniciarRegistros(SI);
        }
        else if(strcmp(valor,"NO")==0)
        {
            EscribirReiniciarRegistros(NO);
        }
        else
        {
            //Valor incorrecto
            return -1;
        }
        return 0;
    }
    if(strcmp(variable,"DirectorioActual")==0)
    {
    	EscribirDirectorioActual(CCadena(valor));
        return 0;
    }
    return -1;
}
//---------------------------------------------------------------------------
CBancoRegistros *CConfiguracion::BancoRegistros(void)
{
    return registros;
}
//---------------------------------------------------------------------------
int CConfiguracion::BaseNumerica(void)
{
    return basenumerica;
}
//---------------------------------------------------------------------------
int CConfiguracion::CargarConfiguracion(void)
{
    ifstream entrada;
    char caracter;
    CCadena nombrevariable;
    CCadena valorvariable;
    int comentario=0;
    int variable=0;
    int error;

    entrada.open(FICHERO_CONFIGURACION);
    if(entrada!=NULL)
    {
        while(entrada.get(caracter))
        {
            if(caracter==';')
            {
                comentario=1;
            }
            else if(caracter=='\n')
            {
                if (comentario==0)
                {
                    error=ActualizarParametro(nombrevariable.Cadena(),
                                              valorvariable.Cadena());
                    if(error!=0)
                    {
                        return -1;
                    }
                }
                comentario=0;
                variable=0;
                nombrevariable=CCadena("");
                valorvariable=CCadena("");
            }
            else if(caracter=='=')
            {
                variable=1;
            }
            else if(comentario==0)
            {
                if(isalpha(caracter) || (caracter==':') || (caracter=='\\'))
                {
                    switch(variable)
                    {
                        case 0 : nombrevariable=nombrevariable+caracter;
                                 break;
                        case 1 : valorvariable=valorvariable+caracter;
                                 break;
                    }
                }
            }

        }
        return 0;
    }
    else
    {
        //Error al abrir el fichero
        return -1;
    }
}
//---------------------------------------------------------------------------
int CConfiguracion::ComprobarPC(void)
{
    return comprobarpc;
}
//---------------------------------------------------------------------------
int CConfiguracion::ComprobarPila(void)
{
    return comprobarpila;
}
//---------------------------------------------------------------------------
CConfiguracion::CConfiguracion(void)
{
    //Inicializacion de atributos
    memoria=NULL;
    registros=NULL;
    procesador=NULL;
    gestorpuntosruptura=NULL;
    entradasalida=NULL;

    //Configuracion por defecto
    modoejecucion=ME_NORMAL;
    modopila=PILA_DECRECIENTE;
    mododepuracion=SI;
    basenumerica=BASE_DECIMAL;
    comprobarpc=NO;
    comprobarpila=NO;
    reiniciarregistros=SI;
    
    directorioactual=CCadena(".");

    return;
}
//---------------------------------------------------------------------------
CEntradaSalida *CConfiguracion::EntradaSalida(void)
{
    return entradasalida;
}
//---------------------------------------------------------------------------
CCadena CConfiguracion::DirectorioActual(void)
{
    return directorioactual;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirBancoRegistros(CBancoRegistros *regs)
{
    registros=regs;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirBaseNumerica(int valor)
{
    basenumerica=valor;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirComprobarPC(int valor)
{
    comprobarpc=valor;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirComprobarPila(int valor)
{
    comprobarpila=valor;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirDirectorioActual(CCadena valor)
{
    directorioactual=valor;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirEntradaSalida(CEntradaSalida *es)
{
    entradasalida=es;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirGestorPuntosRuptura(CGestorPuntosRuptura *gpr)
{
    gestorpuntosruptura=gpr;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirMemoria(CMemoria *mem)
{
    memoria=mem;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirModoDepuracion(int valor)
{
    mododepuracion=valor;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirModoEjecucion(int valor)
{
    modoejecucion=valor;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirModoPila(int valor)
{
    modopila=valor;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirProcesador(CProcesador *proc)
{
    procesador=proc;
    return;
}
//---------------------------------------------------------------------------
void CConfiguracion::EscribirReiniciarRegistros(int valor)
{
    reiniciarregistros=valor;
    return;
}
//---------------------------------------------------------------------------
CGestorPuntosRuptura *CConfiguracion::GestorPuntosRuptura(void)
{
    return gestorpuntosruptura;
}
//---------------------------------------------------------------------------
int CConfiguracion::GuardarConfiguracion(void)
{
    ofstream salida;

    salida.open(FICHERO_CONFIGURACION);
    if(salida!=NULL)
    {
        salida.write("DirectorioActual=",17);
        salida.write(directorioactual.Cadena(),strlen(directorioactual.Cadena()));
        salida.write("\n",1);
        salida.write("ModoEjecucion=",14);
        switch(ModoEjecucion())
        {
            case ME_NORMAL :    salida.write("NORMAL",6);
                                break;
            case ME_PASOAPASO : salida.write("PASOAPASO",9);
                                break;
        }
        salida.write("\n",1);
        salida.write("ModoPila=",9);
        switch(ModoPila())
        {
            case PILA_CRECIENTE :   salida.write("CRECIENTE",9);
                                    break;
            case PILA_DECRECIENTE : salida.write("DECRECIENTE",11);
                                    break;
        }
        salida.write("\n",1);
        salida.write("ModoDepuracion=",15);
        switch(ModoDepuracion())
        {
            case NO : salida.write("NO",2);
                      break;
            case SI : salida.write("SI",2);
                      break;
        }
        salida.write("\n",1);
        salida.write("BaseNumerica=",13);
        switch(BaseNumerica())
        {
            case 10 : salida.write("DECIMAL",7);
                      break;
            case 16 : salida.write("HEXADECIMAL",11);
                      break;
        }
        salida.write("\n",1);
        salida.write("ComprobarPC=",12);
        switch(ComprobarPC())
        {
            case NO : salida.write("NO",2);
                      break;
            case SI : salida.write("SI",2);
                      break;
        }
        salida.write("\n",1);
        salida.write("ComprobarPila=",14);
        switch(ComprobarPila())
        {
            case NO : salida.write("NO",2);
                      break;
            case SI : salida.write("SI",2);
                      break;
        }
        salida.write("\n",1);
        salida.write("ReiniciarRegistros=",19);
        switch(ReiniciarRegistros())
        {
            case NO : salida.write("NO",2);
                      break;
            case SI : salida.write("SI",2);
                      break;
        }
        salida.write("\n",1);
        return 0;
    }
    else
    {
        //Error al abrir el fichero
        return -1;
    }
}
//---------------------------------------------------------------------------
CMemoria *CConfiguracion::Memoria(void)
{
    return memoria;
}
//---------------------------------------------------------------------------
int CConfiguracion::ModoDepuracion(void)
{
    return mododepuracion;
}
//---------------------------------------------------------------------------
int CConfiguracion::ModoEjecucion(void)
{
    return modoejecucion;
}
//---------------------------------------------------------------------------
int CConfiguracion::ModoPila(void)
{
    return modopila;
}
//---------------------------------------------------------------------------
CProcesador *CConfiguracion::Procesador(void)
{
    return procesador;
}
//---------------------------------------------------------------------------
int CConfiguracion::ReiniciarRegistros(void)
{
    return reiniciarregistros;
}
//---------------------------------------------------------------------------
