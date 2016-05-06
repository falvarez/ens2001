//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormPila.h"
#include "FormValorMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmPila::Actualizar(TObject *Sender)
{
    CEntero16b direccion=CEntero16b(grdPila->TopRow);
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
void __fastcall TfrmPila::BotonCentrarClick(TObject *Sender)
{
    CEntero16b sp;
    CEntero16b direccion;
    CEntero16b i=CEntero16b(grdPila->VisibleRowCount);
    conf->BancoRegistros()->Leer(SP,sp);
    switch(conf->ModoPila())
    {
        case PILA_CRECIENTE :
        
            if((sp.Valor()-i.Valor()+1)<MININT)
            {
                direccion=CEntero16b(MININT);
            }
            direccion=sp-i+1;
            break;

        case PILA_DECRECIENTE :

            if((i.Valor()+sp.Valor()-1)>MAXINT)
            {
                direccion=CEntero16b(MAXINT)-i+1;
            }
            direccion=sp;
            break;
    }
    VolcarMemoria(direccion);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPila::BotonIrAClick(TObject *Sender)
{
    CEntero16b direccion;

    try
    {
        direccion=CEntero16b(txtIrA->Text.c_str());
        VolcarMemoria(direccion);
    }
    catch(runtime_error)
    {
        ShowMessage("Valor Incorrecto");
        txtIrA->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPila::Cerrar(TObject *Sender, TCloseAction &Action)
{
    principal->Pila1->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPila::EditarMemoria(TObject *Sender)
{
    if(principal->PermisoEscribir())
    {
        CEntero16b direccion;
        CEntero16b valor;

        direccion=CEntero16b(grdPila->Selection.Top);
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
void __fastcall TfrmPila::LeerTecla(TObject *Sender, WORD &Key,
                                    TShiftState Shift)
{
    if(Key==VK_ESCAPE)
    {
        Close();
    }
    else if(Key==VK_RETURN)
    {
        BotonIrAClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPila::Mostrar(TObject *Sender)
{
    principal->Pila1->Checked=true;
    CEntero16b pila;
    conf->BancoRegistros()->Leer(SP,pila);
    VolcarMemoria(pila);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPila::Ocultar(TObject *Sender)
{
    principal->Pila1->Checked=false;
}
//---------------------------------------------------------------------------
__fastcall TfrmPila::TfrmPila(TComponent* Owner,CConfiguracion *configuracion)
                              : TForm(Owner)
{
    conf=configuracion;
    principal=(TfrmPrincipal *)Owner;
}
//---------------------------------------------------------------------------
void TfrmPila::VolcarMemoria(CEntero16b direccion)
{
    CEntero16b puntero;
    CEntero16b valor;
    CEntero16b i;
    int filas;

    //Comprobamos cuantas filas hay visibles
    filas=grdPila->VisibleRowCount;
    i=CEntero16b(filas);

    //Cargamos donde apunta SP
    conf->BancoRegistros()->Leer(SP,puntero);

    //Centramos la visualizacion
    if(direccion.Valor()>(MAXINT-(filas-1)))
    {
        direccion=CEntero16b(MAXINT-(filas-1));
    }
    grdPila->TopRow=direccion.Valor();
    //Rellenamos los valores visibles
    while(i.Valor()>0 && direccion.Valor()<MAXINT+1)
    {
        i--;
        conf->Memoria()->Leer(direccion,valor);
        //Si es la direccion apuntada por SP ponemos el marcador
        if(direccion.Valor()==puntero.Valor())
        {
            grdPila->Cells[0][direccion.Valor()]=String("SP -> ");
        }
        //Si no, borramos posibles marcadores anteriores
        else
        {
            grdPila->Cells[0][direccion.Valor()]=String("");
        }
        //Ponemos el valor contenido en la direccion de memoria
        switch(conf->BaseNumerica())
        {
            case 10 : 
                grdPila->Cells[1][direccion.Valor()]=
                     String(direccion.DecimalSinSigno());
                grdPila->Cells[2][direccion.Valor()]=
                     String(valor.Decimal());
                break;
            case 16 : 
                grdPila->Cells[1][direccion.Valor()]=
                     String(direccion.Hexadecimal());
                grdPila->Cells[2][direccion.Valor()]=
                     String(valor.Hexadecimal());
                break;
        }
        direccion++;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPila::MemoriaResize(TObject *Sender)
{
    grdPila->Height=Height-110;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPila::PilaDeactivate(TObject *Sender)
{
    TGridRect seleccion;
    seleccion.Left=-1;
    seleccion.Top=-1;
    seleccion.Right=-1;
    seleccion.Bottom=-1;
    grdPila->Selection = seleccion;
}
//---------------------------------------------------------------------------

