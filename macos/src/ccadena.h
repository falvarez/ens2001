//ccadena.h

#ifndef _CCADENA_H_
#define _CCADENA_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include <iostream>
using namespace std;

class CCadena
{
    private:
        //Atributos
        char *texto;
        int longitud;

    public:
        //Constructor por defecto
        CCadena(void);
        //Constructor con inicializacion
        CCadena(char *cadena);
        //Constructor Copia
        CCadena(const CCadena &cadena);
        //Destructor
        ~CCadena(void);
        //Metodos
        //Operadores
        CCadena &operator=(const CCadena &cad);
        friend CCadena operator+(const CCadena &cad1,const CCadena &cad2);
        friend CCadena operator+(const CCadena &cad1,const char *cad2);
        friend CCadena operator+(const char *cad1,const CCadena &cad2);
        friend CCadena operator+(const CCadena &cad1,const char cad2);
        friend CCadena operator+(const char cad1,const CCadena &cad2);
        friend ostream &operator<<(ostream &os,const CCadena &cadena);
        char operator[](int indice);
	    //Acceso a atributos
        int Longitud(void);
        char *Cadena(void);
        //Comparaciones
        int Comparar(CCadena cad2);
        int Comparar(char *cad2);
};

#endif //_CCADENA_H_
