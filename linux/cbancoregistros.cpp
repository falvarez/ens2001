// bancoregistros.cpp
#include "cbancoregistros.h"
//---------------------------------------------------------------------------
CBancoRegistros::CBancoRegistros(CConfiguracion *configuracion)
{
    //Inicializacion de atributos
    codigo1=CEntero16b(0);
    codigo2=CEntero16b(0);
    pila1=CEntero16b(0);
    pila2=CEntero16b(0);
    for(int i=0;i<NUM_BIESTABLES;i++)
    {
        biestables[i]=0;
    }
    for(int i=0;i<NUM_REGISTROS;i++)
    {
        registros[i]=0;
    }
    nombres[A]="A";
    nombres[R0]="R0";
    nombres[R1]="R1";
    nombres[R2]="R2";
    nombres[R3]="R3";
    nombres[R4]="R4";
    nombres[R5]="R5";
    nombres[R6]="R6";
    nombres[R7]="R7";
    nombres[R8]="R8";
    nombres[R9]="R9";
    nombres[PC]="PC";
    nombres[SP]="SP";
    nombres[IX]="IX";
    nombres[IY]="IY";
    nombres[SR]="SR";
    //Damos de alta el componente en la configuracion
    conf=configuracion;
    conf->EscribirBancoRegistros(this);
    return;
}
//---------------------------------------------------------------------------
CEntero16b CBancoRegistros::Codigo1(void)
{
    return codigo1;
}
//---------------------------------------------------------------------------
CEntero16b CBancoRegistros::Codigo2(void)
{
    return codigo2;
}
//---------------------------------------------------------------------------
void CBancoRegistros::Escribir(int registro,CEntero16b valor)
{
    CEntero16b antiguo;
    //Asignamos al registro correspondiente el valor introducido
    if(registro<NUM_REGISTROS)
    {
        antiguo=registros[registro];
        registros[registro]=valor;
    }
    else
    {
        //El registro no existe
        EscribirRegistroExcepcion(EX_REGISTRO_NO_EXISTE);
        throw runtime_error("Registro No Existe");
    }

    if(registro==SP){
        //Actualizamos los limites de la pila
        pila2=valor.Valor();
        //Comprobamos si SP invade el codigo
        if((registros[SP].Valor()>=codigo1.Valor() &&
                registros[SP].Valor()<=codigo2.Valor()) ||
           (registros[SP].Valor()<=codigo1.Valor() &&
                registros[SP].Valor()>=codigo2.Valor()))
        {
            //Si procede, lanzamos la excepcion
            if(conf->ComprobarPila()==SI)
            {
                //Recuperamos el valor anterior
                registros[registro]=antiguo;
                pila2=antiguo.Valor();
                EscribirRegistroExcepcion(EX_SP_INVADE_CODIGO);
                throw runtime_error("SP ha invadido el codigo");
            }
        }
    }
    else if(registro==PC)
    {
        //Comprobamos si PC invade la pila
        if((registros[PC].Valor()>=pila1.Valor() &&
                registros[PC].Valor()<=pila2.Valor()) ||
           (registros[PC].Valor()<=pila1.Valor() &&
                registros[PC].Valor()>=pila2.Valor()))
        {
            //Si procede, lanzamos la excepcion
            if(conf->ComprobarPC()==SI)
            {
                //Recuperamos el valor anterior
                registros[registro]=antiguo;
                EscribirRegistroExcepcion(EX_PC_INVADE_PILA);
                throw runtime_error("PC ha invadido la pila");
            }
        }
    }
    else if(registro==SR)
    {
        //Actualizamos el valor de los biestables
        int sr_auxiliar=registros[SR].Valor();
        for(int biestable=0;biestable<NUM_BIESTABLES;biestable++)
        {
            biestables[biestable]=sr_auxiliar%2;
            sr_auxiliar=sr_auxiliar/2;
        }
    }
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirBiestableEstado(int biestable,int valor)
{
    int nuevosr;

    if(valor!=0)
    {
        valor=1;
    }
    if(biestable<NUM_BIESTABLES)
    {
        //Almacenamos el valor del biestable
        biestables[biestable]=valor;
        //Regeneramos el valor del registro de estado
        nuevosr=0;
        for(int i=NUM_BIESTABLES;i>0;i--)
        {
            nuevosr=nuevosr*2+biestables[i-1];
        }
        registros[SR]=CEntero16b(nuevosr);
    }
    else
    {
        //El biestable no existe
        EscribirRegistroExcepcion(EX_BIESTABLE_NO_EXISTE);
        throw runtime_error("Biestable No Existe");
    }
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirCodigo1(CEntero16b valor)
{
    codigo1=valor;
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirCodigo2(CEntero16b valor)
{
    codigo2=valor;
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirPila1(CEntero16b valor)
{
    pila1=valor;
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirPila2(CEntero16b valor)
{
    pila2=valor;
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirRegistroExcepcion(int valor)
{
    registroexcepcion=valor;
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirRegistroFinEjecucion(int valor)
{
    registrofinejecucion=valor;
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::EscribirRegistroInstruccion(int valor)
{
    registroinstruccion=valor;
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::Leer(int registro,CEntero16b &num)
{
    if (registro<NUM_REGISTROS)
    {
        num=registros[registro];
    }
    else
    {
        //El registro no existe
        EscribirRegistroExcepcion(EX_REGISTRO_NO_EXISTE);
        throw runtime_error("Registro No Existe");
    }
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::LeerBiestableEstado(int biestable,int &valor)
{
    if(biestable<NUM_BIESTABLES)
    {
        //Recuperamos el valor del biestable
        valor=biestables[biestable];
    }
    else
    {
        //El biestable no existe
        EscribirRegistroExcepcion(EX_BIESTABLE_NO_EXISTE);
        throw runtime_error("Biestable No Existe");
    }
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::LeerIdRegistro(CCadena &nombre,int &registro)
{
    if(nombre.Comparar("a")==0 || nombre.Comparar("A")==0)
    {
        registro=A;
    }
    else if(nombre.Comparar("r0")==0 || nombre.Comparar("R0")==0)
    {
        registro=R0;
    }
    else if(nombre.Comparar("r1")==0 || nombre.Comparar("R1")==0)
    {
        registro=R1;
    }
    else if(nombre.Comparar("r2")==0 || nombre.Comparar("R2")==0)
    {
        registro=R2;
    }
    else if(nombre.Comparar("r3")==0 || nombre.Comparar("R3")==0)
    {
        registro=R3;
    }
    else if(nombre.Comparar("r4")==0 || nombre.Comparar("R4")==0)
    {
        registro=R4;
    }
    else if(nombre.Comparar("r5")==0 || nombre.Comparar("R5")==0)
    {    
    	registro=R5;
    }
    else if(nombre.Comparar("r6")==0 || nombre.Comparar("R6")==0)
    {
        registro=R6;
    }
    else if(nombre.Comparar("r7")==0 || nombre.Comparar("R7")==0)
    {
        registro=R7;
    }
    else if(nombre.Comparar("r8")==0 || nombre.Comparar("R8")==0)
    {
        registro=R8;
    }
    else if(nombre.Comparar("r9")==0 || nombre.Comparar("R9")==0)
    {
        registro=R9;
    }
    else if(nombre.Comparar("pc")==0 || nombre.Comparar("PC")==0)
    {
        registro=PC;
    }
    else if(nombre.Comparar("sp")==0 || nombre.Comparar("SP")==0)
    {
        registro=SP;
    }
    else if(nombre.Comparar("ix")==0 || nombre.Comparar("IX")==0)
    {
        registro=IX;
    }
    else if(nombre.Comparar("iy")==0 || nombre.Comparar("IY")==0)
    {
        registro=IY;
    }
    else if(nombre.Comparar("sr")==0 || nombre.Comparar("SR")==0)
    {
        registro=SR;
    }
    else
    {
        //El registro no existe
        EscribirRegistroExcepcion(EX_REGISTRO_NO_EXISTE);
        throw runtime_error("Registro No Existe");
    }
    return;
}
//---------------------------------------------------------------------------
void CBancoRegistros::LeerNombreRegistro(int registro,CCadena &nombre)
{
    if(registro<NUM_REGISTROS)
    {
        nombre=nombres[registro];
    }
    else
    {
        //El registro no existe
        EscribirRegistroExcepcion(EX_REGISTRO_NO_EXISTE);
        throw runtime_error("Registro No Existe");
    }
    return;
}
//---------------------------------------------------------------------------
CEntero16b CBancoRegistros::Pila1(void)
{
    return pila1;
}
//---------------------------------------------------------------------------
CEntero16b CBancoRegistros::Pila2(void)
{
    return pila2;
}
//---------------------------------------------------------------------------
int CBancoRegistros::RegistroExcepcion(void)
{
    return registroexcepcion;
}
//---------------------------------------------------------------------------
int CBancoRegistros::RegistroFinEjecucion(void)
{
    return registrofinejecucion;
}
//---------------------------------------------------------------------------
int CBancoRegistros::RegistroInstruccion(void)
{
    return registroinstruccion;
}
//---------------------------------------------------------------------------
void CBancoRegistros::Reiniciar(void)
{
    //Todos los registros a cero
    for(int i=0;i<NUM_REGISTROS;i++)
    {
        registros[i]=CEntero16b(0);
    }
    if(conf->ModoPila()==PILA_DECRECIENTE)
    {
    	//Si la pila es decreciente, colocamos SP al final de la 
        //memoria, o justo antes del codigo (depende de que hueco
        //es mas grande
        if((MAXINT-codigo2.Valor())<codigo1.Valor())
        {
            registros[SP]=codigo1-CEntero16b(1);
        }
        else
        {           
            registros[SP]=MAXINT;
        }
    }
    else
    {
    	//Si la pila es creciente, colocamos SP justo detras del
    	//codigo, o al principio de la memoria (depende de que hueco
    	//es mas grande
    	if((MAXINT-codigo2.Valor())<codigo1.Valor())
        {
            registros[SP]=CEntero16b(0);
        }
        else
        {           
            registros[SP]=codigo2+CEntero16b(1);
        }
        
    }
    //Inicializamos los registros especiales
    registroexcepcion=EX_NORMAL;
    registroinstruccion=0;
    registrofinejecucion=EJ_SIGUIENTE;
    //Inicializamos los limites de la pila
    pila1=registros[SP];
    pila2=registros[SP];
    return;
}
//---------------------------------------------------------------------------
