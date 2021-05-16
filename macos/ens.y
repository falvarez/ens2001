                /*Fichero ens.y*/

                /*Instrucciones*/
%token MNEMONICO0
%token MNEMONICO1
%token MNEMONICO2
                /*Pseudoinstrucciones*/
%token ORG
%token END
%token EQU
%token RES
%token DATA
                /*Separadores*/
%token EOL
%token SEPARADOR
%token FIN_ETIQ
%token COMILLAS
                /*Operadores aritmeticos*/
%token SUMA
%token RESTA
%token PRODUCTO
%token DIVISION
%token MODULO
%token PARENT_ABRE
%token PARENT_CIERRA
                /*Operandos y modos de direccionamiento*/
%token INMEDIATO_V
%token INMEDIATO_E
%token REGISTRO
%token MEMORIA_V
%token MEMORIA_E
%token INDIRECTO
%token RELAT_PC_V
%token RELAT_PC_E
%token RELAT_IX_V
%token RELAT_IX_E
%token RELAT_IY_V
%token RELAT_IY_E
                /*Datos*/
%token CADENA
%token ENTERO
%token ETIQUETA
                /*Axioma*/
%start programa
%{
                /*Includes*/
#include "compilacion.h"
#include _CADENAS_H_

#include "definiciones.h"
#include "defsc.h"

#include "ens_tab.h"

#include "funcionesauxiliares.h"
#include "gestionetiquetas.h"
#include "gestionerrores.h"
#include "gestionmemoria.h"

int nlin;             /*Contador de numero de lineas*/
int operando;         /*Operando que se esta analizando*/
int errores=0;        /*Errores de sintaxis y semantica*/
int generarcodigo=1;  /*Indica si se debe generar codigo o hay errores*/
struct Instruccion instruccion; /*Almacen temporal de instrucciones*/
int posmem=0;         /*Posicion de memoria sobre la que estamos ensamblando 
                        actualmente*/

char *etiqueta;       /*Etiqueta al comienzo de la linea*/
char *cadena;         /*Literal cadena entre comillas*/

int numetiq;          /*0 si no se ha leido etiqueta, 1 si se ha leido 
                        etiqueta*/
int dirmem;
int desplazamiento;
int *listadatos;      /*Lista de Data (temporal)*/
unsigned int plistadatos; /*Puntero de la lista de datos*/
int dato;             /*Datos introducidos en memoria por una 
		        pseudoinstruccion data*/

unsigned int i;       /*Indice para bucles*/
int retorno;          /*Valor de retorno de funciones*/

        /*Control de errores sintacticos*/
int numregla;
int numtoken;
%}
%%

programa : /*01: programa -> @*/
           
         | /*02: programa -> EOL programa*/
           EOL
           {LiberarListaTokens();}                       
           programa  
           
         | /*03: programa -> linea programa*/ 
           {operando=0;}
           {numregla=0;}
           {numetiq=0;}
           
           linea
           
           {/*ListarTokens();*/
            LiberarListaTokens();}
           
           programa ;

linea : /*04: linea -> ETIQUETA FIN_ETIQ linea_vacia resto*/ 
        ETIQUETA
        FIN_ETIQ
        {numetiq=1;}
        
        {
         retorno=GuardarEtiqueta(etiqueta,posmem);
         if(retorno==-1)
         {
             /*Error asignando memoria*/
             InformarError(ERR_ASIGNACION_MEMORIA,nlin+1,etiqueta);
             generarcodigo=0;
             return -1;
         }
         else if(retorno==-2){
             /*Etiqueta duplicada*/
             InformarError(ERR_ETIQUETA_DUPLICADA,nlin+1,etiqueta);
             /*nlin+1, porque no hemos leido la linea completa todavia*/
             generarcodigo=0;
         }
         else if(retorno==-3){
             /*Etiqueta reservada*/
             InformarError(ERR_NOMBRE_ETIQUETA_RESERVADO,nlin+1,etiqueta);
             /*nlin+1, porque no hemos leido la linea completa todavia*/
             generarcodigo=0;
         }
        }
        
        linea_vacia 
        resto

      | /*05: linea -> resto*/ 
        resto ;
        
linea_vacia : /*06: linea_vacia -> @*/
 
            | /*07: linea_vacia -> EOL linea_vacia*/ 
              EOL 
              linea_vacia ;

