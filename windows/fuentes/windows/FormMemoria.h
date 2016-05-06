//---------------------------------------------------------------------------
#ifndef FormMemoriaH
#define FormMemoriaH
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
#include _CADENAS_H_
#include "cconfiguracion.h"
#include "FormPrincipal.h"
//---------------------------------------------------------------------------
class TfrmMemoria : public TForm
{
    __published:
        //Elementos Graficos
        TStringGrid *grdMemoria;
        TButton *btnReiniciar;
        TEdit *txtIrA;
        TButton *btnIrA;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        //Respuesta a eventos
        //OnClose
        void __fastcall Cerrar(TObject *Sender, TCloseAction &Action);
        //OnPaint
        void __fastcall Actualizar(TObject *Sender);
        //OnKeyDown
        void __fastcall LeerTecla(TObject *Sender, WORD &Key,
                                  TShiftState Shift);
        //OnHide
        void __fastcall Ocultar(TObject *Sender);
        //OnShow
        void __fastcall Mostrar(TObject *Sender);
        //grdMemoria.OnDblClick
        void __fastcall EditarMemoria(TObject *Sender);
        //btnReiniciar.OnClick
        void __fastcall BotonReiniciarClick(TObject *Sender);
        //btnIrA.OnClick
        void __fastcall BotonIrAClick(TObject *Sender);
        void __fastcall MemoriaResize(TObject *Sender);
        void __fastcall MemoriaDeactivate(TObject *Sender);

    private:
        //Clases con las que se interactua
        CConfiguracion *conf;
        TfrmPrincipal *principal;
        
    public:
        //Constructor
        __fastcall TfrmMemoria(TComponent* Owner,
                               CConfiguracion *configuracion);
        //Metodos
        void VolcarMemoria(CEntero16b direccion);
            //Muestra el contenido de la memoria a partir de la direccion
            //indicada.
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMemoria *frmMemoria;
//---------------------------------------------------------------------------
#endif
