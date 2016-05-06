//---------------------------------------------------------------------------
#ifndef FormPrincipalH
#define FormPrincipalH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
#pragma hdrstop
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include <Graphics.hpp>
#include _CADENAS_H_
#include "FormConfiguracion.h"
#include "FormRegistros.h"
#include "FormMemoria.h"
#include "FormPila.h"
#include "FormFuente.h"
#include "FormConsolaEjecucion.h"
#include "ccadena.h"
#include "cconfiguracion.h"
#include "cprocesador.h"
#include "cmemoria.h"
#include "cbancoregistros.h"
#include "cconfiguracion.h"
#include "cgestorpuntosruptura.h"
#include "cinterfazdisco.h"
#include "censamblador.h"
#include "ctprocesador.h"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
    __published:
        //Elementos graficos
        TToolBar *ToolBar1;
        TMainMenu *MainMenu1;
        TMenuItem *mnuArchivo;
        TMenuItem *mnuCargarImagenMemoria;
        TMenuItem *mnuAbrirEnsamblar;
        TMenuItem *mnuGuardarImagenMemoria;
        TMenuItem *mnuConfiguracion;
        TMenuItem *mnuSalir;
        TMenuItem *Ventanas1;
        TMenuItem *Registros1;
        TMenuItem *Memoria1;
        TMenuItem *Pila1;
        TMenuItem *CodigoFuente1;
        TMenuItem *mnuAyuda;
        TMenuItem *mnuAcercaDe;
        TActionList *ActionList1;
        TAction *Salir;
        TAction *CargarImagenMemoria;
        TAction *GuardarImagenMemoria;
        TAction *Configuracion;
        TAction *AbrirEnsamblar;
        TLabel *Label1;
        TStatusBar *stbBarraEstado;
        TOpenDialog *dlgAbrir;
        TSaveDialog *dlgGuardar;
        TMenuItem *Ejecutar1;
        TAction *Ejecutar;
        TMenuItem *Consola1;
        TMemo *mmoMensajes;
        TOpenDialog *dlgEnsamblar;
        TAction *Copiar;
        TAction *SeleccionarTodo;
        TAction *DeseleccionarTodo;
        TAction *Limpiar;
        TMenuItem *Edicion1;
        TMenuItem *SeleccionarTodo1;
        TMenuItem *Copiar1;
        TMenuItem *DeseleccionarTodo1;
        TMenuItem *Limpiar1;
        TPopupMenu *PopupMenu1;
        TMenuItem *SeleccionarTodo2;
        TMenuItem *Copiar2;
        TMenuItem *DeseleccionarTodo2;
        TMenuItem *Limpiar2;
        TMenuItem *mnuGuardarSesion;
        TAction *GuardarSesion;
        TSaveDialog *dlgGuardarSesion;
        TBitBtn *btnAbrirEnsamblar;
        TBitBtn *btnEjecutar;
        TBitBtn *btnCargarImagenMemoria;
        TBitBtn *btnGuardarImagenMemoria;
        TBitBtn *btnGuardarSesion;
        TBitBtn *btnConfiguracion;
        TAction *Parar;
        TImage *imgParar;
        TImage *imgEjecutar;
        TImage *imgPaso;
        //Respuesta a eventos
        //Configuracion.OnExecute
        void __fastcall ConfiguracionExecute(TObject *Sender);
        //Salir.OnExecute
        void __fastcall SalirExecute(TObject *Sender);
        //Registros1.OnClick
        void __fastcall Registros1Click(TObject *Sender);
        //Memoria1.OnClick
        void __fastcall Memoria1Click(TObject *Sender);
        //Pila1.OnClick
        void __fastcall Pila1Click(TObject *Sender);
        //CodigoFuente1.OnClick
        void __fastcall CodigoFuente1Click(TObject *Sender);
        //CargarImagenMemoria.OnExecute
        void __fastcall CargarImagenMemoriaExecute(TObject *Sender);
        //GuardarImagenMemoria.OnExecute
        void __fastcall GuardarImagenMemoriaExecute(TObject *Sender);
        //Ejecutar.OnExecute
        void __fastcall EjecutarExecute(TObject *Sender);
        //OnCloseQuery
        void __fastcall ConfirmarCerrar(TObject *Sender, bool &CanClose);
        //mnuAcercaDe.OnClick
        void __fastcall MenuAcercaDeClick(TObject *Sender);
        //AbrirEnsamblar.OnExecute
        void __fastcall AbrirEnsamblarExecute(TObject *Sender);
        //Consola1.OnClick
        void __fastcall Consola1Click(TObject *Sender);
        //OnResize
        void __fastcall PrincipalResize(TObject *Sender);
        //Copiar.OnExecute
        void __fastcall CopiarExecute(TObject *Sender);
        //SeleccionarTodo.OnExecute
        void __fastcall SeleccionarTodoExecute(TObject *Sender);
        //DeseleccionarTodo.OnExecute
        void __fastcall DeseleccionarTodoExecute(TObject *Sender);
        //Limpiar.OnExecute
        void __fastcall LimpiarExecute(TObject *Sender);
        //btnCargarImagenMemoria.OnEnter
        void __fastcall EstadoCargarImagenMemoria(TObject *Sender);
        //btnGuardarImagenMemoria.OnEnter
        void __fastcall EstadoGuardarImagenMemoria(TObject *Sender);
        //btnAbrirEnsamblar.OnEnter
        void __fastcall EstadoAbrirEnsamblar(TObject *Sender);
        //btnEjecutar.OnEnter
        void __fastcall EstadoEjecutar(TObject *Sender);
        //btnConfiguracion.OnEnter
        void __fastcall EstadoConfiguracion(TObject *Sender);
        //btnGuardarSesion.OnEnter
        void __fastcall EstadoGuardarSesion(TObject *Sender);
        //mmoMensajes.OnEnter
        void __fastcall EstadoMensajes(TObject *Sender);
        //GuardarSesion.OnExecute
        void __fastcall GuardarSesionExecute(TObject *Sender);
        //Parar.OnExecute
        void __fastcall PararExecute(TObject *Sender);
        //OnShow
        void __fastcall Mostrar(TObject *Sender);
        //btnEjecutar.OnClick
        void __fastcall BotonEjecutarClick(TObject *Sender);
        //OnKeyDown
        void __fastcall LeerTeclado(TObject *Sender, WORD &Key,
                                    TShiftState Shift);
        
        //Metodos auxiliares
        int  __fastcall GuardarPosicionVentanas(void);
        int  __fastcall CargarPosicionVentanas(void);

    private :
        //Atributos
        String entrada;
        String salida;
        String textoconsola;
        String tipoentrada;
        //Ventanas Flotantes
        TfrmConfiguracion *vconfiguracion;
        TfrmRegistros *vregistros;
        TfrmMemoria *vmemoria;
        TfrmPila *vpila;
        TfrmFuente *vfuente;
        TfrmConsolaEjecucion *vconsola;
        //Componentes del simulador
        CConfiguracion *conf;
        CMemoria *m;
        CBancoRegistros *b;
        CProcesador *p;
        CEntradaSalida *es;
        CGestorPuntosRuptura *gpr;
        //Hilo que ejecuta la simulacion
        CTProcesador *thread_procesador;
        bool ejecutando;
        //Directorio de trabajo
        char *cwd;

    public:
        //Constructor
        __fastcall TfrmPrincipal(TComponent* Owner);
        //Metodos
        void __fastcall ComenzarEjecucion(void);
        void __fastcall EscribirConsola(void);
        void __fastcall FinEjecucion(void);
        void __fastcall LeerConsola(void);
        void __fastcall MostrarEstado(String estado);
        void __fastcall MostrarMensaje(String mensaje);
        void __fastcall MostrarMensajeDesdeFichero(String fichero);
        void __fastcall RefrescarVentanas(void);
        //Acceso a atributos
        void LeerEntrada(String &valor);
        void EscribirEntrada(String valor);
        void LeerSalida(String &valor);
        void EscribirSalida(String valor);
        void LeerTextoConsola(String &valor);
        void EscribirTextoConsola(String valor);
        void LeerTipoEntrada(String &valor);
        void EscribirTipoEntrada(String valor);
        bool PermisoEscribir(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
