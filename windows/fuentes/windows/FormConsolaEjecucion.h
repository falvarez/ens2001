//---------------------------------------------------------------------------
#ifndef FormConsolaEjecucionH
#define FormConsolaEjecucionH
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"
#include "FormPrincipal.h"
//---------------------------------------------------------------------------
class TfrmConsolaEjecucion : public TForm
{
    __published:
        //Elementos Graficos
        TMemo *mmoConsola;
        TActionList *ActionList1;
        TAction *SeleccionarTodo;
        TAction *Limpiar;
        TAction *Copiar;
        TAction *DeseleccionarTodo;
        TPopupMenu *PopupMenu1;
        TMenuItem *SeleccionarTodo1;
        TMenuItem *Copiar1;
        TMenuItem *DeseleccionarTodo1;
        TMenuItem *Limpiar1;
        TLabel *lblTipo;
        //Respuesta a eventos
        //OnClose
        void __fastcall Cerrar(TObject *Sender, TCloseAction &Action);
        //OnCloseQuery
        void __fastcall ConfirmarCerrar(TObject *Sender, bool &CanClose);
        //OnResize
        void __fastcall ConsolaResize(TObject *Sender);
        //OnShow
        void __fastcall Mostrar(TObject *Sender);
        //mmoConsola.OnKeyDown
        void __fastcall LeerTeclado(TObject *Sender, WORD &Key,
                                    TShiftState Shift);
        //mmoConsola.OnKeyPress
        void __fastcall LeerCaracteres(TObject *Sender, char &Key);
        //SeleccionarTodo.OnExecute
        void __fastcall SeleccionarTodoExecute(TObject *Sender);
        //SeleccionarTodo1.OnClick
        void __fastcall SeleccionarTodo1Click(TObject *Sender);
        //Limpiar.OnExecute
        void __fastcall LimpiarExecute(TObject *Sender);
        //Copiar.OnExecute
        void __fastcall CopiarExecute(TObject *Sender);
        //DeseleccionarTodo.OnExecute
        void __fastcall DeseleccionarTodoExecute(TObject *Sender);
        //Copiar1.OnClick
        void __fastcall Copiar1Click(TObject *Sender);
        //DeseleccionarTodo1.OnClick
        void __fastcall DeseleccionarTodo1Click(TObject *Sender);
        //Limpiar1.OnClick
        void __fastcall Limpiar1Click(TObject *Sender);
        void __fastcall Ocultar(TObject *Sender);

    private:
        //Clases con las que se interactua
        TfrmPrincipal *principal;
        //Atributos
        bool terminar;
        bool modal;
        String buffer;
        
    public:
        //Constructor
        __fastcall TfrmConsolaEjecucion(TComponent* Owner);
        //Metodos
        bool Modal();
            //Leer el atributo modal
        void EscribirModal(bool valor);
            //Escribir el atributo modal
        void LeerBuffer(String &valor);
            //Leer el atributo buffer
        void __fastcall MostrarCadena(String cadena);
            //Muestra la cadena indicada en la consola
        bool Terminar();
            //Leer el atributo terminar
        void EscribirTerminar(bool);
            //Escribir el atributo terminar
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConsolaEjecucion *frmConsolaEjecucion;
//---------------------------------------------------------------------------
#endif
