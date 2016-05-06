//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FormPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::AbrirEnsamblarExecute(TObject *Sender)
{
    String estadoanterior;
    estadoanterior=stbBarraEstado->SimpleText;
    MostrarEstado("Ensamblando Fichero Fuente");

    int lineas=0; //Número de líneas procesadas
    CInterfazDisco *disco;

    //Recuperamos el Directorio Actual
    ForceCurrentDirectory=true;
    dlgEnsamblar->InitialDir=
        String((conf->DirectorioActual()).Cadena());
    //Ningún nombre de fichero por defecto
    dlgEnsamblar->FileName="";
    //Abrimos el cuadro de diálogo
    dlgEnsamblar->Execute();

    if(dlgEnsamblar->FileName!="")
    {
        //Guardamos el Directorio Actual en el que retornamos del diálogo
        conf->EscribirDirectorioActual(CCadena(getcwd(NULL,255)));
        CCadena fichero=CCadena((dlgEnsamblar->FileName).c_str());
        MostrarMensaje(String(S_CADENA_093)+String(fichero.Cadena()));
        CEnsamblador *ens = new CEnsamblador(conf);
        int retorno=ens->Ensamblar(fichero,lineas);
        delete(ens);
        switch(retorno)
        {
            case 0 :   
             
                MostrarMensaje(String(S_CADENA_002)+String(lineas));
                //Lineas procesadas
                MostrarMensaje(String(S_CADENA_004)+String(fichero.Cadena())+
                               String(S_CADENA_005));
                //Fichero //ensamblado correctamente
                //Abrimos el fichero memoria.tmp
                try
                {
                    //Creamos la interfaz de disco
                    disco=new CInterfazDisco(conf);
                    //Leemos el fichero desde disco
                    int retorno=disco->
                        VolcarDiscoAMemoria(CCadena(FICHERO_TEMPORAL_MEMORIA));
                    //Destruimos la interfaz de disco (ya no hace falta)
                    delete(disco);
                    if (retorno!=0)
                    {
                        MostrarMensaje(String(S_CADENA_003)+
                                       String(fichero.Cadena()));
                        //ERROR: Abriendo el fichero
                        }
                    }
                    catch(runtime_error)
                    {
                        MostrarMensaje(String(S_CADENA_043)+
                            String(fichero.Cadena())+String(S_CADENA_044));
                        //ERROR: Contenido del fichero // erroneo
                        //Hay que destruir los recursos creados previamente
                        delete(disco);
                    }
                    conf->BancoRegistros()->Reiniciar();
                    gpr->Reiniciar();
                    break;
                    
            case -1 :
            
                //Mostramos los errores
                MostrarMensajeDesdeFichero(FICHERO_TEMPORAL_ERRORES);
                MostrarMensaje(String(S_CADENA_002)+String(lineas));
                    //Lineas procesadas
                MostrarMensaje(String(S_CADENA_007)+String(fichero.Cadena()));
                    //Error al ensamblar fichero
                break;
                
            case -2 :   
            
                MostrarMensaje(String(S_CADENA_003)+String(fichero.Cadena()));
                    //Error abriendo fichero
                break;
            
            case -3 :
            
                MostrarMensaje(String(S_CADENA_084));
                    //Error generando fichero memoria.tmp
                MostrarMensaje(String(S_CADENA_087));
                    //El directorio de trabajo esta protegido contra 
                    //escritura
                break;
                
            case -4 :
            
                MostrarMensaje(String(S_CADENA_085));
                    //Error generando fichero errores.tmp
                MostrarMensaje(String(S_CADENA_087));
                    //El directorio de trabajo esta protegido contra 
                    //escritura
                break;
                
            case -5 :
            
                MostrarMensaje(String(S_CADENA_086));
                    //Error generando fichero fuente.tmp
                MostrarMensaje(String(S_CADENA_087));
                    //El directorio de trabajo esta protegido contra 
                    //escritura
                break;
        }
    }
    //Volvemos al directorio de trabajo de la aplicacion
    chdir(cwd);
    //Actualizamos el contenido de las ventanas
    RefrescarVentanas();
    MostrarEstado(estadoanterior);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::BotonEjecutarClick(TObject *Sender)
{
    if(ejecutando)
    {
        PararExecute(Sender);
    }
    else
    {
        EjecutarExecute(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::CargarImagenMemoriaExecute(TObject *Sender)
{
    CInterfazDisco *disco;

    String estadoanterior;
    estadoanterior=stbBarraEstado->SimpleText;
    MostrarEstado("Abriendo Imagen de Memoria desde Disco");

    //Recuperamos el Directorio Actual
    ForceCurrentDirectory=true;
    dlgAbrir->InitialDir=
        String((conf->DirectorioActual()).Cadena());
    //Ningún nombre de fichero por defecto
    dlgAbrir->FileName="";
    //Abrimos el cuadro de diálogo
    dlgAbrir->Execute();

    if(dlgAbrir->FileName!="")
    {
        //Guardamos el Directorio Actual en el que retornamos del diálogo
        conf->EscribirDirectorioActual(CCadena(getcwd(NULL,255)));
        CCadena fichero=CCadena((dlgAbrir->FileName).c_str());
        try
        {
            //Creamos la interfaz de disco
            disco=new CInterfazDisco(conf);
            //Leemos el fichero desde disco
            int retorno=disco->VolcarDiscoAMemoria(fichero);
            //Destruimos la interfaz de disco (ya no hace falta)
            delete(disco);
            if (retorno!=0){
                MostrarMensaje(String(S_CADENA_003)+String(fichero.Cadena()));
                //ERROR: Abriendo el fichero
            }
        }
        catch(runtime_error)
        {
            MostrarMensaje(String(S_CADENA_043)+String(fichero.Cadena())+
                           String(S_CADENA_044));
            //ERROR: Contenido del fichero // erroneo
            //Hay que destruir los recursos creados previamente
            delete(disco);
        }
    }
    //Volvemos al directorio de trabajo de la aplicacion
    chdir(cwd);
    MostrarEstado(estadoanterior);
}
//---------------------------------------------------------------------------
int __fastcall TfrmPrincipal::CargarPosicionVentanas(void)
{
    ifstream entrada;
    char lecturaventana [10]; //Nombre de la ventana en el fichero
    String ventana;
    int left;
    int top;
    int width;
    int height;
    int visible;

    entrada.open(FICHERO_CONFIGURACION_WINDOWS);
    if (entrada!=NULL)
    {
        while (entrada)
        {
            entrada>>lecturaventana;
            ventana=String(lecturaventana);
            entrada>>left;
            entrada>>top;
            entrada>>width;
            entrada>>height;
            entrada>>visible;
            if(ventana=="PRINCIPAL")
            {
                Left=left;
                Top=top;
                Height=height;
                Width=width;
            }
            if(ventana=="CONSOLA")
            {
                vconsola->Left=left;
                vconsola->Top=top;
                vconsola->Height=height;
                vconsola->Width=width;
                if(visible==1)
                {
                    Consola1->Checked=true;
                }
                else{
                    Consola1->Checked=false;
                }
            }
            else if(ventana=="REGISTROS")
            {
                vregistros->Left=left;
                vregistros->Top=top;
                vregistros->Height=height;
                vregistros->Width=width;
                if(visible==1)
                {
                    Registros1->Checked=true;
                }
                else
                {
                    Registros1->Checked=false;
                }
            }
            else if(ventana=="MEMORIA")
            {
                vmemoria->Left=left;
                vmemoria->Top=top;
                vmemoria->Height=height;
                vmemoria->Width=width;
                if(visible==1)
                {
                    Memoria1->Checked=true;
                }
                else
                {
                    Memoria1->Checked=false;
                }
            }
            else if(ventana=="PILA")
            {
                vpila->Left=left;
                vpila->Top=top;
                vpila->Height=height;
                vpila->Width=width;
                if(visible==1)
                {
                    Pila1->Checked=true;
                }
                else
                {
                    Pila1->Checked=false;
                }
            }
            else if(ventana=="FUENTE")
            {
                vfuente->Left=left;
                vfuente->Top=top;
                vfuente->Height=height;
                vfuente->Width=width;
                if(visible==1)
                {
                    CodigoFuente1->Checked=true;
                }
                else
                {
                    CodigoFuente1->Checked=false;
                }
            }
        }
        return 0;
    }
    else
    {
        //Error al abrir el fichero
        return -1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::CodigoFuente1Click(TObject *Sender)
{
    if(CodigoFuente1->Checked==true)
    {
        vfuente->Hide();
    }
    else
    {
        vfuente->Show();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::ComenzarEjecucion(void)
{
    MostrarEstado("Ejecutando Codigo");
    vmemoria->btnReiniciar->Enabled=false;
    vregistros->btnReiniciar->Enabled=false;
    btnAbrirEnsamblar->Enabled=false;
    btnCargarImagenMemoria->Enabled=false;
    btnGuardarImagenMemoria->Enabled=false;
    btnGuardarSesion->Enabled=false;
    btnConfiguracion->Enabled=false;
    ejecutando=true;
    RefrescarVentanas();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::ConfiguracionExecute(TObject *Sender)
{
    String estadoanterior;
    
    estadoanterior=stbBarraEstado->SimpleText;
    MostrarEstado("Editando Parametros de Configuracion");
    vconfiguracion->ShowModal();
    RefrescarVentanas();
    MostrarEstado(estadoanterior);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::ConfirmarCerrar(TObject *Sender,bool &CanClose)
{
    int confirmar;
    int retorno;

    confirmar=MessageBox(NULL,"¿Desea abandonar la aplicación?",
                         "Ens2001",MB_YESNO|MB_TASKMODAL|MB_ICONQUESTION);
    if (confirmar==IDYES)
    {
        //Guardamos la posicion de las ventanas
        GuardarPosicionVentanas();
        //Guardamos la configuracion actual
        conf->GuardarConfiguracion();
        //Liberamos recursos y salimos

        delete es;
        delete gpr;
        delete p;
        delete b;
        delete m;

        delete vconsola;
        delete vfuente;
        delete vpila;
        delete vmemoria;
        delete vregistros;
        delete vconfiguracion;

        delete conf;

        //Borramos los archivos temporales
        String fichero;
        String diractual = String(conf->DirectorioActual().Cadena());
        diractual = diractual + "\\";
        //Fichero temporal fuente
        fichero = diractual + FICHERO_TEMPORAL_FUENTE;
        remove(fichero.c_str());
        //Fichero temporal memoria
        fichero = diractual + FICHERO_TEMPORAL_MEMORIA;
        remove(fichero.c_str());
        //Fichero temporal errores
        fichero = diractual + FICHERO_TEMPORAL_ERRORES;
        remove(fichero.c_str());
        free(cwd);

        CanClose=true;
    }
    else
    {
        CanClose=false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Consola1Click(TObject *Sender)
{
    if(Consola1->Checked==true)
    {
        vconsola->Hide();
    }
    else
    {
        vconsola->Show();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::CopiarExecute(TObject *Sender)
{
    mmoMensajes->SetFocus();
    mmoMensajes->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::DeseleccionarTodoExecute(TObject *Sender)
{
    mmoMensajes->SetFocus();
    mmoMensajes->SelLength=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EjecutarExecute(TObject *Sender)
{
    thread_procesador=new CTProcesador(true);
    thread_procesador->EscribirConfiguracion(conf);
    thread_procesador->EscribirPrincipal(this);
    thread_procesador->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EscribirConsola(void)
{
    if(Consola1->Checked==false)
    {
        vconsola->Show();
        Consola1->Checked=true;
    }
    vconsola->MostrarCadena(salida);
}
//---------------------------------------------------------------------------
void TfrmPrincipal::EscribirEntrada(String valor)
{
    entrada=valor;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::EscribirSalida(String valor)
{
    salida=valor;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::EscribirTextoConsola(String valor)
{
    textoconsola=valor;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::EscribirTipoEntrada(String valor)
{
    tipoentrada=valor;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EstadoAbrirEnsamblar(TObject *Sender)
{
    MostrarEstado("Abrir y Ensamblar");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EstadoCargarImagenMemoria(TObject *Sender)
{
    MostrarEstado("Cargar Imagen de Memoria");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EstadoConfiguracion(TObject *Sender)
{
    MostrarEstado("Configuración");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EstadoEjecutar(TObject *Sender)
{
    MostrarEstado("Ejecutar");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EstadoGuardarImagenMemoria(TObject *Sender)
{
    MostrarEstado("Guardar Imagen de Memoria");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EstadoGuardarSesion(TObject *Sender)
{
    MostrarEstado("Guardar Sesión");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::EstadoMensajes(TObject *Sender)
{
    MostrarEstado("");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FinEjecucion(void)
{
    vmemoria->btnReiniciar->Enabled=true;
    vregistros->btnReiniciar->Enabled=true;
    btnAbrirEnsamblar->Enabled=true;
    btnCargarImagenMemoria->Enabled=true;
    btnGuardarImagenMemoria->Enabled=true;
    btnGuardarSesion->Enabled=true;
    btnConfiguracion->Enabled=true;
    ejecutando=false;

    int resultado=conf->BancoRegistros()->RegistroFinEjecucion();

    //Mostramos en la ventana de mensajes el resultado de la ejecución
    switch (resultado){
        case EJ_PASOAPASO :
            MostrarMensaje(String(S_CADENA_025));
            //Modo Paso A Paso. Se detuvo la ejecucion
            break;
        case EJ_HALT : 
            MostrarMensaje(String(S_CADENA_026));
            //Fin del programa. Instruccion HALT
            break;
        case EJ_EXCEPCION :  
            MostrarMensaje(String(S_CADENA_027));
            //Se ha generado una excepcion
            switch(conf->BancoRegistros()->RegistroExcepcion())
            {
                case EX_ENTERO_FUERA_DE_RANGO :
                    MostrarMensaje(String(S_CADENA_028));
                    //"Entero Fuera De Rango"
                    break;
                case EX_DIVISION_POR_CERO :
                    MostrarMensaje(String(S_CADENA_029));
                    //Division Por Cero
                    break;
                case EX_FINALMEMORIA :
                    MostrarMensaje(String(S_CADENA_030));
                    //Sobrepasado el Limite de Memoria
                    break;
                case EX_COPERRONEO :
                    MostrarMensaje(String(S_CADENA_031));
                    //Codigo de Operacion No Reconocido
                    break;
                case EX_MDIRERRONEO :
                    MostrarMensaje(String(S_CADENA_032));
                    //Modo de Direccionamiento Erroneo
                    break;
                case EX_REGISTRO_NO_EXISTE :
                    MostrarMensaje(String(S_CADENA_033));
                    //Registro Inexistente
                    break;
                case EX_MEMORIA_FUERA_DE_RANGO :
                    MostrarMensaje(String(S_CADENA_034));
                    //Acceso a Memoria Fuera de Rango
                    break;
                case EX_DESPLAZ_FUERA_DE_RANGO :
                    MostrarMensaje(String(S_CADENA_035));
                    //Desplazamiento Fuera de Rango
                    break;
                case EX_BIESTABLE_NO_EXISTE :
                    MostrarMensaje(String(S_CADENA_036));
                    //Biestable Inexistente
                    break;
                case EX_MODOPILA_INCORRECTO :
                    MostrarMensaje(String(S_CADENA_037));
                    //Modo de Pila Incorrecto
                    break;
                case EX_INSTRUCCION_NO_IMPLEMENTADA :
                    MostrarMensaje(String(S_CADENA_038));
                    //Instruccion No Implementada
                    break;
                case EX_PC_INVADE_PILA :
                    MostrarMensaje(String(S_CADENA_076));
                    //El Contador de Programa (PC) invadio la zona de pila
                    break;
                case EX_SP_INVADE_CODIGO :
                    MostrarMensaje(String(S_CADENA_077));
                    //El Puntero de Pila (SP) invadio la zona de codigo
                    break;
                case EX_DETENIDO_POR_USUARIO :
                    MostrarMensaje(String(S_CADENA_079));
                    //Ejecucion detenida por el usuario
                    break;
                default : 
                    MostrarMensaje(String(S_CADENA_039));
                    //Excepcion no contemplada
            }
            break;
        case EJ_PUNTORUPTURA : 
            MostrarMensaje(String(S_CADENA_040));
            //Punto de Ruptura Incondicional. Se detuvo la ejecucion
            break;
    }
    vfuente->BotonCentrarClick(this);
    RefrescarVentanas();
    MostrarEstado("Ejecución Finalizada");
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::GuardarImagenMemoriaExecute(TObject *Sender)
{
    String estadoanterior;
    estadoanterior=stbBarraEstado->SimpleText;
    MostrarEstado("Guardando Imagen de Memoria en Disco");

    //Recuperamos el Directorio Actual
    ForceCurrentDirectory=true;
    dlgGuardar->InitialDir=
        String((conf->DirectorioActual()).Cadena());
    //Ningún nombre de fichero por defecto
    dlgGuardar->FileName="";
    //Abrimos el cuadro de diálogo
    dlgGuardar->Execute();

    if(dlgGuardar->FileName!="")
    {
        //Guardamos el Directorio Actual en el que retornamos del diálogo
        conf->EscribirDirectorioActual(CCadena(getcwd(NULL,255)));
        CCadena fichero=CCadena((dlgGuardar->FileName).c_str());
        //Creamos la interfaz de disco
        CInterfazDisco *disco=new CInterfazDisco(conf);
        //Escribimos el contenido de la memoria en el fichero
        int retorno=disco->VolcarMemoriaADisco(fichero);
        //Destruimos la interfaz de disco (ya no hace falta)
        delete(disco);
        if (retorno!=0)
        {
            MostrarMensaje(String(fichero.Cadena()));
            //ERROR: Guardando el fichero
        }
    }
    //Volvemos al directorio de trabajo de la aplicacion
    chdir(cwd);
    MostrarEstado(estadoanterior);
}
//---------------------------------------------------------------------------
int __fastcall TfrmPrincipal::GuardarPosicionVentanas(void)
{
    ofstream salida;
    String escritura;

    salida.open(FICHERO_CONFIGURACION_WINDOWS);
    if (salida!=NULL)
    {
        //Principal
        salida.write("PRINCIPAL",9);
        salida.write("\n",1);
        escritura=String(Left);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(Top);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(Width);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(Height);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        salida.write("1",1);
        salida.write("\n",1);
        //Consola
        salida.write("CONSOLA",7);
        salida.write("\n",1);
        escritura=String(vconsola->Left);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vconsola->Top);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vconsola->Width);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vconsola->Height);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        if(Consola1->Checked==true)
        {
            salida.write("1",1);
        }
        else
        {
            salida.write("0",1);
        }
        salida.write("\n",1);
        //Banco de registros
        salida.write("REGISTROS",9);
        salida.write("\n",1);
        escritura=String(vregistros->Left);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vregistros->Top);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vregistros->Width);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vregistros->Height);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        if(Registros1->Checked==true)
        {
            salida.write("1",1);
        }
        else
        {
            salida.write("0",1);
        }
        salida.write("\n",1);
        //Memoria
        salida.write("MEMORIA",7);
        salida.write("\n",1);
        escritura=String(vmemoria->Left);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vmemoria->Top);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vmemoria->Width);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vmemoria->Height);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        if(Memoria1->Checked==true)
        {
            salida.write("1",1);
        }
        else
        {
            salida.write("0",1);
        }
        salida.write("\n",1);
        //Pila
        salida.write("PILA",4);
        salida.write("\n",1);
        escritura=String(vpila->Left);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vpila->Top);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vpila->Width);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vpila->Height);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        if(Pila1->Checked==true)
        {
            salida.write("1",1);
        }
        else
        {
            salida.write("0",1);
        }
        salida.write("\n",1);
        //Codigo fuente
        salida.write("FUENTE",6);
        salida.write("\n",1);
        escritura=String(vfuente->Left);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vfuente->Top);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vfuente->Width);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        escritura=String(vfuente->Height);
        salida.write(escritura.c_str(),escritura.Length());
        salida.write("\n",1);
        if(CodigoFuente1->Checked==true)
        {
            salida.write("1",1);
        }
        else
        {
            salida.write("0",1);
        }
        salida.write("\n",1);
        return 0;
    }
    else
    {
        //Error al abrir el fichero
        return -1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::GuardarSesionExecute(TObject *Sender)
{
    String estadoanterior;
    estadoanterior=stbBarraEstado->SimpleText;
    MostrarEstado("Guardando Sesión en Disco");

    //Recuperamos el Directorio Actual
    ForceCurrentDirectory=true;
    dlgGuardarSesion->InitialDir=
        String((conf->DirectorioActual()).Cadena());
    //Ningún nombre de fichero por defecto
    dlgGuardarSesion->FileName="";
    //Abrimos el cuadro de diálogo
    dlgGuardarSesion->Execute();

    if(dlgGuardarSesion->FileName!="")
    {
        //Guardamos el Directorio Actual en el que retornamos del diálogo
        conf->EscribirDirectorioActual(CCadena(getcwd(NULL,255)));

        ofstream salida;

        salida.open(dlgGuardarSesion->FileName.c_str());
        if (salida!=NULL)
        {
            salida.write("---- Mensajes ----\n",19);
            salida.write(mmoMensajes->Text.c_str(),
                         mmoMensajes->Text.Length());
            salida.write("---- Consola ----\n",18);
            salida.write(vconsola->mmoConsola->Text.c_str(),
                         vconsola->mmoConsola->Text.Length());
            salida.close();
        }
	else
	{
	    ShowMessage("Error guardando fichero");
	}
    }
    //Volvemos al directorio de trabajo de la aplicacion
    chdir(cwd);
    MostrarEstado(estadoanterior);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::LeerConsola(void)
{
    vconsola->Hide();
    vconsola->lblTipo->Caption=tipoentrada;
    vconsola->EscribirModal(true);
    vconsola->ShowModal();
    vconsola->Close();
    vconsola->lblTipo->Caption="";
    if(vconsola->Terminar())
    {
        thread_procesador->Terminate();
    }
    vconsola->LeerBuffer(entrada);
    vconsola->Show();
    RefrescarVentanas();
}
//---------------------------------------------------------------------------
void TfrmPrincipal::LeerEntrada(String &valor)
{
    valor=entrada;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::LeerSalida(String &valor)
{
    valor=salida;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::LeerTeclado(TObject *Sender, WORD &Key,
                                           TShiftState Shift)
{
    if(Key==VK_ESCAPE)
    {
        Close();
    }
}
//---------------------------------------------------------------------------
void TfrmPrincipal::LeerTextoConsola(String &valor)
{
   valor=textoconsola;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::LeerTipoEntrada(String &valor)
{
    valor=tipoentrada;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::LimpiarExecute(TObject *Sender)
{
    mmoMensajes->SetFocus();
    mmoMensajes->Lines->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Memoria1Click(TObject *Sender)
{
    if(Memoria1->Checked==true)
    {
        vmemoria->Hide();
    }
    else
    {
        vmemoria->Show();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::MenuAcercaDeClick(TObject *Sender)
{
    MessageBox(NULL,(String("Ens2001 para Win32 - ")+String(VERSION)+
               String(" ")+String(FECHA)+String("\n")+
               String(URL)).c_str(),"Ens2001-Acerca de",
               MB_ICONINFORMATION|MB_TASKMODAL|MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Mostrar(TObject *Sender)
{
    if (ejecutando)
    {
        btnEjecutar->Glyph=imgParar->Picture->Bitmap;
        btnEjecutar->Hint="Detener la Ejecución";
    }
    else if (conf->ModoEjecucion()==ME_PASOAPASO)
    {
        btnEjecutar->Glyph=imgPaso->Picture->Bitmap;
        btnEjecutar->Hint="Ejecutar Paso a Paso el Contenido de la Memoria";
    }
    else
    {
        btnEjecutar->Glyph=imgEjecutar->Picture->Bitmap;
        btnEjecutar->Hint="Ejecutar el Contenido de la Memoria";
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::MostrarEstado(String estado)
{
    stbBarraEstado->SimpleText=estado;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::MostrarMensaje(String mensaje)
{
    mmoMensajes->Lines->Add(mensaje);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::MostrarMensajeDesdeFichero(String fichero)
{
    String lineas=mmoMensajes->Lines->Text;
    mmoMensajes->Lines->LoadFromFile(fichero);
    mmoMensajes->Lines->Insert(0,lineas);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::PararExecute(TObject *Sender)
{
    thread_procesador->Terminate();
    thread_procesador->WaitFor();
}
//---------------------------------------------------------------------------
bool TfrmPrincipal::PermisoEscribir(void){

    return ejecutando ? false : true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Pila1Click(TObject *Sender)
{
    if(Pila1->Checked==true)
    {
        vpila->Hide();
    }
    else
    {
        vpila->Show();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::PrincipalResize(TObject *Sender)
{
    mmoMensajes->Width=Width-20;
    mmoMensajes->Height=Height-135;
    stbBarraEstado->Top=437;
    stbBarraEstado->Height=17;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::RefrescarVentanas(void)
{
    vregistros->Refresh();
    vmemoria->Refresh();
    vpila->Refresh();
    vfuente->Refresh();
    vconsola->Refresh();
    Refresh();
    return;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Registros1Click(TObject *Sender)
{
    if(Registros1->Checked==true)
    {
        vregistros->Hide();
    }
    else
    {
        vregistros->Show();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::SalirExecute(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::SeleccionarTodoExecute(TObject *Sender)
{
    mmoMensajes->SetFocus();
    mmoMensajes->SelectAll();
}
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner)
                                        : TForm(Owner)
{
    //Crear e Inicializar Objetos
    conf=new CConfiguracion;

    textoconsola="";
    entrada="";
    salida="";
    ejecutando=false;

    //Crear Formularios
    vconfiguracion=new TfrmConfiguracion(this,conf);
    vregistros=new TfrmRegistros(this,conf);
    vmemoria=new TfrmMemoria(this,conf);
    vpila=new TfrmPila(this,conf);
    vfuente=new TfrmFuente(this,conf);
    vconsola=new TfrmConsolaEjecucion(this);

    m=new CMemoria(conf);
    b=new CBancoRegistros(conf);
    p=new CProcesador(conf);
    gpr=new CGestorPuntosRuptura(conf);
    es=new CEntradaSalida(conf);

    //Reiniciar Registros y Memoria
    b->Reiniciar();
    m->Reiniciar();

    //Lee el directorio de trabajo de la aplicacion
    cwd=getcwd(NULL,255);

    MostrarMensaje("ENS2001 para Win32");
    MostrarMensaje(String("Version ")+String(VERSION)+String(" - ")+
                   String(FECHA));
    MostrarMensaje(String(URL));

    //Cargar Configuracion
    if(conf->CargarConfiguracion()!=0)
    {
        //Se usaron las opciones por defecto
        MostrarMensaje
            ("Fichero de configuracion (ens2001.cfg) no encontrado o erroneo");
        MostrarMensaje("Se usaran las opciones por defecto");
    }
    else
    {
        MostrarMensaje
            ("Fichero de configuracion (ens2001.cfg) cargado con exito");
    }

    CargarPosicionVentanas();

    //Inicializar ventanas flotantes según la configuración almacenada
    if(Registros1->Checked==true)
    {
        vregistros->Show();
    }
    if(Memoria1->Checked==true)
    {
        vmemoria->Show();
    }
    if(Pila1->Checked==true)
    {
        vpila->Show();
    }
    if(CodigoFuente1->Checked==true)
    {
        vfuente->Show();
    }
    if(Consola1->Checked==true)
    {
        vconsola->Show();
    }
}
//---------------------------------------------------------------------------

