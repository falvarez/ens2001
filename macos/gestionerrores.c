/*gestionerrores.c*/

#include "gestionerrores.h"

static struct Error *listaerrores;
static int contadorerrores;
/*-------------------------------------------------------------------------*/
int NuevoError(int codigo,char *descripcion,int linea,char *token)
{
    struct Error *nuevo;
    struct Error *puntero;
    struct Error *anterior;
    int final;

    nuevo=(struct Error *)malloc(sizeof(struct Error));
    if(nuevo!=NULL)
    {
        /*Se asigno memoria correctamente*/
        nuevo->codigo=codigo;
        nuevo->descripcion=strdup(descripcion);
        nuevo->token=strdup(token);
        nuevo->linea=linea;
        if(listaerrores==NULL)
        {
            /*No hay ninguno, creamos el primero*/
            nuevo->siguiente=NULL;
            listaerrores=nuevo;
            contadorerrores++;
            return 0;
        }
        else
        {
            anterior=NULL;
            puntero=listaerrores;
            final=0;
            while((puntero!=NULL) && (final==0))
            {
                if((puntero->linea)==linea)
                {
                    /*Descartamos el error*/
                    free(nuevo->descripcion);
                    free(nuevo);
                    return 0;
                }
                else if((puntero->linea)>linea)
                {
                    /*Insertamos aqui*/
                    nuevo->siguiente=puntero;
                    if(anterior!=NULL)
                    {
                        anterior->siguiente=nuevo;
                    }
                    else
                    {
                    	listaerrores=nuevo;
                    }
                    contadorerrores++;
                    return 0;
                }
                else
                {
                    /*Seguimos recorriendo la lista*/
                    if((puntero->siguiente)!=NULL)
                    {
                        anterior=puntero;
                        puntero=puntero->siguiente;
                    }
                    else
                    {
                        /*Final de la lista*/
                        final=1;
                    }
                }
            }
            /*Insertamos el ultimo*/
            nuevo->siguiente=NULL;
            puntero->siguiente=nuevo;
            contadorerrores++;
            return 0;
        }
    }
    else
    {
        /*Error al asignar memoria*/
        return -1;
    }
}
/*-------------------------------------------------------------------------*/
int InformarError(int codigo,int linea,char *token)
{
    /*Genera la descripcion del error indicado*/
    char error[120];

    if(token==NULL)
    {
        token="";
    }
    switch(codigo)
    {
        case ERR_MODO_DIR_1_ERRONEO :
            sprintf(error,S_CADENA_048); /*Modo Direccionamiento Operando 1*/
            break;
        case ERR_MODO_DIR_2_ERRONEO :
            sprintf(error,S_CADENA_049); /*Modo Direccionamiento Operando 2*/
            break;
        case ERR_INSTRUCCION_NO_RECONOCIDA :
            sprintf(error,S_CADENA_052); /*Instruccion no reconocida"*/
            break;
        case ERR_OP1_INCORRECTO :
            sprintf(error,S_CADENA_053); /*Operando 1 no reconocido*/
            break;
        case ERR_OP2_INCORRECTO :
            sprintf(error,S_CADENA_054); /*Operando 2 no reconocido*/
            break;
        case ERR_ETIQUETA_DUPLICADA :
            sprintf(error,S_CADENA_056); /*Etiqueta Duplicada*/
            break;
        case ERR_ETIQUETA_NO_DEFINIDA :
            sprintf(error,S_CADENA_057); /*Etiqueta No Definida*/
            break;
        case ERR_ENTRADA_INCORRECTA :
            sprintf(error,S_CADENA_058); /*Entrada Incorrecta*/
            break;
        case ERR_EXPRESION_ERRONEA :
            sprintf(error,S_CADENA_059); /*Expresion Erronea*/
            break;
        case ERR_ORG_FUERA_LIMITE_MEMORIA :
            sprintf(error,S_CADENA_062); /*Inicio del Programa Fuera de
                                           la Memoria*/
            break;
        case ERR_RES_FUERA_LIMITE_MEMORIA :
            sprintf(error,S_CADENA_063); /*Reserva de Espacio Excede
                                           los Limites de la Memoria*/
            break;
        case ERR_DATA_FUERA_LIMITE_MEMORIA :
            sprintf(error,S_CADENA_064); /*Datos en Memoria Exceden
                                           los Limites*/
            break;
        case ERR_EXPRESION_FUERA_DE_RANGO :
            sprintf(error,S_CADENA_065); /*Valor de Expresion Fuera de Rango*/
            break;
        case ERR_NOMBRE_ETIQUETA_RESERVADO :
            sprintf(error,S_CADENA_070); /*Nombre de Etiqueta No Valido*/
            break;
        case ERR_ASIGNACION_MEMORIA :
            sprintf(error,S_CADENA_071); /*Error en asignacion de memoria*/
            break;
        case ERR_ENTERO_FUERA_DE_RANGO :
            sprintf(error,S_CADENA_082); /*Entero fuera de rango*/
            break;
        case ERR_SE_ESPERABA_OP1 :
            sprintf(error,S_CADENA_088); /*Se esperaba el primer operando*/
            break;
        case ERR_SE_ESPERABA_OP2 :
            sprintf(error,S_CADENA_089); /*Se esperaba el segundo operando*/
            break;
        case ERR_SE_ESPERABA_EOL :
            sprintf(error,S_CADENA_090); /*Se esperaba fin de linea*/
            break;
        case ERR_SE_ESPERABA_SEPARADOR :
            sprintf(error,S_CADENA_091); /*Se esperaba coma*/
            break;
        case ERR_LISTA_DATOS_ERRONEA :
            sprintf(error,S_CADENA_083); /*Lista de datos no valida*/
            break;
        case ERR_DESPLAZAMIENTO_FUERA_RANGO :
            sprintf(error,S_CADENA_092); /*Desplazamiento fuera de rango*/
            break;
		case ERR_DESBORDAMIENTO_PILA_ANALIZADOR :
            sprintf(error,S_CADENA_095); /*Desbordamiento de pila en el
                                           analizador sintactico*/
            break;            
        default :
            sprintf(error,S_CADENA_066); /*Error no Tratado*/
    }
    return NuevoError(codigo,error,linea,token);
}
/*-------------------------------------------------------------------------*/
void InicializarListaErrores(void)
{
    listaerrores=NULL;
    contadorerrores=0;
}
/*-------------------------------------------------------------------------*/
void LiberarListaErrores(void)
{
    /*Va recorriendo la lista de errores y liberando el espacio asignado*/
    struct Error *puntero; /*Puntero para recorrer la lista de errores*/

    while(listaerrores!=NULL)
    {
        puntero=listaerrores;
        listaerrores=listaerrores->siguiente;
        free(puntero->descripcion);
        free(puntero->token);
        free(puntero);
    }
}
/*-------------------------------------------------------------------------*/
int ListarErrores(char *nombrefichero)
{
    FILE *fd;
    char *caracter;

    fd=fopen(nombrefichero,"r");
    if(fd!=NULL)
    {
        caracter=(char *)malloc(sizeof(char));
        while(fread(caracter,1,sizeof(char),fd)!=0)
        {
            printf("%c",*caracter);
        }
        free(caracter);
        fclose(fd);
        return 0;
    }
    else
    {
        /*Error al abrir el fichero*/
        return -1;
    }
}
/*-------------------------------------------------------------------------*/
int VolcarFicheroErrores(char *nombrefichero)
{
    FILE *fd; /*Descriptor del fichero de errores*/
    struct Error *puntero; /*Puntero para recorrer la lista de errores*/
    char *numlin;
    char *cod;
    int error; /*Errores en la escritura del fichero*/
    int valorretorno; /*Valor de retorno de la funcion*/

    puntero=listaerrores;
    error=0;
    fd=fopen(nombrefichero,"w");
    if (fd!=NULL)
    {
        while((puntero!=NULL) && (error==0))
        {
            numlin=EnteroACadena(puntero->linea,10);
            cod=EnteroACadena(puntero->codigo,10);
            if(fwrite("Linea ",sizeof(char),strlen("Linea "),fd)!=
               strlen("Linea "))
            {
                error=1;
            }   
            if(fwrite(numlin,sizeof(char),strlen(numlin),fd)!=
               strlen(numlin))
            {
            	error=1;
            }
            if(fwrite(": ERROR[",sizeof(char),8,fd)!=8)
            {
            	error=1;
            }
            if(fwrite(cod,sizeof(char),strlen(cod),fd)!=strlen(cod))
            {
            	error=1;
            }
            if(fwrite("] ",sizeof(char),strlen(") "),fd)!=strlen(") "))
            {
            	error=1;
            }
            if(fwrite(puntero->descripcion,sizeof(char),
                   strlen(puntero->descripcion),fd)!=
                   strlen(puntero->descripcion))
            {
            	error=1;
            }
            if(strlen(puntero->token)>0)
            {
                fwrite(" - ",sizeof(char),strlen(" - "),fd);
                fwrite(puntero->token,sizeof(char),strlen(puntero->token),fd);
            }
            fwrite("\n",sizeof(char),strlen("\n"),fd);
            puntero=puntero->siguiente;
            free(numlin);
            free(cod);
        }
        fclose(fd);
        if(error==1)
        {
            /*Hubo algun error durante la escritura*/
            valorretorno=-1;
        }
        else
        {
            /*Todo correcto*/
            valorretorno=0;
        }
    }
    else
    {
        /*Error al abrir el fichero*/
        valorretorno=-1;
    }
    return valorretorno;
}
/*-------------------------------------------------------------------------*/
