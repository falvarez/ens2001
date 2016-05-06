//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormMemoria.h"
#include "FormValorMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::Actualizar(TObject *Sender)
{
    CEntero16b direccion=CEntero16b(grdMemoria->TopRow);
    VolcarMemoria(direccion);
    switch(conf->BaseNumerica())
    {
        case 10 : txtIrA->Text=direccion.DecimalSinSigno();
                  break;
        case 16 : txtIrA->Text=direccion.Hexadecimal();
                  break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::BotonIrAClick(TObject *Sender)
{
    CEntero16b direccion;

    try
    {
        direccion=CEntero16b(txtIrA->Text.c_str());
        grdMemoria->TopRow=direccion.Valor();
        Actualizar(Sender);
    }
    catch(runtime_error)
    {
        ShowMessage("Valor Incorrecto");
        txtIrA->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::BotonReiniciarClick(TObject *Sender)
{
    if (principal->PermisoEscribir())
    {
        int confirmar=
            MessageBox(NULL,"¿Reiniciar la Memoria?",
                       "Ens2001",MB_YESNO|MB_TASKMODAL|MB_ICONQUESTION);
        if(confirmar==IDYES)
        {
            conf->Memoria()->Reiniciar();
            principal->RefrescarVentanas();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::Cerrar(TObject *Sender, TCloseAction &Action)
{
    principal->Memoria1->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::EditarMemoria(TObject *Sender)
{
    if (principal->PermisoEscribir())
    {
        CEntero16b direccion;
        CEntero16b valor;

        direccion=CEntero16b(grdMemoria->Selection.Top);
        conf->Memoria()->Leer(direccion,valor);
        TfrmValorMemoria *vvalormemoria=
            new TfrmValorMemoria(this,conf);
        switch(conf->BaseNumerica())
        {
            case 10:
                vvalormemoria->lblDireccion->Caption=
                    String(direccion.DecimalSinSigno());
                vvalormemoria->txtMemoria->Text=
                    String(valor.Decimal());
                break;
            case 16:
                vvalormemoria->lblDireccion->Caption=
                    String(direccion.Hexadecimal());
                vvalormemoria->txtMemoria->Text=String(valor.Hexadecimal());
                break;
        }
        vvalormemoria->Top=Top+10;
        vvalormemoria->Left=Left+10;
        vvalormemoria->ShowModal();
        delete vvalormemoria;
        principal->RefrescarVentanas();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::LeerTecla(TObject *Sender, WORD &Key,
                                       TShiftState Shift)
{
    if (Key==VK_ESCAPE)
    {
        Close();
    }
    else if(Key==VK_RETURN)
    {
        BotonIrAClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::Mostrar(TObject *Sender)
{
    principal->Memoria1->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::Ocultar(TObject *Sender)
{
    principal->Memoria1->Checked=false;
}
//---------------------------------------------------------------------------
__fastcall TfrmMemoria::TfrmMemoria(TComponent* Owner,
                                    CConfiguracion *configuracion)
                                    : TForm(Owner)
{
    conf=configuracion;
    principal=(TfrmPrincipal *)Owner;
}
//---------------------------------------------------------------------------
void TfrmMemoria::VolcarMemoria(CEntero16b direccion)
{
    CEntero16b valor;
    CCadena parametro;
    CEntero16b i;
    int filas;

    //Comprobamos cuantas filas hay visibles
    filas=grdMemoria->VisibleRowCount;
    i=CEntero16b(filas);

    int cod1=conf->BancoRegistros()->Codigo1().Valor();
    int cod2=conf->BancoRegistros()->Codigo2().Valor();
    int pila1=conf->BancoRegistros()->Pila1().Valor();
    int pila2=conf->BancoRegistros()->Pila2().Valor();
    //Centramos la visualizacion
    if (direccion.Valor()>(MAXINT-(filas-1)))
    {
        direccion=CEntero16b(MAXINT-(filas-1));
    }
    grdMemoria->TopRow=direccion.Valor();
    //Rellenamos los valores visibles
    while(i.Valor()>0 && direccion.Valor()<MAXINT+1)
    {
        i--;
        conf->Memoria()->Leer(direccion,valor);
        //Miramos si la posicion de memoria pertenece al codigo, 
        //a la pila o a nada
        if((cod1<=direccion.Valor() && cod2>=direccion.Valor()) ||
           (cod2<=direccion.Valor() && cod1>=direccion.Valor()))
        {
            grdMemoria->Cells[0][direccion.Valor()]=String(" C ");
        }
        else
        {
            grdMemoria->Cells[0][direccion.Valor()]=String("");
        }
        if((pila1<=direccion.Valor() && pila2>=direccion.Valor()) ||
           (pila2<=direccion.Valor() && pila1>=direccion.Valor()))
        {
            grdMemoria->Cells[0][direccion.Valor()]=
                grdMemoria->Cells[0][direccion.Valor()]+String(" P ");
        }
        switch(conf->BaseNumerica())
        {
            case 10 : 
                grdMemoria->Cells[1][direccion.Valor()]=
                    String(direccion.DecimalSinSigno());
                grdMemoria->Cells[2][direccion.Valor()]=
                    String(valor.Decimal());
                break;
            case 16 :  
                grdMemoria->Cells[1][direccion.Valor()]=
                    String(direccion.Hexadecimal());
                grdMemoria->Cells[2][direccion.Valor()]=
                    String(valor.Hexadecimal());
                break;
        }
        direccion++;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::MemoriaResize(TObject *Sender)
{
    grdMemoria->Height=Height-110;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMemoria::MemoriaDeactivate(TObject *Sender)
{
    TGridRect seleccion;
    seleccion.Left=-1;
    seleccion.Top=-1;
    seleccion.Right=-1;
    seleccion.Bottom=-1;
    grdMemoria->Selection = seleccion;
}
//---------------------------------------------------------------------------

