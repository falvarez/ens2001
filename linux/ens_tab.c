/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MNEMONICO0 = 258,
     MNEMONICO1 = 259,
     MNEMONICO2 = 260,
     ORG = 261,
     END = 262,
     EQU = 263,
     RES = 264,
     DATA = 265,
     EOL = 266,
     SEPARADOR = 267,
     FIN_ETIQ = 268,
     COMILLAS = 269,
     SUMA = 270,
     RESTA = 271,
     PRODUCTO = 272,
     DIVISION = 273,
     MODULO = 274,
     PARENT_ABRE = 275,
     PARENT_CIERRA = 276,
     INMEDIATO_V = 277,
     INMEDIATO_E = 278,
     REGISTRO = 279,
     MEMORIA_V = 280,
     MEMORIA_E = 281,
     INDIRECTO = 282,
     RELAT_PC_V = 283,
     RELAT_PC_E = 284,
     RELAT_IX_V = 285,
     RELAT_IX_E = 286,
     RELAT_IY_V = 287,
     RELAT_IY_E = 288,
     CADENA = 289,
     ENTERO = 290,
     ETIQUETA = 291
   };
#endif
/* Tokens.  */
#define MNEMONICO0 258
#define MNEMONICO1 259
#define MNEMONICO2 260
#define ORG 261
#define END 262
#define EQU 263
#define RES 264
#define DATA 265
#define EOL 266
#define SEPARADOR 267
#define FIN_ETIQ 268
#define COMILLAS 269
#define SUMA 270
#define RESTA 271
#define PRODUCTO 272
#define DIVISION 273
#define MODULO 274
#define PARENT_ABRE 275
#define PARENT_CIERRA 276
#define INMEDIATO_V 277
#define INMEDIATO_E 278
#define REGISTRO 279
#define MEMORIA_V 280
#define MEMORIA_E 281
#define INDIRECTO 282
#define RELAT_PC_V 283
#define RELAT_PC_E 284
#define RELAT_IX_V 285
#define RELAT_IX_E 286
#define RELAT_IY_V 287
#define RELAT_IY_E 288
#define CADENA 289
#define ENTERO 290
#define ETIQUETA 291




