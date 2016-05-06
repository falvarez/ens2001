//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormValorMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmValorMemoria::BotonAceptarClick(TObject *Sender)
{
    try
    {
        CEntero16b dir=CEntero16b(lblDireccion->Caption.c_str());
        CEntero16b num=CEntero16b(txtMemoria->Text.c_str());
        //Escribimos en memoria
        conf->Memoria()->Escribir(dir,num);
        Close();
    }
    catch(runtime_error)
    {
        ShowMessage("Valor Incorrecto");
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmValorMemoria::LeerTecla(TObject *Sender,WORD &Key,
                                            TShiftState Shift)
{
    if(Key==VK_ESCAPE)
    {
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmValorMemoria::Mostrar(TObject *Sender)
{
    txtMemoria->SetFocus();
}
//---------------------------------------------------------------------------
__fastcall TfrmValorMemoria::TfrmValorMemoria(TComponent* Owner,
                                              CConfiguracion *configuracion)
                                              : TForm(Owner)
{
    conf=configuracion;
}
//---------------------------------------------------------------------------
