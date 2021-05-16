//cinterfazdisco.cpp

#include "cinterfazdisco.h"
//---------------------------------------------------------------------------
//Constructor
CInterfazDisco::CInterfazDisco(CConfiguracion *configuracion)
{
    conf=configuracion;
    return;
}
//---------------------------------------------------------------------------
//Metodos
int CInterfazDisco::VolcarDiscoAMemoria(CCadena fichero)
{
    ifstream entrada;
    unsigned char datoH[1];
    unsigned char datoL[1];
    CEntero16b dato;

#ifdef _ENS2001_WINDOWS_
    entrada.open(fichero.Cadena(),ios::binary);
#endif
#ifdef _ENS2001_CONSOLA_
    entrada.open(fichero.Cadena(),ios::binary);
#endif
#ifdef _ENS2001_MACOS_
    entrada.open(fichero.Cadena());
#endif
    if (entrada!=NULL)
    {
        for(int i=0;i<MAXINT+1;i++)
        {
            entrada.read((char *)datoH,1);
            entrada.read((char *)datoL,1);
            dato=CEntero16b((*datoH)*256+(*datoL));
            conf->Memoria()->Escribir(CEntero16b(i),dato);
        }
        entrada.close();
        return 0;
    }
    else
    {
        //Error al abrir el fichero
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazDisco::VolcarMemoriaADisco(CCadena fichero)
{
    ofstream salida;
    unsigned char datoH[1];
    unsigned char datoL[1];
    CEntero16b dato;

#ifdef _ENS2001_WINDOWS_
    salida.open(fichero.Cadena(),ios::binary);
#endif
#ifdef _ENS2001_CONSOLA_
    salida.open(fichero.Cadena(),ios::binary);
#endif
#ifdef _ENS2001_MACOS_
    salida.open(fichero.Cadena());
#endif

    if (salida!=NULL)
    {
        for(int i=0;i<MAXINT+1;i++)
        {
            conf->Memoria()->Leer(CEntero16b(i),dato);
            *datoH=dato.Valor()/256;
            *datoL=dato.Valor()%256;
            salida.write((char *)datoH,1);
            salida.write((char *)datoL,1);
        }
        salida.close();
        return 0;
    }
    else
    {
        //Error al abrir el fichero
        return -1;
    }
}
//---------------------------------------------------------------------------
