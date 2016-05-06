#define YY_parse_h_included

/*  A Bison++ parser, made from fuentes\ens.y  */

 /* with Bison++ version bison++ Version 1.21-8, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#if defined( _MSDOS ) || defined(MSDOS) || defined(__MSDOS__) 
#define __MSDOS_AND_ALIKE
#endif
#if defined(_WINDOWS) && defined(_MSC_VER)
#define __HAVE_NO_ALLOCA
#define __MSDOS_AND_ALIKE
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
#include <alloca.h>

#elif defined (__MSDOS_AND_ALIKE)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1  

/* #line 73 "bison.cc" */
#line 85 "fuentes\\ens_tab.c"
#line 45 "fuentes\\ens.y"

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

#line 73 "bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_parse_BISON 1
#ifndef YY_parse_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_parse_COMPATIBILITY 1
#else
#define  YY_parse_COMPATIBILITY 0
#endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_parse_LTYPE
#define YY_parse_LTYPE YYLTYPE
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_parse_STYPE 
#define YY_parse_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_parse_DEBUG
#define  YY_parse_DEBUG YYDEBUG
#endif
#endif
#ifdef YY_parse_STYPE
#ifndef yystype
#define yystype YY_parse_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_parse_USE_GOTO
#define YY_parse_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
#define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

/* #line 117 "bison.cc" */
#line 176 "fuentes\\ens_tab.c"

#line 117 "bison.cc"
/*  YY_parse_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "bison.cc" */
#line 185 "fuentes\\ens_tab.c"

#line 121 "bison.cc"
/* prefix */
#ifndef YY_parse_DEBUG

/* #line 123 "bison.cc" */
#line 192 "fuentes\\ens_tab.c"

#line 123 "bison.cc"
/* YY_parse_DEBUG */
#endif


#ifndef YY_parse_LSP_NEEDED

/* #line 128 "bison.cc" */
#line 202 "fuentes\\ens_tab.c"

#line 128 "bison.cc"
 /* YY_parse_LSP_NEEDED*/
#endif



/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
#ifndef YY_parse_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_parse_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
      /* We used to use `unsigned long' as YY_parse_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

#ifndef YY_parse_STYPE
#define YY_parse_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
#define YY_parse_PARSE yyparse
#endif
#ifndef YY_parse_LEX
#define YY_parse_LEX yylex
#endif
#ifndef YY_parse_LVAL
#define YY_parse_LVAL yylval
#endif
#ifndef YY_parse_LLOC
#define YY_parse_LLOC yylloc
#endif
#ifndef YY_parse_CHAR
#define YY_parse_CHAR yychar
#endif
#ifndef YY_parse_NERRS
#define YY_parse_NERRS yynerrs
#endif
#ifndef YY_parse_DEBUG_FLAG
#define YY_parse_DEBUG_FLAG yydebug
#endif
#ifndef YY_parse_ERROR
#define YY_parse_ERROR yyerror
#endif
#ifndef YY_parse_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_parse_PARSE_PARAM
#ifndef YY_parse_PARSE_PARAM_DEF
#define YY_parse_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_parse_PARSE_PARAM
#define YY_parse_PARSE_PARAM void
#endif
#endif
#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_parse_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_parse_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_parse_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_parse_PURE
#ifndef YYPURE
#define YYPURE YY_parse_PURE
#endif
#endif
#ifdef YY_parse_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_parse_DEBUG 
#endif
#endif
#ifndef YY_parse_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_parse_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_parse_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_parse_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 236 "bison.cc" */
#line 315 "fuentes\\ens_tab.c"
#define	MNEMONICO0	258
#define	MNEMONICO1	259
#define	MNEMONICO2	260
#define	ORG	261
#define	END	262
#define	EQU	263
#define	RES	264
#define	DATA	265
#define	EOL	266
#define	SEPARADOR	267
#define	FIN_ETIQ	268
#define	COMILLAS	269
#define	SUMA	270
#define	RESTA	271
#define	PRODUCTO	272
#define	DIVISION	273
#define	MODULO	274
#define	PARENT_ABRE	275
#define	PARENT_CIERRA	276
#define	INMEDIATO_V	277
#define	INMEDIATO_E	278
#define	REGISTRO	279
#define	MEMORIA_V	280
#define	MEMORIA_E	281
#define	INDIRECTO	282
#define	RELAT_PC_V	283
#define	RELAT_PC_E	284
#define	RELAT_IX_V	285
#define	RELAT_IX_E	286
#define	RELAT_IY_V	287
#define	RELAT_IY_E	288
#define	CADENA	289
#define	ENTERO	290
#define	ETIQUETA	291


