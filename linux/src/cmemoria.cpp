// cmemoria.cpp
#include "cmemoria.h"

CMemoria::CMemoria(CConfiguracion *configuracion)
{
    //Damos de alta el componente en la configuracion
    conf=configuracion;
    conf->EscribirMemoria(this);
    return;
}
//---------------------------------------------------------------------------
void CMemoria::Escribir(CEntero16b direccion,CEntero16b valor)
{
    //Guardamos el valor en memoria
    celdas[direccion.Valor()]=valor;
    return;
};
//---------------------------------------------------------------------------
void CMemoria::Leer(CEntero16b direccion,CEntero16b &valor)
{
    //Recuperamos el valor almacenado en memoria
    valor=celdas[direccion.Valor()];
    return;
}
//---------------------------------------------------------------------------
void CMemoria::Reiniciar(void)
{
    //Bucle para inicializar la memoria a 0
    for(int i=MININT;i<(MAXINT+1);i++)
    {
        celdas[i]=CEntero16b(0);
    }
    return;
}
//---------------------------------------------------------------------------
