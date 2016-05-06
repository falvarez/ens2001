//---------------------------------------------------------------------------
#ifndef FormValorRegistroH
#define FormValorRegistroH
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
#include _CADENAS_H_
#include "cconfiguracion.h"
#include "cbancoregistros.h"
//---------------------------------------------------------------------------
class TfrmValorRegistro : public TForm
{
    __published:
        //Elementos graficos
        TLabel *lblRegistro;
        TEdit *txtRegistro;
        TButton *btnAceptar;
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
        //atributos
        int reg;
        
    public:
        //Constructor
        __fastcall TfrmValorRegistro(TComponent* Owner,
                                     CConfiguracion *configuracion);
        //Metodos
        int Reg(void);
            //Leer el atributo reg
        void EscribirReg(int valor);
            //Escribir el atributo reg
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmValorRegistro *frmValorRegistro;
//---------------------------------------------------------------------------
#endif