#line 236 "bison.cc"
 /* #defines tokens */
#else
/* CLASS */
#ifndef YY_parse_CLASS
#define YY_parse_CLASS parse
#endif
#ifndef YY_parse_INHERIT
#define YY_parse_INHERIT
#endif
#ifndef YY_parse_MEMBERS
#define YY_parse_MEMBERS 
#endif
#ifndef YY_parse_LEX_BODY
#define YY_parse_LEX_BODY  
#endif
#ifndef YY_parse_ERROR_BODY
#define YY_parse_ERROR_BODY  
#endif
#ifndef YY_parse_CONSTRUCTOR_PARAM
#define YY_parse_CONSTRUCTOR_PARAM
#endif
#ifndef YY_parse_CONSTRUCTOR_CODE
#define YY_parse_CONSTRUCTOR_CODE
#endif
#ifndef YY_parse_CONSTRUCTOR_INIT
#define YY_parse_CONSTRUCTOR_INIT
#endif
/* choose between enum and const */
#ifndef YY_parse_USE_CONST_TOKEN
#define YY_parse_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_parse_USE_CONST_TOKEN != 0
#ifndef YY_parse_ENUM_TOKEN
#define YY_parse_ENUM_TOKEN yy_parse_enum_token
#endif
#endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
#if YY_parse_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 280 "bison.cc" */
#line 399 "fuentes\\ens_tab.c"
static const int MNEMONICO0;
static const int MNEMONICO1;
static const int MNEMONICO2;
static const int ORG;
static const int END;
static const int EQU;
static const int RES;
static const int DATA;
static const int EOL;
static const int SEPARADOR;
static const int FIN_ETIQ;
static const int COMILLAS;
static const int SUMA;
static const int RESTA;
static const int PRODUCTO;
static const int DIVISION;
static const int MODULO;
static const int PARENT_ABRE;
static const int PARENT_CIERRA;
static const int INMEDIATO_V;
static const int INMEDIATO_E;
static const int REGISTRO;
static const int MEMORIA_V;
static const int MEMORIA_E;
static const int INDIRECTO;
static const int RELAT_PC_V;
static const int RELAT_PC_E;
static const int RELAT_IX_V;
static const int RELAT_IX_E;
static const int RELAT_IY_V;
static const int RELAT_IY_E;
static const int CADENA;
static const int ENTERO;
static const int ETIQUETA;


#line 280 "bison.cc"
 /* decl const */
#else
enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0

/* #line 283 "bison.cc" */
#line 442 "fuentes\\ens_tab.c"
	,MNEMONICO0=258
	,MNEMONICO1=259
	,MNEMONICO2=260
	,ORG=261
	,END=262
	,EQU=263
	,RES=264
	,DATA=265
	,EOL=266
	,SEPARADOR=267
	,FIN_ETIQ=268
	,COMILLAS=269
	,SUMA=270
	,RESTA=271
	,PRODUCTO=272
	,DIVISION=273
	,MODULO=274
	,PARENT_ABRE=275
	,PARENT_CIERRA=276
	,INMEDIATO_V=277
	,INMEDIATO_E=278
	,REGISTRO=279
	,MEMORIA_V=280
	,MEMORIA_E=281
	,INDIRECTO=282
	,RELAT_PC_V=283
	,RELAT_PC_E=284
	,RELAT_IX_V=285
	,RELAT_IX_E=286
	,RELAT_IY_V=287
	,RELAT_IY_E=288
	,CADENA=289
	,ENTERO=290
	,ETIQUETA=291


