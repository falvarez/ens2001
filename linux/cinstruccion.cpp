//instruccion.cpp
#include "cinstruccion.h"
//---------------------------------------------------------------------------
CInstruccion::CInstruccion(CConfiguracion *configuracion,int md1,int op1,
                           int md2,int op2)
{
    mododir1=md1;
    operando1=op1;
    mododir2=md2;
    operando2=op2;

    conf=configuracion;
    return;
}
//---------------------------------------------------------------------------
int CInstruccion::Entrada(void)
{
    //Proceso generico. A definir por cada instruccion
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::Proceso(void)
{
    //Proceso generico. A definir por cada instruccion
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::Salida(void)
{
    //Salida generica. A definir por cada instruccion
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::PushPila(CEntero16b operando)
{
    CEntero16b direccion;

    conf->BancoRegistros()->Leer(SP,direccion);
    conf->Memoria()->Escribir(direccion,operando);
    switch (conf->ModoPila())
    {
        case PILA_CRECIENTE :   direccion++;
                                break;
        case PILA_DECRECIENTE : direccion--;
                                break;
        default : conf->BancoRegistros()->
                          EscribirRegistroExcepcion(EX_MODOPILA_INCORRECTO);
                  throw runtime_error("Modo Pila No Soportado");
    }
    conf->BancoRegistros()->Escribir(SP,direccion);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::PopPila(CEntero16b &operando)
{
    CEntero16b direccion;

    conf->BancoRegistros()->Leer(SP,direccion);
    switch (conf->ModoPila())
    {
        case PILA_CRECIENTE :   direccion--;
                                break;
        case PILA_DECRECIENTE : direccion++;
                                break;
        default : conf->BancoRegistros()->
                          EscribirRegistroExcepcion(EX_MODOPILA_INCORRECTO);
                  throw runtime_error("Modo Pila No Soportado");
    }
    conf->BancoRegistros()->Escribir(SP,direccion);
    conf->BancoRegistros()->Leer(SP,direccion);
    conf->Memoria()->Leer(direccion,operando);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::Entrada2Operandos(void)
{
    CEntero16b auxiliar;

    //Recuperamos el operando 1 en origen1
    switch (mododir1){
        case MD_INMEDIATO :
            origen1 = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,origen1);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),origen1);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,origen1);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }

    //Recuperamos el operando 2 en origen2

    switch (mododir2){
        case MD_INMEDIATO :
            origen2 = CEntero16b(operando2);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando2,origen2);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando2),origen2);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando2,auxiliar);
            conf->Memoria()->Leer(auxiliar,origen2);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando2),origen2);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando2),origen2);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::EntradaSalto(void)
{
    CEntero16b auxiliar;

    switch(mododir1)
    {
        case MD_MEMORIA :
            resultado = CEntero16b(operando1);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,resultado);
            break;
        case MD_RELATIVO_PC :
            conf->BancoRegistros()->Leer(PC,auxiliar);
            resultado = auxiliar + CEntero16b(operando1);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::Aritmetica(int operacion,CEntero16b &resultado,
                             CEntero16b op1,CEntero16b op2)
{
    switch(operacion)
    {
        case ALU_SUMA :
            resultado = op1 + op2;
            break;
        case ALU_RESTA :
            resultado = op1 - op2;
            break;
        case ALU_PRODUCTO :
            resultado = op1 * op2;
            break;
        case ALU_DIVISION :
            if (op2.Valor()==0)
            {
                //EXCEPCION DIVISION POR CERO
                conf->BancoRegistros()->
                          EscribirRegistroExcepcion(EX_DIVISION_POR_CERO);
                throw runtime_error("Division Por Cero");
            }
            resultado = op1 / op2;
            break;
        case ALU_MODULO :
            if (op2.Valor()==0)
            {
                //EXCEPCION DIVISION POR CERO
                conf->BancoRegistros()->
                           EscribirRegistroExcepcion(EX_DIVISION_POR_CERO);
                throw runtime_error("Division Por Cero");
            }
            resultado = op1 % op2;
            break;
        case ALU_INC :
            resultado = op1 + CEntero16b(1);
            break;
        case ALU_DEC :
            resultado = op1 - CEntero16b(1);
            break;
        case ALU_CAMBIO_SIG :
            resultado = - op1;
            break;
        default :
            //OPERACION INCORRECTA
            throw runtime_error("Operacion Aritmetica Incorrecta");
    }
    //Actualizamos los biestables de estado
    conf->BancoRegistros()->EscribirBiestableEstado(BS_Z,resultado.Z());
    conf->BancoRegistros()->EscribirBiestableEstado(BS_S,resultado.S());
    conf->BancoRegistros()->EscribirBiestableEstado(BS_V,resultado.V());
    conf->BancoRegistros()->EscribirBiestableEstado(BS_C,resultado.C());
    conf->BancoRegistros()->EscribirBiestableEstado(BS_P,resultado.P());
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::Logica(int operacion,CEntero16b &resultado,
                         CEntero16b op1,CEntero16b op2)
{
    switch(operacion)
    {
        case ALU_AND : resultado = op1 & op2;
                       break;
        case ALU_OR :  resultado = op1 | op2;
                       break;
        case ALU_NOT : resultado = ~ op1;
                       break;
        case ALU_XOR : resultado = op1 ^ op2;
                       break;
        default :      //OPERACION INCORRECTA
                       throw runtime_error("Operacion Logica Incorrecta");
    }
    //Las operaciones logicas no modifican el valor de los biestables de estado
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CInstruccion::Ejecutar(void)
{
    int error;

    error=Entrada();
    if(error!=EJ_SIGUIENTE)
    {
        return error;
    }
    error=Proceso();
    if(error!=EJ_SIGUIENTE)
    {
        return error;
    }
    error=Salida();
    return error;
}
//---------------------------------------------------------------------------
//Juego de instrucciones
//000 - NOP
I_nop::I_nop(CConfiguracion *configuracion)
     : CInstruccion(configuracion)
{
    return;
}
//---------------------------------------------------------------------------
//001 - HALT
I_halt::I_halt(CConfiguracion *configuracion)
    : CInstruccion(configuracion)
{
    return;
}
//---------------------------------------------------------------------------
int I_halt::Salida(void)
{
    conf->BancoRegistros()->EscribirBiestableEstado(BS_H,1);
    return EJ_HALT;
}
//---------------------------------------------------------------------------
//002 - MOVE
I_move::I_move(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_move::Entrada(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            resultado = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int I_move::Salida(void)
{
    CEntero16b auxiliar;

    switch (mododir2){
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando2,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando2),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando2,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Escribir(auxiliar+CEntero16b(operando2),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Escribir(auxiliar+CEntero16b(operando2),resultado);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//003 - PUSH
I_push::I_push(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_push::Entrada(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            resultado = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int I_push::Salida(void)
{
    int retorno;

    retorno=PushPila(resultado);
    return retorno;
}
//---------------------------------------------------------------------------
//004 - POP
I_pop::I_pop(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_pop::Entrada(void)
{
    int retorno;
    retorno=PopPila(resultado);
    return retorno;
}
//---------------------------------------------------------------------------
int I_pop::Salida(void)
{
    CEntero16b auxiliar;

    switch (mododir1){
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//005 - ADD
I_add::I_add(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_add::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_add::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_SUMA,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_add::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//006 - SUB
I_sub::I_sub(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_sub::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_sub::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_RESTA,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_sub::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//007 - MUL
I_mul::I_mul(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_mul::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_mul::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_PRODUCTO,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_mul::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//008 - DIV
I_div::I_div(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_div::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_div::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_DIVISION,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_div::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//009 - MOD
I_mod::I_mod(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_mod::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_mod::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_MODULO,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_mod::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//010 - INC
I_inc::I_inc(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_inc::Entrada(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            origen1 = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,origen1);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),origen1);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,origen1);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int I_inc::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_INC,resultado,origen1);
    return retorno;
}
//---------------------------------------------------------------------------
int I_inc::Salida(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//011 - DEC
I_dec::I_dec(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_dec::Entrada(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            origen1 = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,origen1);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),origen1);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,origen1);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int I_dec::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_DEC,resultado,origen1);
    return retorno;
}
//---------------------------------------------------------------------------
int I_dec::Salida(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//012 - NEG
I_neg::I_neg(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_neg::Entrada(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            origen1 = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,origen1);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),origen1);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,origen1);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int I_neg::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_CAMBIO_SIG,resultado,origen1);
    return retorno;
}
//---------------------------------------------------------------------------
int I_neg::Salida(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//013 - CMP
I_cmp::I_cmp(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_cmp::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_cmp::Proceso(void)
{
    int retorno;

    retorno=Aritmetica(ALU_RESTA,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
//014 - AND
I_and::I_and(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_and::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_and::Proceso(void)
{
    int retorno;

    retorno=Logica(ALU_AND,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_and::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//015 - OR
I_or::I_or(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_or::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_or::Proceso(void)
{
    int retorno;

    retorno=Logica(ALU_OR,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_or::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//016 - XOR
I_xor::I_xor(CConfiguracion *configuracion,int md1,int op1,int md2,int op2)
    : CInstruccion(configuracion,md1,op1,md2,op2)
{
    return;
}
//---------------------------------------------------------------------------
int I_xor::Entrada(void)
{
    int retorno;

    retorno=Entrada2Operandos();
    return retorno;
}
//---------------------------------------------------------------------------
int I_xor::Proceso(void)
{
    int retorno;

    retorno=Logica(ALU_XOR,resultado,origen1,origen2);
    return retorno;
}
//---------------------------------------------------------------------------
int I_xor::Salida(void)
{
    conf->BancoRegistros()->Escribir(A,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//017 - NOT
I_not::I_not(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_not::Entrada(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            origen1 = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,origen1);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),origen1);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,origen1);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),origen1);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int I_not::Proceso(void)
{
    int retorno;

    retorno=Logica(ALU_NOT,resultado,origen1);
    return retorno;
}
//---------------------------------------------------------------------------
int I_not::Salida(void)
{
    CEntero16b auxiliar;

    switch (mododir1)
    {
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//018 - BR
I_br::I_br(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_br::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_br::Salida(void)
{
    conf->BancoRegistros()->Escribir(PC,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//019 - BZ
I_bz::I_bz(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bz::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bz::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_Z,biestable);
    if (biestable==1)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//020 - BNZ
I_bnz::I_bnz(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bnz::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bnz::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_Z,biestable);
    if (biestable==0)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//021 - BP
I_bp::I_bp(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bp::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bp::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_S,biestable);
    if (biestable==0)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//022 - BN
I_bn::I_bn(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bn::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bn::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_S,biestable);
    if (biestable==1)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//023 - BV
I_bv::I_bv(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bv::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bv::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_V,biestable);
    if (biestable==1)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//024 - BNV
I_bnv::I_bnv(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bnv::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bnv::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_V,biestable);
    if (biestable==0)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//025 - BC
I_bc::I_bc(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bc::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bc::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_C,biestable);
    if (biestable==1)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//026 - BNC
I_bnc::I_bnc(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bnc::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bnc::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_C,biestable);
    if (biestable==0)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//027 - BE
I_be::I_be(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_be::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_be::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_P,biestable);
    if (biestable==0)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//028 - BO
I_bo::I_bo(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_bo::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_bo::Salida(void)
{
    int biestable;

    conf->BancoRegistros()->LeerBiestableEstado(BS_P,biestable);
    if (biestable==1)
    {
        conf->BancoRegistros()->Escribir(PC,resultado);
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//029 - CALL
I_call::I_call(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_call::Entrada(void)
{
    int retorno;

    retorno=EntradaSalto();
    return retorno;
}
//---------------------------------------------------------------------------
int I_call::Proceso(void)
{
    int retorno;

    conf->BancoRegistros()->Leer(PC,origen1);
    retorno=PushPila(origen1);
    return retorno;
}
//---------------------------------------------------------------------------
int I_call::Salida(void)
{
    conf->BancoRegistros()->Escribir(PC,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//030 - RET
I_ret::I_ret(CConfiguracion *configuracion)
    : CInstruccion(configuracion)
{
    return;
}
//---------------------------------------------------------------------------
int I_ret::Proceso(void)
{
    int retorno;

    retorno=PopPila(resultado);
    return retorno;
}
//---------------------------------------------------------------------------
int I_ret::Salida(void)
{
    conf->BancoRegistros()->Escribir(PC,resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//031 - INCHAR
I_inchar::I_inchar(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_inchar::Entrada(void)
{
    char caracter;
    int valorcaracter;
    CEntero16b auxiliar;

    conf->EntradaSalida()->Leer(caracter);
    valorcaracter=(int)caracter;
    if(valorcaracter<0)
    {
    	//Pasamos a entero de 8 bits sin signo
    	valorcaracter=MAXDESP+1+valorcaracter;
    }
    resultado=CEntero16b(valorcaracter);
    switch (mododir1)
    {
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//032 - ININT
I_inint::I_inint(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_inint::Entrada(void)
{
    CEntero16b entero;
    CEntero16b auxiliar;

    conf->EntradaSalida()->Leer(entero);
    resultado=CEntero16b(entero);
    switch (mododir1)
    {
        case MD_REGISTRO :
            conf->BancoRegistros()->Escribir(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Escribir(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Escribir(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->
                Escribir(auxiliar+CEntero16b(operando1),resultado);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//033 - INSTR
I_instr::I_instr(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_instr::Entrada(void)
{
    CCadena cadena;
    int valorcaracter;
    CEntero16b auxiliar;
    CEntero16b direccion;
    int i;

    conf->EntradaSalida()->Leer(cadena);
    for(i=0;i<cadena.Longitud();i++)
    {
    	valorcaracter=(int)cadena[i];
    	if(valorcaracter<0)
    	{
    	    //Pasamos a entero de 8 bits sin signo
    	    valorcaracter=MAXDESP+1+valorcaracter; 
    	}
        resultado=CEntero16b(valorcaracter);
        switch (mododir1)
        {
            case MD_MEMORIA :
            	direccion=CEntero16b(operando1)+CEntero16b(i);
                break;
            case MD_INDIRECTO :            	
                conf->BancoRegistros()->Leer(operando1,auxiliar);
                direccion=auxiliar+CEntero16b(i);
                break;
            case MD_RELATIVO_IX :
                conf->BancoRegistros()->Leer(IX,auxiliar);
                direccion=auxiliar+CEntero16b(operando1)+CEntero16b(i);
                break;
            case MD_RELATIVO_IY :
                conf->BancoRegistros()->Leer(IY,auxiliar);
                direccion=auxiliar+CEntero16b(operando1)+CEntero16b(i);
                break;
            default :
                conf->BancoRegistros()->
                    EscribirRegistroExcepcion(EX_MDIRERRONEO);
                throw runtime_error("Modo De Direccionamiento Erroneo");
        }
        if(direccion.C()==1)
        {
        	conf->BancoRegistros()->
        	    EscribirRegistroExcepcion(EX_FINALMEMORIA);
        	throw runtime_error("Se sobrepaso el limite de memoria");
        }
        else
        {
            conf->Memoria()->Escribir(direccion,resultado);
        }
    }
    //Hay que poner el caracter final de cadena
    switch (mododir1)
    {
        case MD_MEMORIA :
            direccion=CEntero16b(operando1)+CEntero16b(i);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            direccion=auxiliar+CEntero16b(i);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            direccion=auxiliar+CEntero16b(operando1)+CEntero16b(i);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            direccion=auxiliar+CEntero16b(operando1)+CEntero16b(i);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    if(direccion.C()==1)
    {
        conf->BancoRegistros()->EscribirRegistroExcepcion(EX_FINALMEMORIA);
        throw runtime_error("Se sobrepaso el limite de memoria");
    }
    else
    {
        conf->Memoria()->Escribir(direccion,CEntero16b(0));
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//034 - WRCHAR
I_wrchar::I_wrchar(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_wrchar::Salida(void)
{
    CEntero16b auxiliar;
    char caracter;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            resultado = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    caracter=(char)resultado.Valor();
    conf->EntradaSalida()->Escribir(caracter);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//0035 - WRINT
I_wrint::I_wrint(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_wrint::Salida(void)
{
    CEntero16b auxiliar;
    //int entero;

    switch (mododir1)
    {
        case MD_INMEDIATO :
            resultado = CEntero16b(operando1);
            break;
        case MD_REGISTRO :
            conf->BancoRegistros()->Leer(operando1,resultado);
            break;
        case MD_MEMORIA :
            conf->Memoria()->Leer(CEntero16b(operando1),resultado);
            break;
        case MD_INDIRECTO :
            conf->BancoRegistros()->Leer(operando1,auxiliar);
            conf->Memoria()->Leer(auxiliar,resultado);
            break;
        case MD_RELATIVO_IX :
            conf->BancoRegistros()->Leer(IX,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        case MD_RELATIVO_IY :
            conf->BancoRegistros()->Leer(IY,auxiliar);
            conf->Memoria()->Leer(auxiliar+CEntero16b(operando1),resultado);
            break;
        default :
            conf->BancoRegistros()->EscribirRegistroExcepcion(EX_MDIRERRONEO);
            throw runtime_error("Modo De Direccionamiento Erroneo");
    }
    conf->EntradaSalida()->Escribir(resultado);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
//0036 - WRSTR
I_wrstr::I_wrstr(CConfiguracion *configuracion,int md1,int op1)
    : CInstruccion(configuracion,md1,op1)
{
    return;
}
//---------------------------------------------------------------------------
int I_wrstr::Salida(void)
{
    CEntero16b auxiliar;
    CCadena cadena;
    CEntero16b direccion;
    int i;

    resultado=1;
    i=0;
    while(resultado.Valor()!=0)
    {
        switch (mododir1)
        {
            case MD_MEMORIA :
                direccion=CEntero16b(operando1)+CEntero16b(i);
                break;
            case MD_INDIRECTO :
                conf->BancoRegistros()->Leer(operando1,auxiliar);
                direccion=auxiliar+CEntero16b(i);
                break;
            case MD_RELATIVO_IX :
                conf->BancoRegistros()->Leer(IX,auxiliar);
                direccion=auxiliar+CEntero16b(operando1)+CEntero16b(i);
                break;
            case MD_RELATIVO_IY :
                conf->BancoRegistros()->Leer(IY,auxiliar);
                direccion=auxiliar+CEntero16b(operando1)+CEntero16b(i);
                break;
            default :
                conf->BancoRegistros()->
                    EscribirRegistroExcepcion(EX_MDIRERRONEO);
                throw runtime_error("Modo De Direccionamiento Erroneo");
        }
        if(direccion.C()==1)
        {
        	conf->BancoRegistros()->
        	    EscribirRegistroExcepcion(EX_FINALMEMORIA);
        	throw runtime_error("Se sobrepaso el limite de memoria");
        }
        else
        {
            conf->Memoria()->Leer(direccion,resultado);
            cadena=cadena+(char)resultado.Valor();
            i++;
        }
    }
    conf->EntradaSalida()->Escribir(cadena);
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
