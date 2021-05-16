//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ctprocesador.h"
#include "centradasalida.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Unit1::UpdateCaption()
//      {
//    Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall CTProcesador::CTProcesador(bool CreateSuspended)
                                      : TThread(CreateSuspended)
{
    FreeOnTerminate=true;
}
//---------------------------------------------------------------------------
void __fastcall CTProcesador::Execute()
{
    int h;

    Synchronize(vprincipal->ComenzarEjecucion);
    configuracion->EntradaSalida()->EscribirHilo(this);
    configuracion->BancoRegistros()->LeerBiestableEstado(BS_H,h);
    if((configuracion->ReiniciarRegistros()==SI) && (h==1))
    {
        //Si finalizo el programa anteriormente,y esta activada la opcion
        //en la configuracion, reseteamos los registros
        configuracion->BancoRegistros()->Reiniciar();
    }
    else
    {
        ReturnValue=EJ_SIGUIENTE;
    }
    while(!Terminated && ReturnValue==EJ_SIGUIENTE)
    {
        ReturnValue=configuracion->Procesador()->EjecutarPaso();
    }
    configuracion->BancoRegistros()->EscribirRegistroFinEjecucion(ReturnValue);
    if(Terminated)
    {
        configuracion->BancoRegistros()->
            EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
        configuracion->BancoRegistros()->
            EscribirRegistroFinEjecucion(EJ_EXCEPCION);
    }
    Synchronize(vprincipal->FinEjecucion);

}
//---------------------------------------------------------------------------
void CTProcesador::EscribirConfiguracion(CConfiguracion *conf)
{
    configuracion=conf;
}
//---------------------------------------------------------------------------
void CTProcesador::EscribirPrincipal(TfrmPrincipal *ventana)
{
    vprincipal=ventana;
}
//---------------------------------------------------------------------------
int CTProcesador::Leer(CEntero16b &entero)
{
    String entrada;

    vprincipal->EscribirTipoEntrada("Entero");
    Synchronize(vprincipal->LeerConsola);
    try
    {
        vprincipal->LeerEntrada(entrada);
        entero=CEntero16b(entrada.c_str());
    }
    catch(std::runtime_error)
    {
        entero=CEntero16b(0);
    }
}
//---------------------------------------------------------------------------
int CTProcesador::Leer(char &caracter)
{
    String entrada;
    String salida;

    vprincipal->EscribirTipoEntrada("Car�cter");
    Synchronize(vprincipal->LeerConsola);
    vprincipal->LeerSalida(salida);
    if(salida.Length()>0)
    {
        vprincipal->LeerEntrada(entrada);
        caracter=entrada.c_str()[0];
    }
    else
    {
        caracter='\n';
    }
}
//---------------------------------------------------------------------------
int CTProcesador::Leer(CCadena &cadena)
{
    String entrada;

    vprincipal->EscribirTipoEntrada("Cadena");
    Synchronize(vprincipal->LeerConsola);
    vprincipal->LeerEntrada(entrada);
    cadena=CCadena(entrada.c_str());
}
//---------------------------------------------------------------------------
int CTProcesador::Escribir(CEntero16b entero)
{
    switch(configuracion->BaseNumerica())
    {
        case 10 : vprincipal->EscribirSalida(String(entero.Decimal()));
                  break;
        case 16 : vprincipal->EscribirSalida(String(entero.Hexadecimal()));
                  break;
    }
    Synchronize(vprincipal->EscribirConsola);
}
//---------------------------------------------------------------------------
int CTProcesador::Escribir(char caracter)
{
    vprincipal->EscribirSalida(String(caracter));
    Synchronize(vprincipal->EscribirConsola);
}
//---------------------------------------------------------------------------
int CTProcesador::Escribir(CCadena cadena)
{
    vprincipal->EscribirSalida(String(cadena.Cadena()));
    Synchronize(vprincipal->EscribirConsola);
}
//---------------------------------------------------------------------------