resto : /*08: resto -> instruccion*/
        instruccion
                
      | /*09: resto -> pseudoinstruccion*/
        pseudoinstruccion   
        
      | /*10: resto -> error EOL*/
        error 
        EOL
        
        {
         switch(numregla)
         {
             case 11 :
             
                 if(numtoken==2)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,
                                   ConsultarToken(2));
                 }
                 break;
                 
             case 12 :
             
                 if(numtoken==2)
                 {
                     if(strcmp(ConsultarToken(2),"<EOL>")==0)
                     {
                         InformarError(ERR_SE_ESPERABA_OP1,nlin,"<EOL>");
                     }
                     else
                     {
                         InformarError(ERR_OP1_INCORRECTO,nlin,
                                       ConsultarToken(2));
                     }
                 }
                 else if(numtoken==3)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,
                                   ConsultarToken(3));
                 }
                 break;
                 
             case 13 :
             
                 if(numtoken==2)
                 {
                     if(strcmp(ConsultarToken(2),"<EOL>")==0)
                     {
                         InformarError(ERR_SE_ESPERABA_OP1,nlin,"<EOL>");
                     }
                     else
                     {
                         InformarError(ERR_OP1_INCORRECTO,nlin,
                                       ConsultarToken(2));
                     }
                 }
                 else if(numtoken==3)
                 {
                     InformarError(ERR_SE_ESPERABA_SEPARADOR,nlin,
                                   ConsultarToken(3));
                 }
                 else if(numtoken==4)
                 {
                     if(strcmp(ConsultarToken(4),"<EOL>")==0)
                     {
                         InformarError(ERR_SE_ESPERABA_OP2,nlin,"<EOL>");
                     }
                     else
                     {
                         InformarError(ERR_OP2_INCORRECTO,nlin,
                                       ConsultarToken(4));
                     }
                 }
                 else if(numtoken==5)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,
                                   ConsultarToken(5));
                 }
                 break;
                 
             case 26 :
             
                 if(numtoken==2)
                 {
                     if(strcmp(ConsultarToken(0),"<EOL>")==0)
                     {
                         InformarError(ERR_EXPRESION_ERRONEA,nlin-1,"<EOL>");
                     }
                     else
                     {
                     	 InformarError(ERR_EXPRESION_ERRONEA,nlin,"");
                     }
                 }
                 else if(numtoken==3)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,ConsultarToken(0));
                 }
             
             case 27 : 
             
                 if(numtoken==2)
                 {
                     if(strcmp(ConsultarToken(0),"<EOL>")==0)
                     {
                         InformarError(ERR_EXPRESION_ERRONEA,nlin-1,"<EOL>");
                     }
                     else
                     {
                     	 InformarError(ERR_EXPRESION_ERRONEA,nlin,"");
                     }
                 }
                 else if(numtoken==3)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,ConsultarToken(0));
                 }
                 
             case 28 :
             
                 if(numtoken==2)
                 {
                     if(strcmp(ConsultarToken(0),"<EOL>")==0)
                     {
                         InformarError(ERR_EXPRESION_ERRONEA,nlin-1,"<EOL>");
                     }
                     else
                     {
                     	 InformarError(ERR_EXPRESION_ERRONEA,nlin,"");
                     }
                 }
                 else if(numtoken==3)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,ConsultarToken(0));
                 } 
                 
             case 29 :
             
                 if(numtoken==2)
                 {
                     if(strcmp(ConsultarToken(0),"<EOL>")==0)
                     {
                         InformarError(ERR_EXPRESION_ERRONEA,nlin-1,"<EOL>");
                     }
                     else
                     {
                     	 InformarError(ERR_EXPRESION_ERRONEA,nlin,"");
                     }
                 }
                 else if(numtoken==3)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,ConsultarToken(0));
                 } 
                 
             case 30 :
             
                 if(numtoken==2)
                 {
                     InformarError(ERR_SE_ESPERABA_EOL,nlin,ConsultarToken(0));
                 }
                 
             default :
             
                 InformarError(ERR_INSTRUCCION_NO_RECONOCIDA,nlin,
                           ConsultarToken(1));
         }
         generarcodigo=0;
         yyerrok;
        } ;

