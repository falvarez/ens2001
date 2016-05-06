//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("winens.res");
USEUNIT("fuentes\ccadena.cpp");
USEUNIT("fuentes\cconfiguracion.cpp");
USEUNIT("fuentes\cdesensamblador.cpp");
USEUNIT("fuentes\censamblador.cpp");
USEUNIT("fuentes\centero16b.cpp");
USEUNIT("fuentes\cgestorinstrucciones.cpp");
USEUNIT("fuentes\cgestorpuntosruptura.cpp");
USEUNIT("fuentes\cinstruccion.cpp");
USEUNIT("fuentes\cinterfazdisco.cpp");
USEUNIT("fuentes\cmemoria.cpp");
USEUNIT("fuentes\cprocesador.cpp");
USEUNIT("fuentes\ctprocesador.cpp");
USEUNIT("fuentes\gestionmemoria.c");
USEUNIT("fuentes\gestionerrores.c");
USEUNIT("fuentes\gestionetiquetas.c");
USEUNIT("fuentes\funcionesauxiliares.c");
USEUNIT("fuentes\ens_lex.c");
USEUNIT("fuentes\ENS_TAB.C");
USEFORM("fuentes\windows\FormValorRegistro.cpp", frmValorRegistro);
USEFORM("fuentes\windows\FormConfiguracion.cpp", frmConfiguracion);
USEFORM("fuentes\windows\FormConsolaEjecucion.cpp", frmConsolaEjecucion);
USEFORM("fuentes\windows\FormFuente.cpp", frmFuente);
USEFORM("fuentes\windows\FormMemoria.cpp", frmMemoria);
USEFORM("fuentes\windows\FormPila.cpp", frmPila);
USEFORM("fuentes\windows\FormPrincipal.cpp", frmPrincipal);
USEFORM("fuentes\windows\FormRegistros.cpp", frmRegistros);
USEFORM("fuentes\windows\FormValorMemoria.cpp", frmValorMemoria);
USEUNIT("fuentes\cbancoregistros.cpp");
USEUNIT("fuentes\centradasalida.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 TfrmPrincipal *frmPrincipal;
                 Application->Initialize();
                 Application->Title = "Ens2001";
                 Application->CreateForm(__classid(TfrmPrincipal), &frmPrincipal);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
