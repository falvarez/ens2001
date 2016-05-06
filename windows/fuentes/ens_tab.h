#ifndef YY_parse_h_included
#define YY_parse_h_included

#line 1 "bison.h"
/* before anything */
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
#endif
#include <stdio.h>

/* #line 14 "bison.h" */
#line 21 "fuentes\\ens_tab.h"

#line 14 "bison.h"
 /* %{ and %header{ and %union, during decl */
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
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_parse_STYPE 
#define YY_parse_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_parse_DEBUG
#define  YY_parse_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
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

/* #line 63 "bison.h" */
#line 75 "fuentes\\ens_tab.h"

#line 63 "bison.h"
/* YY_parse_PURE */
#endif

/* #line 65 "bison.h" */
#line 82 "fuentes\\ens_tab.h"

#line 65 "bison.h"
/* prefix */
#ifndef YY_parse_DEBUG

/* #line 67 "bison.h" */
#line 89 "fuentes\\ens_tab.h"

#line 67 "bison.h"
/* YY_parse_DEBUG */
#endif
#ifndef YY_parse_LSP_NEEDED

/* #line 70 "bison.h" */
#line 97 "fuentes\\ens_tab.h"

#line 70 "bison.h"
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

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_parse_PURE
extern YY_parse_STYPE YY_parse_LVAL;
#endif


/* #line 143 "bison.h" */
#line 175 "fuentes\\ens_tab.h"
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


#line 143 "bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
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

/* #line 182 "bison.h" */
#line 254 "fuentes\\ens_tab.h"
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


#line 182 "bison.h"
 /* decl const */
#else
enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0

/* #line 185 "bison.h" */
#line 297 "fuentes\\ens_tab.h"
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


#line 185 "bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
#ifdef YY_parse_PURE
#ifdef YY_parse_LSP_NEEDED
 virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
#else
 virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
#endif
#else
 virtual int YY_parse_LEX() YY_parse_LEX_BODY;
 YY_parse_STYPE YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
 YY_parse_LTYPE YY_parse_LLOC;
#endif
 int YY_parse_NERRS;
 int YY_parse_CHAR;
#endif
#if YY_parse_DEBUG != 0
public:
 int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_parse_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_parse_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_parse_DEBUG 
#define YYDEBUG YY_parse_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "bison.h" */
#line 388 "fuentes\\ens_tab.h"
#endif