#line 283 "bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_parse_PARSE (YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
#ifdef YY_parse_PURE
#ifdef YY_parse_LSP_NEEDED
 virtual int  YY_parse_LEX (YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
#else
 virtual int  YY_parse_LEX (YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
#endif
#else
 virtual int YY_parse_LEX() YY_parse_LEX_BODY;
 YY_parse_STYPE YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
 YY_parse_LTYPE YY_parse_LLOC;
#endif
 int   YY_parse_NERRS;
 int    YY_parse_CHAR;
#endif
#if YY_parse_DEBUG != 0
 int YY_parse_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#if YY_parse_USE_CONST_TOKEN != 0

/* #line 314 "bison.cc" */
#line 513 "fuentes\\ens_tab.c"
const int YY_parse_CLASS::MNEMONICO0=258;
const int YY_parse_CLASS::MNEMONICO1=259;
const int YY_parse_CLASS::MNEMONICO2=260;
const int YY_parse_CLASS::ORG=261;
const int YY_parse_CLASS::END=262;
const int YY_parse_CLASS::EQU=263;
const int YY_parse_CLASS::RES=264;
const int YY_parse_CLASS::DATA=265;
const int YY_parse_CLASS::EOL=266;
const int YY_parse_CLASS::SEPARADOR=267;
const int YY_parse_CLASS::FIN_ETIQ=268;
const int YY_parse_CLASS::COMILLAS=269;
const int YY_parse_CLASS::SUMA=270;
const int YY_parse_CLASS::RESTA=271;
const int YY_parse_CLASS::PRODUCTO=272;
const int YY_parse_CLASS::DIVISION=273;
const int YY_parse_CLASS::MODULO=274;
const int YY_parse_CLASS::PARENT_ABRE=275;
const int YY_parse_CLASS::PARENT_CIERRA=276;
const int YY_parse_CLASS::INMEDIATO_V=277;
const int YY_parse_CLASS::INMEDIATO_E=278;
const int YY_parse_CLASS::REGISTRO=279;
const int YY_parse_CLASS::MEMORIA_V=280;
const int YY_parse_CLASS::MEMORIA_E=281;
const int YY_parse_CLASS::INDIRECTO=282;
const int YY_parse_CLASS::RELAT_PC_V=283;
const int YY_parse_CLASS::RELAT_PC_E=284;
const int YY_parse_CLASS::RELAT_IX_V=285;
const int YY_parse_CLASS::RELAT_IX_E=286;
const int YY_parse_CLASS::RELAT_IY_V=287;
const int YY_parse_CLASS::RELAT_IY_E=288;
const int YY_parse_CLASS::CADENA=289;
const int YY_parse_CLASS::ENTERO=290;
const int YY_parse_CLASS::ETIQUETA=291;


#line 314 "bison.cc"
 /* const YY_parse_CLASS::token */
#endif
/*apres const  */
YY_parse_CLASS::YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM) YY_parse_CONSTRUCTOR_INIT
{
#if YY_parse_DEBUG != 0
YY_parse_DEBUG_FLAG=0;
#endif
YY_parse_CONSTRUCTOR_CODE;
};
#endif

/* #line 325 "bison.cc" */
#line 564 "fuentes\\ens_tab.c"


#define	YYFINAL		117
#define	YYFLAG		-32768
#define	YYNTBASE	37

#define YYTRANSLATE(x) ((unsigned)(x) <= 291 ? yytranslate[x] : 83)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36
};

#if YY_parse_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     2,     6,     7,     8,     9,    10,    17,    18,
    19,    26,    28,    29,    32,    34,    36,    39,    40,    41,
    46,    47,    48,    49,    56,    57,    58,    59,    60,    61,
    72,    74,    76,    78,    80,    82,    84,    86,    88,    90,
    92,    94,    96,    97,    98,    99,   106,   107,   108,   109,
   116,   117,   118,   119,   120,   128,   129,   130,   131,   138,
   139,   140,   145,   148,   152,   156,   158,   160,   164,   168,
   172,   174,   178,   180,   181,   185,   186,   192,   194,   196,
   197
};

