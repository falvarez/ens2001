//ctprocesador.h

#ifndef _CTPROCESADOR_H_
#define _CTPROCESADOR_H_

#include "compilacion.h"
#include "definiciones.h"
#include "defscpp.h"
#include <Classes.hpp>
#include "cconfiguracion.h"
#include "cprocesador.h"
#include "windows\FormPrincipal.h"

class CTProcesador : public TThread
{
    private:
        CConfiguracion *configuracion;
        TfrmPrincipal *vprincipal;

    protected:
        void __fastcall Execute();

    public:
        __fastcall CTProcesador(bool CreateSuspended);
        void EscribirConfiguracion(CConfiguracion *conf);
        void EscribirPrincipal(TfrmPrincipal *ventana);
        int Leer(CEntero16b &entero);
        int Leer(char &caracter);
        int Leer(CCadena &cadena);

        int Escribir(CEntero16b entero);
        int Escribir(char caracter);
        int Escribir(CCadena cadena);
};

#endif //_CTPROCESADOR_H_
