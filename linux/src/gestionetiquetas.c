/*gestionetiquetas.c*/

#include "gestionetiquetas.h"

static struct EntradaTablaEtiquetas *tablaetiquetas;
static int punteroteq;
static int contadorteq;

static struct EntradaTablaConfiguracion *tablaconfiguracion;
static int punterotcf;
static int contadortcf;
/*-------------------------------------------------------------------------*/
int ConsultarEtiqueta(char *etiqueta,int *valor)
{
    int i;

    for(i=0;i<punteroteq;i++)
    {
        if(strcmp(etiqueta,tablaetiquetas[i].etiqueta)==0)
        {
            //Etiqueta encontrada
            *valor=tablaetiquetas[i].valor;
            return 0;
        }
    }
    *valor=0;
    return -1;
}
/*-------------------------------------------------------------------------*/
int DarValorEtiqueta(const char *etiqueta,int valor)
{
    int i;
    if(valor<MININT)
    {
    	valor=valor+MAXINT+1;
    }
    if((valor<MININT) || (valor>MAXINT))
    {
    	return -2;
    }
    for(i=0;i<punteroteq;i++)
    {
        if(strcmp(etiqueta,tablaetiquetas[i].etiqueta)==0)
        {
            //Etiqueta encontrada
            tablaetiquetas[i].valor=valor;
            return 0;
        }
    }
    return -1;
}
/*-------------------------------------------------------------------------*/
int GuardarEtiqueta(const char *etiqueta,int valor)
{
    char *nueva;
    int i;
    struct EntradaTablaEtiquetas *tablanueva;
    
    if((valor<MININT) || (valor>MAXINT))
    {
    	return -4;
    }
    /*Comprobamos si se trata de una palabra reservada*/
    if(EsPalabraReservada(etiqueta)==1)
    {
        return -3;
    }
    /*Comprobamos si hay espacio en memoria*/
    if(punteroteq==contadorteq)
    {
        /*Memoria completa, hay que pedir mas*/
        /*Pedimos en bloques*/
        tablanueva=(struct EntradaTablaEtiquetas *)malloc
            (sizeof(struct EntradaTablaEtiquetas)*(contadorteq+BLOQ_TETIQ));
        if(tablanueva!=NULL)
        {
            /*Se asigno espacio correctamente*/
            for(i=0;i<contadorteq;i++)
            {
                tablanueva[i].etiqueta=tablaetiquetas[i].etiqueta;
                tablanueva[i].valor=tablaetiquetas[i].valor;
            }
            free(tablaetiquetas);
            contadorteq=contadorteq+BLOQ_TETIQ;
            tablaetiquetas=tablanueva;
        }
        else
        {
            return -1;
        }
    }
    for(i=0;i<punteroteq;i++)
    {
        if(strcmp(etiqueta,tablaetiquetas[i].etiqueta)==0)
        {
            //Etiqueta encontrada
            return -2;
        }
    }
    nueva=(char *)strdup((const char *)etiqueta);
    tablaetiquetas[punteroteq].etiqueta=nueva;
    tablaetiquetas[punteroteq].valor=valor;
    punteroteq++;
    return 0;
}
/*-------------------------------------------------------------------------*/
void InicializarTablaEtiquetas(void)
{
    tablaetiquetas=NULL;
    punteroteq=0;
    contadorteq=0;
}
/*-------------------------------------------------------------------------*/
void LiberarTablaEtiquetas(void)
{
    if(tablaetiquetas!=NULL)
    {
        free(tablaetiquetas);
    }
    punteroteq=0;
    contadorteq=0;
}
/*-------------------------------------------------------------------------*/
int EscribirTablaConfiguracion(const char *etiqueta,int posicion,
                               int desplazamiento,int mododireccionamiento,
                               int linea)
{
    char *nueva;
    struct EntradaTablaConfiguracion *tablanueva;
    int i;

    /*Comprobamos si hay espacio en memoria*/
    if(punterotcf==contadortcf)
    {
        /*Memoria completa, hay que pedir mas*/
        /*Pedimos en bloques*/
        tablanueva=(struct EntradaTablaConfiguracion *)malloc
            (sizeof(struct EntradaTablaConfiguracion)*(contadortcf+BLOQ_TCNF));
        if (tablanueva!=NULL)
        {
            /*Se asigno espacio correctamente*/
            for(i=0;i<contadortcf;i++)
            {
                tablanueva[i].etiqueta=tablaconfiguracion[i].etiqueta;
                tablanueva[i].posicion=tablaconfiguracion[i].posicion;
                tablanueva[i].desplazamiento=
                    tablaconfiguracion[i].desplazamiento;
                tablanueva[i].mododireccionamiento=
                    tablaconfiguracion[i].mododireccionamiento;
                tablanueva[i].linea=tablaconfiguracion[i].linea;
            }
            free(tablaconfiguracion);
            contadortcf=contadortcf+BLOQ_TCNF;
            tablaconfiguracion=tablanueva;
        }
        else
        {
            return -1;
        }
    }
    nueva=(char *)strdup((const char *)etiqueta);
    tablaconfiguracion[punterotcf].etiqueta=nueva;
    tablaconfiguracion[punterotcf].posicion=posicion;
    tablaconfiguracion[punterotcf].desplazamiento=desplazamiento;
    tablaconfiguracion[punterotcf].mododireccionamiento=mododireccionamiento;
    tablaconfiguracion[punterotcf].linea=linea;
    punterotcf++;

    return 0;
}
/*-------------------------------------------------------------------------*/
void InicializarTablaConfiguracion(void)
{
    tablaconfiguracion=NULL;
    punterotcf=0;
    contadortcf=0;
}
/*-------------------------------------------------------------------------*/
void LiberarTablaConfiguracion(void)
{
    if(tablaconfiguracion!=NULL)
    {
        free(tablaconfiguracion);
    }
    punterotcf=0;
    contadortcf=0;
}
/*-------------------------------------------------------------------------*/
int RevisarTablaConfiguracion(void)
{
    int existe;
    int *valor;
    int valoractual;
    int posicion;
    int desplazamiento;
    int mododireccionamiento;
    int linea;
    int i;
    int valorretorno;

    valorretorno=0;
    valor=(int *)malloc(sizeof(int));
    for(i=0;i<punterotcf;i++)
    {
        existe=ConsultarEtiqueta(tablaconfiguracion[i].etiqueta,valor);
        posicion=tablaconfiguracion[i].posicion;
        desplazamiento=tablaconfiguracion[i].desplazamiento;
        mododireccionamiento=tablaconfiguracion[i].mododireccionamiento;
        linea=tablaconfiguracion[i].linea;
        if (existe!=-1)
        {
            /*Comprobamos que la etiqueta sea correcta*/
            switch(mododireccionamiento)
            {
                case MD_INMEDIATO :
                case MD_MEMORIA :

                    break;

                case MD_RELATIVO_IX :
                case MD_RELATIVO_IY :

                    if ((*valor<MINDESP) || (*valor>MAXDESP))
                    {
                        //Error. Etiqueta incorrecta
                        InformarError(ERR_DESPLAZAMIENTO_FUERA_RANGO,linea,
                                      tablaconfiguracion[i].etiqueta);
                        valorretorno=-1;
                    }
                    break;

                case MD_RELATIVO_PC :

                    /*Convertimos la direccion a relativa*/
                    *valor=*valor-posicion-1;
                    if ((*valor<-128) || (*valor>127))
                    {
                        //Error. Etiqueta incorrecta
                        InformarError(ERR_DESPLAZAMIENTO_FUERA_RANGO,linea,
                                      tablaconfiguracion[i].etiqueta);
                        valorretorno=-1;
                    }
                    else if(*valor<0)
                    {
                    	*valor=*valor+MAXDESP+1;
                    }
                    break;

                case MD_NO_OPERANDO :
                case MD_REGISTRO :
                case MD_INDIRECTO :
                default :

                    /*ERROR*/
                    valorretorno=-1;
            }
            /*Actualizamos la memoria con el valor correspondiente*/
            if((mododireccionamiento==MD_REGISTRO) ||
               (mododireccionamiento==MD_INDIRECTO) ||
               (mododireccionamiento==MD_RELATIVO_IX) ||
               (mododireccionamiento==MD_RELATIVO_IY) ||
               (mododireccionamiento==MD_RELATIVO_PC))
            {
                valoractual=LeerMemoria(posicion);
                if(desplazamiento==0)
                {
                    *valor=(*valor)*256;
                }
                EscribirMemoria(posicion,(*valor)+valoractual);
            }
            else
            {
                EscribirMemoria(posicion,*valor);
            }
        }
        else
        {
            //Error. Etiqueta no definida
            if(EsPalabraReservada(tablaconfiguracion[i].etiqueta))
            {
            	InformarError(ERR_NOMBRE_ETIQUETA_RESERVADO,linea,
                              tablaconfiguracion[i].etiqueta);
            }
            else
            {
                InformarError(ERR_ETIQUETA_NO_DEFINIDA,linea,
                              tablaconfiguracion[i].etiqueta);
            }
            valorretorno=-1;
        }
    }
    free(valor);
    return valorretorno;
}
/*-------------------------------------------------------------------------*/
int ListaEtiquetas(void)
{
    /*FUNCION PARA DEPURACION*/
    int i;

    printf("TABLA DE ETIQUETAS\n");
    for(i=0;i<punteroteq;i++)
    {
        printf("%s -> %d\n",tablaetiquetas[i].etiqueta,tablaetiquetas[i].valor);
    }
    return 0;
}
/*-------------------------------------------------------------------------*/
int ListaTablaConfiguracion(void)
{
    /*FUNCION PARA DEPURACION*/
    int i;

    printf("TABLA DE CONFIGURACION\n");
    printf("ETIQUETA - POSICION - DESPLAZ - MODODIR - LINEA\n");
    for(i=0;i<punterotcf;i++)
    {
        printf("%s %d %d %d %d\n",
               tablaconfiguracion[i].etiqueta,
               tablaconfiguracion[i].posicion,
               tablaconfiguracion[i].desplazamiento,
               tablaconfiguracion[i].mododireccionamiento,
               tablaconfiguracion[i].linea);
    }
    return 0;
}
/*-------------------------------------------------------------------------*/
