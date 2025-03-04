//cinstruccion.h

#ifndef _CINSTRUCCION_H_
#define _CINSTRUCCION_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
#include "centradasalida.h"

class CInstruccion
{
    protected :
        //Atributos
        int mododir1;
        int operando1;
        int mododir2;
        int operando2;

        //Valores auxiliares
        CEntero16b origen1; //Primer operando (cuando se aplica)
        CEntero16b origen2; //Segundo operando (cuando se aplica)
        CEntero16b resultado; //Resultado de una operacion (cuando se aplica)

        //Clases con las que se interactua
        CConfiguracion *conf;

        //Metodos auxiliares
        virtual int Entrada(void); //Datos de entrada para la instruccion
        virtual int Proceso(void); //Accion que realiza la instruccion
        virtual int Salida(void); //Resultados que devuelve o almacena la
                                  //instruccion

        int Aritmetica(int operacion,CEntero16b &resultado,
                       CEntero16b op1,CEntero16b op2=CEntero16b(0));
            //resultado <- op1 operacion op2
            //si op2=0, la operacion es unaria
            //Se actualizan los biestables de estado
        int Logica(int operacion,CEntero16b &resultado,
                   CEntero16b op1,CEntero16b op2=CEntero16b(0));
            //resultado <- op1 operacion op2
            //si op2=0, la operacion es unaria
            //No se actualizan los biestables de estado
        int Entrada2Operandos(void);
            //op1 -> origen1
            //op2 -> origen2
        int EntradaSalto(void);
            //Cuando se trata de una instruccion de salto, la entrada de
            //operandos es un poco especial, se trata aqui
        int PushPila(CEntero16b operando);
            //Segun el modo de funcionamiento de la pila,
            //Almacena valor en la misma
        int PopPila(CEntero16b &operando);
            //Segun el modo de funcionamiento de la pila,
            //Recupera valor desde la misma

    public :
        //Constructor
        CInstruccion(CConfiguracion *configuracion,int md1=0,int op1=0,
                     int md2=0,int op2=0);

        //Metodos
        int Ejecutar(void);

};

//Juego de instrucciones
//000 - NOP
class I_nop : public CInstruccion
{
    public :
        //Constructor
        I_nop(CConfiguracion *configuracion);
};

//001 - HALT
class I_halt : public CInstruccion
{
    private :
        int Salida(void); //DEVUELVE EJ_HALT

    public :
        //Constructor
        I_halt(CConfiguracion *configuracion);
};

//002 - MOVE
class I_move : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Origen1
        int Salida(void); //Origen1 -> Operando2

    public :
        //Constructor
        I_move(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//003 - PUSH
class I_push : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Resultado
        int Salida(void); //Push en pila de Resultado

    public :
        //Constructor
        I_push(CConfiguracion *configuracion,int md1,int op1);
};

//004 - POP
class I_pop : public CInstruccion
{
    private :
        int Entrada(void); //Pop desde pila de Resultado
        int Salida(void); //Resultado -> Operando1

    public :
        //Constructor
        I_pop(CConfiguracion *configuracion,int md1,int op1);
};

//005 - ADD
class I_add : public CInstruccion
{
    private :
        int Entrada(void); //Op1 -> Origen1 ; Op2 -> Origen2
        int Proceso(void); //Origen1 + Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_add(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//006 - SUB
class I_sub : public CInstruccion
{
    private :
        int Entrada(void); //Op1 -> Origen1 ; Op2 -> Origen2
        int Proceso(void); //Origen1 - Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_sub(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//007 - MUL
class I_mul : public CInstruccion
{
    private :
        int Entrada(void); //Op1 -> Origen1 ; Op2 -> Origen2
        int Proceso(void); //Origen1 * Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_mul(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//008 - DIV
class I_div : public CInstruccion
{
    private :
        int Entrada(void); //Op1 -> Origen1 ; Op2 -> Origen2
        int Proceso(void); //Origen1 / Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_div(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//009 - MOD
class I_mod : public CInstruccion
{
    private :
        int Entrada(void); //Op1 -> Origen1 ; Op2 -> Origen2
        int Proceso(void); //Origen1 % Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_mod(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//010 - INC
class I_inc : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 - > Origen1
        int Proceso(void); //Origen1 + 1 -> Resultado
        int Salida(void); //Resultado -> Operando1

    public :
        //Constructor
        I_inc(CConfiguracion *configuracion,int md1,int op1);
};

//011 - DEC
class I_dec : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 - > Origen1
        int Proceso(void); //Origen1 - 1 -> Resultado
        int Salida(void); //Resultado -> Operando1

    public :
        //Constructor
        I_dec(CConfiguracion *configuracion,int md1,int op1);
};

//012 - NEG
class I_neg : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Origen1
        int Proceso(void); // - Origen1 -> Resultado
        int Salida(void); //Resultado -> Origen1