instruccion : /*11: instruccion -> MNEMONICO0 EOL*/
              {numregla=11;
               operando=0; 
               numtoken=1;}
              MNEMONICO0
              {numtoken=2;
               operando=3;}
              EOL
              
              {
               instruccion.codop=$2;
               instruccion.mdir1=0;
               instruccion.op1=0;
               instruccion.etiqueta1=NULL;
               instruccion.longitud1=0;
               instruccion.mdir2=0;
               instruccion.op2=0;
               instruccion.etiqueta2=NULL;
               instruccion.longitud2=0;
               errores=ComprobarInstruccion(instruccion.codop,
                       instruccion.mdir1,instruccion.op1,
                       instruccion.mdir2,instruccion.op2);
               if(errores==0)
               {
                   AlmacenaInstruccion(0);
               }
               else
               {
                   InformarError(errores,nlin,"");
                   generarcodigo=0;
                   yyerrok;
               }
              }
              
            | /*12: instruccion -> MNEMONICO1 operando EOL*/
              {numregla=12;
               operando=0;
               numtoken=1;}
              MNEMONICO1
              {numtoken=2;
               operando=1;} 
              operando
              {numtoken=3;
               operando=3;}
              EOL
                       
              {
               instruccion.codop=$2;
               instruccion.mdir2=0;
               instruccion.op2=0;
               instruccion.etiqueta2=NULL;
               instruccion.longitud2=0;
               errores=ComprobarInstruccion(instruccion.codop,
                       instruccion.mdir1,instruccion.op1,
                       instruccion.mdir2,instruccion.op2);
               dirmem=posmem+1;
               desplazamiento=0;
               if(instruccion.etiqueta1!=NULL)
               {
                   EscribirTablaConfiguracion(instruccion.etiqueta1,
                                              dirmem,desplazamiento,
                                              instruccion.mdir1,nlin);
               }
               if(errores==0)
               {
                   AlmacenaInstruccion(1);
               }
               else
               {
                   InformarError(errores,nlin,"");
                   generarcodigo=0;
                   yyerrok;
               }
              }
 	      
            | /*13: instruccion -> MNEMONICO2 operando SEPARADOR operando EOL*/
              {numregla=13;
               numtoken=1;
               operando=0;}
              MNEMONICO2
              {numtoken=2;
               operando=1;}
              operando
              {numtoken=3;}
              SEPARADOR
              {numtoken=4;
               operando=2;}
              operando
              {numtoken=5;
               operando=3;}
              EOL
              
              {
               instruccion.codop=$2;
               errores=ComprobarInstruccion(instruccion.codop,
                       instruccion.mdir1,instruccion.op1,
                       instruccion.mdir2,instruccion.op2);
               /*Operando1*/
               dirmem=posmem+1;
               desplazamiento=0;
               if(instruccion.etiqueta1!=NULL)
               {
                   EscribirTablaConfiguracion(instruccion.etiqueta1,
                                              dirmem,desplazamiento,
                                              instruccion.mdir1,nlin);
               }
               /*Operando2*/
               if((instruccion.mdir1==MD_INMEDIATO) || 
                  (instruccion.mdir1==MD_MEMORIA) ||
                  (instruccion.mdir2==MD_INMEDIATO) || 
                  (instruccion.mdir2==MD_MEMORIA))
               {
                   dirmem=posmem+2;
                   desplazamiento=0;
               }
               else
               {
                   desplazamiento=8;
               }
               if(instruccion.etiqueta2!=NULL)
               {
                   EscribirTablaConfiguracion(instruccion.etiqueta2,
                                              dirmem,desplazamiento,
                                              instruccion.mdir2,nlin);
               }
               if (errores==0)
               {
                   AlmacenaInstruccion(2);
               }
               else
               {
                   InformarError(errores,nlin,"");
                   generarcodigo=0;
                   yyerrok;
               }
              } ;

