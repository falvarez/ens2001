//---------------------------------------------------------------------------
#ifndef FormConfiguracionH
#define FormConfiguracionH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#pragma hdrstop
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include _CADENAS_H_
#include "cconfiguracion.h"
//---------------------------------------------------------------------------
class TfrmConfiguracion : public TForm
{
    __published: 
        //Elementos graficos
        TRadioGroup *rdgBaseRepresentacion;
        TRadioGroup *rdgModoPila;
        TRadioGroup *rdgModoDepuracion;
        TRadioGroup *rdgModoEjecucion;
        TRadioGroup *rdgComprobarPC;
        TRadioGroup *rdgComprobarPila;
        TRadioGroup *rdgResetearRegistros;
        TButton *btnAceptar;
        TButton *btnCancelar;
        //Respuesta a eventos
        //OnKeyDown
        void __fastcall LeerTecla(TObject *Sender,WORD &Key,
                                  TShiftState Shift);
        //OnShow
        void __fastcall MostrarConfiguracion(TObject *Sender);
        //btnAceptar.OnClick
        void __fastcall BotonAceptarClick(TObject *Sender);
        //btnCancelar.OnClick
        void __fastcall BotonCancelarClick(TObject *Sender);

    private: 
        //Clases con las que interactua
        CConfiguracion *conf;

    public: 
        //Constructor
        __fastcall TfrmConfiguracion(TComponent* Owner,
                                     CConfiguracion *configuracion);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConfiguracion *frmConfiguracion;
//---------------------------------------------------------------------------
#endif
