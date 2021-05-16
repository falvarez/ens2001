//cprocesador.cpp
#include "cprocesador.h"
//---------------------------------------------------------------------------
CProcesador::CProcesador(CConfiguracion *configuracion)
{
    //Damos de alta el componente en la configuracion
    conf=configuracion;
    conf->EscribirProcesador(this);
    return;
}
//---------------------------------------------------------------------------
int CProcesador::Ejecutar(void)
{
    CGestorInstrucciones *gestorinstrucciones;
    CInstruccion *instruccion;

    //Inicializacion
    int resultadoejecucion=EJ_SIGUIENTE;
    conf->BancoRegistros()->EscribirBiestableEstado(BS_H,0);
    try
    {
        gestorinstrucciones=new CGestorInstrucciones(conf);
    }
    catch(std::bad_alloc)
    {
        throw std::bad_alloc();
    }
    while(resultadoejecucion==EJ_SIGUIENTE)
    {
        //Reestablecemos las condiciones iniciales para cada instruccion
        CEntero16b registroauxiliar=CEntero16b(0);
        int op1=0;
        int op2=0;
        conf->BancoRegistros()->EscribirRegistroExcepcion(EX_NORMAL);
        //FETCH INSTRUCCION
        try
        {
            FetchInstruccion(registroauxiliar);
        }
        catch(std::runtime_error)
        {
            resultadoejecucion=EJ_EXCEPCION;
            delete(gestorinstrucciones);
            return resultadoejecucion;
        }
        //DECODIFICAR INSTRUCCION
        int codop=registroauxiliar.Valor() / 64; //10 primeros bits
        int md1=(registroauxiliar.Valor() / 8) % 8; //bits 11-13
        int md2=(registroauxiliar.Valor() % 8); //bits 14-16
        //FETCH OPERANDOS
        try
        {
            FetchOperandos(md1,op1,md2,op2);
        }
        catch(std::runtime_error)
        {
            resultadoejecucion=EJ_EXCEPCION;
            delete(gestorinstrucciones);
            return resultadoejecucion;
        }
        //Obtenemos la instruccion
        //Si la instruccion esta mal formada, devolvemos una instruccion
        //no implementada
        if(ComprobarInstruccion(codop,md1,op1,md2,op2)!=0)
        {
            instruccion=NULL;
        }
        else
        {
            instruccion=gestorinstrucciones->
                ObtenerInstruccion(codop,md1,op1,md2,op2);
        }
        //Ejecutamos la instruccion
        try
        {
            if(instruccion!=NULL)
            {
                resultadoejecucion=instruccion->Ejecutar();
            }
            else
            {
                conf->BancoRegistros()->
                    EscribirRegistroExcepcion(EX_INSTRUCCION_NO_IMPLEMENTADA);
                throw std::runtime_error("Instruccion no implementada");
            }
        }
        catch(std::runtime_error)
        {
            //Se produjo una excepcion
            //El codigo que lanza la excepcion se encarga de actualizar
            //el registro de excepciones
            resultadoejecucion=EJ_EXCEPCION;
            delete(gestorinstrucciones);
            delete(instruccion);
            return resultadoejecucion;
        }
#ifdef _ENS2001_CONSOLA_
        //Comprobamos si el usuario ha pulsado ESCAPE
        if(kbhit())
        {
            char tecla=getch();
            if(tecla==27)
            {
                conf->BancoRegistros()->
                    EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
                resultadoejecucion=EJ_EXCEPCION;
            }
        }
#endif
        //Si estamos en modo paso a paso, hay que parar
        if(conf->ModoEjecucion()==ME_PASOAPASO &&
           resultadoejecucion==EJ_SIGUIENTE)
        {
            resultadoejecucion=EJ_PASOAPASO;
        }
        //Si la siguiente instruccion lleva punto de ruptura, hay que parar
        //salvo que tengamos desactivados los puntos de ruptura
        CEntero16b pc;
        conf->BancoRegistros()->Leer(PC,pc);
        if((conf->GestorPuntosRuptura()->Consultar(pc)==1) &&
           (conf->ModoDepuracion()==SI))
        {
            resultadoejecucion=EJ_PUNTORUPTURA;
        }
        //Ya no necesitamos la instruccion
        delete(instruccion);
    }
    //Ya no necesitamos el gestor de instrucciones
    delete(gestorinstrucciones);
    //Se ha detenido la ejecucion. Devolvemos la condicion de parada
    return resultadoejecucion;
}
//---------------------------------------------------------------------------
int CProcesador::EjecutarPaso(void)
{
    CGestorInstrucciones *gestorinstrucciones;
    CInstruccion *instruccion;

    //Inicializacion
    int resultadoejecucion=EJ_SIGUIENTE;
    conf->BancoRegistros()->EscribirBiestableEstado(BS_H,0);
    try
    {
        gestorinstrucciones=new CGestorInstrucciones(conf);
    }
    catch(std::bad_alloc)
    {
        throw std::bad_alloc();
    }
    //Reestablecemos las condiciones iniciales para cada instruccion
    CEntero16b registroauxiliar=CEntero16b(0);
    int op1=0;
    int op2=0;
    conf->BancoRegistros()->EscribirRegistroExcepcion(EX_NORMAL);
    //FETCH INSTRUCCION
    try
    {
        FetchInstruccion(registroauxiliar);
    }
    catch(std::runtime_error)
    {
        resultadoejecucion=EJ_EXCEPCION;
        delete(gestorinstrucciones);
        return resultadoejecucion;
    }
    //DECODIFICAR INSTRUCCION
    int codop=registroauxiliar.Valor() / 64; //10 primeros bits
    int md1=(registroauxiliar.Valor() / 8) % 8; //bits 11-13
    int md2=(registroauxiliar.Valor() % 8); //bits 14-16
    //FETCH OPERANDOS
    try
    {
        FetchOperandos(md1,op1,md2,op2);
    }
    catch(std::runtime_error)
    {
        resultadoejecucion=EJ_EXCEPCION;
        delete(gestorinstrucciones);
        return resultadoejecucion;
    }
    //Obtenemos la instruccion
    //Si la instruccion esta mal formada, devolvemos una instruccion
    //no implementada
    if(ComprobarInstruccion(codop,md1,op1,md2,op2)!=0)
    {
        instruccion=NULL;
    }
    else
    {
        instruccion=gestorinstrucciones->
            ObtenerInstruccion(codop,md1,op1,md2,op2);
    }
    //Ejecutamos la instruccion
    try
    {
        if (instruccion!=NULL)
        {
            resultadoejecucion=instruccion->Ejecutar();
        }
        else
        {
            conf->BancoRegistros()->
                EscribirRegistroExcepcion(EX_INSTRUCCION_NO_IMPLEMENTADA);
            throw std::runtime_error("Instruccion no implementada");
        }
    }
    catch(std::runtime_error)
    {
        //Se produjo una excepcion
        //El codigo que lanza la excepcion se encarga de actualizar
        //el registro de excepciones
        resultadoejecucion=EJ_EXCEPCION;
        delete(gestorinstrucciones);
        delete(instruccion);
        return resultadoejecucion;
    }
    //Si estamos en modo paso a paso, hay que parar
    if(conf->ModoEjecucion()==ME_PASOAPASO && resultadoejecucion==EJ_SIGUIENTE)
    {
        resultadoejecucion=EJ_PASOAPASO;
    }
    //Si la siguiente instruccion lleva punto de ruptura, hay que parar
    //salvo que tengamos desactivados los puntos de ruptura
    CEntero16b pc;
    conf->BancoRegistros()->Leer(PC,pc);
    if ((conf->GestorPuntosRuptura()->Consultar(pc)==1) &&
        (conf->ModoDepuracion()==SI))
    {
        resultadoejecucion=EJ_PUNTORUPTURA;
    }
    //Ya no necesitamos la instruccion
    delete(instruccion);
    //Ya no necesitamos el gestor de instrucciones
    delete(gestorinstrucciones);
    //Se ha detenido la ejecucion. Devolvemos la condicion de parada
    return resultadoejecucion;
}
//---------------------------------------------------------------------------
void CProcesador::FetchInstruccion(CEntero16b &codop)
{
    CEntero16b pc;

    //Lee PC
    conf->BancoRegistros()->Leer(PC,pc);
    //Lee el codigo de operacion al que apunta PC
    conf->Memoria()->Leer(pc,codop);
    //Incrementa PC
    pc++;
    if (pc.C()==1)
    {
        //Se ha sobrepasado el limite superior de memoria
        conf->BancoRegistros()->EscribirRegistroExcepcion(EX_FINALMEMORIA);
        throw std::runtime_error("PC supero el limite de memoria");
    }
    conf->BancoRegistros()->Escribir(PC,pc);
    return;
}
//---------------------------------------------------------------------------
void CProcesador::FetchOperandos(int md1,int &op1,int md2,int &op2)
{
    CEntero16b pc;
    CEntero16b registroauxiliar;

    //PRIMER OPERANDO
    if (md1!=0)
    {
        conf->BancoRegistros()->Leer(PC,pc);
        conf->Memoria()->Leer(pc,registroauxiliar);
        if (md1==MD_INMEDIATO || md1==MD_MEMORIA)
        {
            //Leemos la palabra entera
            op1=registroauxiliar.Valor();
        }
        else
        {
            //Leemos el byte superior
            op1=(registroauxiliar.Valor()/256);
            //Hacemos extension de signo
            if (op1>127)
            {
                op1=op1 | 65280;
            }
        }
        pc++;
        conf->BancoRegistros()->Escribir(PC,pc);
        if (pc.C()==1)
        {
            //Se ha sobrepasado el limite superior de memoria
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_FINALMEMORIA);
            throw std::runtime_error("PC supero el limite de memoria");
        }
    }
    else
    {
        //No hay primer operando
        op1=0;
    }
    //SEGUNDO OPERANDO
    if (md2!=0)
    {
        if (md1==MD_INMEDIATO || md1==MD_MEMORIA ||
            md2==MD_INMEDIATO || md2==MD_MEMORIA)
        {
            //Hay algun operando que necesita una palabra completa
            //Tenemos que leer otra palabra
            conf->BancoRegistros()->Leer(PC,pc);
            conf->Memoria()->Leer(pc,registroauxiliar);
            pc++;
            conf->BancoRegistros()->Escribir(PC,pc);
            if (pc.C()==1)
            {
                //Se ha sobrepasado el limite superior de memoria
                conf->BancoRegistros()->
                    EscribirRegistroExcepcion(EX_FINALMEMORIA);
                throw std::runtime_error("PC supero el limite de memoria");
            }
        }
        //Tenemos el operando en el registro auxiliar
        //Recuperamos el byte inferior
        if (md2==MD_INMEDIATO || md2==MD_MEMORIA)
        {
            op2=registroauxiliar.Valor();
        }
        else
        {
            op2=registroauxiliar.Valor()%256;
            //Hacemos extension de signo
            if (op2>127)
            {
                op2=op2 | 65280;
            }
        }
    }
    else{
        //No hay segundo operando
        op2=0;
    }
    return;
}
//---------------------------------------------------------------------------