operando : /*14: operando -> INMEDIATO_V*/
           INMEDIATO_V

           {
            if(operando==1)
            {
                instruccion.mdir1=MD_INMEDIATO;
                instruccion.op1=$1;
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_INMEDIATO;
                instruccion.op2=$1;
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           }
           
         | /*15: operando -> INMEDIATO_E*/
           INMEDIATO_E
           
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_INMEDIATO;
                instruccion.op1=$1;
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=16;
            }
            else
            {
                instruccion.mdir2=MD_INMEDIATO;
                instruccion.op2=$1;
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud2=16;
            }
           }
        
         | /*16: operando -> REGISTRO*/
           REGISTRO
         
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_REGISTRO;
                instruccion.op1=$1;
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_REGISTRO;
                instruccion.op2=$1;
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           }
           
         | /*17: operando -> MEMORIA_V*/
           MEMORIA_V
         
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_MEMORIA;
                instruccion.op1=$1;
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_MEMORIA;
                instruccion.op2=$1;
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
	   }
           
         | /*18: operando -> MEMORIA_E*/
           MEMORIA_E
            
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_MEMORIA;
                instruccion.op1=$1;
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=16;
            }
            else
            {
                instruccion.mdir2=MD_MEMORIA;
                instruccion.op2=$1;
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud2=16;
            }
           }
           
         | /*19: operando -> INDIRECTO*/
           INDIRECTO
           
           {
            if (operando==1)
            {
                instruccion.mdir1=MD_INDIRECTO;
                instruccion.op1=$1;
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_INDIRECTO;
                instruccion.op2=$1;
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           }
           
         | /*20: operando -> RELAT_PC_V*/
           RELAT_PC_V
           
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_PC;
                instruccion.op1=$1;
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_PC;
                instruccion.op2=$1;
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           }
            
         | /*21: operando -> RELAT_PC_E*/
           RELAT_PC_E
           
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_PC;
                instruccion.op1=$1;
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_PC;
                instruccion.op2=$1;
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           }
           
         | /*22: operando -> RELAT_IX_V*/
           RELAT_IX_V
           
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IX;
                instruccion.op1=$1;
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IX;
                instruccion.op2=$1;
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           }
         | /*23: operando -> RELAT_IX_E*/
           RELAT_IX_E
           
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IX;
                instruccion.op1=$1;
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IX;
                instruccion.op2=$1;
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           }
           
         | /*24: operando -> RELAT_IY_V*/
           RELAT_IY_V
           
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IY;
                instruccion.op1=$1;
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IY;
                instruccion.op2=$1;
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           }
           
         | /*25: operando -> RELAT_IY_E*/
           RELAT_IY_E
           
           {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IY;
                instruccion.op1=$1;
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IY;
                instruccion.op2=$1;
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           } ;

