//---------------------------------------------------------------------------
#ifndef FormRegistrosH
#define FormRegistrosH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#pragma hdrstop
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include _CADENAS_H_
#include "FormPrincipal.h"
#include "cconfiguracion.h"
#include "cbancoregistros.h"
//---------------------------------------------------------------------------
class TfrmRegistros : public TForm
{
    __published:
        //Elementos graficos
        TGroupBox *grpRegistros;
        TLabel *lblRegA;
        TLabel *lblRegR0;
        TLabel *lblRegR1;
        TLabel *lblRegR2;
        TLabel *lblRegR3;
        TLabel *lblRegR5;
        TLabel *lblRegR4;
        TLabel *lblRegR6;
        TLabel *lblRegR7;
        TLabel *lblRegR8;
        TLabel *lblRegR9;
        TLabel *lblRegPC;
        TLabel *lblRegSP;
        TLabel *lblRegIX;
        TLabel *lblRegIY;
        TLabel *lblRegSR;
        TGroupBox *GroupBox1;
        TLabel *lblBSZ;
        TLabel *lblBS;
        TLabel *lblBSP;
        TLabel *lblBSC;
        TLabel *lblBSV;
        TEdit *txtRegR0;
        TEdit *txtRegR1;
        TEdit *txtRegR2;
        TEdit *txtRegR3;
        TEdit *txtRegR4;
        TEdit *txtRegR5;
        TEdit *txtRegR6;
        TEdit *txtRegR7;
        TEdit *txtRegR8;
        TEdit *txtRegR9;
        TEdit *txtRegPC;
        TEdit *txtRegSP;
        TEdit *txtRegIX;
        TEdit *txtRegIY;
        TEdit *txtRegSR;
        TEdit *txtBSZ;
        TEdit *txtBSS;
        TEdit *txtBSP;
        TEdit *txtBSV;
        TEdit *txtRegA;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TLabel *lblPila1;
        TLabel *lblPila2;
        TLabel *lblCodigo1;
        TLabel *lblCodigo2;
        TEdit *txtBSC;
        TButton *btnReiniciar;
        TGroupBox *GroupBox2;
        TLabel *lblInstruccion;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *txtBSH;
        //Respuesta a eventos
        //OnClose
        void __fastcall Cerrar(TObject *Sender, TCloseAction &Action);
        //OnPaint
        void __fastcall Actualizar(TObject *Sender);
        //txtRegA.OnDblClick
        void __fastcall EditarRegistroA(TObject *Sender);
        //txtRegR0.OnDblClick
        void __fastcall EditarRegistroR0(TObject *Sender);
        //txtRegR1.OnDblClick
        void __fastcall EditarRegistroR1(TObject *Sender);
        //txtRegR2.OnDblClick
        void __fastcall EditarRegistroR2(TObject *Sender);
        //txtRegR3.OnDblClick
        void __fastcall EditarRegistroR3(TObject *Sender);
        //txtRegR4.OnDblClick
        void __fastcall EditarRegistroR4(TObject *Sender);
        //txtRegR5.OnDblClick
        void __fastcall EditarRegistroR5(TObject *Sender);
        //txtRegR6.OnDblClick
        void __fastcall EditarRegistroR6(TObject *Sender);
        //txtRegR7.OnDblClick
        void __fastcall EditarRegistroR7(TObject *Sender);
        //txtRegR8.OnDblClick
        void __fastcall EditarRegistroR8(TObject *Sender);
        //txtRegR9.OnDblClick
        void __fastcall EditarRegistroR9(TObject *Sender);
        //txtRegPC.OnDblClick
        void __fastcall EditarRegistroPC(TObject *Sender);
        //txtRegSP.OnDblClick
        void __fastcall EditarRegistroSP(TObject *Sender);
        //txtRegIX.OnDblClick
        void __fastcall EditarRegistroIX(TObject *Sender);
        //txtRegIY.OnDblClick
        void __fastcall EditarRegistroIY(TObject *Sender);
        //txtRegSR.OnDblClick
        void __fastcall EditarRegistroSR(TObject *Sender);
        //txt*.OnKeyDown
        void __fastcall LeerTecla(TObject *Sender, WORD &Key,
                                  TShiftState Shift);
        //OnHide
        void __fastcall Ocultar(TObject *Sender);
        //OnShow
        void __fastcall Mostrar(TObject *Sender);
        //btnResetar.OnClick
        void __fastcall BotonReiniciarClick(TObject *Sender);

    private:
        //Clases con las que se interactua
        CConfiguracion *conf;
        TfrmPrincipal *principal;
        //Funciones auxiliares
        void __fastcall EditarRegistro(int registro);

    public:
        //Constructor
        __fastcall TfrmRegistros(TComponent* Owner,CConfiguracion *conf);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRegistros *frmRegistros;
//---------------------------------------------------------------------------
#endif
