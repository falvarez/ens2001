//censamblador.cpp
#include "censamblador.h"

//Constructor
CEnsamblador::CEnsamblador(CConfiguracion *configuracion)
{
    conf=configuracion;
    return;
}
//---------------------------------------------------------------------------
int CEnsamblador::Ensamblar(CCadena fichero,int &lineas)
{
    int resultado;
    int *nlin;
    int *codigoinicio;
    int *codigofin;

    //Copiamos el fichero de entrada en un fichero temporal
    //y a�adimos un salto de linea para asegurar que la ultima linea se
    //ensambla
    ifstream entrada;
    ofstream salida;
    unsigned char caracter[1];

    entrada.open(fichero.Cadena());
    if(entrada!=NULL)
    {
        salida.open(FICHERO_TEMPORAL_FUENTE);
        if(salida!=NULL)
        {
            while(entrada.read((char *)caracter,1))
            {
                salida.write((char *)caracter,1);
            }
            salida.write("\n",1);
            entrada.close();
            salida.close();
        }
        else
        {
            //Error al abrir el fichero de salida
            lineas=0;
            return -5;
        }
    }
    else
    {   
    	//Error al abrir el fichero de entrada
    	lineas=0;
    	return -2;
    }
    nlin=(int *)malloc(sizeof(int));
    codigoinicio=(int *)malloc(sizeof(int));
    codigofin=(int *)malloc(sizeof(int));
    resultado=Ens(FICHERO_TEMPORAL_FUENTE,nlin,codigoinicio,codigofin);
    conf->BancoRegistros()->EscribirCodigo1(CEntero16b(*codigoinicio));
    conf->BancoRegistros()->EscribirCodigo2(CEntero16b(*codigofin));
    lineas=(*nlin)-1; //habiamos a�adido una linea artificialmente
    free(codigofin);
    free(codigoinicio);
    free(nlin);
    return resultado;
}