pseudoinstruccion : /*26: pseudoinstruccion -> ORG expresion EOL*/
		    {numregla=26;
		     numtoken=1;}
           	    ORG
		    {numtoken=2;
		     operando=1;}
		    expresion 
		    {numtoken=3;
		     operando=3;} 
		    EOL
                    
                    {
                     if(($4<0) && ($4>=-32768))
                     {
                         /*Pasamos a complemento a 2*/
                         $4=$4+MAXINT+1;
                     }
                     if(($4<MININT) || ($4>MAXINT))
                     {
                         InformarError(ERR_ORG_FUERA_LIMITE_MEMORIA,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         posmem=$4;
                     }
                    }
                    
                  | /*27: pseudoinstruccion -> RES expresion EOL*/
           	    {numregla=27;
           	     numtoken=1;}
           	    RES
           	    {numtoken=2;}
                    expresion
                    {numtoken=3;
                     operando=3;}
                    EOL
                    
                    {
                     if(($4<0) && ($4>=-32768))
                     {
                         /*Pasamos a complemento a 2*/
                         $4=$4+MAXINT+1;
                     }
                     else if($4<-32768)
                     {
                         InformarError(ERR_RES_FUERA_LIMITE_MEMORIA,nlin,"");
                     }
                     if(posmem+$4>MAXINT)
                     {
                         InformarError(ERR_RES_FUERA_LIMITE_MEMORIA,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         posmem=posmem+$4;
                         /*Para que se actualicen los limites de memoria*/
                         EscribirMemoria(posmem-1,0); 
                     }                     
                    }
                    
                  | /*28: pseudoinstruccion -> DATA lista_datos EOL*/
           	    {numregla=28;
           	     numtoken=1;}
           	    DATA
                    {numtoken=2;
                     operando=1;}
                    
                    {
                     listadatos=(int *)malloc(sizeof(int)*1000); 
                     plistadatos=0;
                    }
                    
                    lista_datos
                    {numtoken=3;
                     operando=3;}
                    EOL
                    
                    {
                     if((posmem+plistadatos)>(MAXINT+1))
                     {
                         InformarError(ERR_DATA_FUERA_LIMITE_MEMORIA,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         for(i=0;i<plistadatos;i++)
                         {
                             dato=listadatos[i];
                             if(dato<0)
                             {
                                 dato=256+dato;
                             }
                             EscribirMemoria(posmem+i,dato);
                         }
                         posmem=posmem+plistadatos;
                         free(listadatos);
                     }
                    }
                    
                  | /*29: pseudoinstruccion -> EQU expresion EOL*/
           	    {numregla=29;
           	     numtoken=1;}
           	    EQU
                    {numtoken=2;
                     operando=1;}
                    expresion
                    {numtoken=3;
                     operando=3;}
                    EOL
                    
                    {
                     if(($4<-((MAXINT+1)/2)) || ($4>MAXINT))
                     {
                         InformarError(ERR_EXPRESION_FUERA_DE_RANGO,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         if(etiqueta!=NULL)
                         {
                             DarValorEtiqueta(etiqueta,$4);
                         }
                         else
                         {
                             InformarError(ERR_ETIQUETA_NO_DEFINIDA,nlin,etiqueta);
                             generarcodigo=0;
                         }
                     }
                    }
                    
                  | /*30: pseudoinstruccion -> END EOL*/
           	    {numregla=30;
           	     numtoken=1;}
           	    END
                    {numtoken=2;
                     operando=3;}
                    EOL
                    
                    {
                     nlin++;
					 return(0);
                    } ;

expresion : /*31: expresion -> RESTA expresion_2*/
            RESTA 
            expresion_2
            
            {
             $$=-$2;
            }
            
          | /*32: expresion -> expresion SUMA expresion_2*/
            expresion 
            SUMA 
            expresion_2
            
            {
             $$=$1+$3;
            }
            
          | /*33: expresion -> expresion RESTA expresion_2*/
            expresion 
            RESTA 
            expresion_2
            
            {
             $$=$1-$3;
            }
            
          | /*34: expresion -> expresion_2*/ 
            expresion_2
          
            {
             $$=$1;
            }
            
          | /*35: expresion -> error*/
            error
          
            {
             if(strcmp(ConsultarToken(0),"<EOL>")==0)
             {
                 InformarError(ERR_EXPRESION_ERRONEA,nlin,"<EOL>");
             }
             else
             {
                 InformarError(ERR_EXPRESION_ERRONEA,nlin+1,"");
             }
             generarcodigo=0;
             $$=0;
            } ;

expresion_2 : /*36: expresion_2 -> expresion_2 PRODUCTO expresion_3*/
              expresion_2
              PRODUCTO
              expresion_3
              
              {
               $$=$1*$3;
              }
              
            | /*37: expresion_2 -> expresion_2 DIVISION expresion_3*/
              expresion_2
              DIVISION
              expresion_3
              
              {
               if($3!=0)
               {
                   $$=$1/$3;
               }
               else
               {
                   InformarError(ERR_EXPRESION_ERRONEA,nlin+1,S_CADENA_096);
                   generarcodigo=0;
               }
              }
              
            | /*38: expresion_2 -> expresion_2 MODULO expresion_3*/
              expresion_2
              MODULO
              expresion_3
              
              {
               if($3!=0)
               {
                   $$=$1%$3;
               }
               else
               {
                   InformarError(ERR_EXPRESION_ERRONEA,nlin+1,S_CADENA_096);
                   generarcodigo=0;
               }
              }
              
            | /*39: expresion_2 -> expresion_3*/
              expresion_3
            
              {
               $$=$1;
              } ;

expresion_3 : /*40: expresion_3 -> PARENT_ABRE expresion PARENT_CIERRA*/
              PARENT_ABRE
              expresion
              PARENT_CIERRA
              
              {
               $$=$2;
              }
              
            | /*41: expresion_3 -> ENTERO*/
              ENTERO
            
              {
               $$=$1;
              } ;

lista_datos : /*42: lista_datos -> ENTERO resto_lista_datos*/
              ENTERO
              
              {
               listadatos[plistadatos]=$1;
               plistadatos=plistadatos+1;
              }
              
              resto_lista_datos

            | /*43: lista_datos -> CADENA resto_lista_datos*/
              COMILLAS
              CADENA
              COMILLAS
              
              {
               for(i=0;i<(strlen(cadena));i++)
               {
                   /*Buscamos caracteres especiales*/
                   if(cadena[i]=='\\')
                   {
                       switch(cadena[i+1])
                       {
                           case '0' : listadatos[plistadatos]=(int)'\0';
                                      i++;
                                      break;
                           case 'n' : listadatos[plistadatos]=(int)'\n';
                                      i++;
                                      break;
                           case 't' : listadatos[plistadatos]=(int)'\t';
                                      i++;
                                      break;
                           default :  listadatos[plistadatos]=(int)cadena[i+1];
                       }
                   }
                   else
                   {
                       listadatos[plistadatos]=(int)cadena[i];
                       /*
                           if(listadatos[plistadatos]<0)
                           {
                               listadatos[plistadatos]=
                                   MAXDESP+1+listadatos[plistadatos];
                           }
                       */
                   }
                   plistadatos=plistadatos+1;
               }
               listadatos[plistadatos]=0;
               plistadatos=plistadatos+1;
              }
               
              resto_lista_datos
               
            | /*44: lista_datos -> EOL*/
              EOL
            
              {
               InformarError(ERR_LISTA_DATOS_ERRONEA,nlin,"<EOL>");
               generarcodigo=0;
              }
              
            | /*45: lista_datos -> error*/
              error  ;

resto_lista_datos : /*46: resto_lista_datos -> @*/
                  | /*47: resto_lista_datos -> SEPARADOR lista_datos*/
                    SEPARADOR
                    lista_datos ;

%%

int yyerror (char *s)
{
    return -1;
}

int yywrap()
{
    return 1;
}

int CalculaPosmem(void)
{
        if((instruccion.mdir1 == MD_INMEDIATO || 
             instruccion.mdir1 == MD_MEMORIA) &&
           (instruccion.mdir2 == MD_INMEDIATO || 
             instruccion.mdir2 == MD_MEMORIA))
        {
            posmem=posmem+3;
        }
        else if(instruccion.mdir1==MD_NO_OPERANDO && 
                instruccion.mdir2==MD_NO_OPERANDO)
        {
            posmem=posmem+1;
        }
        else
        {
            posmem=posmem+2;
        }
        return(0);
}

int AlmacenaInstruccion(int operandos)
{
    EscribirMemoria(posmem,
        instruccion.codop*64 + instruccion.mdir1*8 + instruccion.mdir2);
    posmem++;
    if(operandos >= 1)
    {
        if(instruccion.mdir1==MD_INMEDIATO || instruccion.mdir1==MD_MEMORIA)
        {
            EscribirMemoria(posmem,instruccion.op1);
        }
        else
        {
            EscribirMemoria(posmem,(instruccion.op1*(MAXDESP+1))%(MAXINT+1));
        }
        posmem++;
    }
    if(operandos==2)
    {
        if(instruccion.mdir1 == MD_INMEDIATO ||
           instruccion.mdir1 == MD_MEMORIA ||
           instruccion.mdir2 == MD_INMEDIATO ||
           instruccion.mdir2 == MD_MEMORIA)
        {
            EscribirMemoria(posmem,instruccion.op2);
            posmem++;
        }
        else
        {
            EscribirMemoria(posmem-1,
                    LeerMemoria(posmem-1) | (instruccion.op2%(MAXDESP+1)));
        }
    }
    return 0;
}

int Ens(const char *fichero,int *lineas,int *codigoinicio,int *codigofin)
{
        /*Devuelve:
          lineas = Lineas de Fichero de entrada procesadas
          Ens = 0 si se genero codigo
                -1 si no se genero codigo
                -2 si hubo algun error al leer el fichero
                -3 si hubo algun error al escribir el fichero memoria.tmp
                -4 si hubo algun error al volcar el fichero errores.tmp
        */

    extern FILE *yyin;

    /*Inicializamos variables*/
    nlin=0;
    generarcodigo=1;
    InicializarMemoria();
    InicializarTablaEtiquetas();
    InicializarTablaConfiguracion();
    LiberarListaTokens();
    posmem=0;
    /*Abrimos el fichero para analizar*/
    yyin=fopen(fichero,"r");
    if(yyin!=NULL)
    {
        *codigoinicio=0;
        *codigofin=0;
        rewind(yyin);
        if(yyparse()!=0)
        {
            InformarError(ERR_DESBORDAMIENTO_PILA_ANALIZADOR,0,"");
        }
        /*ListaEtiquetas();*/
        /*ListaTablaConfiguracion();*/
        if(RevisarTablaConfiguracion()!=0)
        {
            /*Hubo algun error al actualizar el codigo con los
              valores de las etiquetas*/
            generarcodigo=0;
        }
        if(generarcodigo==1)
        {
            /*Si no se ha producido ningun error anteriormente*/
            if(VolcarMemoria(FICHERO_TEMPORAL_MEMORIA,codigoinicio,
                             codigofin)!=0)
            {
                generarcodigo=-2;
            }
        }
        else
        {
            if(VolcarFicheroErrores(FICHERO_TEMPORAL_ERRORES)!=0)
            {
                generarcodigo=-3;
            }
        }
        /*Liberamos recursos*/
        yyrestart(yyin);
        fclose(yyin);
        *lineas=nlin;
        LiberarListaErrores();
        LiberarTablaConfiguracion();
        LiberarTablaEtiquetas();
        return generarcodigo-1;
    }
    else
    {
        *lineas=0;
        return -2;
    }
}
