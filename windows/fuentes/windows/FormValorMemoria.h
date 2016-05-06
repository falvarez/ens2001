//---------------------------------------------------------------------------
#ifndef FormValorMemoriaH
#define FormValorMemoriaH
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
//---------------------------------------------------------------------------
class TfrmValorMemoria : public TForm
{
    __published:
        //Elementos graficos
        TButton *btnAceptar;
        TEdit *txtMemoria;
        TLabel *lblDireccion;
        //Respuesta a eventos
        //btnAceptar.OnClick
        void __fastcall BotonAceptarClick(TObject *Sender);
        //OnKeyDown
        void __fastcall LeerTecla(TObject *Sender, WORD &Key,
                                  TShiftState Shift);
        //OnShow
        void __fastcall Mostrar(TObject *Sender);
        
    private:
        //Clases con las que se interactua
        CConfiguracion *conf;

    public:
        //Constructor
        __fastcall TfrmValorMemoria(TComponent* Owner,
                                    CConfiguracion *configuracion);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmValorMemoria *frmValorMemoria;
//---------------------------------------------------------------------------
#endif
