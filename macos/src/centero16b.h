//centero16b.h

#ifndef _CENTERO16B_H_
#define _CENTERO16B_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"

extern "C" char *EnteroACadena(int entero,int base);

class CEntero16b
{
    private:
        //Atributos
        int valor;
        int valor_Z;
        int valor_S;
        int valor_V;
        int valor_C;
        int valor_P;

        //Metodos auxiliares
        int CalculaCero(int num);
        int CalculaSigno(int num);
        int CalculaParidad(int num);
        int CalculaAcarreo(int num);
        int CalculaDesbordamiento(int num);
        int InternoAEntero(int num);
            //Pasa de la representacion interna en complemento a 2
            //a valor entero con signo
        int InternoAEnteroCorto(int num);
            //Pasa de la representacion interna en complemento a 2
            //a valor entero con signo (para 8 bits)
        int EnteroAInterno(int num);
            //Pasa de valor entero con signo a la representacion
            //interna en complemento a 2
    public:
        //Constructores
        CEntero16b(); //Constructor por defecto, genera el valor 0
        CEntero16b(int num);
        CEntero16b(const char *valor);
        CEntero16b(const CEntero16b &entero); //Constructor Copia

        //Operaciones Aritmeticas y Logicas
        CEntero16b operator++ (int);
        CEntero16b operator-- (int);

        CEntero16b operator+ (const CEntero16b &ent2);
        CEntero16b operator- (const CEntero16b &ent2);
        CEntero16b operator- (void);
        CEntero16b operator* (const CEntero16b &ent2);
        CEntero16b operator/ (const CEntero16b &ent2);
        CEntero16b operator% (const CEntero16b &ent2);

        CEntero16b operator& (const CEntero16b &ent2);
        CEntero16b operator| (const CEntero16b &ent2);
        CEntero16b operator^ (const CEntero16b &ent2);
        CEntero16b operator~ (void);

        //Metodos
        //Visualizacion en distinas bases
        char *Decimal(void);
        char *DecimalFormateado(void);
        char *DecimalSinSigno(void);
        char *DecimalSinSignoFormateado(void);
        char *DecimalCorto(void);
        char *Hexadecimal(void);
        char *HexadecimalCorto(void);
        //Consulta de atributos
        int Valor(void);
        //Consulta de los biestables de estado asociados
        int Z(void);
        int S(void);
        int V(void);
        int C(void);
        int P(void);
};

#endif //_CENTERO16B_H_
