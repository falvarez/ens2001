//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormConfiguracion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguracion::BotonAceptarClick(TObject *Sender)
{
    //Guardamos la configuracion
    if(rdgBaseRepresentacion->Items->
           Strings[rdgBaseRepresentacion->ItemIndex]=="Base 10 (&decimal)")
    {
        conf->EscribirBaseNumerica(10);
    }
    else
    {
        conf->EscribirBaseNumerica(16);
    }
    if(rdgModoPila->Items->Strings[rdgModoPila->ItemIndex] == 
       "Direcciones &Ascendentes")
    {
        conf->EscribirModoPila(PILA_CRECIENTE);
    }
    else
    {
        conf->EscribirModoPila(PILA_DECRECIENTE);
    }
    if(rdgModoDepuracion->Items->Strings[rdgModoDepuracion->ItemIndex]=="Sí")
    {
        conf->EscribirModoDepuracion(SI);
    }
    else
    {
        conf->EscribirModoDepuracion(NO);
    }
    if(rdgModoEjecucion->Items->Strings[rdgModoEjecucion->ItemIndex]=="Sí")
    {
        conf->EscribirModoEjecucion(ME_PASOAPASO);
    }
    else
    {
        conf->EscribirModoEjecucion(ME_NORMAL);
    }
    if(rdgComprobarPC->Items->Strings[rdgComprobarPC->ItemIndex]=="Sí")
    {
        conf->EscribirComprobarPC(SI);
    }
    else
    {
        conf->EscribirComprobarPC(NO);
    }
    if(rdgComprobarPila->Items->Strings[rdgComprobarPila->ItemIndex]=="Sí")
    {
        conf->EscribirComprobarPila(SI);
    }
    else
    {
        conf->EscribirComprobarPila(NO);
    }
    if(rdgResetearRegistros->Items->Strings[rdgResetearRegistros->ItemIndex]==
       "Sí")
    {
        conf->EscribirReiniciarRegistros(SI);
    }
    else
    {
        conf->EscribirReiniciarRegistros(NO);
    }
    if(conf->GuardarConfiguracion()!=0)
    {
    	//Error al guardar el fichero de configuracion
    	ShowMessage("Error al guardar la configuración en disco");
    }
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguracion::BotonCancelarClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguracion::LeerTecla(TObject *Sender,WORD &Key,
                                             TShiftState Shift)
{
    if (Key==VK_ESCAPE)
    {
        this->Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguracion::MostrarConfiguracion(TObject *Sender)
{
    if(conf->BaseNumerica()==10)
    {
        rdgBaseRepresentacion->ItemIndex=0;
    }
    else
    {
        rdgBaseRepresentacion->ItemIndex=1;
    }
    if(conf->ModoPila()==PILA_CRECIENTE)
    {
        rdgModoPila->ItemIndex=0;
    }
    else
    {
        rdgModoPila->ItemIndex=1;
    }
    if(conf->ModoDepuracion()==SI)
    {
        rdgModoDepuracion->ItemIndex=0;
    }
    else
    {
        rdgModoDepuracion->ItemIndex=1;
    }
    if(conf->ModoEjecucion()==ME_PASOAPASO)
    {
        rdgModoEjecucion->ItemIndex=0;
    }
    else
    {
        rdgModoEjecucion->ItemIndex=1;
    }
    if(conf->ComprobarPC()==SI)
    {
        rdgComprobarPC->ItemIndex=0;
    }
    else
    {
        rdgComprobarPC->ItemIndex=1;
    }
    if(conf->ComprobarPila()==SI)
    {
        rdgComprobarPila->ItemIndex=0;
    }
    else
    {
        rdgComprobarPila->ItemIndex=1;
    }
    if(conf->ReiniciarRegistros()==SI)
    {
        rdgResetearRegistros->ItemIndex=0;
    }
    else
    {
        rdgResetearRegistros->ItemIndex=1;
    }
}
//---------------------------------------------------------------------------
__fastcall TfrmConfiguracion::TfrmConfiguracion(TComponent* Owner,
                                                CConfiguracion *configuracion)
                                                : TForm(Owner)
{
    conf=configuracion;
}
//---------------------------------------------------------------------------

