//cgestorpuntosruptura.cpp

#include "cgestorpuntosruptura.h"
//---------------------------------------------------------------------------
CGestorPuntosRuptura::CGestorPuntosRuptura(CConfiguracion *configuracion)
{
    //Inicializamos la lista de puntos
    Reiniciar();
    //Damos de alta el componente en la configuracion
    conf=configuracion;
    conf->EscribirGestorPuntosRuptura(this);
    return;
}
//---------------------------------------------------------------------------
int CGestorPuntosRuptura::Consultar(CEntero16b direccion)
{
    if (direcciones[direccion.Valor()])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//---------------------------------------------------------------------------
int CGestorPuntosRuptura::Intercambiar(CEntero16b direccion)
{
    if(direcciones[direccion.Valor()])
    {
        direcciones[direccion.Valor()]=false;
        return 0;
    }
    else
    {
        direcciones[direccion.Valor()]=true;
        return 1;
    }
}
//---------------------------------------------------------------------------
void CGestorPuntosRuptura::Reiniciar(void)
{
    for(int i=0;i<(MAXINT+1);i++)
    {
        direcciones[i]=false;
    }
}
//---------------------------------------------------------------------------