/* Copy the first part of user declarations.  */
#line 45 "ens.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "ens.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     5,     9,    10,    11,    12,    13,
      20,    21,    22,    29,    31,    32,    35,    37,    39,    42,
      43,    44,    49,    50,    51,    52,    59,    60,    61,    62,
      63,    64,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    93,    95,    97,    99,   100,   101,   102,   109,   110,
     111,   112,   119,   120,   121,   122,   123,   131,   132,   133,
     134,   141,   142,   143,   148,   151,   155,   159,   161,   163,
     167,   171,   175,   177,   181,   183,   184,   188,   189,   195,
     197,   199,   200
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    -1,    -1,    11,    39,    38,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    44,    43,    38,    -1,
      -1,    -1,    36,    13,    45,    46,    47,    48,    -1,    48,
      -1,    -1,    11,    47,    -1,    49,    -1,    61,    -1,     1,
      11,    -1,    -1,    -1,    50,     3,    51,    11,    -1,    -1,
      -1,    -1,    52,     4,    53,    60,    54,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    55,     5,    56,    60,    57,    12,
      58,    60,    59,    11,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,    -1,
      -1,    -1,    62,     6,    63,    77,    64,    11,    -1,    -1,
      -1,    -1,    65,     9,    66,    77,    67,    11,    -1,    -1,
      -1,    -1,    -1,    68,    10,    69,    70,    80,    71,    11,
      -1,    -1,    -1,    -1,    72,     8,    73,    77,    74,    11,
      -1,    -1,    -1,    75,     7,    76,    11,    -1,    16,    78,
      -1,    77,    15,    78,    -1,    77,    16,    78,    -1,    78,
      -1,     1,    -1,    78,    17,    79,    -1,    78,    18,    79,
      -1,    78,    19,    79,    -1,    79,    -1,    20,    77,    21,
      -1,    35,    -1,    -1,    35,    81,    83,    -1,    -1,    14,
      34,    14,    82,    83,    -1,    11,    -1,     1,    -1,    -1,
      12,    80,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    93,    92,    97,    98,    99,   103,    97,
     111,   113,   109,   140,   142,   145,   149,   152,   155,   318,
     322,   318,   352,   356,   359,   352,   393,   397,   400,   402,
     405,   393,   455,   475,   495,   515,   535,   555,   575,   595,
     615,   634,   654,   674,   694,   697,   700,   694,   722,   725,
     727,   722,   755,   758,   761,   767,   755,   794,   797,   800,
     794,   825,   828,   825,   838,   846,   855,   864,   871,   887,
     896,   913,   930,   937,   946,   955,   953,   967,   963,  1007,
    1015,  1017,  1019
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MNEMONICO0", "MNEMONICO1", "MNEMONICO2",
  "ORG", "END", "EQU", "RES", "DATA", "EOL", "SEPARADOR", "FIN_ETIQ",
  "COMILLAS", "SUMA", "RESTA", "PRODUCTO", "DIVISION", "MODULO",
  "PARENT_ABRE", "PARENT_CIERRA", "INMEDIATO_V", "INMEDIATO_E", "REGISTRO",
  "MEMORIA_V", "MEMORIA_E", "INDIRECTO", "RELAT_PC_V", "RELAT_PC_E",
  "RELAT_IX_V", "RELAT_IX_E", "RELAT_IY_V", "RELAT_IY_E", "CADENA",
  "ENTERO", "ETIQUETA", "$accept", "programa", "@1", "@2", "@3", "@4",
  "@5", "linea", "@6", "@7", "linea_vacia", "resto", "instruccion", "@8",
  "@9", "@10", "@11", "@12", "@13", "@14", "@15", "@16", "@17", "operando",
  "pseudoinstruccion", "@18", "@19", "@20", "@21", "@22", "@23", "@24",
  "@25", "@26", "@27", "@28", "@29", "@30", "@31", "@32", "expresion",
  "expresion_2", "expresion_3", "lista_datos", "@33", "@34",
  "resto_lista_datos", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    38,    40,    41,    42,    43,    38,
      45,    46,    44,    44,    47,    47,    48,    48,    48,    50,
      51,    49,    52,    53,    54,    49,    55,    56,    57,    58,
      59,    49,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    62,    63,    64,    61,    65,    66,
      67,    61,    68,    69,    70,    71,    61,    72,    73,    74,
      61,    75,    76,    61,    77,    77,    77,    77,    77,    78,
      78,    78,    78,    79,    79,    81,    80,    82,    80,    80,
      80,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     0,     0,     0,     0,     6,
       0,     0,     6,     1,     0,     2,     1,     1,     2,     0,
       0,     4,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    10,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     0,     6,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     0,     0,     0,
       6,     0,     0,     4,     2,     3,     3,     1,     1,     3,
       3,     3,     1,     3,     1,     0,     3,     0,     5,     1,
       1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     3,     0,     6,     5,     1,     7,     4,     0,     0,
       0,     8,    13,    16,     0,     0,     0,    17,     0,     0,
       0,     0,     0,    18,    10,     5,    20,    23,    27,    45,
      49,    53,    58,    62,    11,     9,     0,     0,     0,     0,
       0,    54,     0,     0,    14,    21,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    24,    28,
      68,     0,     0,    74,    46,    67,    72,    50,     0,    59,
      63,    14,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    79,     0,    75,    55,     0,
      15,    12,    25,    29,    73,    65,    66,    47,    69,    70,
      71,    51,     0,    81,     0,    60,     0,    77,     0,    76,
      56,    30,    81,    82,     0,    78,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     4,     3,     6,     8,    25,    11,    34,    44,
      72,    12,    13,    14,    36,    15,    37,    73,    16,    38,
      74,   106,   114,    58,    17,    18,    39,    79,    19,    40,
      83,    20,    41,    68,   104,    21,    42,    89,    22,    43,
      64,    65,    66,    88,   103,   112,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int8 yypact[] =
{
      17,   -46,    27,   -46,    17,   -46,   -46,   -46,     0,    23,
      18,   -46,   -46,   -46,    40,    55,    39,   -46,    54,    52,
      53,    56,    58,   -46,   -46,    17,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,    51,    25,    25,    10,
      10,   -46,    10,    67,    68,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,    -6,    10,   -46,     5,    20,   -46,     5,    11,     5,
     -46,    68,    66,    69,    65,    20,     3,    -6,    -6,    70,
      -6,    -6,    -6,    71,   -46,   -46,    32,   -46,   -46,    72,
     -46,   -46,   -46,   -46,   -46,    20,    20,   -46,   -46,   -46,
     -46,   -46,    73,    74,    77,   -46,    25,   -46,    11,   -46,
     -46,   -46,    74,   -46,    78,   -46,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,    -2,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
      13,    19,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -38,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -27,   -45,   -40,   -23,   -46,   -46,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -62
static const yytype_int8 yytable[] =
{
      59,     9,     7,   -19,   -22,   -26,   -44,   -61,   -57,   -48,
     -52,    60,    84,    67,    62,    69,    75,    -2,    77,    78,
      77,    78,    85,    35,    94,    86,    61,     5,     1,    63,
      62,    24,    95,    96,    23,    76,    10,    80,    81,    82,
      98,    99,   100,    26,    28,    63,    87,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    27,
      29,    30,    45,    31,    32,    33,   102,     9,   111,   -19,
     -22,   -26,   -44,   -61,   -57,   -48,   -52,    93,    70,    71,
      92,    97,   101,   105,    90,   113,   108,   107,   110,   116,
     115,    91
};

static const yytype_uint8 yycheck[] =
{
      38,     1,     4,     3,     4,     5,     6,     7,     8,     9,
      10,     1,     1,    40,    20,    42,    61,     0,    15,    16,
      15,    16,    11,    25,    21,    14,    16,     0,    11,    35,
      20,    13,    77,    78,    11,    62,    36,    17,    18,    19,
      80,    81,    82,     3,     5,    35,    35,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     4,
       6,     9,    11,    10,     8,     7,    34,     1,   106,     3,
       4,     5,     6,     7,     8,     9,    10,    12,    11,    11,
      11,    11,    11,    11,    71,   108,    12,    14,    11,    11,
     112,    72
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    38,    40,    39,     0,    41,    38,    42,     1,
      36,    44,    48,    49,    50,    52,    55,    61,    62,    65,
      68,    72,    75,    11,    13,    43,     3,     4,     5,     6,
       9,    10,     8,     7,    45,    38,    51,    53,    56,    63,
      66,    69,    73,    76,    46,    11,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    60,    60,
       1,    16,    20,    35,    77,    78,    79,    77,    70,    77,
      11,    11,    47,    54,    57,    78,    77,    15,    16,    64,
      17,    18,    19,    67,     1,    11,    14,    35,    80,    74,
      47,    48,    11,    12,    21,    78,    78,    11,    79,    79,
      79,    11,    34,    81,    71,    11,    58,    14,    12,    83,
      11,    60,    82,    80,    59,    83,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 93 "ens.y"
    {LiberarListaTokens();;}
    break;

  case 5:
#line 97 "ens.y"
    {operando=0;;}
    break;

  case 6:
#line 98 "ens.y"
    {numregla=0;;}
    break;

  case 7:
#line 99 "ens.y"
    {numetiq=0;;}
    break;

  case 8:
#line 103 "ens.y"
    {/*ListarTokens();*/
            LiberarListaTokens();;}
    break;

  case 10:
#line 111 "ens.y"
    {numetiq=1;;}
    break;

  case 11:
#line 113 "ens.y"
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
        ;}
    break;

  case 18:
#line 158 "ens.y"
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
        ;}
    break;

  case 19:
