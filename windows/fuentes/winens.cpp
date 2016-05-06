//---------------------------------------------------------------------------
#include "compilacion.h"
#include <vcl.h>
#pragma hdrstop
#include "definiciones.h"
#include "defscpp.h"
//---------------------------------------------------------------------------
USERES("winens.res");
USEUNIT("cbancoregistros.cpp");
USEUNIT("centradasalida.cpp");
USEUNIT("ccadena.cpp");
USEUNIT("cconfiguracion.cpp");
USEUNIT("cdesensamblador.cpp");
USEUNIT("censamblador.cpp");
USEUNIT("centero16b.cpp");
USEUNIT("cgestorinstrucciones.cpp");
USEUNIT("cgestorpuntosruptura.cpp");
USEUNIT("cinstruccion.cpp");
USEUNIT("cinterfazdisco.cpp");
USEUNIT("cmemoria.cpp");
USEUNIT("cprocesador.cpp");
USEFORM("FormConfiguracion.cpp", frmConfiguracion);
USEFORM("FormFuente.cpp", frmFuente);
USEFORM("FormMemoria.cpp", frmMemoria);
USEFORM("FormPila.cpp", frmPila);
USEFORM("FormPrincipal.cpp", frmPrincipal);
USEFORM("FormRegistros.cpp", frmRegistros);
USEFORM("FormValorRegistro.cpp", frmValorRegistro);
USEUNIT("gestionmemoria.c");
USEUNIT("ENS_TAB.C");
USEUNIT("funcionesauxiliares.c");
USEUNIT("gestionerrores.c");
USEUNIT("gestionetiquetas.c");
USEUNIT("ens_lex.c");
USEFORM("FormValorMemoria.cpp", frmValorMemoria);
USEUNIT("ctprocesador.cpp");
USEFORM("FormConsolaEjecucion.cpp", frmConsolaEjecucion);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    //Formulario Principal
    TfrmPrincipal *frmPrincipal;
    try
    {
         Application->Initialize();
         Application->Title = "Ens2001";
         Application->CreateForm(__classid(TfrmPrincipal), &frmPrincipal);
         Application->Run();
    }
    catch(Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
