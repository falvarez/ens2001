//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormRegistros.h"
#include "FormValorRegistro.h"
#include "cdesensamblador.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::Actualizar(TObject *Sender)
{
    CEntero16b a;
    CEntero16b r0;
    CEntero16b r1;
    CEntero16b r2;
    CEntero16b r3;
    CEntero16b r4;
    CEntero16b r5;
    CEntero16b r6;
    CEntero16b r7;
    CEntero16b r8;
    CEntero16b r9;
    CEntero16b pc;
    CEntero16b sp;
    CEntero16b ix;
    CEntero16b iy;
    CEntero16b sr;

    int z;
    int c;
    int v;
    int p;
    int s;
    int h;

    CEntero16b cod1;
    CEntero16b cod2;
    CEntero16b pila1;
    CEntero16b pila2;

    conf->BancoRegistros()->Leer(A,a);
    conf->BancoRegistros()->Leer(R0,r0);
    conf->BancoRegistros()->Leer(R1,r1);
    conf->BancoRegistros()->Leer(R2,r2);
    conf->BancoRegistros()->Leer(R3,r3);
    conf->BancoRegistros()->Leer(R4,r4);
    conf->BancoRegistros()->Leer(R5,r5);
    conf->BancoRegistros()->Leer(R6,r6);
    conf->BancoRegistros()->Leer(R7,r7);
    conf->BancoRegistros()->Leer(R8,r8);
    conf->BancoRegistros()->Leer(R9,r9);
    conf->BancoRegistros()->Leer(PC,pc);
    conf->BancoRegistros()->Leer(SP,sp);
    conf->BancoRegistros()->Leer(IX,ix);
    conf->BancoRegistros()->Leer(IY,iy);
    conf->BancoRegistros()->Leer(SR,sr);

    conf->BancoRegistros()->LeerBiestableEstado(BS_Z,z);
    conf->BancoRegistros()->LeerBiestableEstado(BS_C,c);
    conf->BancoRegistros()->LeerBiestableEstado(BS_V,v);
    conf->BancoRegistros()->LeerBiestableEstado(BS_P,p);
    conf->BancoRegistros()->LeerBiestableEstado(BS_S,s);
    conf->BancoRegistros()->LeerBiestableEstado(BS_H,h);

    cod1=conf->BancoRegistros()->Codigo1();
    cod2=conf->BancoRegistros()->Codigo2();
    pila1=conf->BancoRegistros()->Pila1();
    pila2=conf->BancoRegistros()->Pila2();

    switch(conf->BaseNumerica())
    {
        case 10 :
        
            txtRegA->Text=String(a.Decimal());
            txtRegR0->Text=String(r0.Decimal());
            txtRegR1->Text=String(r1.Decimal());
            txtRegR2->Text=String(r2.Decimal());
            txtRegR3->Text=String(r3.Decimal());
            txtRegR4->Text=String(r4.Decimal());
            txtRegR5->Text=String(r5.Decimal());
            txtRegR6->Text=String(r6.Decimal());
            txtRegR7->Text=String(r7.Decimal());
            txtRegR8->Text=String(r8.Decimal());
            txtRegR9->Text=String(r9.Decimal());
            txtRegPC->Text=String(pc.DecimalSinSigno());
            txtRegSP->Text=String(sp.DecimalSinSigno());
            txtRegIX->Text=String(ix.DecimalSinSigno());
            txtRegIY->Text=String(iy.DecimalSinSigno());
            txtRegSR->Text=String(sr.Decimal());

            lblPila1->Caption=String(pila1.DecimalSinSigno());
            lblPila2->Caption=String(pila2.DecimalSinSigno());
            lblCodigo1->Caption=String(cod1.DecimalSinSigno());
            lblCodigo2->Caption=String(cod2.DecimalSinSigno());
            break;
            
        case 16 :
        
            txtRegA->Text=String(a.Hexadecimal());
            txtRegR0->Text=String(r0.Hexadecimal());
            txtRegR1->Text=String(r1.Hexadecimal());
            txtRegR2->Text=String(r2.Hexadecimal());
            txtRegR3->Text=String(r3.Hexadecimal());
            txtRegR4->Text=String(r4.Hexadecimal());
            txtRegR5->Text=String(r5.Hexadecimal());
            txtRegR6->Text=String(r6.Hexadecimal());
            txtRegR7->Text=String(r7.Hexadecimal());
            txtRegR8->Text=String(r8.Hexadecimal());
            txtRegR9->Text=String(r9.Hexadecimal());
            txtRegPC->Text=String(pc.Hexadecimal());
            txtRegSP->Text=String(sp.Hexadecimal());
            txtRegIX->Text=String(ix.Hexadecimal());
            txtRegIY->Text=String(iy.Hexadecimal());
            txtRegSR->Text=String(sr.Hexadecimal());

            lblPila1->Caption=String(pila1.Hexadecimal());
            lblPila2->Caption=String(pila2.Hexadecimal());
            lblCodigo1->Caption=String(cod1.Hexadecimal());
            lblCodigo2->Caption=String(cod2.Hexadecimal());
            break;
    }
    txtBSZ->Text=String(z);
    txtBSC->Text=String(c);
    txtBSS->Text=String(s);
    txtBSP->Text=String(p);
    txtBSV->Text=String(v);
    txtBSH->Text=String(h);
    //Desensamblamos la siguiente instruccion
    CDesensamblador *desens=new CDesensamblador(conf);
    CCadena instruccion;
    desens->Desensamblar(pc,instruccion);
    lblInstruccion->Caption=String(instruccion.Cadena());
    delete desens;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::BotonReiniciarClick(TObject *Sender)
{
    if(principal->PermisoEscribir())
    {
        int confirmar=
            MessageBox(NULL,"¿Reiniciar el Banco de Registros?",
                       "Ens2001",MB_YESNO|MB_TASKMODAL|MB_ICONQUESTION);
        if(confirmar==IDYES)
        {
            conf->BancoRegistros()->Reiniciar();
            Refresh();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::Cerrar(TObject *Sender,TCloseAction &Action)
{
    principal->Registros1->Checked=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistro(int registro)
{
    if (principal->PermisoEscribir())
    {
        CEntero16b reg;
        CCadena nombre;

        conf->BancoRegistros()->Leer(registro,reg);
        conf->BancoRegistros()->
            LeerNombreRegistro(registro,nombre);

        TfrmValorRegistro *vvalorregistro=
            new TfrmValorRegistro(this,conf);
        vvalorregistro->Caption="Editar "+String(nombre.Cadena());
        vvalorregistro->lblRegistro->Caption=String(nombre.Cadena());
        vvalorregistro->EscribirReg(registro);
        switch(conf->BaseNumerica())
        {
            case 10:
                if(registro==PC || registro==SP || registro==IX || registro==IY)
                {
                    vvalorregistro->txtRegistro->Text=
                        String(reg.DecimalSinSigno());
                }
                else
                {
                    vvalorregistro->txtRegistro->Text=String(reg.Decimal());
                }
                break;
            case 16:
                vvalorregistro->txtRegistro->Text=String(reg.Hexadecimal());
                break;
        }
        vvalorregistro->Top=Top+10;
        vvalorregistro->Left=Left+10;
        vvalorregistro->ShowModal();
        delete vvalorregistro;
        principal->RefrescarVentanas();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroA(TObject *Sender)
{
    EditarRegistro(A);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR0(TObject *Sender)
{
    EditarRegistro(R0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR1(TObject *Sender)
{
    EditarRegistro(R1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR2(TObject *Sender)
{
    EditarRegistro(R2);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR3(TObject *Sender)
{
    EditarRegistro(R3);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR4(TObject *Sender)
{
    EditarRegistro(R4);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR5(TObject *Sender)
{
    EditarRegistro(R5);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR6(TObject *Sender)
{
    EditarRegistro(R6);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR7(TObject *Sender)
{
    EditarRegistro(R7);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR8(TObject *Sender)
{
    EditarRegistro(R8);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroR9(TObject *Sender)
{
    EditarRegistro(R9);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroPC(TObject *Sender)
{
    EditarRegistro(PC);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroSP(TObject *Sender)
{
    EditarRegistro(SP);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroIX(TObject *Sender)
{
    EditarRegistro(IX);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroIY(TObject *Sender)
{
    EditarRegistro(IY);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::EditarRegistroSR(TObject *Sender)
{
    EditarRegistro(SR);
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::LeerTecla(TObject *Sender,WORD &Key,
                                         TShiftState Shift)
{
    if (Key==VK_ESCAPE)
    {
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::Mostrar(TObject *Sender)
{
    principal->Registros1->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmRegistros::Ocultar(TObject *Sender)
{
    principal->Registros1->Checked=false;
}
//---------------------------------------------------------------------------
__fastcall TfrmRegistros::TfrmRegistros(TComponent* Owner,
                                        CConfiguracion *configuracion)
                                        : TForm(Owner)
{
    conf=configuracion;
    principal=(TfrmPrincipal *)Owner;
}
//---------------------------------------------------------------------------
