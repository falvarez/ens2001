//cinterfazconsola.cpp
#include "cinterfazconsola.h"

void CInterfazConsola::ExtraerComando(char *entrada,
                                      char &comando,
                                      CCadena &parametro1,
                                      CCadena &parametro2,
                                      int &nparametros)
{
    //Separamos los datos de entrada
    int i=0; //Puntero para la entrada
    CCadena com=CCadena(); //Comando
    nparametros=0; //Numero de parametros leidos
    parametro1=CCadena(); //Primer parametro
    parametro2=CCadena(); //Segundo parametro

    //Saltamos blancos
    while((entrada[i]!='\0') && (entrada[i]==' ' || entrada[i]=='\t'))
    {
        i++;
    }

    //Comando
    while((entrada[i]!='\0') && (entrada[i]!=' ' && entrada[i]!='\t'))
    {
        com=com+entrada[i];
        i++;
    }

    //Saltamos blancos
    while((entrada[i]!='\0') && (entrada[i]==' ' || entrada[i]=='\t'))
    {
        i++;
    }

    //Primer parametro
    if(entrada[i]=='"')
    {
        i++;
        //El parametro va entrecomillado, puede ocupar mas
        //de una palabra
        while((entrada[i]!='\0') && (entrada[i]!='"'))
        {
            parametro1=parametro1+entrada[i];
            i++;
        }
    }
    else
    {
        //Es un parametro de una palabra
        while((entrada[i]!='\0') && (entrada[i]!=' ' && entrada[i]!='\t'))
        {
            parametro1=parametro1+entrada[i];
            i++;
        }
    }

    //Saltamos blancos
    while((entrada[i]!='\0') && (entrada[i]==' ' || entrada[i]=='\t'))
    {
        i++;
    }

    //Segundo parametro
    if(entrada[i]=='"')
    {
        i++;
        //El parametro va entrecomillado, puede ocupar mas de una palabra
        while((entrada[i]!='\0') && (entrada[i]!='"'))
        {
            parametro2=parametro2+entrada[i];
            i++;
        }
    }
    else
    {
        while((entrada[i]!='\0') && (entrada[i]!=' ' && entrada[i]!='\t'))
        {
            parametro2=parametro2+entrada[i];
            i++;
        }
    }

    //Comprobamos cuantos parametros se han introducido
    if(parametro1.Longitud()>0)
    {
        //Existe el primer parametro
        nparametros++;
    }

    if(parametro2.Longitud()>0)
    {
        //Existe el segundo parametro
        nparametros++;
    }

    //Validamos el comando introducido
    if(com.Longitud()==0)
    {
        //No se ha introducido ningun comando
        comando='0';
    }
    else if(com.Longitud()==1)
    {
        //Se ha introducido un comando correcto (un caracter)
        comando=com[0];
    }
    else
    {
        //Se ha introducido un comando de mas de un caracter
        comando='1';
    }
    //Ignoramos el resto de la entrada
    return;
}
//---------------------------------------------------------------------------
int CInterfazConsola::Ayuda(void)
{
    ifstream file;

    file.open(FICHERO_AYUDA);
    if(file!=NULL){
        cout<<file.rdbuf()<<endl;
        file.close();
        return 0;
    }
    else
    {
        //Error al abrir el fichero
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::Base(CCadena valor)
{
    int base=atoi(valor.Cadena());
    switch(base)
    {
        case 10 : cout<<S_CADENA_008<<endl;
                    //Representacion en base decimal
                  break;
        case 16 : cout<<S_CADENA_009<<endl;
                    //Representacion en base hexadecimal
                  break;
        default : cout<<S_CADENA_016;
                    //Base de representacion incorrecta -
                  cout<<S_CADENA_017<<endl;
                    //Valores posibles: 10, 16
                  return -1;
    }
    conf->EscribirBaseNumerica(base);
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::CargarMemoria(CCadena fichero)
{
    CInterfazDisco *disco;

    try
    {
        //Creamos la interfaz de disco
        disco=new CInterfazDisco(conf);
        //Leemos el fichero desde disco
        int retorno=disco->VolcarDiscoAMemoria(fichero);
        //Destruimos la interfaz de disco (ya no hace falta)
        delete(disco);
        if (retorno!=0)
        {
            cout<<S_CADENA_003<<fichero<<endl; //ERROR: Abriendo el fichero
            return -1;
        }
        else
        {
            return 0;
        }
    }
    catch(std::runtime_error)
    {
        //Se produjo un error al rellenar la memoria -> datos incorrectos
        cout<<S_CADENA_043<<fichero<<S_CADENA_044<<endl;
            //ERROR: Contenido del fichero // erroneo
        //Hay que destruir los recursos creados previamente
        delete(disco);
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::Desensamblar(CCadena dir,CCadena num)
{
    CDesensamblador *desens;
    CCadena instruccion;
    CCadena parametro;

    try
    {
        //Creamos el objeto desensamblador
        desens=new CDesensamblador(conf);

        //Recuperamos dir
        parametro="dir";
        CEntero16b direccion=CEntero16b(dir.Cadena());
            //Produce excepcion si dir no esta en el rango aceptable

        //Recuperamos num
        parametro="num";
        CEntero16b i=CEntero16b(num.Cadena());
            //Produce excepcion si num no esta en el rango aceptable

        while(i.Valor()>0 && direccion.Valor()<MAXINT+1)
        {
            i--;
            //Miramos si hay definido un punto de ruptura
            switch(conf->GestorPuntosRuptura()->Consultar(direccion)){
            case 0 : cout<<"  ";
                     break;
            case 1 : cout<<"* ";
                     break;
            }
            //Miramos si en esta posicion esta PC
            CEntero16b pc;
            conf->BancoRegistros()->Leer(PC,pc);
            if(direccion.Valor()==pc.Valor())
            {
                cout<<"PC-> ";
            }
            else
            {
                cout<<"     ";
            }
            //Mostramos la direccion
            switch(conf->BaseNumerica())
            {
                case 10 : cout<<direccion.DecimalSinSigno()<<": ";
                          break;
                case 16 : cout<<direccion.Hexadecimal()<<": ";
                          break;
            }
            //Desensamblamos la instruccion
            desens->Desensamblar(direccion,instruccion);
            cout<<instruccion<<endl;
            if((direccion.Valor()==MININT) && (i.Valor()>0))
            {
                cout<<S_CADENA_018<<endl;
                    //AVISO: Se sobrepasa el limite de memoria
                delete(desens);
                return 0;
            }
        }
        //Destruimos el objeto desensamblador
        delete(desens);
        return 0;
    }
    catch(std::runtime_error)
    {
        cout<<S_CADENA_019<<parametro<<endl; //ERROR: Parametro incorrecto -
        //Hay que liberar los recursos previamente creados
        delete(desens);
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::Ejecutar(void)
{
    CEntero16b pc;
    int h;
    conf->BancoRegistros()->LeerBiestableEstado(BS_H,h);

    if((conf->ReiniciarRegistros()==SI) && (h==1))
    {
        //Si finalizo el programa anteriormente,y esta activada la opcion
        //en la configuracion, reseteamos los registros
        conf->BancoRegistros()->Reiniciar();
    }
    if(conf->ModoEjecucion()==ME_PASOAPASO)
    {
        conf->BancoRegistros()->Leer(PC,pc);
        Desensamblar(CCadena(pc.Decimal()),"1");
    }
    int retorno=conf->Procesador()->Ejecutar();
    switch (retorno)
    {
        case EJ_PASOAPASO : cout<<endl<<S_CADENA_025<<endl; 
                                //Modo Paso A Paso. Se detuvo la ejecucion
                            break;
        case EJ_HALT :      cout<<endl<<S_CADENA_026<<endl; 
                                //Fin del programa. Instruccion HALT
                            break;
        case EJ_EXCEPCION : 
        
            cout<<endl<<S_CADENA_027<<endl; //Se ha generado una excepcion
            switch(conf->BancoRegistros()->RegistroExcepcion())
            {
                case EX_ENTERO_FUERA_DE_RANGO :
                    cout<<S_CADENA_028<<endl; //Entero Fuera De Rango
                    break;
                case EX_DIVISION_POR_CERO :
                    cout<<S_CADENA_029<<endl; //Division Por Cero
                    break;
                case EX_FINALMEMORIA :
                    cout<<S_CADENA_030<<endl; 
                        //Sobrepasado el Limite de Memoria
                    break;
                case EX_COPERRONEO :
                    cout<<S_CADENA_031<<endl; 
                        //Codigo de Operacion No Reconocido
                    break;
                case EX_MDIRERRONEO :
                    cout<<S_CADENA_032<<endl; 
                        //Modo de Direccionamiento Erroneo
                    break;
                case EX_REGISTRO_NO_EXISTE :
                    cout<<S_CADENA_033<<endl; //Registro Inexistente
                    break;
                case EX_MEMORIA_FUERA_DE_RANGO :
                    cout<<S_CADENA_034<<endl; 
                        //Acceso a Memoria Fuera de Rango
                    break;
                case EX_DESPLAZ_FUERA_DE_RANGO :
                    cout<<S_CADENA_035<<endl; //Desplazamiento Fuera de Rango
                    break;
                case EX_BIESTABLE_NO_EXISTE :
                    cout<<S_CADENA_036<<endl; //Biestable Inexistente
                    break;
                case EX_MODOPILA_INCORRECTO :
                    cout<<S_CADENA_037<<endl; //Modo de Pila Incorrecto
                    break;
                case EX_INSTRUCCION_NO_IMPLEMENTADA :
                    cout<<S_CADENA_038<<endl; //Instruccion No Implementada
                    break;
                case EX_PC_INVADE_PILA :
                    cout<<S_CADENA_076<<endl; 
                        //El Contador de Programa (PC) invadio la zona de pila
                    break;
                case EX_SP_INVADE_CODIGO :
                    cout<<S_CADENA_077<<endl; 
                        //El Puntero de Pila (SP) invadio la zona de codigo
                    break;
                case EX_DETENIDO_POR_USUARIO :
                    cout<<S_CADENA_079<<endl; 
                        //Ejecucion detenida por el usuario
                    break;
                default : 
                    cout<<S_CADENA_039<<endl; //Excepcion no contemplada
            }
            break;
        case EJ_PUNTORUPTURA : cout<<S_CADENA_040<<endl; 
                                   //Punto de Ruptura Incondicional.
                                   //Se detuvo la ejecucion
                               break;
    }
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::Ensamblar(CCadena fichero)
{
    int lineas;

    cout<<S_CADENA_093<<fichero<<endl;
    CEnsamblador *ens = new CEnsamblador(conf);
    int retorno=ens->Ensamblar(fichero,lineas);
    switch(retorno)
    {
        case 0 :  cout<<S_CADENA_002<<lineas<<endl; //Lineas procesadas
                  cout<<S_CADENA_004<<fichero<<S_CADENA_005<<endl; 
                      //Fichero //ensamblado correctamente
                  CargarMemoria(FICHERO_TEMPORAL_MEMORIA);
                  conf->BancoRegistros()->Reiniciar();
                  conf->GestorPuntosRuptura()->Reiniciar();
                  return 0;
        case -1 : ListarErrores(FICHERO_TEMPORAL_ERRORES);
                  cout<<S_CADENA_002<<lineas<<endl; //Lineas procesadas
                  cout<<S_CADENA_007<<fichero<<endl; 
                      //Error al ensamblar fichero
                  return -1;
        case -2 : cout<<S_CADENA_003<<fichero<<endl; //Error abriendo fichero
                  return -1;
        case -3 : cout<<S_CADENA_084<<endl; 
                      //Error generando fichero memoria.tmp
                  cout<<S_CADENA_087<<endl;
                      //El directorio de trabajo esta protegido contra 
                      //escritura
        	  return -1;
        case -4 : cout<<S_CADENA_085<<endl; 
                      //Error generando fichero errores.tmp
                  cout<<S_CADENA_087<<endl;
                      //El directorio de trabajo esta protegido contra 
                      //escritura
        	  return -1;
        case -5 : cout<<S_CADENA_086<<endl; 
                      //Error generando fichero fuente.tmp
                  cout<<S_CADENA_087<<endl;
                      //El directorio de trabajo esta protegido contra 
                      //escritura
        default : return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::EscribirMemoria(CCadena direccion,CCadena valor)
{
    CCadena parametro;

    try
    {
        //Leemos direccion
        parametro="dir";
        CEntero16b dir=CEntero16b(direccion.Cadena());
        //Leemos valor
        parametro="valor";
        CEntero16b num=CEntero16b(valor.Cadena());
        //Escribimos en memoria
        conf->Memoria()->Escribir(dir,num);
        return 0;
    }
    catch (runtime_error)
    {
        cout<<S_CADENA_019<<parametro<<endl; //ERROR: Error en parametro -
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::EscribirRegistro(CCadena registro,CCadena valor)
{
    CEntero16b num;

    try
    {
        num=CEntero16b(valor.Cadena());

        if(registro.Comparar("a")==0 || registro.Comparar("A")==0)
        {
            conf->BancoRegistros()->Escribir(A,num);
        }
        else if(registro.Comparar("r0")==0 || registro.Comparar("R0")==0)
        {
            conf->BancoRegistros()->Escribir(R0,num);
        }
        else if(registro.Comparar("r1")==0 || registro.Comparar("R1")==0)
        {
            conf->BancoRegistros()->Escribir(R1,num);
        }
        else if(registro.Comparar("r2")==0 || registro.Comparar("R2")==0)
        {
            conf->BancoRegistros()->Escribir(R2,num);
        }
        else if(registro.Comparar("r3")==0 || registro.Comparar("R3")==0)
        {
            conf->BancoRegistros()->Escribir(R3,num);
        }
        else if(registro.Comparar("r4")==0 || registro.Comparar("R4")==0)
        {
            conf->BancoRegistros()->Escribir(R4,num);
        }
        else if(registro.Comparar("r5")==0 || registro.Comparar("R5")==0)
        {
            conf->BancoRegistros()->Escribir(R5,num);
        }
        else if(registro.Comparar("r6")==0 || registro.Comparar("R6")==0)
        {
            conf->BancoRegistros()->Escribir(R6,num);
        }
        else if(registro.Comparar("r7")==0 || registro.Comparar("R7")==0)
        {
            conf->BancoRegistros()->Escribir(R7,num);
        }
        else if(registro.Comparar("r8")==0 || registro.Comparar("R8")==0)
        {
            conf->BancoRegistros()->Escribir(R8,num);
        }
        else if(registro.Comparar("r9")==0 || registro.Comparar("R9")==0)
        {
            conf->BancoRegistros()->Escribir(R9,num);
        }
        else if(registro.Comparar("pc")==0 || registro.Comparar("PC")==0)
        {
            conf->BancoRegistros()->Escribir(PC,num);
        }
        else if(registro.Comparar("sp")==0 || registro.Comparar("SP")==0)
        {
            conf->BancoRegistros()->Escribir(SP,num);
        }
        else if(registro.Comparar("ix")==0 || registro.Comparar("IX")==0)
        {
            conf->BancoRegistros()->Escribir(IX,num);
        }
        else if(registro.Comparar("iy")==0 || registro.Comparar("IY")==0)
        {
            conf->BancoRegistros()->Escribir(IY,num);
        }
        else if(registro.Comparar("sr")==0 || registro.Comparar("SR")==0)
        {
            conf->BancoRegistros()->Escribir(SR,num);
        }
        else
        {
            cout<<S_CADENA_021<<endl; //ERROR: Registro inexistente
            return -1;
        }
        return 0;
     }
     catch(std::runtime_error)
     {
        if(conf->BancoRegistros()->RegistroExcepcion()==EX_SP_INVADE_CODIGO)
        {
            cout<<S_CADENA_080<<endl; //ERROR: SP Invade el Codigo
        }
        else if(conf->BancoRegistros()->RegistroExcepcion()==EX_PC_INVADE_PILA)
        {
            cout<<S_CADENA_081<<endl; //ERROR: PC Invade la Pila
        }
        else
        {
            cout<<S_CADENA_022<<endl; //ERROR: Valor fuera de rango
        }
        return -1;
     }
}
//---------------------------------------------------------------------------
int CInterfazConsola::EstadoSimulador(void)
{
    //base representacion
    int configuracion=conf->BaseNumerica();
    switch(configuracion)
    {
        case BASE_DECIMAL :     cout<<S_CADENA_008<<endl;
                                    //Representacion en base decimal
                                break;
        case BASE_HEXADECIMAL : cout<<S_CADENA_009<<endl;
                                    //Representacion en base hexadecimal
                                break;
    }
    //pila
    configuracion=conf->ModoPila();
    switch(configuracion)
    {
        case PILA_CRECIENTE :   cout<<S_CADENA_010<<endl;
                                  //La pila crece en direcciones crecientes
                                break;
        case PILA_DECRECIENTE : cout<<S_CADENA_011<<endl;
                                  //La pila crece en direcciones decrecientes
                                break;
    }
    //puntos ruptura
    configuracion=conf->ModoDepuracion();
    switch(configuracion)
    {
        case SI : cout<<S_CADENA_012<<endl;
                   //Se detendra la ejecucion si se encuentran
                   //puntos de ruptura
                  break;
        case NO : cout<<S_CADENA_013<<endl;
                   //Se ignoraran los puntos de ruptura establecidos
                  break;
    }
    //modo ejecucion
    configuracion=conf->ModoEjecucion();
    switch(configuracion)
    {
        case ME_PASOAPASO : cout<<S_CADENA_014<<endl; //Ejecucion paso a paso
                            break;
        case ME_NORMAL :    cout<<S_CADENA_015<<endl; //Ejecucion normal
                            break;
    }
    //comprobar pc
    configuracion=conf->ComprobarPC();
    switch(configuracion)
    {
        case NO : cout<<S_CADENA_072<<endl;
                   //No se comprobara si PC invade el espacio de pila
                  break;
        case SI : cout<<S_CADENA_073<<endl;
                   //Se comprobara si PC invade el espacio de pila
                  break;
    }
    //comprobar pila
    configuracion=conf->ComprobarPila();
    switch(configuracion)
    {
        case NO : cout<<S_CADENA_074<<endl;
                   //No se comprobara si SP invade el espacio de codigo
                  break;
        case SI : cout<<S_CADENA_075<<endl;
                   //Se comprobara si SP invade el espacio de codigo
                  break;
    }
    //reiniciar registros
    configuracion=conf->ReiniciarRegistros();
    switch(configuracion)
    {
        case NO : cout<<S_CADENA_068<<endl;
                   //No se inicializaran los registros antes de ejecutar
                  break;
        case SI : cout<<S_CADENA_069<<endl;
                   //Se inicializaran los registros antes de ejecutar
                  break;
    }
    cout<<endl; //Una linea adicional de separacion
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::GuardarMemoria(CCadena fichero)
{
    //Creamos la interfaz de disco
    CInterfazDisco *disco=new CInterfazDisco(conf);
    //Escribimos el contenido de la memoria en el fichero
    int retorno=disco->VolcarMemoriaADisco(fichero);
    //Destruimos la interfaz de disco (ya no hace falta)
    delete(disco);
    if(retorno!=0)
    {
        cout<<S_CADENA_078<<fichero<<endl; //ERROR: Guardando el fichero
        return -1;
    }
    else
    {
        return 0;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::IntercambiarComprobarPC(void)
{
    if(conf->ComprobarPC()==NO)
    {
        conf->EscribirComprobarPC(SI);
        cout<<S_CADENA_073<<endl; 
            //Se comprobara si el PC invade el espacio de pila
    }
    else
    {
        conf->EscribirComprobarPC(NO);
        cout<<S_CADENA_072<<endl; 
            //No se comprobara si el PC invade el espacio de pila�
    }
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::IntercambiarComprobarPila(void)
{
    if(conf->ComprobarPila()==NO)
    {
        conf->EscribirComprobarPila(SI);
        cout<<S_CADENA_075<<endl; 
            //Se comprobara si la pila invade el espacio del codigo
    }
    else
    {
        conf->EscribirComprobarPila(NO);
        cout<<S_CADENA_074<<endl; 
            //No se comprobara si la pila invade el espacio del codigo
    }
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::IntercambiarModoPasoAPaso(void)
{
    if(conf->ModoEjecucion()==ME_NORMAL)
    {
        conf->EscribirModoEjecucion(ME_PASOAPASO);
        cout<<S_CADENA_014<<endl; //Ejecucion Paso A Paso
    }
    else
    {
        conf->EscribirModoEjecucion(ME_NORMAL);
        cout<<S_CADENA_015<<endl; //Ejecucion Normal
    }
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::IntercambiarModoPila(void)
{
    if(conf->ModoPila()==PILA_CRECIENTE)
    {
        conf->EscribirModoPila(PILA_DECRECIENTE);
        cout<<S_CADENA_011<<endl; //La pila crece en direcciones decrecientes
    }
    else
    {
        conf->EscribirModoPila(PILA_CRECIENTE);
        cout<<S_CADENA_010<<endl; //La pila crece en direcciones crecientes
    }
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::IntercambiarPararPuntosRuptura(void)
{
    if(conf->ModoDepuracion()==NO)
    {
        conf->EscribirModoDepuracion(SI);
        cout<<S_CADENA_012<<endl; 
            //Se detendra la ejecucion si se encuentran puntos de ruptura
    }
    else
    {
        conf->EscribirModoDepuracion(NO);
        cout<<S_CADENA_013<<endl; 
            //Se ignoraran los puntos de ruptura establecidos
    }
    return 0;
}
int CInterfazConsola::IntercambiarPuntoRuptura(CCadena direccion)
{
    try
    {
        CEntero16b dir=CEntero16b(direccion.Cadena());
        int estado=conf->GestorPuntosRuptura()->Intercambiar(dir);
        switch(conf->BaseNumerica())
        {
            case BASE_DECIMAL :     cout<<dir.DecimalSinSigno()<<": ";
                                    break;
            case BASE_HEXADECIMAL : cout<<dir.Hexadecimal()<<": ";
                                    break;
        }
        if (estado==0)
        {
            cout<<S_CADENA_023; //Punto de Ruptura Desactivado
        }
        else
        {
            cout<<S_CADENA_024; //Punto de Ruptura Activado
        }
        cout<<endl;
        return 0;
    }
    catch(std::runtime_error)
    {
        cout<<S_CADENA_019<<"dir"<<endl; //ERROR: Parametro incorrecto -
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::IntercambiarReiniciarRegistros(void)
{
    if(conf->ReiniciarRegistros()==SI)
    {
        conf->EscribirReiniciarRegistros(NO);
        cout<<S_CADENA_068<<endl; 
            //No se inicializaran los registros antes de ejecutar
    }
    else
    {
        conf->EscribirReiniciarRegistros(SI);
        cout<<S_CADENA_069<<endl; 
            //Se inicializaran los registros antes de ejecutar
    }
    return 0;
}
//---------------------------------------------------------------------------
void CInterfazConsola::LeerBancoRegistros(void){

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
    cout<<S_CADENA_020<<endl; //Banco de Registros
    switch(conf->BaseNumerica())
    {
        case 10 : cout<<" A: "<<a.DecimalFormateado()<<" ";
                  cout<<"PC: "<<pc.DecimalSinSignoFormateado()<<" ";
                  cout<<"SP: "<<sp.DecimalSinSignoFormateado()<<" ";
                  cout<<"IX: "<<ix.DecimalSinSignoFormateado()<<" ";
                  cout<<"IY: "<<iy.DecimalSinSignoFormateado()<<" ";
                  cout<<"SR: "<<sr.DecimalFormateado()<<" "<<endl;
                  cout<<"R0: "<<r0.DecimalFormateado()<<" ";
                  cout<<"R1: "<<r1.DecimalFormateado()<<" ";
                  cout<<"R2: "<<r2.DecimalFormateado()<<" ";
                  cout<<"R3: "<<r3.DecimalFormateado()<<" ";
                  cout<<"R4: "<<r4.DecimalFormateado()<<" ";
                  cout<<"R5: "<<r5.DecimalFormateado()<<" "<<endl;
                  cout<<"R6: "<<r6.DecimalFormateado()<<" ";
                  cout<<"R7: "<<r7.DecimalFormateado()<<" ";
                  cout<<"R8: "<<r8.DecimalFormateado()<<" ";
                  cout<<"R9: "<<r9.DecimalFormateado()<<" ";
                  break;
        case 16 : cout<<" A: "<<a.Hexadecimal()<<" ";
                  cout<<"PC: "<<pc.Hexadecimal()<<" ";
                  cout<<"SP: "<<sp.Hexadecimal()<<" ";
                  cout<<"IX: "<<ix.Hexadecimal()<<" ";
                  cout<<"IY: "<<iy.Hexadecimal()<<" ";
                  cout<<"SR: "<<sr.Hexadecimal()<<" "<<endl;
                  cout<<"R0: "<<r0.Hexadecimal()<<" ";
                  cout<<"R1: "<<r1.Hexadecimal()<<" ";
                  cout<<"R2: "<<r2.Hexadecimal()<<" ";
                  cout<<"R3: "<<r3.Hexadecimal()<<" ";
                  cout<<"R4: "<<r4.Hexadecimal()<<" ";
                  cout<<"R5: "<<r5.Hexadecimal()<<" "<<endl;
                  cout<<"R6: "<<r6.Hexadecimal()<<" ";
                  cout<<"R7: "<<r7.Hexadecimal()<<" ";
                  cout<<"R8: "<<r8.Hexadecimal()<<" ";
                  cout<<"R9: "<<r9.Hexadecimal()<<" ";
                  break;
    }
    cout<<" Z:"<<z<<" C:"<<c<<" V:"<<v<<" P:"<<p<<" S:"<<s<<" H:"<<h<<endl;
    switch(conf->BaseNumerica())
    {
        case 10 : cout<<"Codigo ["<<cod1.DecimalSinSigno();
                  cout<<","<<cod2.DecimalSinSigno();
                  cout<<"] Pila ["<<pila1.DecimalSinSigno();
                  cout<<","<<pila2.DecimalSinSigno()<<"]"<<endl;
                  break;
        case 16 : cout<<"Codigo ["<<cod1.Hexadecimal();
                  cout<<","<<cod2.Hexadecimal();
                  cout<<"] Pila ["<<pila1.Hexadecimal();
                  cout<<","<<pila2.Hexadecimal()<<"]"<<endl;
                  break;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::LeerMemoria(CCadena direccion)
{
    CEntero16b valor;

    try
    {
        CEntero16b dir=CEntero16b(direccion.Cadena());
        conf->Memoria()->Leer(dir,valor);
        switch (conf->BaseNumerica())
        {
            case 10 : cout<<dir.DecimalSinSigno()<<": ";
            	      cout<<valor.DecimalFormateado()<<endl;
                      break;
            case 16 : cout<<dir.Hexadecimal()<<": ";
                      cout<<valor.Hexadecimal()<<endl;
                      break;
        }
        return 0;
    }
    catch(std::runtime_error)
    {
        cout<<S_CADENA_042<<endl; //ERROR: Direccion fuera de rango
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::LeerRegistro(CCadena registro)
{
    CEntero16b valor;
    CCadena nombreregistro;
    int identificador;
    
    try
    {
    	conf->BancoRegistros()->
    	    LeerIdRegistro(registro,identificador);
    	conf->BancoRegistros()->
    	    LeerNombreRegistro(identificador,nombreregistro);
    	conf->BancoRegistros()->
    	    Leer(identificador,valor);
    	switch(conf->BaseNumerica())
        {
            case 10 : if((identificador==PC) || (identificador==SP) ||
            		 (identificador==IX) || (identificador==IY))
            	      {
                          cout<<nombreregistro<<": "<<
                              valor.DecimalSinSignoFormateado();
                      }
                      else
                      {
                      	  cout<<nombreregistro<<": "<<
                              valor.DecimalFormateado();
                      }
            	      cout<<endl;
                      break;
            case 16 : cout<<nombreregistro<<": "<<valor.Hexadecimal()<<endl;
                      break;
        }
        return 0;
    }
    catch(std::runtime_error)
    {
        cout<<S_CADENA_021<<endl; //ERROR: Registro inexistente
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::Salir(void)
{
    char respuesta;

    cout<<S_CADENA_045; //Seguro que desea salir (S/N)?
    cin>>respuesta;
    cin.ignore();
    if(respuesta=='S' || respuesta=='s')
    {
        if((conf->GuardarConfiguracion())!=0)
        {
            cout<<"Error al guardar el archivo de configuracion"<<endl;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::VolcarBloqueMemoria(CCadena dir,CCadena num)
{
    CEntero16b valor;
    CEntero16b direccion;
    CEntero16b i;
    CCadena parametro;

    try
    {
        //Controlamos dir
        parametro="dir";
        direccion=CEntero16b(dir.Cadena()); //Produce excepcion si dir
                                            //no esta en el rango aceptable

        //Controlamos num
        parametro="num";
        i=CEntero16b(num.Cadena()); //Produce excepcion si num
                                    //no esta en el rango aceptable

        //Recuperamos los valores para las zonas de codigo y pila
        int cod1=conf->BancoRegistros()->Codigo1().Valor();
        int cod2=conf->BancoRegistros()->Codigo2().Valor();
        int pila1=conf->BancoRegistros()->Pila1().Valor();
        int pila2=conf->BancoRegistros()->Pila2().Valor();

        while(i.Valor()>0 && direccion.Valor()<MAXINT+1)
        {
            i--;
            conf->Memoria()->Leer(direccion,valor);
            if((cod1<=direccion.Valor() && cod2>=direccion.Valor()) ||
               (cod2<=direccion.Valor() && cod1>=direccion.Valor()))
            {
                cout<<" C ";
            }
            else if((pila1<=direccion.Valor() && pila2>=direccion.Valor()) ||
                    (pila2<=direccion.Valor() && pila1>=direccion.Valor()))
            {
                cout<<" P ";
            }
            else
            {
                cout<<"   ";
            }
            switch(conf->BaseNumerica())
            {
                case 10 : cout<<direccion.DecimalSinSigno()<<": ";
                          cout<<valor.DecimalFormateado()<<endl;
                          break;
                case 16 : cout<<direccion.Hexadecimal()<<": ";
                          cout<<valor.Hexadecimal()<<endl;
                          break;
            }
            direccion++;
            if((direccion.Valor()==MININT) && (i.Valor()>0))
            {
                cout<<S_CADENA_018<<endl; 
                    //AVISO: Se sobrepasa el limite de memoria
                return 0;
            }
        }
        return 0;
    }
    catch(std::runtime_error)
    {
        cout<<S_CADENA_019<<parametro<<endl; //ERROR: Parametro incorrecto -
        return -1;
    }
}
//---------------------------------------------------------------------------
int CInterfazConsola::VolcarPila(CCadena num)
{
    CEntero16b valor;
    CEntero16b sp;
    CEntero16b direccion;
    CEntero16b i;

    try
    {
        conf->BancoRegistros()->Leer(SP,sp);
        //Controlamos num
        i=CEntero16b(num.Cadena()); //Produce excepcion si num
                                    //no esta en el rango aceptable
        switch(conf->ModoPila())
        {
            case PILA_CRECIENTE :   if((sp.Valor()-i.Valor()+1)<MININT)
                                    {
                                        i=sp+1;
                                    }
                                    direccion=sp-i+1;
                                    break;

            case PILA_DECRECIENTE : if((i.Valor()+sp.Valor()-1)>MAXINT)
                                    {
                                        i=CEntero16b(MAXINT+1-sp.Valor());
                                    }
                                    direccion=sp;
                                    break;
        }
        while(i.Valor()>0)
        {
            i--;
            conf->Memoria()->Leer(direccion,valor);
            if(direccion.Valor()==sp.Valor())
            {
                cout<<"SP->";
            }
            else
            {
                cout<<"    ";
            }
            switch(conf->BaseNumerica())
            {
                case 10 : cout<<direccion.DecimalSinSigno()<<": ";
                          cout<<valor.DecimalFormateado()<<endl;
                          break;
                case 16 : cout<<direccion.Hexadecimal()<<": ";
                          cout<<valor.Hexadecimal()<<endl;
                          break;
            }
            direccion=direccion+CEntero16b(1);
        }
        return 0;
    }
    catch(std::runtime_error)
    {
        cout<<S_CADENA_019" num"<<endl; //ERROR: Parametro incorrecto -
        return -1;
    }
}
//---------------------------------------------------------------------------
//Constructor
CInterfazConsola::CInterfazConsola(CConfiguracion *configuracion)
{
    conf=configuracion;
    return;
}
//---------------------------------------------------------------------------
//Metodos
int CInterfazConsola::LeerComandos(void)
{
    int respuesta;
    char entrada[50];

    char comando;
    CCadena parametro1;
    CCadena parametro2;
    int nparametros;

    respuesta=0;

    while(respuesta!=1)
    {
        //Prompt
        cout<<"ENS2001> ";
        //Leemos la entrada
        cin.get(entrada,50);
        cin.ignore();
        comando='0';
        ExtraerComando(entrada,comando,parametro1,parametro2,nparametros);
        switch(comando)
        {
            case 'g' :
            case 'G' :  
         
                if(nparametros==0)
                {
                    respuesta=IntercambiarComprobarPC();
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
             
            case 'i' :
            case 'I' :  
            
                if(nparametros==0)
                {
                    respuesta=IntercambiarComprobarPila();
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
             
            case 'o' :
            case 'O' :  
         
                respuesta=EstadoSimulador();
                break;
             
            case 'n' :
            case 'N' :
         
                if(nparametros==1)
                {
                    respuesta=Base(parametro1);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
                
            case 'd' :
            case 'D' :  
            
                if(nparametros==2)
                {
                    respuesta=Desensamblar(parametro1,parametro2);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
                
            case 'v' :
            case 'V' :  if(nparametros==2)
                {
                    respuesta=VolcarBloqueMemoria(parametro1,parametro2);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
                
            case 'p' :
            case 'P' :  
            
                if(nparametros==1)
                {
                    respuesta=VolcarPila(parametro1); // Antes ponía ==, huele a bug que tira para atrás
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
     
            case 'r' :
            case 'R' :  if(nparametros==0)
               {
                   LeerBancoRegistros();
                   respuesta=0;
               }
               else if(nparametros==1)
               {
                   if((strcmp(parametro1.Cadena(),"RESET")==0) ||
                      (strcmp(parametro1.Cadena(),"reset")==0))
                   {
                    conf->BancoRegistros()->Reiniciar();
                    cout<<"Banco de Registros reiniciado"<<endl;
                   }
                   else
                   {
                    respuesta=LeerRegistro(parametro1);
                   }
               }
               else if(nparametros==2)
               {
                   respuesta=EscribirRegistro(parametro1,parametro2);
               }
               break;
       
            case 'k' :
            case 'K' :  
         
                respuesta=IntercambiarModoPila();
                break;
        
            case 'b' :
            case 'B' :  
            
                if(nparametros==0)
                {
                    respuesta=IntercambiarPararPuntosRuptura();
                }
                else if(nparametros==1)
                {
                    respuesta=IntercambiarPuntoRuptura(parametro1);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                       //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
               
            case 'c' :
            case 'C' :  
            
                if(nparametros==1)
                {
                    respuesta=Ensamblar(parametro1);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                       //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
               
            case 't' :
            case 'T' :  
            
                if(nparametros==0)
                {
                    respuesta=IntercambiarReiniciarRegistros();
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                       //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
               
            case 'e' :
            case 'E' : 
            
                respuesta=Ejecutar();
                break;
                
            case 'a' :
            case 'A' : 
            
                respuesta=IntercambiarModoPasoAPaso();
                break;
                
            case 'm' :
            case 'M' : 
            
                if(nparametros==1)
                {
                    if((strcmp(parametro1.Cadena(),"RESET")==0) ||
                       (strcmp(parametro1.Cadena(),"reset")==0))
                    {
                        conf->Memoria()->Reiniciar();
                        cout<<"Memoria reiniciada"<<endl;
                    }
                    else
                    {
                         respuesta=LeerMemoria(parametro1);
                    }
                }
                else if(nparametros==2)
                {
                    respuesta=EscribirMemoria(parametro1,parametro2);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
               
            case 'l' :
            case 'L' :  
            
                if(nparametros==1)
                {
                    respuesta=CargarMemoria(parametro1);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                       //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
               
            case 's' :
            case 'S' :  
            
                if(nparametros==1)
                {
                    respuesta=GuardarMemoria(parametro1);
                }
                else
                {
                    cout<<S_CADENA_046<<endl;
                        //ERROR: Numero de parametros incorrecto
                    respuesta=0;
                }
                break;
               
            case 'h' :
            case 'H' :  
            
                respuesta=Ayuda();
                if(respuesta!=0)
                {
                    cout<<S_CADENA_067<<endl;
                       //ERROR: Falta el fichero ayuda.txt
                }
                break;
               
            case 'q' :
            case 'Q' :  
            
                respuesta=Salir();
                break;
                
            case '0' :  
            
               break;//Comando vacio
               
            default :
            
                cout<<S_CADENA_047<<endl;
                    //ERROR: Comando no reconocido
                break;

        }
    }
    return 0;
}
//---------------------------------------------------------------------------
int CInterfazConsola::EnsamblarLineaComando(CCadena fichero)
{
    return Ensamblar(fichero);
}
//---------------------------------------------------------------------------
int CInterfazConsola::EstadoInicialSimulador(void)
{
    return EstadoSimulador();
}
