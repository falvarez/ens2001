//ccadena.cpp
#include "ccadena.h"
//---------------------------------------------------------------------------
CCadena::CCadena(void)
{
    longitud=0;
    texto=new char[longitud+1];
    strcpy(texto,"");
    return;
}
//---------------------------------------------------------------------------
CCadena::CCadena(const char *cadena)
{
    longitud=strlen(cadena);
    texto=new char[longitud+1];
    strcpy(texto,cadena);
    return;
}
//---------------------------------------------------------------------------
CCadena::CCadena(const CCadena &cadena)
{
    longitud=cadena.longitud;
    texto=new char[longitud+1];
    strcpy(texto,cadena.texto);
    return;
}
//---------------------------------------------------------------------------
CCadena::~CCadena(void)
{
    delete [] texto;
    return;
}
//---------------------------------------------------------------------------
CCadena &CCadena::operator=(const CCadena &cad)
{
    if(this!=&cad)
    {
        longitud=cad.longitud;
        delete [] texto;
        texto=new char[longitud+1];
        strcpy(texto,cad.texto);
    }
    return *this;
}
//---------------------------------------------------------------------------
CCadena operator+(const CCadena &cad1,const CCadena &cad2)
{
    CCadena nueva;

    nueva.longitud=cad1.longitud+cad2.longitud;
    nueva.texto=new char[nueva.longitud+1];
    strcpy(nueva.texto,cad1.texto);
    strcat(nueva.texto,cad2.texto);
    return nueva;
}
//---------------------------------------------------------------------------
CCadena operator+(const CCadena &cad1,const char *cad2)
{
    CCadena nueva;

    nueva.longitud=cad1.longitud+strlen(cad2);
    nueva.texto=new char[nueva.longitud+1];
    strcpy(nueva.texto,cad1.texto);
    strcat(nueva.texto,cad2);
    return nueva;
}
//---------------------------------------------------------------------------
CCadena operator+(const char *cad1,const CCadena &cad2)
{
    CCadena nueva;

    nueva.longitud=strlen(cad1)+cad2.longitud;
    nueva.texto=new char[nueva.longitud+1];
    strcpy(nueva.texto,cad1);
    strcat(nueva.texto,cad2.texto);
    return nueva;
}
//---------------------------------------------------------------------------
CCadena operator+(const CCadena &cad1,const char cad2)
{
    CCadena nueva;
    char *aux;

    aux=new char[2];
    aux[0]=cad2;
    aux[1]='\0';

    nueva.longitud=cad1.longitud+1;
    nueva.texto=new char[nueva.longitud+1];
    strcpy(nueva.texto,cad1.texto);
    strcat(nueva.texto,aux);
    delete [] aux;
    return nueva;
}
//---------------------------------------------------------------------------
CCadena operator+(const char cad1,const CCadena &cad2)
{
    CCadena nueva;
    char *aux;

    aux=new char[2];
    aux[0]=cad1;
    aux[1]='\0';

    nueva.longitud=1+cad2.longitud;
    nueva.texto=new char[nueva.longitud+1];
    strcpy(nueva.texto,aux);
    strcat(nueva.texto,cad2.texto);
    delete [] aux;
    return nueva;
}
//---------------------------------------------------------------------------
ostream &operator<<(ostream &os,const CCadena &cadena)
{
    return(os<<cadena.texto);
}
//---------------------------------------------------------------------------
char CCadena::operator[](int indice)
{
    if(indice>longitud)
    {
        return '\0';
    }
    else
    {
        return(*(texto+indice));
    }
}
//---------------------------------------------------------------------------
int CCadena::Longitud(void)
{
    return longitud;
}
//---------------------------------------------------------------------------
char *CCadena::Cadena(void)
{
    return texto;
}
//---------------------------------------------------------------------------
int CCadena::Comparar(CCadena cad2)
{
    return(strcmp(texto,cad2.texto));
}
//---------------------------------------------------------------------------
int CCadena::Comparar(char *cad2)
{
    return(strcmp(texto,cad2));
}
//---------------------------------------------------------------------------
int CCadena::Comparar(const char *cad2)
{
    return(strcmp(texto,cad2));
}
//---------------------------------------------------------------------------