static const short yyrhs[] = {    -1,
     0,    11,    38,    37,     0,     0,     0,     0,     0,    39,
    40,    41,    43,    42,    37,     0,     0,     0,    36,    13,
    44,    45,    46,    47,     0,    47,     0,     0,    11,    46,
     0,    48,     0,    60,     0,     1,    11,     0,     0,     0,
    49,     3,    50,    11,     0,     0,     0,     0,    51,     4,
    52,    59,    53,    11,     0,     0,     0,     0,     0,     0,
    54,     5,    55,    59,    56,    12,    57,    59,    58,    11,
     0,    22,     0,    23,     0,    24,     0,    25,     0,    26,
     0,    27,     0,    28,     0,    29,     0,    30,     0,    31,
     0,    32,     0,    33,     0,     0,     0,     0,    61,     6,
    62,    76,    63,    11,     0,     0,     0,     0,    64,     9,
    65,    76,    66,    11,     0,     0,     0,     0,     0,    67,
    10,    68,    69,    79,    70,    11,     0,     0,     0,     0,
    71,     8,    72,    76,    73,    11,     0,     0,     0,    74,
     7,    75,    11,     0,    16,    77,     0,    76,    15,    77,
     0,    76,    16,    77,     0,    77,     0,     1,     0,    77,
    17,    78,     0,    77,    18,    78,     0,    77,    19,    78,
     0,    78,     0,    20,    76,    21,     0,    35,     0,     0,
    35,    80,    82,     0,     0,    14,    34,    14,    81,    82,
     0,    11,     0,     1,     0,     0,    12,    79,     0
};

#endif

#if YY_parse_DEBUG != 0
static const short yyrline[] = { 0,
    89,    91,    96,    96,    98,    99,   103,   106,   108,   113,
   137,   139,   142,   144,   148,   151,   154,   317,   322,   326,
   351,   356,   359,   363,   392,   397,   400,   402,   405,   409,
   454,   474,   494,   514,   534,   554,   574,   594,   614,   633,
   653,   673,   693,   697,   700,   704,   721,   725,   727,   731,
   754,   758,   761,   767,   771,   793,   797,   800,   804,   824,
   828,   832,   837,   845,   854,   863,   870,   886,   895,   912,
   929,   936,   945,   952,   962,   962,  1006,  1006,  1014,  1017,
  1018
};

static const char * const yytname[] = {   "$","error","$illegal.","MNEMONICO0",
"MNEMONICO1","MNEMONICO2","ORG","END","EQU","RES","DATA","EOL","SEPARADOR","FIN_ETIQ",
"COMILLAS","SUMA","RESTA","PRODUCTO","DIVISION","MODULO","PARENT_ABRE","PARENT_CIERRA",
"INMEDIATO_V","INMEDIATO_E","REGISTRO","MEMORIA_V","MEMORIA_E","INDIRECTO","RELAT_PC_V",
"RELAT_PC_E","RELAT_IX_V","RELAT_IX_E","RELAT_IY_V","RELAT_IY_E","CADENA","ENTERO",
"ETIQUETA","programa","@1","@2","@3","@4","@5","linea","@6","@7","linea_vacia",
"resto","instruccion","@8","@9","@10","@11","@12","@13","@14","@15","@16","@17",
"operando","pseudoinstruccion","@18","@19","@20","@21","@22","@23","@24","@25",
"@26","@27","@28","@29","@30","@31","@32","expresion","expresion_2","expresion_3",
"lista_datos","@33","@34","resto_lista_datos",""
};
#endif

static const short yyr1[] = {     0,
    37,    38,    37,    39,    40,    41,    42,    37,    44,    45,
    43,    43,    46,    46,    47,    47,    47,    49,    50,    48,
    51,    52,    53,    48,    54,    55,    56,    57,    58,    48,
    59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    61,    62,    63,    60,    64,    65,    66,    60,
    67,    68,    69,    70,    60,    71,    72,    73,    60,    74,
    75,    60,    76,    76,    76,    76,    76,    77,    77,    77,
    77,    78,    78,    80,    79,    81,    79,    79,    79,    82,
    82
};

static const short yyr2[] = {     0,
     0,     0,     3,     0,     0,     0,     0,     6,     0,     0,
     6,     1,     0,     2,     1,     1,     2,     0,     0,     4,
     0,     0,     0,     6,     0,     0,     0,     0,     0,    10,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     0,     0,     0,     6,     0,     0,     0,     6,
     0,     0,     0,     0,     7,     0,     0,     0,     6,     0,
     0,     4,     2,     3,     3,     1,     1,     3,     3,     3,
     1,     3,     1,     0,     3,     0,     5,     1,     1,     0,
     2
};

