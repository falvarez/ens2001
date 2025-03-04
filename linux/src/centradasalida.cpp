//centradasalida.cpp
#include "centradasalida.h"
#ifdef _ENS2001_WINDOWS_
//---------------------------------------------------------------------------
CEntradaSalida::CEntradaSalida(CConfiguracion *configuracion)
{
	conf=configuracion;
	conf->EscribirEntradaSalida(this);
	return;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(CEntero16b entero)
{
        thread_procesador->Escribir(entero);
	return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(char caracter)
{
        thread_procesador->Escribir(caracter);
	return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(CCadena cadena)
{
        thread_procesador->Escribir(cadena);
	return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
void CEntradaSalida::EscribirHilo(CTProcesador *hilo)
{
        thread_procesador=hilo;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(CEntero16b &entero)
{	
	//Si lee un entero no valido, recoge un valor 0
        thread_procesador->Leer(entero);
	return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(char &caracter)
{
        thread_procesador->Leer(caracter);
	return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(CCadena &cadena)
{
        thread_procesador->Leer(cadena);
     	return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
#endif
#ifdef _ENS2001_CONSOLA_
//---------------------------------------------------------------------------
CEntradaSalida::CEntradaSalida(CConfiguracion *configuracion)
{
    conf=configuracion;
    conf->EscribirEntradaSalida(this);
    return;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(CCadena cadena)
{
    cout<<cadena.Cadena();
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(char caracter)
{
    cout<<caracter;
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(CEntero16b entero)
{
    switch(conf->BaseNumerica()){
        case 10 : cout<<entero.Decimal();
                  break;
        case 16 : cout<<entero.Hexadecimal();
                  break;
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(CCadena &cadena)
{
    if(!LeerEntrada(cadena))
    {
        conf->BancoRegistros()->
                           EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
        throw std::runtime_error("Tecla ESC pulsada durante entrada");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(char &caracter)
{
    CCadena entrada;
    if(!LeerEntrada(entrada))
    {
        conf->BancoRegistros()->
                           EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
        throw std::runtime_error("Tecla ESC pulsada durante entrada");
    }
    caracter=entrada.Cadena()[0];
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(CEntero16b &entero)
{
    //Si lee un entero no valido, recoge un valor 0
    CCadena entrada;
    if(!LeerEntrada(entrada))
    {
        conf->BancoRegistros()->
                           EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
        throw std::runtime_error("Tecla ESC pulsada durante entrada");
    }
    else
    {
        try
        {
            entero=CEntero16b(entrada.Cadena());
        }
        catch(std::runtime_error)
        {
            entero=CEntero16b(0);
        }
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
bool CEntradaSalida::LeerEntrada(CCadena &entrada)
{
    char lectura[256];
    int puntero=0;
    char caracter='\0';
    int estado=0;
    
    while(caracter!=(char)KEY_INTRO)
    {
        while(!kbhit){} //Esperamos la pulsacion de una tecla
        
        caracter=getch();
        
        if(estado!=CONTROL){
            //Tratamiento de retroceso
            if(caracter==KEY_BACKSPACE)
            {
                puntero--;
                if(puntero<0)
                {
                    puntero=0;
                }
                cout<<'\b'<<' '<<'\b';
                estado=KEY_BACKSPACE;
            }
            //Tratamiento de abortar ejecucion
            else if(caracter==KEY_ESCAPE)
            {
                return false;
            }
            //Tratamiento de leer entrada
            else if(caracter==KEY_INTRO)
            {
                lectura[puntero]='\0';
                puntero++;
            }
            //Tratamiento de tildes y dieresis
            else if(caracter==AGUDO)
            {
                estado=AGUDO;
            }
            else if(caracter==GRAVE)
            {
                estado=GRAVE;
            }
            else if(caracter==DIERESIS)
            {
            estado=DIERESIS;
            }
            else if(caracter==CIRCUNFLEJO)
            {
                estado=CIRCUNFLEJO;
            }
            else if(caracter==0)
            {
                estado=CONTROL;
            }
            else
            {
            	estado=0;
            }
            if(estado==0)
            {
                lectura[puntero]=caracter;
                puntero++;
                cout<<caracter;
            } 
        }
        else
        {
            estado=0;
        }      
    }
    entrada=CCadena(lectura);
    cout<<endl;
    return true;
}
//---------------------------------------------------------------------------
#endif
#ifdef _ENS2001_LINUX_
//---------------------------------------------------------------------------
CEntradaSalida::CEntradaSalida(CConfiguracion *configuracion)
{
    conf=configuracion;
    conf->EscribirEntradaSalida(this);
    return;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(CCadena cadena)
{
    cout<<cadena.Cadena();
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(char caracter)
{
    cout<<caracter;
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Escribir(CEntero16b entero)
{
    switch(conf->BaseNumerica()){
        case 10 : cout<<entero.Decimal();
                  break;
        case 16 : cout<<entero.Hexadecimal();
                  break;
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(CCadena &cadena)
{
    if(!LeerEntrada(cadena))
    {
        conf->BancoRegistros()->
                           EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
        throw std::runtime_error("Tecla ESC pulsada durante entrada");
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(char &caracter)
{
    CCadena entrada;
    if(!LeerEntrada(entrada))
    {
        conf->BancoRegistros()->
                           EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
        throw std::runtime_error("Tecla ESC pulsada durante entrada");
    }
    caracter=entrada.Cadena()[0];
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
int CEntradaSalida::Leer(CEntero16b &entero)
{
    //Si lee un entero no valido, recoge un valor 0
    CCadena entrada;
    if(!LeerEntrada(entrada))
    {
        conf->BancoRegistros()->
                           EscribirRegistroExcepcion(EX_DETENIDO_POR_USUARIO);
        throw std::runtime_error("Tecla ESC pulsada durante entrada");
    }
    else
    {
        try
        {
            entero=CEntero16b(entrada.Cadena());
        }
        catch(std::runtime_error)
        {
            entero=CEntero16b(0);
        }
    }
    return EJ_SIGUIENTE;
}
//---------------------------------------------------------------------------
bool CEntradaSalida::LeerEntrada(CCadena &entrada)
{
    char lectura[256];
    int puntero=0;
    char caracter='\0';
    int estado=0;
    
    cin.get(lectura,255);
    entrada=CCadena(lectura);
    cin.ignore();
    return true;
}
//---------------------------------------------------------------------------
#endif
