//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormValorRegistro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmValorRegistro::BotonAceptarClick(TObject *Sender)
{
    CEntero16b num;

    try
    {
        num=CEntero16b(txtRegistro->Text.Trim().c_str());
        switch(reg)
        {
            case A :
                conf->BancoRegistros()->Escribir(A,num);
                break;
            case R0 :
                conf->BancoRegistros()->Escribir(R0,num);
                break;
            case R1 :
                conf->BancoRegistros()->Escribir(R1,num);
                break;
            case R2 :
                conf->BancoRegistros()->Escribir(R2,num);
                break;
            case R3 :
                conf->BancoRegistros()->Escribir(R3,num);
                break;
            case R4 :
                conf->BancoRegistros()->Escribir(R4,num);
                break;
            case R5 :
                conf->BancoRegistros()->Escribir(R5,num);
                break;
            case R6 :
                conf->BancoRegistros()->Escribir(R6,num);
                break;
            case R7 :
                conf->BancoRegistros()->Escribir(R7,num);
                break;
            case R8 :
                conf->BancoRegistros()->Escribir(R8,num);
                break;
            case R9 :
                conf->BancoRegistros()->Escribir(R9,num);
                break;
            case PC :
                conf->BancoRegistros()->Escribir(PC,num);
                break;
            case SP :
                conf->BancoRegistros()->Escribir(SP,num);
                break;
            case IX :
                conf->BancoRegistros()->Escribir(IX,num);
                break;
            case IY :
                conf->BancoRegistros()->Escribir(IY,num);
                break;
            case SR :
                conf->BancoRegistros()->Escribir(SR,num);
                break;
        }
        Close();
    }
    catch(runtime_error)
    {
        if(conf->BancoRegistros()->RegistroExcepcion()== EX_SP_INVADE_CODIGO)
        {
            ShowMessage("Valor Incorrecto: SP invade la zona de código");
        }
        else if(conf->BancoRegistros()->RegistroExcepcion()== 
                EX_PC_INVADE_PILA)
        {
            ShowMessage("Valor Incorrecto: PC invade la zona de pila");
        }
        else
        {
            ShowMessage("Valor Incorrecto");
        }
    }
}
//---------------------------------------------------------------------------
void TfrmValorRegistro::EscribirReg(int valor)
{
    reg=valor;
}
//---------------------------------------------------------------------------
void __fastcall TfrmValorRegistro::LeerTecla(TObject *Sender,WORD &Key,
                                             TShiftState Shift)
{
    if(Key==VK_ESCAPE)
    {
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmValorRegistro::Mostrar(TObject *Sender)
{
    txtRegistro->SetFocus();
}
//---------------------------------------------------------------------------
int TfrmValorRegistro::Reg(void)
{
    return reg;
}
//---------------------------------------------------------------------------
__fastcall TfrmValorRegistro::TfrmValorRegistro(TComponent* Owner,
                                                CConfiguracion *configuracion)
                                                : TForm(Owner)
{
    conf=configuracion;
}
//---------------------------------------------------------------------------