static const short yydefact[] = {     4,
     2,     5,     4,     6,     3,     0,     0,     0,     7,    12,
    15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
    17,     9,     4,    19,    22,    26,    44,    48,    52,    57,
    61,    10,     8,     0,     0,     0,     0,     0,    53,     0,
     0,    13,    20,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    23,    27,    67,     0,     0,
    73,    45,    66,    71,    49,     0,    58,    62,    13,     0,
     0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
     0,    79,    78,     0,    74,    54,     0,    14,    11,    24,
    28,    72,    64,    65,    46,    68,    69,    70,    50,     0,
    80,     0,    59,     0,    76,     0,    75,    55,    29,    80,
    81,     0,    77,    30,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     3,     2,     4,     6,    23,     9,    32,    42,    70,    10,
    11,    12,    34,    13,    35,    71,    14,    36,    72,   104,
   112,    56,    15,    16,    37,    77,    17,    38,    81,    18,
    39,    66,   102,    19,    40,    87,    20,    41,    62,    63,
    64,    86,   101,   110,   107
};

static const short yypact[] = {    17,
-32768,-32768,    17,-32768,-32768,     0,    16,    28,-32768,-32768,
-32768,    39,    40,    38,-32768,    53,    51,    52,    55,    54,
-32768,-32768,    17,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    67,    25,    25,    10,    10,-32768,    10,
    68,    69,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -4,    10,
-32768,     5,    15,-32768,     5,    11,     5,-32768,    69,    66,
    70,    65,    15,     8,    -4,    -4,    71,    -4,    -4,    -4,
    72,-32768,-32768,    30,-32768,-32768,    73,-32768,-32768,-32768,
-32768,-32768,    15,    15,-32768,-32768,-32768,-32768,-32768,    74,
    75,    78,-32768,    25,-32768,    11,-32768,-32768,-32768,    75,
-32768,    79,-32768,-32768,    85,    86,-32768
};

static const short yypgoto[] = {    14,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -3,    -5,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   -36,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -25,   -57,
   -40,   -15,-32768,-32768,   -18
};


#define	YYLAST		92


static const short yytable[] = {    57,
     7,    73,   -18,   -21,   -25,   -43,   -60,   -56,   -47,   -51,
    58,    82,    65,   115,    67,    60,    -1,    93,    94,    75,
    76,    83,    75,    76,    84,    59,    21,     1,    92,    60,
    61,    78,    79,    80,    74,     8,    33,    96,    97,    98,
    22,    24,    26,    25,    61,    85,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    27,    28,
    31,    29,    30,   100,    89,    88,     7,   109,   -18,   -21,
   -25,   -43,   -60,   -56,   -47,   -51,    91,    43,    68,    69,
    90,    95,    99,   103,   116,   117,   106,   105,   108,   114,
   111,   113
};

static const short yycheck[] = {    36,
     1,    59,     3,     4,     5,     6,     7,     8,     9,    10,
     1,     1,    38,     0,    40,    20,     0,    75,    76,    15,
    16,    11,    15,    16,    14,    16,    11,    11,    21,    20,
    35,    17,    18,    19,    60,    36,    23,    78,    79,    80,
    13,     3,     5,     4,    35,    35,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,     6,     9,
     7,    10,     8,    34,    70,    69,     1,   104,     3,     4,
     5,     6,     7,     8,     9,    10,    12,    11,    11,    11,
    11,    11,    11,    11,     0,     0,    12,    14,    11,    11,
   106,   110
};

#line 325 "bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#if YY_parse_USE_GOTO != 0
/* 
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } } 
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO 
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL 
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL 
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)  
YYENDDECLARELABEL
/* ALLOCA SIMULATION */
/* __HAVE_NO_ALLOCA */
#ifdef __HAVE_NO_ALLOCA
int __alloca_free_ptr(char *ptr,char *ref)
{if(ptr!=ref) free(ptr);
 return 0;}

#define __ALLOCA_alloca(size) malloc(size)
#define __ALLOCA_free(ptr,ref) __alloca_free_ptr((char *)ptr,(char *)ref)

#ifdef YY_parse_LSP_NEEDED
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		    __ALLOCA_free(yyls,yylsa)+\
		   (num))
#else
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		   (num))
#endif
#else
#define __ALLOCA_return(num) return(num)
#define __ALLOCA_alloca(size) alloca(size)
#define __ALLOCA_free(ptr,ref) 
#endif

