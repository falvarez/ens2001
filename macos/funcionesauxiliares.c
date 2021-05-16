/*funcionesauxiliares.c*/
#include "funcionesauxiliares.h"
/*-------------------------------------------------------------------------*/
char *listatokens[10];
int plistatokens=0;
/*-------------------------------------------------------------------------*/
int ComprobarOperando(int mdir,int op)
{
    switch(mdir)
    {
        case MD_NO_OPERANDO : if(op!=0)
                              {
                                  return -1;
                              }
        case MD_INMEDIATO :
        case MD_MEMORIA :     if((op<MININT) || (op>MAXINT))
                              {
                                  return -1;
                              }
                              break;
        case MD_REGISTRO :
        case MD_INDIRECTO :   if((op<0) || (op>(NUM_REGISTROS-1)))
                              {
                                  return -1;
                              }
                              break;
        case MD_RELATIVO_IX :
        case MD_RELATIVO_IY :
        case MD_RELATIVO_PC : if(op<0)
                              {
                                  /*Pasamos a Complemento a 2*/
                                  op=op+(MAXINT+1);
                              }
                              if(op>255)
                              {
                              /*Pasamos a 8 bits*/
                                  op=op-(MAXINT+1)+(MAXDESP+1);
                              }
                              if((op<0) || (op>255))
                              {
                                  return -1;
                              }
                              break;
    }
    return 0;
}
/*-------------------------------------------------------------------------*/
int ComprobarInstruccion(int codop,int mdir1,int op1,int mdir2,int op2)
{
    int resultado=0;

    switch(codop)
    {
        case NOP :
        case HALT :
        case RET :    if(mdir1!=MD_NO_OPERANDO)
                      {
                          resultado=ERR_MODO_DIR_1_ERRONEO;
                      }
                      else if(mdir2!=MD_NO_OPERANDO)
                      {
                          resultado=ERR_MODO_DIR_2_ERRONEO;
                      }
                      break;;
        case MOVE :   if((mdir1!=MD_INMEDIATO) && (mdir1!=MD_REGISTRO) &&
                         (mdir1!=MD_MEMORIA) && (mdir1!=MD_INDIRECTO) &&
                         (mdir1!=MD_RELATIVO_IX) && (mdir1!=MD_RELATIVO_IY))
                      {
                          resultado=ERR_MODO_DIR_1_ERRONEO;
                      }
                      else if((mdir2!=MD_REGISTRO) &&
                         (mdir2!=MD_MEMORIA) && (mdir2!=MD_INDIRECTO) &&
                         (mdir2!=MD_RELATIVO_IX) && (mdir2!=MD_RELATIVO_IY))
                      {
                          resultado=ERR_MODO_DIR_2_ERRONEO;
                      }
                      break;
        case PUSH :
        case WRCHAR :
        case WRINT :  if((mdir1!=MD_INMEDIATO) && (mdir1!=MD_REGISTRO) &&
                         (mdir1!=MD_MEMORIA) && (mdir1!=MD_INDIRECTO) &&
                         (mdir1!=MD_RELATIVO_IX) && (mdir1!=MD_RELATIVO_IY))
                      {
                          resultado=ERR_MODO_DIR_1_ERRONEO;
                      }
                      else if(mdir2!=MD_NO_OPERANDO)
                      {
                          resultado=ERR_MODO_DIR_2_ERRONEO;
                      }
                      break;
        case NEG :
        case NOT :
        case POP :
        case INC :
        case DEC :
        case INCHAR :
        case ININT :  if((mdir1!=MD_REGISTRO) &&
                         (mdir1!=MD_MEMORIA) && (mdir1!=MD_INDIRECTO) &&
                         (mdir1!=MD_RELATIVO_IX) && (mdir1!=MD_RELATIVO_IY))
                      {
                          resultado=ERR_MODO_DIR_1_ERRONEO;
                      }
                      else if(mdir2!=MD_NO_OPERANDO)
                      {
                          resultado=ERR_MODO_DIR_2_ERRONEO;
                      }
                      break;
        case ADD :
        case SUB :
        case MUL :
        case DIV :
        case MOD :
        case AND :
        case OR :
        case XOR :
        case CMP :    if((mdir1!=MD_INMEDIATO) && (mdir1!=MD_REGISTRO) &&
                         (mdir1!=MD_MEMORIA) && (mdir1!=MD_INDIRECTO) &&
                         (mdir1!=MD_RELATIVO_IX) && (mdir1!=MD_RELATIVO_IY))
                      {
                          resultado=ERR_MODO_DIR_1_ERRONEO;
                      }
                      if((mdir2!=MD_INMEDIATO) && (mdir2!=MD_REGISTRO) &&
                         (mdir2!=MD_MEMORIA) && (mdir2!=MD_INDIRECTO) &&
                         (mdir2!=MD_RELATIVO_IX) && (mdir2!=MD_RELATIVO_IY))
                      {
                          resultado=ERR_MODO_DIR_2_ERRONEO;
                      }
                      break;
        case BR :
        case BZ :
        case BNZ :
        case BP :
        case BN :
        case BV :
        case BNV :
        case BC :
        case BNC :
        case BE :
        case BO :
        case CALL :   if((mdir1!=MD_MEMORIA) && (mdir1!=MD_INDIRECTO) &&
                         (mdir1!=MD_RELATIVO_PC))
                      {
                          resultado=ERR_MODO_DIR_1_ERRONEO;
                      }
                      else if(mdir2!=MD_NO_OPERANDO)
                      {
                          resultado=ERR_MODO_DIR_2_ERRONEO;
                      }
                      break;
        case INSTR :
        case WRSTR :  if((mdir1!=MD_MEMORIA) && (mdir1!=MD_INDIRECTO) &&
                         (mdir1!=MD_RELATIVO_IX) && (mdir1!=MD_RELATIVO_IY))
                      {
                          resultado=ERR_MODO_DIR_1_ERRONEO;
                      }
                      else if(mdir2!=MD_NO_OPERANDO)
                      {
                          resultado=ERR_MODO_DIR_2_ERRONEO;
                      }
                      break;
    }
    if(ComprobarOperando(mdir1,op1)!=0)
    {
        resultado=ERR_OP1_INCORRECTO;
    }
    if(ComprobarOperando(mdir2,op2)!=0)
    {
        resultado=ERR_OP2_INCORRECTO;
    }
    return resultado;
}
/*-------------------------------------------------------------------------*/
char *CopiarCadena(char *origen,int caracteres)
{
    char *nueva;
    int i;

    nueva=(char *)malloc(sizeof(char)*(caracteres+1));
    for(i=0;i<caracteres;i++)
    {
        nueva[i]=origen[i];
    }
    nueva[caracteres]='\0';
    return nueva;
}
/*-------------------------------------------------------------------------*/
int Decimal(char *entrada,int bits)
{
    int num;
    int i;
    int maximo=2;
    int minimo;

    if(bits<1)
    {
    	/*Numero de bits incorrecto*/
    	return -2;
    }
    for(i=1;i<bits;i++)
    {
    	maximo=maximo*2;
    }
    minimo=-maximo/2;
    
    num = atoi(entrada);
    if((num<0) && (num>=minimo))
    {
    	num=num+maximo;
    }
    if((num<0) || (num>maximo-1))
    {
    	return -1;
    }
    return num;
}
/*-------------------------------------------------------------------------*/
char *EnteroACadena(int entero,int base)
{
    int negativo;
    int final;
    int resto;
    char *digito;
    char *cadena;
    char *auxiliar;

    cadena=(char *)malloc(sizeof(char)*25);
    auxiliar=(char *)malloc(sizeof(char)*25);

    strcpy(cadena,"");

    if(entero<0)
    {
        negativo=1;
        if(base==10)
        {
            entero=-entero;
        }
        else if(base==16)
        {
            entero=(MAXINT+1)+entero;
        }
    }
    else
    {
        negativo=0;
    }
    final=0;
    while(final==0)
    {
        resto=entero%base;
        entero=entero/base;
        if(entero==0)
        {
            final=1;
        }
        switch(resto)
        {
            case 0 : digito=strdup("0");
                     break;
            case 1 : digito=strdup("1");
                     break;
            case 2 : digito=strdup("2");
                     break;
            case 3 : digito=strdup("3");
                     break;
            case 4 : digito=strdup("4");
                     break;
            case 5 : digito=strdup("5");
                     break;
            case 6 : digito=strdup("6");
                     break;
            case 7 : digito=strdup("7");
                     break;
            case 8 : digito=strdup("8");
                     break;
            case 9 : digito=strdup("9");
                     break;
            case 10: digito=strdup("A");
                     break;
            case 11: digito=strdup("B");
                     break;
            case 12: digito=strdup("C");
                     break;
            case 13: digito=strdup("D");
                     break;
            case 14: digito=strdup("E");
                     break;
            case 15: digito=strdup("F");
                     break;
        }
        strcpy(auxiliar,cadena);
        strcpy(cadena,digito);
        strcat(cadena,auxiliar);
   }
   if((negativo==1) && (base==10))
   {
       strcpy(auxiliar,cadena);
       strcpy(cadena,"-");
       strcat(cadena,auxiliar);
   }
   return cadena;
}
/*-------------------------------------------------------------------------*/
int EsPalabraReservada(const char *identificador)
{
    int i;
    char *lista[]={"nop","NOP",
                   "halt","HALT",
                   "move","MOVE",
                   "push","PUSH",
                   "pop","POP",
                   "add","ADD",
                   "sub","SUB",
                   "mul","MUL",
                   "div","DIV",
                   "mod","MOD",
                   "inc","INC",
                   "dec","DEC",
                   "neg","NEG",
                   "cmp","CMP",
                   "and","AND",
                   "or","OR",
                   "xor","XOR",
                   "not","NOT",
                   "br","BR",
                   "bz","BZ",
                   "bnz","BNZ",
                   "bc","BC",
                   "bnc","BNC",
                   "bp","BP",
                   "bn","BN",
                   "bv","BV",
                   "bnv","BNV",
                   "be","BE",
                   "bo","BO",
                   "call","CALL",
                   "ret","RET",
                   "inint","ININT",
                   "inchar","INCHAR",
                   "instr","INSTR",
                   "wrint","WRINT",
                   "wrchar","WRCHAR",
                   "wrstr","WRSTR",
                   "org","ORG",
                   "res","RES",
                   "data","DATA",
                   "equ","EQU",
                   "end","END",
                   NULL
                  };
    i=0;
    while(lista[i]!=NULL)
    {
        if(strcmp(identificador,lista[i])==0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
/*-------------------------------------------------------------------------*/
int Hexadecimal(char *entrada,int bits)
{
    int num;
    int auxiliar;
    int i;
    int maximo=2;
    
    if(bits<1)
    {
    	/*Numero de bits incorrecto*/
    	return -2;
    }
    for(i=1;i<bits;i++)
    {
    	maximo=maximo*2;
    }
    
    num=0;
    for(i=2;i<(int)strlen(entrada);i++)
    {
        switch(entrada[i])
        {
            case '0' : auxiliar=0;
                       break;
            case '1' : auxiliar=1;
                       break;
            case '2' : auxiliar=2;
                       break;
            case '3' : auxiliar=3;
                       break;
            case '4' : auxiliar=4;
                       break;
            case '5' : auxiliar=5;
                       break;
            case '6' : auxiliar=6;
                       break;
            case '7' : auxiliar=7;
                       break;
            case '8' : auxiliar=8;
                       break;
            case '9' : auxiliar=9;
                       break;
            case 'a' :
            case 'A' : auxiliar=10;
                       break;
            case 'b' :
            case 'B' : auxiliar=11;
                       break;
            case 'c' :
            case 'C' : auxiliar=12;
                       break;
            case 'd' :
            case 'D' : auxiliar=13;
                       break;
            case 'e' :
            case 'E' : auxiliar=14;
                       break;
            case 'f' :
            case 'F' : auxiliar=15;
                       break;
            default :  return -1;
        }
        num=num*16+auxiliar;
    }
    if((num<0) || (num>(maximo-1)))
    {
    	return -1;
    }
    else
    {
        return num;
    }
}
/*-------------------------------------------------------------------------*/
int LiberarListaTokens(void)
{
    int i;
    
    for(i=0;i<plistatokens;i++)
    {
        if(listatokens[i]!=NULL)
        {
            free(listatokens[i]);
        }
    }
    plistatokens=0;
    return 0;
}
/*-------------------------------------------------------------------------*/
char *ConsultarToken(int num)
{
    if((num>0) && (num<10))
    {
        return(strdup(listatokens[num-1]));
    }
    else if(num==0)
    {
    	return(strdup(listatokens[plistatokens-1]));
    }
    else
    {
    	return NULL;
    }
}
/*-------------------------------------------------------------------------*/
int NuevoToken(char *token)
{
    if(plistatokens<10)
    {
        listatokens[plistatokens]=strdup(token);
        plistatokens++;
        return plistatokens;
    }
    else
    {
    	return 0;
    }
}
/*-------------------------------------------------------------------------*/
void ListarTokens(void)
{
    /*FUNCION PARA DEPURACION*/
    int i;
    
    printf(">listartokens\n");
    for(i=0;i<plistatokens;i++)
    {
    	printf("[%d] %s\n",i,listatokens[i]);
    }
}
/*-------------------------------------------------------------------------*/