    public :
        //Constructor
        I_neg(CConfiguracion *configuracion,int md1,int op);
};

//013 - CMP
class I_cmp : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Origen1 ; Operando2 -> Origen2
        int Proceso(void); //Origen1 - Origen2 -> Resultado (para
                           //actualizar biestables)

    public :
        //Constructor
        I_cmp(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//014 - AND
class I_and : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Origen1 ; Operando2 -> Origen2
        int Proceso(void); //Origen1 & Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_and(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//015 - OR
class I_or : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Origen1 ; Operando2 -> Origen2
        int Proceso(void); //Origen1 | Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_or(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//016 - XOR
class I_xor : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Origen1 ; Operando2 -> Origen2
        int Proceso(void); //Origen1 ^ Origen2 -> Resultado
        int Salida(void); //Resultado -> .A

    public :
        //Constructor
        I_xor(CConfiguracion *configuracion,int md1,int op1,int md2,int op2);
};

//017 - NOT
class I_not : public CInstruccion
{
    private :
        int Entrada(void); //Operando1 -> Origen1
        int Proceso(void); //~ Origen1 -> Resultado
        int Salida(void); //Resultado -> Origen1

    public :
        //Constructor
        I_not(CConfiguracion *configuracion,int md1,int op1);
};

//018 - BR
class I_br : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion (siempre),
                          //carga nuevo PC

    public :
        //Constructor
        I_br(CConfiguracion *configuracion,int md1,int op1);
};

//019 - BZ
class I_bz : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bz(CConfiguracion *configuracion,int md1,int op1);
};

//020 - BNZ
class I_bnz : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bnz(CConfiguracion *configuracion,int md1,int op1);
};

//021 - BP
class I_bp : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bp(CConfiguracion *configuracion,int md1,int op1);
};

//022 - BN
class I_bn : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bn(CConfiguracion *configuracion,int md1,int op1);
};

//023 - BV
class I_bv : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bv(CConfiguracion *configuracion,int md1,int op1);
};

//024 - BNV
class I_bnv : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bnv(CConfiguracion *configuracion,int md1,int op1);
};

//025 - BC
class I_bc : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bc(CConfiguracion *configuracion,int md1,int op1);
};

//026 - BNC
class I_bnc : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bnc(CConfiguracion *configuracion,int md1,int op1);
};

//027 - BE
class I_be : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_be(CConfiguracion *configuracion,int md1,int op1);
};

//028 - BO
class I_bo : public CInstruccion
{
    private :
        int Entrada(void); //Recupera destino
        int Salida(void); //Si se cumple la condicion, carga nuevo PC

    public :
        //Constructor
        I_bo(CConfiguracion *configuracion,int md1,int op1);
};

//029 - CALL
class I_call : public CInstruccion
{
    private:
        int Entrada(void); //Recupera destino
        int Proceso(void); //Push PC
        int Salida(void); //Carga direccion destino en PC

    public :
        //Constructor
        I_call(CConfiguracion *configuracion,int md1,int op1);
};

//030 - RET
class I_ret : public CInstruccion
{
    private :
        int Proceso(void); //Pop PC en resultado
        int Salida(void); //resultado -> PC

    public :
        //Constructor
        I_ret(CConfiguracion *configuracion);
};

//031 - INCHAR
class I_inchar : public CInstruccion
{
    private :
        int Entrada(void); //E/S -> operando1

    public :
        //Constructor
        I_inchar(CConfiguracion *configuracion,int md1,int op1);
};

//032 - ININT
class I_inint : public CInstruccion
{
    private :
        int Entrada(void); //E/S -> operando1

    public :
        //Constructor
        I_inint(CConfiguracion *configuracion,int md1,int op1);
};

//033 - INSTR
class I_instr : public CInstruccion
{
    private :
        int Entrada(void); //E/S -> operando1

    public :
        //Constructor
        I_instr(CConfiguracion *configuracion,int md1,int op1);
};

//034 - WRCHAR
class I_wrchar : public CInstruccion
{
    private :
        int Salida(void); //operando1 -> E/S

    public :
        //Constructor
        I_wrchar(CConfiguracion *configuracion,int md1,int op1);
};

//035 - WRINT
class I_wrint : public CInstruccion
{
    private :
        int Salida(void); //operando1 -> E/S

    public :
        //Constructor
        I_wrint(CConfiguracion *configuracion,int md1,int op1);
};

//036 - WRSTR
class I_wrstr : public CInstruccion
{
    private :
        int Salida(void); //operando1 -> E/S

    public :
        //Constructor
        I_wrstr(CConfiguracion *configuracion,int md1,int op1);
};

#endif //_CINSTRUCCION_H_
