//gestorinstrucciones.cpp
#include "cgestorinstrucciones.h"

CGestorInstrucciones::CGestorInstrucciones(CConfiguracion *configuracion)
{

    conf=configuracion;
    return;
}
//---------------------------------------------------------------------------
CInstruccion *CGestorInstrucciones::ObtenerInstruccion(int codop,
                                                       int md1,int op1,
                                                       int md2,int op2)
{
    CInstruccion *instruccion;

    switch(codop)
    {
        case NOP :    instruccion=new I_nop(conf);
                      break;
        case HALT :   instruccion=new I_halt(conf);
                      break;
        case MOVE :   instruccion=new I_move(conf,md1,op1,md2,op2);
                      break;
        case PUSH :   instruccion=new I_push(conf,md1,op1);
                      break;
        case POP :    instruccion=new I_pop(conf,md1,op1);
                      break;
        case ADD :    instruccion=new I_add(conf,md1,op1,md2,op2);
                      break;
        case SUB :    instruccion=new I_sub(conf,md1,op1,md2,op2);
                      break;
        case MUL :    instruccion=new I_mul(conf,md1,op1,md2,op2);
                      break;
        case DIV :    instruccion=new I_div(conf,md1,op1,md2,op2);
                      break;
        case MOD :    instruccion=new I_mod(conf,md1,op1,md2,op2);
                      break;
        case INC :    instruccion=new I_inc(conf,md1,op1);
                      break;
        case DEC :    instruccion=new I_dec(conf,md1,op1);
                      break;
        case NEG :    instruccion=new I_neg(conf,md1,op1);
                      break;
        case CMP :    instruccion=new I_cmp(conf,md1,op1,md2,op2);
                      break;
        case AND :    instruccion=new I_and(conf,md1,op1,md2,op2);
                      break;
        case OR :     instruccion=new I_or(conf,md1,op1,md2,op2);
                      break;
        case XOR :    instruccion=new I_xor(conf,md1,op1,md2,op2);
                      break;
        case NOT :    instruccion=new I_not(conf,md1,op1);
                      break;
        case BR :     instruccion=new I_br(conf,md1,op1);
                      break;
        case BZ :     instruccion=new I_bz(conf,md1,op1);
                      break;
        case BNZ :    instruccion=new I_bnz(conf,md1,op1);
                      break;
        case BP :     instruccion=new I_bp(conf,md1,op1);
                      break;
        case BN :     instruccion=new I_bn(conf,md1,op1);
                      break;
        case BV :     instruccion=new I_bv(conf,md1,op1);
                      break;
        case BNV :    instruccion=new I_bnv(conf,md1,op1);
                      break;
        case BC :     instruccion=new I_bc(conf,md1,op1);
                      break;
        case BNC :    instruccion=new I_bnc(conf,md1,op1);
                      break;
        case BE :     instruccion=new I_be(conf,md1,op1);
                      break;
        case BO :     instruccion=new I_bo(conf,md1,op1);
                      break;
        case CALL :   instruccion=new I_call(conf,md1,op1);
                      break;
        case RET :    instruccion=new I_ret(conf);
                      break;
        case INCHAR : instruccion=new I_inchar(conf,md1,op1);
                      break;
        case ININT :  instruccion=new I_inint(conf,md1,op1);
                      break;
        case INSTR :  instruccion=new I_instr(conf,md1,op1);
                      break;
        case WRCHAR : instruccion=new I_wrchar(conf,md1,op1);
                      break;
        case WRINT :  instruccion=new I_wrint(conf,md1,op1);
                      break;
        case WRSTR :  instruccion=new I_wrstr(conf,md1,op1);
                      break;
        default :     instruccion=NULL;
    }
    return instruccion;
}
