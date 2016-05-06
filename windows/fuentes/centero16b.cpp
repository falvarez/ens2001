//centero16b.cpp
#include "centero16b.h"
//---------------------------------------------------------------------------
int CEntero16b::C(void)
{
    return valor_C;
}
//---------------------------------------------------------------------------
int CEntero16b::CalculaAcarreo(int num)
{
    //Aplicable para numeros sin signo (esto es
    //entre 0 y 65535)

    if((num>MAXINT) || (num<MININT))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//---------------------------------------------------------------------------
int CEntero16b::CalculaCero(int num)
{
    if(num==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//---------------------------------------------------------------------------
int CEntero16b::CalculaDesbordamiento(int num)
{
    //Aplicable para numeros con signo (esto es
    //entre -32768 y 32767)

    if((num<-((MAXINT+1)/2)) || (num>((MAXINT-1)/2)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//---------------------------------------------------------------------------
int CEntero16b::CalculaParidad(int num)
{
    //Aplicable para numeros sin signo (esto es
    //entre 0 y 65535)

    int auxiliar=num;
    int contador=0;
    for(int i=0;i<16;i++)
    {
        contador=contador+(auxiliar%2);
        auxiliar=auxiliar/2;
    }
    return contador%2;
}
//---------------------------------------------------------------------------
int CEntero16b::CalculaSigno(int num)
{
    //Aplicable para numeros sin signo (esto es
    //entre 0 y 65535)

    return num/((MAXINT+1)/2);
}
//---------------------------------------------------------------------------
CEntero16b::CEntero16b()
{
    valor=0;
    valor_Z=1;
    valor_S=0;
    valor_V=0;
    valor_C=0;
    valor_P=1;
    return;
}
//---------------------------------------------------------------------------
CEntero16b::CEntero16b(int num)
{
    if((num<-((MAXINT+1)/2)) || (num>MAXINT))
    {
        throw runtime_error("Entero Fuera De Rango");
    }
    else
    {
        valor=EnteroAInterno(num);
        //BS_Z
        valor_Z=CalculaCero(valor);
        //BS_S
        valor_S=CalculaSigno(valor);
        //BS_V
        valor_V=0;
        //BS_C
        valor_C=0;
        //BS_P
        valor_P=CalculaParidad(valor);
    }
    return;
}
//---------------------------------------------------------------------------
CEntero16b::CEntero16b(const char *num)
{
    unsigned int i;
    int auxiliar;

    //Si empieza por 0x, puede ser hexadecimal
    if (num[0]=='0' && num[1]=='x')
    {
        valor=0;
        for(i=2;i<strlen(num);i++)
        {
            switch(num[i])
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
                default :  throw runtime_error("Entero Fuera De Rango");
            }
            valor=valor*16+auxiliar;
        }
    }
    //Si empieza por un digito, puede ser decimal
    else if(isdigit(num[0]))
    {
        valor=atoi(num);
    }
    //Si empieza por -, puede ser un decimal negativo
    else if(num[0]=='-')
    {
        valor=atoi(num);
        if((valor<0) && (valor>=-32768))
        {
            valor=MAXINT+1+valor;
        }
        else
        {
            valor=MAXINT+1;
        }
    }
    //Si empieza por otra cosa, directamente se desecha
    else
    {
        valor=MAXINT+1;
    }
    if((valor<MININT) || (valor>MAXINT))
    {
        throw runtime_error("Entero Fuera De Rango");
    }
    else
    {
        //BS_Z
        valor_Z=CalculaCero(valor);
        //BS_S
        valor_S=CalculaSigno(valor);
        //BS_V
        valor_V=0;
        //BS_C
        valor_C=0;
        //BS_P
        valor_P=CalculaParidad(valor);
    }
    return;
}
//---------------------------------------------------------------------------
CEntero16b::CEntero16b(const CEntero16b &entero)
{
    valor=entero.valor;
    valor_Z=entero.valor_Z;
    valor_S=entero.valor_S;
    valor_V=entero.valor_V;
    valor_C=entero.valor_C;
    valor_P=entero.valor_P;
    return;
}
//---------------------------------------------------------------------------
char *CEntero16b::Decimal(void)
{
    char *cadena=EnteroACadena(InternoAEntero(valor),10);
    return cadena;
}
//---------------------------------------------------------------------------
char *CEntero16b::DecimalCorto(void)
{
    int num=InternoAEnteroCorto(valor);
    char *cadena=EnteroACadena(num,10);
    return cadena;
}
//---------------------------------------------------------------------------
char *CEntero16b::DecimalFormateado(void)
{
    char *cadena=EnteroACadena(InternoAEntero(valor),10);
    CCadena blanco=CCadena(" ");
    CCadena cadaux=CCadena(cadena);
    while(cadaux.Longitud()<6)
    {
        cadaux=blanco+cadaux;
    }
    strcpy(cadena,cadaux.Cadena());
    return cadena;
}
//---------------------------------------------------------------------------
char *CEntero16b::DecimalSinSigno(void)
{
    char *cadena=EnteroACadena(valor,10);
    return cadena;
}
//---------------------------------------------------------------------------
char *CEntero16b::DecimalSinSignoFormateado(void)
{
    char *cadena=EnteroACadena(valor,10);
    CCadena blanco=CCadena(" ");
    CCadena cadaux=CCadena(cadena);
    while(cadaux.Longitud()<6)
    {
        cadaux=blanco+cadaux;
    }
    strcpy(cadena,cadaux.Cadena());
    return cadena;
}
//---------------------------------------------------------------------------
int CEntero16b::EnteroAInterno(int num)
{
    int correccion=0;

    if(num<0)
    {
        correccion=MAXINT+1;
    }
    return correccion+num;
}
//---------------------------------------------------------------------------
char *CEntero16b::Hexadecimal(void)
{
    char *cadena=EnteroACadena(valor,16);
    CCadena cero=CCadena("0");
    CCadena hex=CCadena("0x");
    CCadena cadaux=CCadena(cadena);
    while(cadaux.Longitud()<4)
    {
        cadaux=cero+cadaux;
    }
    cadaux=hex+cadaux;
    strcpy(cadena,cadaux.Cadena());
    return cadena;
}
//---------------------------------------------------------------------------
char *CEntero16b::HexadecimalCorto(void)
{
    char *cadena=EnteroACadena(valor,16);
    CCadena cero=CCadena("0");
    CCadena hex=CCadena("0x");
    CCadena cadaux=CCadena(cadena);
    while(cadaux.Longitud()<2)
    {
        cadaux=cero+cadaux;
    }
    cadaux=hex+cadaux;
    strcpy(cadena,cadaux.Cadena());
    return cadena;
}
//---------------------------------------------------------------------------
int CEntero16b::InternoAEntero(int num)
{
    int correccion=0;

    if(num>=((MAXINT+1)/2))
    {
        correccion=MAXINT+1;
    }
    return num-correccion;
}
//---------------------------------------------------------------------------
int CEntero16b::InternoAEnteroCorto(int num)
{
    int correccion=0;

    if(num>=128)
    {
        correccion=256;
    }
    return num-correccion;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator++ (int)
{
    CEntero16b resultado;
    int auxiliar;
    int auxiliarsinsigno;

    resultado = *this;
    auxiliar=InternoAEntero(valor);
    auxiliarsinsigno=valor;
    auxiliar++;
    auxiliarsinsigno++;

    valor=EnteroAInterno(auxiliar)%(MAXINT+1);
        //El resultado siempre se representa con 16 bits

    //Actualizacion biestables de estado
    //BS_Z
    valor_Z=CalculaCero(valor);
    //BS_S
    valor_S=CalculaSigno(valor);
    //BS_V
    valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    valor_P=CalculaParidad(valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator-- (int)
{
    CEntero16b resultado;
    int auxiliar;
    int auxiliarsinsigno;

    resultado = *this;
    auxiliar=InternoAEntero(valor);
    auxiliarsinsigno=valor;
    auxiliar--;
    auxiliarsinsigno--;

    valor=EnteroAInterno(auxiliar)%(MAXINT+1);
        //El resultado siempre se representa con 16 bits

    //Actualizacion biestables de estado
    //BS_Z
    valor_Z=CalculaCero(valor);
    //BS_S
    valor_S=CalculaSigno(valor);
    //BS_V
    valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    valor_P=CalculaParidad(valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator+ (const CEntero16b &ent2)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    auxiliar=InternoAEntero(valor) + InternoAEntero(ent2.valor);
    auxiliarsinsigno=valor+ent2.valor;
    resultado=CEntero16b(EnteroAInterno(auxiliar)%(MAXINT+1));

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator- (const CEntero16b &ent2)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    auxiliar=InternoAEntero(valor)-InternoAEntero(ent2.valor);
    auxiliarsinsigno=valor-ent2.valor;
    resultado=CEntero16b(EnteroAInterno(auxiliar)%(MAXINT+1));

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator- (void)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    auxiliar= -InternoAEntero(valor);
    auxiliarsinsigno= -valor;
    resultado=CEntero16b(EnteroAInterno(auxiliar)%(MAXINT+1));

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator* (const CEntero16b &ent2)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    auxiliar=InternoAEntero(valor) * InternoAEntero(ent2.valor);
    auxiliarsinsigno=valor*ent2.valor;
    resultado=CEntero16b(EnteroAInterno(auxiliar)%(MAXINT+1));

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator/ (const CEntero16b &ent2)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    if(ent2.valor==0)
    {
        throw runtime_error("Division Por Cero");
    }

    auxiliar=InternoAEntero(valor) / InternoAEntero(ent2.valor);
    auxiliarsinsigno=valor/ent2.valor;
    resultado=CEntero16b(EnteroAInterno(auxiliar)%(MAXINT+1));

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator% (const CEntero16b &ent2)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    if (ent2.valor==0)
    {
        throw runtime_error("Division Por Cero");
    }

    auxiliar=InternoAEntero(valor)%InternoAEntero(ent2.valor);
    auxiliarsinsigno=valor%ent2.valor;
    resultado=CEntero16b(EnteroAInterno(auxiliar)%(MAXINT+1));

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator& (const CEntero16b &ent2)
{
    int auxiliar;
    //int auxiliarsinsigno;
    CEntero16b resultado;

    auxiliar=valor & ent2.valor;
    resultado=CEntero16b(auxiliar);

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator| (const CEntero16b &ent2)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    auxiliar=valor | ent2.valor;
    auxiliarsinsigno=valor | ent2.valor;
    resultado=CEntero16b(auxiliar);

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator^ (const CEntero16b &ent2)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    auxiliar=valor ^ ent2.valor;
    auxiliarsinsigno=valor^ent2.valor;
    resultado=CEntero16b(auxiliar);

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
CEntero16b CEntero16b::operator~ (void)
{
    int auxiliar;
    int auxiliarsinsigno;
    CEntero16b resultado;

    //Este operador funciona en signo-magnitud
    if(valor>32767)
    {
        auxiliar=~(valor-(MAXINT+1));
        auxiliarsinsigno=~(valor-(MAXINT+1));
    }
    else
    {
        auxiliar=~valor;
        auxiliarsinsigno=~valor;
    }
    resultado=CEntero16b(auxiliar);

    //Actualizacion biestables de estado
    //BS_Z
    resultado.valor_Z=CalculaCero(resultado.valor);
    //BS_S
    resultado.valor_S=CalculaSigno(resultado.valor);
    //BS_V
    resultado.valor_V=CalculaDesbordamiento(auxiliar);
    //BS_C
    resultado.valor_C=CalculaAcarreo(auxiliarsinsigno);
    //BS_P
    resultado.valor_P=CalculaParidad(resultado.valor);

    return resultado;
}
//---------------------------------------------------------------------------
int CEntero16b::P(void)
{
    return valor_P;
}
//---------------------------------------------------------------------------
int CEntero16b::S(void)
{
    return valor_S;
}
//---------------------------------------------------------------------------
int CEntero16b::V(void)
{
    return valor_V;
}
//---------------------------------------------------------------------------
int CEntero16b::Valor(void)
{
    return valor;
}
//---------------------------------------------------------------------------
int CEntero16b::Z(void)
{
    return valor_Z;
}
//---------------------------------------------------------------------------
