//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include _CADENAS_H_

#include "FormFuente.h"

#include "cdesensamblador.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::Actualizar(TObject *Sender)
{
    String direccion;
    CEntero16b dir;

    if(!volcando)
    {
        if(filaactual>(grdFuente->TopRow))
        {
            dir=CEntero16b(grdFuente->TopRow);
        }
        else
        {
            direccion=grdFuente->Cells[1][grdFuente->TopRow];
            if(direccion=="")
            {
                direccion=grdFuente->TopRow;
            }
            try
            {
                dir=CEntero16b(direccion.c_str());
            }
            catch(runtime_error)
            {
                dir=CEntero16b(0);
            }
        }
        VolcarFuente(dir);
        txtIrA->Text=grdFuente->Cells[1][grdFuente->TopRow];
        filaactual=grdFuente->TopRow;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::BotonCentrarClick(TObject *Sender)
{
    CEntero16b pc;
    
    conf->BancoRegistros()->Leer(PC,pc);
    VolcarFuente(pc);
    txtIrA->Text=grdFuente->Cells[1][grdFuente->TopRow];
    filaactual=grdFuente->TopRow;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::BotonIrAClick(TObject *Sender)
{
    CEntero16b direccion;

    try
    {
        direccion=CEntero16b(txtIrA->Text.c_str());
        grdFuente->TopRow=direccion.Valor();
        Actualizar(Sender);
    }
    catch(runtime_error)
    {
        ShowMessage("Valor Incorrecto");
        txtIrA->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::Cerrar(TObject *Sender, TCloseAction &Action)
{
    principal->CodigoFuente1->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::EditarPuntoRuptura(TObject *Sender)
{
    CEntero16b direccion;
    CEntero16b pc;

    int celda=grdFuente->Selection.Top;
    direccion=CEntero16b((grdFuente->Cells[1][celda]).c_str());

    int puntoruptura=conf->GestorPuntosRuptura()->Intercambiar(direccion);
    conf->BancoRegistros()->Leer(PC,pc);
    //Colocamos el puntero pc si corresponde
    if(direccion.Valor()==pc.Valor())
    {
        grdFuente->Cells[0][celda]=String("PC -> ");
    }
    else
    {
        grdFuente->Cells[0][celda]=String("");
    }
    //Colocamos el indicador de punto de ruptura si corresponde
    if (puntoruptura==0)
    {
        grdFuente->Cells[0][celda]=String("")+grdFuente->Cells[0][celda];
    }
    else
    {
        grdFuente->Cells[0][celda]=String(" * ")+grdFuente->Cells[0][celda];
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::LeerTecla(TObject *Sender, WORD &Key,
                                      TShiftState Shift)
{
    if (Key==VK_ESCAPE)
    {
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::Mostrar(TObject *Sender)
{
    principal->CodigoFuente1->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::Ocultar(TObject *Sender)
{
    principal->CodigoFuente1->Checked=false;
}
//---------------------------------------------------------------------------
__fastcall TfrmFuente::TfrmFuente(TComponent* Owner,
                                  CConfiguracion *configuracion)
                                  : TForm(Owner)
{
    conf=configuracion;
    principal=(TfrmPrincipal *)Owner;
    grdFuente->ColWidths[0]=40;
    grdFuente->ColWidths[1]=40;
    grdFuente->ColWidths[2]=165;
    volcando=false;
}
//---------------------------------------------------------------------------
void TfrmFuente::VolcarFuente(CEntero16b direccion)
{
    CDesensamblador *desens;
    CCadena instruccion;
    CEntero16b pc;
    int i=0;
    int filas;
    int direccionanterior;
    bool fin=false; //Final de la memoria

    //Comienza el volcado
    volcando=true;
    //Creamos el objeto desensamblador
    desens=new CDesensamblador(conf);
    //Comprobamos cuantas filas hay visibles
    filas=grdFuente->VisibleRowCount;
    conf->BancoRegistros()->Leer(PC,pc);
    grdFuente->TopRow=direccion.Valor();
    while(i<(filas+1) && !fin)
    {
        //Miramos si hay definido un punto de ruptura
        switch(conf->GestorPuntosRuptura()->Consultar(direccion))
        {
            case 0 : grdFuente->Cells[0][grdFuente->TopRow+i]="";
                     break;
            case 1 : grdFuente->Cells[0][grdFuente->TopRow+i]=" * ";
                     break;
        }
        //Si es la direccion apuntada por PC ponemos el marcador
        if(direccion.Valor()==pc.Valor())
        {
            grdFuente->Cells[0][grdFuente->TopRow+i]=
                grdFuente->Cells[0][grdFuente->TopRow+i]+String("PC -> ");
        }
        switch(conf->BaseNumerica())
        {
            case 10 : grdFuente->Cells[1][grdFuente->TopRow+i]=
                          String(direccion.DecimalSinSigno());
                      break;
            case 16 : grdFuente->Cells[1][grdFuente->TopRow+i]=
                          String(direccion.Hexadecimal());
                      break;
        }
        //Desensamblamos la instruccion
        direccionanterior=direccion.Valor();
        desens->Desensamblar(direccion,instruccion);
        if(direccionanterior >= direccion.Valor())
        {
            //Se ha traspasado el limite de memoria
            fin=true;
        }
        grdFuente->Cells[2][grdFuente->TopRow+i]=String(instruccion.Cadena());
        i++;
    }
    if(fin)
    {
        //Rellenamos con blancos el resto del codigo fuente
        while(i<(filas+1))
        {
            grdFuente->Cells[0][grdFuente->TopRow+i]="";
            grdFuente->Cells[1][grdFuente->TopRow+i]="";
            grdFuente->Cells[2][grdFuente->TopRow+i]="";
            i++;
        }
    }
    //Destruimos el objeto desensamblador
    delete(desens);
    //Finaliza el volcado
    volcando=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::FuenteResize(TObject *Sender)
{
    grdFuente->Height=Height-110;
}
//---------------------------------------------------------------------------
void __fastcall TfrmFuente::FuenteDeactivate(TObject *Sender)
{
    TGridRect seleccion;
    seleccion.Left=-1;
    seleccion.Top=-1;
    seleccion.Right=-1;
    seleccion.Bottom=-1;
    grdFuente->Selection = seleccion;        
}
//---------------------------------------------------------------------------

