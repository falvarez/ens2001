//---------------------------------------------------------------------------
#ifndef FormFuenteH
#define FormFuenteH
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
class TfrmFuente : public TForm
{
    __published:
        //Elementos graficos
        TStringGrid *grdFuente;
        TEdit *txtIrA;
        TButton *btnIrA;
        TButton *btnCentrar;
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
        //OnShow
        void __fastcall Mostrar(TObject *Sender);
        //OnHide
        void __fastcall Ocultar(TObject *Sender);
        //grdFuente.OnDblClick
        void __fastcall EditarPuntoRuptura(TObject *Sender);
        //btnIrA.OnClick
        void __fastcall BotonIrAClick(TObject *Sender);
        //btnCentrar.Click
        void __fastcall BotonCentrarClick(TObject *Sender);
        void __fastcall FuenteResize(TObject *Sender);
        void __fastcall FuenteDeactivate(TObject *Sender);
        
    private:
        //Clases con las que se interactua
        CConfiguracion *conf;
        TfrmPrincipal *principal;
        //Variable auxiliar para prevenir un bucle infinito al actualizar
        bool volcando;
        int filaactual;
        
    public:
        //Constructor
        __fastcall TfrmFuente(TComponent* Owner,
                              CConfiguracion *configuracion);
        //Metodos
        void VolcarFuente(CEntero16b direccion);
            //Desensambla codigo a partir de la direccion indicada
            //por el parametro.
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFuente *frmFuente;
//---------------------------------------------------------------------------
#endif
