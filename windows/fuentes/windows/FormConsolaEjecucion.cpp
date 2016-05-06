//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormConsolaEjecucion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::Cerrar(TObject *Sender,
                                             TCloseAction &Action)
{
    principal->Consola1->Checked=false;
    modal=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::ConfirmarCerrar(TObject *Sender,
      bool &CanClose)
{
    if(modal && !terminar)
    {
        ShowMessage("Introduzca un valor o interrumpa la ejecución pulsando la tecla ESC");
        CanClose=false;
    }
    else
    {
        CanClose=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::ConsolaResize(TObject *Sender)
{
    mmoConsola->Height=Height-70;
    mmoConsola->Width=Width-25;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::CopiarExecute(TObject *Sender)
{
    mmoConsola->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::Copiar1Click(TObject *Sender)
{
    CopiarExecute(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::DeseleccionarTodoExecute(TObject *Sender)
{
    mmoConsola->SelLength=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::DeseleccionarTodo1Click(TObject *Sender)
{
    DeseleccionarTodoExecute(Sender);
}
//---------------------------------------------------------------------------
void TfrmConsolaEjecucion::EscribirModal(bool valor)
{
    modal=valor;
}
//---------------------------------------------------------------------------
void TfrmConsolaEjecucion::EscribirTerminar(bool valor)
{
    terminar=valor;
}
//---------------------------------------------------------------------------
void TfrmConsolaEjecucion::LeerBuffer(String &valor)
{
    valor=buffer;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::LeerCaracteres(TObject *Sender,
                                                     char &Key)
{
    if(modal)
    {
        if(Key!='\b')
        {
            MostrarCadena(String(Key));
            buffer=buffer+String(Key);
        }
        else if(buffer!="")
        {
            //Tratar borrado
            String ultimalinea=
                mmoConsola->Lines->Strings[mmoConsola->Lines->Count-1];

            String nuevobuffer=String(buffer.c_str(),buffer.Length()-1);
            String nuevalinea=
                String(ultimalinea.c_str(),ultimalinea.Length()-1);

            buffer=nuevobuffer;
            mmoConsola->Lines->Delete(mmoConsola->Lines->Count-1);
            mmoConsola->Lines->Add(nuevalinea);
            mmoConsola->SelStart=mmoConsola->Lines->Text.Length()-2;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::LeerTeclado(TObject *Sender,WORD &Key,
                                                  TShiftState Shift)
{
    if(modal)
    {
        if(Key==VK_RETURN)
        {
            //Añadimos retorno de carro
            mmoConsola->Lines->Add("");
            //No se detiene la ejecucion
            terminar=false;
            modal=false; //Para distinguir de la pulsacion
                         //del boton de cerrar ventana
            Close();
        }
        else if(Key==VK_ESCAPE)
        {
            //Se detiene la ejecucion a peticion del usuario
            terminar=true;
            Close();
        }
    }
    else if(Key==VK_ESCAPE)
    {
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::LimpiarExecute(TObject *Sender)
{
    mmoConsola->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::Limpiar1Click(TObject *Sender)
{
    LimpiarExecute(Sender);
}
//---------------------------------------------------------------------------
bool TfrmConsolaEjecucion::Modal()
{
    return modal;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::Mostrar(TObject *Sender)
{
    principal->Consola1->Checked=true;
    terminar=false;
    if(modal)
    {
        buffer="";
        principal->btnEjecutar->Enabled=false;
    }
    else
    {
        principal->btnEjecutar->Enabled=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::MostrarCadena(String cadena)
{
    String ultimalinea;
    int lineas=mmoConsola->Lines->Count;
    if (lineas>0)
    {
        ultimalinea=mmoConsola->Lines->Strings[lineas-1];
        mmoConsola->Lines->Delete(lineas-1);
    }
    for(int i=1;i<=cadena.Length();i++)
    {
        if(cadena[i]=='\n')
        {
            mmoConsola->Lines->Add(ultimalinea);
            ultimalinea="";
        }
        else
        {
            ultimalinea=ultimalinea+String(cadena[i]);
        }
    }
    mmoConsola->Lines->Add(ultimalinea);
    mmoConsola->SelStart=mmoConsola->Lines->Text.Length()-2;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::SeleccionarTodoExecute(TObject *Sender)
{
    mmoConsola->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::SeleccionarTodo1Click(
      TObject *Sender)
{
    SeleccionarTodoExecute(Sender);
}
//---------------------------------------------------------------------------
bool TfrmConsolaEjecucion::Terminar()
{
    return terminar;
}
//---------------------------------------------------------------------------
__fastcall TfrmConsolaEjecucion::TfrmConsolaEjecucion(TComponent* Owner)
                                                      : TForm(Owner)
{
    principal=(TfrmPrincipal *)Owner;
    mmoConsola->Clear();
    terminar=false;
    buffer="";
    modal=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsolaEjecucion::Ocultar(TObject *Sender)
{
    principal->Consola1->Checked=false;
    principal->btnEjecutar->Enabled=true;
}
//---------------------------------------------------------------------------

