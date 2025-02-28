//cbancoregistros.h

#ifndef _CBANCOREGISTROS_H_
#define _CBANCOREGISTROS_H_

#include "compilacion.h"
#ifdef _ENS2001_WINDOWS_
#include <vcl.h>
#pragma hdrstop
#endif
#include "definiciones.h"
#include "defscpp.h"
#include "cconfiguracion.h"

class CBancoRegistros
{
    private:
        //Atributos
        CEntero16b registros[NUM_REGISTROS]; //Valores de los registros
        int biestables[NUM_BIESTABLES]; //Valores de los biestables
        CCadena nombres[NUM_REGISTROS]; //Nombres de los registros

        int registroexcepcion; //Registro de excepcion
        int registroinstruccion; //Registro de instruccion
        int registrofinejecucion; //Condicion de final de ejecucion

        CEntero16b codigo1; //Limite del codigo
        CEntero16b codigo2; //Limite del codigo

        CEntero16b pila1; //Limite de la pila
        CEntero16b pila2; //Limite de la pila

        //Clases con las que se interactua
        CConfiguracion *conf;

    public:
        //Constructor
        CBancoRegistros(CConfiguracion *configuracion);
            //Inicializa todos los registros a cero
            //Casos especiales:
            //    PC = Direccion mas baja de memoria (MININT)
            //    SP = Direccion mas alta de memoria (MAXINT)
        //Metodos
        //Acceso a registro de excepcion
        int RegistroExcepcion(void);
        void EscribirRegistroExcepcion(int valor);
	//Acceso a registro de instruccion
        int RegistroInstruccion(void);
        void EscribirRegistroInstruccion(int valor);
	//Acceso a registro fin de ejecucion
        int RegistroFinEjecucion(void);
        void EscribirRegistroFinEjecucion(int valor);
	//Acceso a limite 1 de codigo
        CEntero16b Codigo1(void);
        void EscribirCodigo1(CEntero16b valor);
	//Acceso a limite 2 de codigo
        CEntero16b Codigo2(void);
        void EscribirCodigo2(CEntero16b valor);
	//Acceso a limite 1 de pila
        CEntero16b Pila1(void);
        void EscribirPila1(CEntero16b valor);
	//Acceso a limite 2 de pila
        CEntero16b Pila2(void);
        void EscribirPila2(CEntero16b valor);
	//Acceso a registros
        void Escribir(int registro,CEntero16b valor);
            //Escribe un valor en un registro
            //registro: id del registro elegido (definiciones.h)
            //valor: valor numerico a introducir en el registro
            //excepciones posibles:
            //    EX_REGISTRO_NO_EXISTE
        void Leer(int registro,CEntero16b &valor);
            //Lee el contenido de un registro
            //registro: id del registro elegido (definiciones.h)
            //valor: el valor de dicho registro
            //excepciones posibles:
            //    EX_REGISTRO_NO_EXISTE
        //Acceso a biestables de estado
        void EscribirBiestableEstado(int biestable,int valor);
            //Escribe un valor en un biestable de estado
            //biestable: id del biestable elegido (definiciones.h)
            //valor: valor a introducir en el biestable (0 o 1)
            //     si valor es distinto de 0 introduce un 1, si no un 0
            //excepciones posibles:
            //    EX_BIESTABLE_NO_EXISTE
        void LeerBiestableEstado(int biestable,int &valor);
            //Lee el valor contenido en un biestable de estado
            //biestable: id del biestable elegido (definiciones.h)
            //valor: valor que contenia el biestable (0 o 1)
            //excepciones posibles:
            //    EX_BIESTABLE_NO_EXISTE
        void LeerNombreRegistro(int registro,CCadena &nombre);
            //Devuelve el nombre de un registro determinado
        void LeerIdRegistro(CCadena &nombre,int &registro);
            //Devuelve el identificador numerico de un registro determinado 
        void Reiniciar(void);
            //Reiniciar el valor de los registros
            //El valor de SP se actualizara segun la configuracion de la pila
};

#endif //_CBANCOREGISTROS_H_
