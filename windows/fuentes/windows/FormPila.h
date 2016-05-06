//---------------------------------------------------------------------------
#ifndef FormPilaH
#define FormPilaH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>
#pragma hdrstop
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
#include "FormPrincipal.h"
//---------------------------------------------------------------------------
class TfrmPila : public TForm
{
    __published:
        //Elementos Graficos
        TStringGrid *grdPila;
        TButton *btnCentrar;
        TEdit *txtIrA;
        TButton *btnIrA;
        TLabel *Label2;
        TLabel *Label3;
        //Respuesta a eventos
        //OnClose
        void __fastcall Cerrar(TObject *Sender, TCloseAction &Action);
        //OnKeyDown
        void __fastcall LeerTecla(TObject *Sender, WORD &Key,
                                  TShiftState Shift);
        //OnShow
        void __fastcall Mostrar(TObject *Sender);
        //OnHide
        void __fastcall Ocultar(TObject *Sender);
        //OnPaint
        void __fastcall Actualizar(TObject *Sender);
        //grdPila.OnDblClick
        void __fastcall EditarMemoria(TObject *Sender);
        //btnCentrar.OnClick
        void __fastcall BotonCentrarClick(TObject *Sender);
        //btnIrA.Click
        void __fastcall BotonIrAClick(TObject *Sender);
        void __fastcall MemoriaResize(TObject *Sender);
        void __fastcall PilaDeactivate(TObject *Sender);
        
    private:
        //Clases con las que se interactua
        CConfiguracion *conf;
        TfrmPrincipal *principal;
        
    public:
        //Constructor
        __fastcall TfrmPila(TComponent* Owner,CConfiguracion *configuracion);
        //Metodos
        void VolcarMemoria(CEntero16b direccion);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPila *frmPila;
//---------------------------------------------------------------------------
#endif
