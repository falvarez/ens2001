		/*ens.l*/
%{
#include "definiciones.h"
#include "defsc.h"
#include "ens_tab.h"
#include "funcionesauxiliares.h"
#include "gestionerrores.h"

extern int nlin;
extern char *etiqueta;
extern char *cadena;
extern int generarcodigo;

int estado; /*Estado del analizador lexico*/
%}
		/*Patrones auxiliares*/
		
dec		-?[0-9][0-9]*
decsinsigno     [0-9][0-9]*
ident		[a-zA-Z][a-zA-Z0-9_]*
hex		0[x|X][0-9a-fA-F][0-9a-fA-F]*
cadena		[^\n^\"]*

		/*Estados*/
%x EXPR DATOS CAD
%%

<INITIAL,EXPR,DATOS,CAD><<EOF>>	{
				 nlin++;
				 yylval=0;
				 yyterminate();
			 	 return(EOL);
			 	}

<INITIAL,EXPR,DATOS,CAD>[ \t]+	;/*Para ignorar espacios y tabuladores*/
<INITIAL,EXPR,DATOS,CAD>;.*	;/*Para ignorar comentarios*/
		
		/*Juego de instrucciones*/	
			
nop|NOP			{
			 yylval=NOP;
			 NuevoToken(yytext);
			 return(MNEMONICO0);
			}
halt|HALT		{
			 yylval=HALT;
			 NuevoToken(yytext);
			 return(MNEMONICO0);
			}	
move|MOVE		{
			 yylval=MOVE;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}
push|PUSH		{
			 yylval=PUSH;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
pop|POP			{
			 yylval=POP;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
add|ADD			{
			 yylval=ADD;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}
sub|SUB			{
			 yylval=SUB;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}	
mul|MUL			{
			 yylval=MUL;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}
div|DIV			{
			 yylval=DIV;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}	
mod|MOD			{
			 yylval=MOD;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}	
inc|INC			{
			 yylval=INC;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
dec|DEC			{
			 yylval=DEC;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
neg|NEG			{
			 yylval=NEG;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
cmp|CMP			{
			 yylval=CMP;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}	
and|AND			{
			 yylval=AND;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}	
or|OR 			{
			 yylval=OR;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}
xor|XOR			{
			 yylval=XOR;
			 NuevoToken(yytext);
			 return(MNEMONICO2);
			}	
not|NOT			{
			 yylval=NOT;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
br|BR 			{
			 yylval=BR;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
bz|BZ 			{
			 yylval=BZ;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
bnz|BNZ			{
			 yylval=BNZ;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
bp|BP 			{
			 yylval=BP;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
bn|BN 			{
			 yylval=BN;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
bv|BV 			{
			 yylval=BV;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
bnv|BNV			{
			 yylval=BNV;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
bc|BC 			{
			 yylval=BC;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
bnc|BNC			{
			 yylval=BNC;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
be|BE 			{
			 yylval=BE;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
bo|BO			{
			 yylval=BO;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
call|CALL		{
			 yylval=CALL;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
ret|RET			{
			 yylval=RET;
			 NuevoToken(yytext);
			 return(MNEMONICO0);
			}
inchar|INCHAR	 	{
			 yylval=INCHAR;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
inint|ININT	 	{
			 yylval=ININT;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}
instr|INSTR		{
			 yylval=INSTR;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
wrchar|WRCHAR		{
			 yylval=WRCHAR;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
wrint|WRINT		{
			 yylval=WRINT;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}	
wrstr|WRSTR		{
			 yylval=WRSTR;
			 NuevoToken(yytext);
			 return(MNEMONICO1);
			}		 		 		 		 		 		 		 		 	 	 		 
		 			 
		/*Pseudoinstrucciones del ensamblador*/
		
org|ORG			{
			 yylval=ORG;
			 NuevoToken(yytext);
			 BEGIN(EXPR);
			 estado=ESTADO_EXPRESION;
			 return(ORG);
			}
equ|EQU			{
			 yylval=EQU;
			 NuevoToken(yytext);
			 BEGIN(EXPR);
			 estado=ESTADO_EXPRESION;
			 return(EQU);
			}
end|END			{
			 yylval=END;
			 NuevoToken(yytext);
			 return(END);
			}
res|RES			{
			 yylval=RES;
			 NuevoToken(yytext);
			 BEGIN(EXPR);
			 estado=ESTADO_EXPRESION;
			 return(RES);
			}
data|DATA		{
			 yylval=DATA;
			 NuevoToken(yytext);
			 BEGIN(DATOS);
			 estado=ESTADO_DATOS;
			 return(DATA);
			}		 		 		 		 
		 		 
		/*Separadores*/ 
		
<INITIAL,EXPR,DATOS,CAD>\n	{
				 nlin++;
				 yylval=0;
				 NuevoToken("<EOL>");
				 BEGIN(INITIAL);
				 estado=ESTADO_INICIAL;
				 return(EOL);
				}
<INITIAL,DATOS>\,	{
			 yylval=0;
			 NuevoToken(",");
			 return(SEPARADOR);
			} 
<INITIAL>\:		{
			 yylval=0;
			 NuevoToken(":");
			 return(FIN_ETIQ);
			}	
<DATOS>\"		{
			 yylval=0;
			 NuevoToken("\"");
			 BEGIN(CAD);
			 estado=ESTADO_CADENA;
			 return(COMILLAS);
			} 
<CAD>\"			{
			 yylval=0;
			 NuevoToken("\"");
			 BEGIN(DATOS);
			 estado=ESTADO_DATOS;
			 return(COMILLAS);
			} 	
		 
		 /*Operadores aritméticos*/ 
		 
<EXPR>\+		{
			 yylval=0;
			 return(SUMA);
			}	
<EXPR>\-		{
			 yylval=0;
			 return(RESTA);
			}	 
<EXPR>\*		{
			 yylval=0;
			 return(PRODUCTO);
			}
<EXPR>\/		{
			 yylval=0;
			 return(DIVISION);
			}
<EXPR>\%		{
			 yylval=0;
			 return(MODULO);
			}
<EXPR>\(		{
			 yylval=0;
			 return(PARENT_ABRE);
			}
<EXPR>\)		{
			 yylval=0;
			 return(PARENT_CIERRA);
			}
	
		/*Operandos*/
		/*Direccionamiento Inmediato*/
		
\#{dec}			{
			 yylval=Decimal((char *)(yytext+1),16);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
		 	 return(INMEDIATO_V);
			}
\#{hex}			{
			 yylval=Hexadecimal((char *)(yytext+1),16);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
		 	 return(INMEDIATO_V);
			}
		 
\#{ident}		{
			 yylval=0;
			 etiqueta=CopiarCadena(yytext+1,strlen(yytext)-1);
			 NuevoToken(yytext);
           		 return(INMEDIATO_E);
			}  

 		/*Direccionamiento Directo a Registro*/ 
 		               	
\.(r0|R0)		{
			 yylval=R0;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r1|R1)		{
			 yylval=R1;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r2|R2)		{
			 yylval=R2;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r3|R3)		{
			 yylval=R3;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r4|R4)		{
			 yylval=R4;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r5|R5)		{
			 yylval=R5;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r6|R6)		{
			 yylval=R6;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r7|R7)		{
			 yylval=R7;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r8|R8)		{
			 yylval=R8;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(r9|R9)		{
			 yylval=R9;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(a|A)			{
			 yylval=A;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 
\.(sr|SR)		{
			 yylval=SR;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 		 		 		 		 		 		 		 		 		 		                  	
\.(ix|IX)		{
			 yylval=IX;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}
\.(iy|IY)		{
			 yylval=IY;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}
\.(sp|SP)		{
			 yylval=SP;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}
\.(pc|PC)		{
			 yylval=PC;
			 NuevoToken(yytext);
			 return(REGISTRO);
			}		 		 		 
		      
		/*Direccionamiento Directo a Memoria*/ 
		            
\/{dec}			{
			 yylval=Decimal((char *)(yytext+1),16);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
			 return(MEMORIA_V);
			}
\/{hex}			{
			 yylval=Hexadecimal((char *)(yytext+1),16);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
			 return(MEMORIA_V);
			}		 
\/{ident}		{
			 yylval=0;
			 etiqueta=CopiarCadena(yytext+1,strlen(yytext)-1);
			 NuevoToken(yytext);
             		 return(MEMORIA_E);
			}  
                 	
  		/*Direccionamiento Indirecto*/  
  		             	
\[\.(r0|R0)\]		{
			 yylval=R0;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r1|R1)\]		{
			 yylval=R1;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r2|R2)\]		{
			 yylval=R2;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r3|R3)\]		{
			 yylval=R3;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r4|R4)\]		{
			 yylval=R4;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r5|R5)\]		{
			 yylval=R5;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r6|R6)\]		{
			 yylval=R6;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r7|R7)\]		{
			 yylval=R7;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r8|R8)\]		{
			 yylval=R8;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(r9|R9)\]		{
			 yylval=R9;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(a|A)\]		{
			 yylval=A;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(sr|SR)\]		{
			 yylval=SR;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(ix|IX)\]		{
			 yylval=IX;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(iy|IY)\]		{
			 yylval=IY;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(sp|SP)\]		{
			 yylval=SP;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}
\[\.(pc|PC)\]		{
			 yylval=PC;
			 NuevoToken(yytext);
			 return(INDIRECTO);
			}   
		
		/*Direccionamiento Relativo a PC*/
			 
\${dec}			{
			 yylval=Decimal((char *)(yytext+1),8);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
			 return(RELAT_PC_V);
			}
\${hex}		    {
			 yylval=Hexadecimal((char *)(yytext+1),8);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
			 return(RELAT_PC_V);
			}		 
\${ident}		{
			 yylval=0;
			 etiqueta=CopiarCadena(yytext+1,strlen(yytext)-1);
			 NuevoToken(yytext);
              		 return(RELAT_PC_E);
			}  	
                 		 
        	/*Direccionamiento Relativo a IX*/ 
        	        	
\#{dec}\[\.(ix|IX)\]	{
			 yylval=Decimal((char *)(yytext+1),8);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
		 	 return(RELAT_IX_V);
			}
\#{hex}\[\.(ix|IX)\]	{
			 yylval=Hexadecimal(CopiarCadena(yytext+1,strlen(yytext+1)-5),8);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			     		   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
		 	 return(RELAT_IX_V);
			}		 
\#{ident}\[\.(ix|IX)\]	{
			 yylval=0;
			 etiqueta=CopiarCadena(yytext+1,strlen(yytext)-6);
			 NuevoToken(yytext);
                 	 return(RELAT_IX_E);
			}  
                 	
     		/*Direccionamiento Relativo a IY*/  
     		          	
\#{dec}\[\.(iy|IY)\] 	{
			 yylval=Decimal((char *)(yytext+1),8);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			                   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
		 	 return(RELAT_IY_V);
			}
\#{hex}\[\.(iy|IY)\]	{
			 yylval=Hexadecimal(CopiarCadena(yytext+1,strlen(yytext+1)-5),8);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			                   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
		 	 return(RELAT_IY_V);
			}		 
\#{ident}\[\.(iy|IY)\]	{
			 yylval=0;
			 etiqueta=CopiarCadena(yytext+1,strlen(yytext)-6);
			 NuevoToken(yytext);
        	         return(RELAT_IY_E);
			}  
        	         	 
  		/*Cadenas de caracteres*/               		     
                 		
<CAD>{cadena}		{
			 yylval=0;
			 cadena=CopiarCadena(yytext,strlen(yytext));
			 NuevoToken(yytext);
			 return(CADENA);
			}  
		 
		/*Etiquetas*/		 
		 
<INITIAL,EXPR>{ident}	{
			 yylval=0;
			 etiqueta=CopiarCadena(yytext,strlen(yytext));
			 NuevoToken(yytext);
			 return(ETIQUETA);
			}
			
		/*Numeros enteros*/			
			 
<EXPR>{decsinsigno}	{
			 yylval=Decimal((char *)yytext,16);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			                   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
               		 return(ENTERO);
			}
               		 
<INITIAL,DATOS>{dec}  	{
			 yylval=Decimal((char *)yytext,16);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			                   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
               		 return(ENTERO);
			}
                 
<EXPR,DATOS>{hex}	{
			 yylval=Hexadecimal((char *)yytext,16);
			 if(yylval<0)
			 {
			     InformarError(ERR_ENTERO_FUERA_DE_RANGO,
			                   nlin+1,yytext);
			     generarcodigo=0;
			 }
			 NuevoToken(yytext);
		 	 return(ENTERO);
			}
				
		/*Caracteres incorrectos*/
				 	 
<INITIAL,EXPR,DATOS,CAD>. {
			   yylval=0;
                           if(estado==ESTADO_EXPRESION)
                           {
                               InformarError(ERR_EXPRESION_ERRONEA,nlin+1,
                                             yytext);
                           }
                           else if((estado==ESTADO_DATOS) ||
                                   (estado==ESTADO_CADENA))
                           {
                               InformarError(ERR_LISTA_DATOS_ERRONEA,
                                             nlin+1,yytext);
                           }
                           else
                           {
			       InformarError(ERR_ENTRADA_INCORRECTA,nlin+1,
			                     yytext);
			   }
			   NuevoToken(yytext);
			   generarcodigo=0;
			  }
%%