/* ENDALLOCA SIMULATION */

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_parse_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        __ALLOCA_return(0)
#define YYABORT         __ALLOCA_return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_parse_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_parse_CHAR = (token), YY_parse_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_parse_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_parse_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_parse_PURE
/* UNPURE */
#define YYLEX           YY_parse_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_parse_CHAR;                      /*  the lookahead symbol        */
YY_parse_STYPE      YY_parse_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_parse_NERRS;                 /*  number of parse errors so far */
#ifdef YY_parse_LSP_NEEDED
YY_parse_LTYPE YY_parse_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_parse_LSP_NEEDED
#define YYLEX           YY_parse_LEX(&YY_parse_LVAL, &YY_parse_LLOC)
#else
#define YYLEX           YY_parse_LEX(&YY_parse_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_parse_DEBUG != 0
int YY_parse_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_parse_CLASS::
#endif
     YY_parse_PARSE(YY_parse_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_parse_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_parse_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_parse_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_parse_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_parse_LSP_NEEDED
  YY_parse_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_parse_LTYPE *yyls = yylsa;
  YY_parse_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_parse_PURE
  int YY_parse_CHAR;
  YY_parse_STYPE YY_parse_LVAL;
  int YY_parse_NERRS;
#ifdef YY_parse_LSP_NEEDED
  YY_parse_LTYPE YY_parse_LLOC;
#endif
#endif

  YY_parse_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_parse_NERRS = 0;
  YY_parse_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_parse_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_parse_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_parse_LSP_NEEDED
      YY_parse_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_parse_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_parse_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_parse_ERROR("parser stack overflow");
	  __ALLOCA_return(2);
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) __ALLOCA_alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      __ALLOCA_free(yyss1,yyssa);
      yyvs = (YY_parse_STYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
      __ALLOCA_free(yyvs1,yyvsa);
#ifdef YY_parse_LSP_NEEDED
      yyls = (YY_parse_LTYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
      __ALLOCA_free(yyls1,yylsa);
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_parse_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_parse_CHAR == YYEMPTY)
    {
#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_parse_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_parse_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_parse_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_parse_CHAR);

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_parse_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_parse_CHAR, YY_parse_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_parse_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_parse_CHAR != YYEOF)
    YY_parse_CHAR = YYEMPTY;

  *++yyvsp = YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
  *++yylsp = YY_parse_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 811 "bison.cc" */
#line 1259 "fuentes\\ens_tab.c"

  switch (yyn) {

case 2:
#line 93 "fuentes\\ens.y"
{LiberarListaTokens();;
    break;}
case 4:
#line 97 "fuentes\\ens.y"
{operando=0;;
    break;}
case 5:
#line 98 "fuentes\\ens.y"
{numregla=0;;
    break;}
case 6:
#line 99 "fuentes\\ens.y"
{numetiq=0;;
    break;}
case 7:
#line 103 "fuentes\\ens.y"
{/*ListarTokens();*/
            LiberarListaTokens();;
    break;}
case 9:
#line 111 "fuentes\\ens.y"
{numetiq=1;;
    break;}
case 10:
#line 113 "fuentes\\ens.y"
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
        ;
    break;}
case 17:
#line 158 "fuentes\\ens.y"
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
        ;
    break;}
case 18:
#line 318 "fuentes\\ens.y"
{numregla=11;
               operando=0; 
               numtoken=1;;
    break;}
case 19:
#line 322 "fuentes\\ens.y"
{numtoken=2;
               operando=3;;
    break;}
case 20:
#line 326 "fuentes\\ens.y"
{
               instruccion.codop=yyvsp[-2];
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
              ;
    break;}
case 21:
#line 352 "fuentes\\ens.y"
{numregla=12;
               operando=0;
               numtoken=1;;
    break;}
case 22:
#line 356 "fuentes\\ens.y"
{numtoken=2;
               operando=1;;
    break;}
case 23:
#line 359 "fuentes\\ens.y"
{numtoken=3;
               operando=3;;
    break;}
case 24:
#line 363 "fuentes\\ens.y"
{
               instruccion.codop=yyvsp[-4];
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
              ;
    break;}
case 25:
#line 393 "fuentes\\ens.y"
{numregla=13;
               numtoken=1;
               operando=0;;
    break;}
case 26:
#line 397 "fuentes\\ens.y"
{numtoken=2;
               operando=1;;
    break;}
case 27:
#line 400 "fuentes\\ens.y"
{numtoken=3;;
    break;}
case 28:
#line 402 "fuentes\\ens.y"
{numtoken=4;
               operando=2;;
    break;}