#line 318 "ens.y"
    {numregla=11;
               operando=0; 
               numtoken=1;;}
    break;

  case 20:
#line 322 "ens.y"
    {numtoken=2;
               operando=3;;}
    break;

  case 21:
#line 326 "ens.y"
    {
               instruccion.codop=(yyvsp[(2) - (4)]);
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
              ;}
    break;

  case 22:
#line 352 "ens.y"
    {numregla=12;
               operando=0;
               numtoken=1;;}
    break;

  case 23:
#line 356 "ens.y"
    {numtoken=2;
               operando=1;;}
    break;

  case 24:
#line 359 "ens.y"
    {numtoken=3;
               operando=3;;}
    break;

  case 25:
#line 363 "ens.y"
    {
               instruccion.codop=(yyvsp[(2) - (6)]);
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
              ;}
    break;

  case 26:
#line 393 "ens.y"
    {numregla=13;
               numtoken=1;
               operando=0;;}
    break;

  case 27:
#line 397 "ens.y"
    {numtoken=2;
               operando=1;;}
    break;

  case 28:
#line 400 "ens.y"
    {numtoken=3;;}
    break;

  case 29:
#line 402 "ens.y"
    {numtoken=4;
               operando=2;;}
    break;

  case 30:
#line 405 "ens.y"
    {numtoken=5;
               operando=3;;}
    break;

  case 31:
#line 409 "ens.y"
    {
               instruccion.codop=(yyvsp[(2) - (10)]);
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
              ;}
    break;

  case 32:
#line 457 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_INMEDIATO;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_INMEDIATO;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;}
    break;

  case 33:
#line 477 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_INMEDIATO;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=16;
            }
            else
            {
                instruccion.mdir2=MD_INMEDIATO;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud2=16;
            }
           ;}
    break;

  case 34:
#line 497 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_REGISTRO;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_REGISTRO;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;}
    break;

  case 35:
#line 517 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_MEMORIA;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_MEMORIA;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
	   ;}
    break;

  case 36:
#line 537 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_MEMORIA;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=16;
            }
            else
            {
                instruccion.mdir2=MD_MEMORIA;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud2=16;
            }
           ;}
    break;

  case 37:
#line 557 "ens.y"
    {
            if (operando==1)
            {
                instruccion.mdir1=MD_INDIRECTO;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_INDIRECTO;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;}
    break;

  case 38:
#line 577 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_PC;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_PC;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;}
    break;

  case 39:
#line 597 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_PC;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_PC;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           ;}
    break;

  case 40:
#line 617 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IX;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IX;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;}
    break;

  case 41:
#line 636 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IX;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IX;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           ;}
    break;

  case 42:
#line 656 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IY;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=NULL;
                instruccion.longitud1=0;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IY;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=NULL;
                instruccion.longitud2=0;
            }
           ;}
    break;

  case 43:
#line 676 "ens.y"
    {
            if(operando==1)
            {
                instruccion.mdir1=MD_RELATIVO_IY;
                instruccion.op1=(yyvsp[(1) - (1)]);
                instruccion.etiqueta1=etiqueta;
                instruccion.longitud1=8;
            }
            else
            {
                instruccion.mdir2=MD_RELATIVO_IY;
                instruccion.op2=(yyvsp[(1) - (1)]);
                instruccion.etiqueta2=etiqueta;
                instruccion.longitud1=8;
            }
           ;}
    break;

  case 44:
#line 694 "ens.y"
    {numregla=26;
		     numtoken=1;;}
    break;

  case 45:
#line 697 "ens.y"
    {numtoken=2;
		     operando=1;;}
    break;

  case 46:
#line 700 "ens.y"
    {numtoken=3;
		     operando=3;;}
    break;

  case 47:
#line 704 "ens.y"
    {
                     if(((yyvsp[(4) - (6)])<0) && ((yyvsp[(4) - (6)])>=-32768))
                     {
                         /*Pasamos a complemento a 2*/
                         (yyvsp[(4) - (6)])=(yyvsp[(4) - (6)])+MAXINT+1;
                     }
                     if(((yyvsp[(4) - (6)])<MININT) || ((yyvsp[(4) - (6)])>MAXINT))
                     {
                         InformarError(ERR_ORG_FUERA_LIMITE_MEMORIA,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         posmem=(yyvsp[(4) - (6)]);
                     }
                    ;}
    break;

  case 48:
#line 722 "ens.y"
    {numregla=27;
           	     numtoken=1;;}
    break;

  case 49:
#line 725 "ens.y"
    {numtoken=2;;}
    break;

  case 50:
#line 727 "ens.y"
    {numtoken=3;
                     operando=3;;}
    break;

  case 51:
#line 731 "ens.y"
    {
                     if(((yyvsp[(4) - (6)])<0) && ((yyvsp[(4) - (6)])>=-32768))
                     {
                         /*Pasamos a complemento a 2*/
                         (yyvsp[(4) - (6)])=(yyvsp[(4) - (6)])+MAXINT+1;
                     }
                     else if((yyvsp[(4) - (6)])<-32768)
                     {
                         InformarError(ERR_RES_FUERA_LIMITE_MEMORIA,nlin,"");
                     }
                     if(posmem+(yyvsp[(4) - (6)])>MAXINT)
                     {
                         InformarError(ERR_RES_FUERA_LIMITE_MEMORIA,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         posmem=posmem+(yyvsp[(4) - (6)]);
                         /*Para que se actualicen los limites de memoria*/
                         EscribirMemoria(posmem-1,0); 
                     }                     
                    ;}
    break;

  case 52:
#line 755 "ens.y"
    {numregla=28;
           	     numtoken=1;;}
    break;

  case 53:
#line 758 "ens.y"
    {numtoken=2;
                     operando=1;;}
    break;

  case 54:
#line 761 "ens.y"
    {
                     listadatos=(int *)malloc(sizeof(int)*1000); 
                     plistadatos=0;
                    ;}
    break;

  case 55:
#line 767 "ens.y"
    {numtoken=3;
                     operando=3;;}
    break;

  case 56:
#line 771 "ens.y"
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
                    ;}
    break;

  case 57:
#line 794 "ens.y"
    {numregla=29;
           	     numtoken=1;;}
    break;

  case 58:
#line 797 "ens.y"
    {numtoken=2;
                     operando=1;;}
    break;

  case 59:
#line 800 "ens.y"
    {numtoken=3;
                     operando=3;;}
    break;

  case 60:
#line 804 "ens.y"
    {
                     if(((yyvsp[(4) - (6)])<-((MAXINT+1)/2)) || ((yyvsp[(4) - (6)])>MAXINT))
                     {
                         InformarError(ERR_EXPRESION_FUERA_DE_RANGO,nlin,"");
                         generarcodigo=0;
                     }
                     else
                     {
                         if(etiqueta!=NULL)
                         {
                             DarValorEtiqueta(etiqueta,(yyvsp[(4) - (6)]));
                         }
                         else
                         {
                             InformarError(ERR_ETIQUETA_NO_DEFINIDA,nlin,etiqueta);
                             generarcodigo=0;
                         }
                     }
                    ;}
    break;

  case 61:
#line 825 "ens.y"
    {numregla=30;
           	     numtoken=1;;}
    break;

  case 62:
#line 828 "ens.y"
    {numtoken=2;
                     operando=3;;}
    break;

  case 63:
#line 832 "ens.y"
    {
                     nlin++;
					 return(0);
                    ;}
    break;

  case 64:
#line 841 "ens.y"
    {
             (yyval)=-(yyvsp[(2) - (2)]);
            ;}
    break;

  case 65:
#line 850 "ens.y"
    {
             (yyval)=(yyvsp[(1) - (3)])+(yyvsp[(3) - (3)]);
            ;}
    break;

  case 66:
#line 859 "ens.y"
    {
             (yyval)=(yyvsp[(1) - (3)])-(yyvsp[(3) - (3)]);
            ;}
    break;

  case 67:
#line 866 "ens.y"
    {
             (yyval)=(yyvsp[(1) - (1)]);
            ;}
    break;

  case 68:
#line 873 "ens.y"
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
             (yyval)=0;
            ;}
    break;

  case 69:
#line 891 "ens.y"
    {
               (yyval)=(yyvsp[(1) - (3)])*(yyvsp[(3) - (3)]);
              ;}
    break;

  case 70:
#line 900 "ens.y"
    {
               if((yyvsp[(3) - (3)])!=0)
               {
                   (yyval)=(yyvsp[(1) - (3)])/(yyvsp[(3) - (3)]);
               }
               else
               {
                   InformarError(ERR_EXPRESION_ERRONEA,nlin+1,S_CADENA_096);
                   generarcodigo=0;
               }
              ;}
    break;

  case 71:
#line 917 "ens.y"
    {
               if((yyvsp[(3) - (3)])!=0)
               {
                   (yyval)=(yyvsp[(1) - (3)])%(yyvsp[(3) - (3)]);
               }
               else
               {
                   InformarError(ERR_EXPRESION_ERRONEA,nlin+1,S_CADENA_096);
                   generarcodigo=0;
               }
              ;}
    break;

  case 72:
#line 932 "ens.y"
    {
               (yyval)=(yyvsp[(1) - (1)]);
              ;}
    break;

  case 73:
#line 941 "ens.y"
    {
               (yyval)=(yyvsp[(2) - (3)]);
              ;}
    break;

  case 74:
#line 948 "ens.y"
    {
               (yyval)=(yyvsp[(1) - (1)]);
              ;}
    break;

  case 75:
#line 955 "ens.y"
    {
               listadatos[plistadatos]=(yyvsp[(1) - (1)]);
               plistadatos=plistadatos+1;
              ;}
    break;

  case 77:
#line 967 "ens.y"
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
              ;}
    break;

  case 79:
#line 1009 "ens.y"
    {
               InformarError(ERR_LISTA_DATOS_ERRONEA,nlin,"<EOL>");
               generarcodigo=0;
              ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2509 "ens.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1022 "ens.y"


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