case 29:
#line 405 "fuentes\\ens.y"
{numtoken=5;
               operando=3;;
    break;}
case 30:
#line 409 "fuentes\\ens.y"
{
               instruccion.codop=yyvsp[-8];
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
              ;
    break;}
case 31:
#line 457 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_INMEDIATO;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_INMEDIATO;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;
    break;}
case 32:
#line 477 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_INMEDIATO;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=16;
            }
            else
            {
                instruccion.mdir2=MD_INMEDIATO;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud2=16;
            }
           ;
    break;}
case 33:
#line 497 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_REGISTRO;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_REGISTRO;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;
    break;}
case 34:
#line 517 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_MEMORIA;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_MEMORIA;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
	   ;
    break;}
case 35:
#line 537 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_MEMORIA;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=16;
            }
            else
            {
                instruccion.mdir2=MD_MEMORIA;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud2=16;
            }
           ;
    break;}
case 36:
#line 557 "fuentes\\ens.y"
{
            if (operando==1)
            {
                instruccion.mdir1=MD_INDIRECTO;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_INDIRECTO;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;
    break;}
case 37:
#line 577 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_PC;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_PC;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;
    break;}
case 38:
#line 597 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_PC;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_PC;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           ;
    break;}
case 39:
#line 617 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IX;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IX;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;
    break;}
case 40:
#line 636 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IX;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IX;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           ;
    break;}
case 41:
#line 656 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IY;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IY;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;
    break;}
case 42:
#line 676 "fuentes\\ens.y"
{
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IY;
                instruccion.op1=yyvsp[0];
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IY;
                instruccion.op2=yyvsp[0];
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           ;
    break;}
case 43:
#line 694 "fuentes\\ens.y"
{numregla=26;
		     numtoken=1;;
    break;}
case 44:
#line 697 "fuentes\\ens.y"
{numtoken=2;
		     operando=1;;
    break;}
case 45:
#line 700 "fuentes\\ens.y"
{numtoken=3;
		     operando=3;;
    break;}
case 46:
#line 704 "fuentes\\ens.y"
{
                     if((yyvsp[-2]<0) && (yyvsp[-2]>=-32768))
                     {
                         /*Pasamos a complemento a 2*/
                         yyvsp[-2]=yyvsp[-2]+MAXINT+1;
                     }
                     if((yyvsp[-2]<MININT) || (yyvsp[-2]>MAXINT))
                     {
                         InformarError(ERR_ORG_FUERA_LIMITE_MEMORIA,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         posmem=yyvsp[-2];
                     }
                    ;
    break;}
case 47:
#line 722 "fuentes\\ens.y"
{numregla=27;
           	     numtoken=1;;
    break;}
case 48:
#line 725 "fuentes\\ens.y"
{numtoken=2;;
    break;}
case 49:
#line 727 "fuentes\\ens.y"
{numtoken=3;
                     operando=3;;
    break;}
case 50:
#line 731 "fuentes\\ens.y"
{
                     if((yyvsp[-2]<0) && (yyvsp[-2]>=-32768))
                     {
                         /*Pasamos a complemento a 2*/
                         yyvsp[-2]=yyvsp[-2]+MAXINT+1;
                     }
                     else if(yyvsp[-2]<-32768)
                     {
                         InformarError(ERR_RES_FUERA_LIMITE_MEMORIA,nlin,"");
                     }
                     if(posmem+yyvsp[-2]>MAXINT)
                     {
                         InformarError(ERR_RES_FUERA_LIMITE_MEMORIA,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         posmem=posmem+yyvsp[-2];
                         /*Para que se actualicen los limites de memoria*/
                         EscribirMemoria(posmem-1,0); 
                     }                     
                    ;
    break;}
case 51:
#line 755 "fuentes\\ens.y"
{numregla=28;
           	     numtoken=1;;
    break;}
case 52:
#line 758 "fuentes\\ens.y"
{numtoken=2;
                     operando=1;;
    break;}
case 53:
#line 761 "fuentes\\ens.y"
{
                     listadatos=(int *)malloc(sizeof(int)*1000); 
                     plistadatos=0;
                    ;
    break;}
case 54:
#line 767 "fuentes\\ens.y"
{numtoken=3;
                     operando=3;;
    break;}
case 55:
#line 771 "fuentes\\ens.y"
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
                    ;
    break;}
case 56:
#line 794 "fuentes\\ens.y"
{numregla=29;
           	     numtoken=1;;
    break;}
case 57:
#line 797 "fuentes\\ens.y"
{numtoken=2;
                     operando=1;;
    break;}
case 58:
#line 800 "fuentes\\ens.y"
{numtoken=3;
                     operando=3;;
    break;}
case 59:
#line 804 "fuentes\\ens.y"
{
                     if((yyvsp[-2]<-((MAXINT+1)/2)) || (yyvsp[-2]>MAXINT))
                     {
                         InformarError(ERR_EXPRESION_FUERA_DE_RANGO,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         if(etiqueta!=NULL)
                         {
                             DarValorEtiqueta(etiqueta,yyvsp[-2]);
                         }
                         else
                         {
                             InformarError(ERR_ETIQUETA_NO_DEFINIDA,nlin,etiqueta);
                             generarcodigo=0;
                         }
                     }
                    ;
    break;}
case 60:
#line 825 "fuentes\\ens.y"
{numregla=30;
           	     numtoken=1;;
    break;}
case 61:
#line 828 "fuentes\\ens.y"
{numtoken=2;
                     operando=3;;
    break;}
case 62:
#line 832 "fuentes\\ens.y"
{
                     nlin++;
					 return(0);
                    ;
    break;}
case 63:
#line 841 "fuentes\\ens.y"
{
             yyval=-yyvsp[0];
            ;
    break;}
case 64:
#line 850 "fuentes\\ens.y"
{
             yyval=yyvsp[-2]+yyvsp[0];
            ;
    break;}
case 65:
#line 859 "fuentes\\ens.y"
{
             yyval=yyvsp[-2]-yyvsp[0];
            ;
    break;}
case 66:
#line 866 "fuentes\\ens.y"
{
             yyval=yyvsp[0];
            ;
    break;}
case 67:
#line 873 "fuentes\\ens.y"
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
             yyval=0;
            ;
    break;}
case 68:
#line 891 "fuentes\\ens.y"
{
               yyval=yyvsp[-2]*yyvsp[0];
              ;
    break;}
case 69:
#line 900 "fuentes\\ens.y"
{
               if(yyvsp[0]!=0)
               {
                   yyval=yyvsp[-2]/yyvsp[0];
               }
               else
               {
                   InformarError(ERR_EXPRESION_ERRONEA,nlin+1,S_CADENA_096);
                   generarcodigo=0;
               }
              ;
    break;}
case 70:
#line 917 "fuentes\\ens.y"
{
               if(yyvsp[0]!=0)
               {
                   yyval=yyvsp[-2]%yyvsp[0];
               }
               else
               {
                   InformarError(ERR_EXPRESION_ERRONEA,nlin+1,S_CADENA_096);
                   generarcodigo=0;
               }
              ;
    break;}
case 71:
#line 932 "fuentes\\ens.y"
{
               yyval=yyvsp[0];
              ;
    break;}
case 72:
#line 941 "fuentes\\ens.y"
{
               yyval=yyvsp[-1];
              ;
    break;}
case 73:
#line 948 "fuentes\\ens.y"
{
               yyval=yyvsp[0];
              ;
    break;}
case 74:
#line 955 "fuentes\\ens.y"
{
               listadatos[plistadatos]=yyvsp[0];
               plistadatos=plistadatos+1;
              ;
    break;}
case 76:
#line 967 "fuentes\\ens.y"
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
              ;
    break;}
case 78:
#line 1009 "fuentes\\ens.y"
{
               InformarError(ERR_LISTA_DATOS_ERRONEA,nlin,"<EOL>");
               generarcodigo=0;
              ;
    break;}
}

#line 811 "bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_parse_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_parse_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_parse_LLOC.first_line;
      yylsp->first_column = YY_parse_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_parse_NERRS;

#ifdef YY_parse_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_parse_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_parse_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_parse_ERROR_VERBOSE */
	YY_parse_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_parse_CHAR == YYEOF)
	YYABORT;

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_parse_CHAR, yytname[yychar1]);
#endif

      YY_parse_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_parse_LSP_NEEDED
  yylsp--;
#endif

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
  *++yylsp = YY_parse_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 1010 "bison.cc" */
#line 2380 "fuentes\\ens_tab.c"
#line 1022 "fuentes\\ens.y"


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
