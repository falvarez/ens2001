/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 45 "src/ens.y"

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

#line 113 "ens.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ENS_TAB_H_INCLUDED
# define YY_YY_ENS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ENS_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "ENTERO", "ETIQUETA", "$accept", "programa", "$@1", "$@2", "$@3", "$@4",
  "$@5", "linea", "$@6", "$@7", "linea_vacia", "resto", "instruccion",
  "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16",
  "$@17", "operando", "pseudoinstruccion", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30",
  "$@31", "$@32", "expresion", "expresion_2", "expresion_3", "lista_datos",
  "$@33", "$@34", "resto_lista_datos", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-62)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,    -2,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
      13,    19,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -38,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -27,   -45,   -40,   -23,   -46,   -46,   -22
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

static const yytype_int8 yycheck[] =
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 93 "src/ens.y"
           {LiberarListaTokens();}
#line 1460 "ens.tab.c"
    break;

  case 5:
#line 97 "src/ens.y"
           {operando=0;}
#line 1466 "ens.tab.c"
    break;

  case 6:
#line 98 "src/ens.y"
           {numregla=0;}
#line 1472 "ens.tab.c"
    break;

  case 7:
#line 99 "src/ens.y"
           {numetiq=0;}
#line 1478 "ens.tab.c"
    break;

  case 8:
#line 103 "src/ens.y"
           {/*ListarTokens();*/
            LiberarListaTokens();}
#line 1485 "ens.tab.c"
    break;

  case 10:
#line 111 "src/ens.y"
        {numetiq=1;}
#line 1491 "ens.tab.c"
    break;

  case 11:
#line 113 "src/ens.y"
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
#line 1518 "ens.tab.c"
    break;

  case 18:
#line 158 "src/ens.y"
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
        }
#line 1681 "ens.tab.c"
    break;

  case 19:
#line 318 "src/ens.y"
              {numregla=11;
               operando=0; 
               numtoken=1;}
#line 1689 "ens.tab.c"
    break;

  case 20:
#line 322 "src/ens.y"
              {numtoken=2;
               operando=3;}
#line 1696 "ens.tab.c"
    break;

  case 21:
#line 326 "src/ens.y"
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
              }
#line 1725 "ens.tab.c"
    break;

  case 22:
#line 352 "src/ens.y"
              {numregla=12;
               operando=0;
               numtoken=1;}
#line 1733 "ens.tab.c"
    break;

  case 23:
#line 356 "src/ens.y"
              {numtoken=2;
               operando=1;}
#line 1740 "ens.tab.c"
    break;

  case 24:
#line 359 "src/ens.y"
              {numtoken=3;
               operando=3;}
#line 1747 "ens.tab.c"
    break;

  case 25:
#line 363 "src/ens.y"
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
              }
#line 1780 "ens.tab.c"
    break;

  case 26:
#line 393 "src/ens.y"
              {numregla=13;
               numtoken=1;
               operando=0;}
#line 1788 "ens.tab.c"
    break;

  case 27:
#line 397 "src/ens.y"
              {numtoken=2;
               operando=1;}
#line 1795 "ens.tab.c"
    break;

  case 28:
#line 400 "src/ens.y"
              {numtoken=3;}
#line 1801 "ens.tab.c"
    break;

  case 29:
#line 402 "src/ens.y"
              {numtoken=4;
               operando=2;}
#line 1808 "ens.tab.c"
    break;

  case 30:
#line 405 "src/ens.y"
              {numtoken=5;
               operando=3;}
#line 1815 "ens.tab.c"
    break;

  case 31:
#line 409 "src/ens.y"
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
              }
#line 1864 "ens.tab.c"
    break;

  case 32:
#line 457 "src/ens.y"
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
           }
#line 1885 "ens.tab.c"
    break;

  case 33:
#line 477 "src/ens.y"
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
           }
#line 1906 "ens.tab.c"
    break;

  case 34:
#line 497 "src/ens.y"
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
           }
#line 1927 "ens.tab.c"
    break;

  case 35:
#line 517 "src/ens.y"
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
	   }
#line 1948 "ens.tab.c"
    break;

  case 36:
#line 537 "src/ens.y"
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
           }
#line 1969 "ens.tab.c"
    break;

  case 37:
#line 557 "src/ens.y"
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
           }
#line 1990 "ens.tab.c"
    break;

  case 38:
#line 577 "src/ens.y"
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
           }
#line 2011 "ens.tab.c"
    break;

  case 39:
#line 597 "src/ens.y"
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
           }
#line 2032 "ens.tab.c"
    break;

  case 40:
#line 617 "src/ens.y"
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
           }
#line 2053 "ens.tab.c"
    break;

  case 41:
#line 636 "src/ens.y"
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
           }
#line 2074 "ens.tab.c"
    break;

  case 42:
#line 656 "src/ens.y"
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
           }
#line 2095 "ens.tab.c"
    break;

  case 43:
#line 676 "src/ens.y"
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
           }
#line 2116 "ens.tab.c"
    break;

  case 44:
#line 694 "src/ens.y"
                    {numregla=26;
		     numtoken=1;}
#line 2123 "ens.tab.c"
    break;

  case 45:
#line 697 "src/ens.y"
                    {numtoken=2;
		     operando=1;}
#line 2130 "ens.tab.c"
    break;

  case 46:
#line 700 "src/ens.y"
                    {numtoken=3;
		     operando=3;}
#line 2137 "ens.tab.c"
    break;

  case 47:
#line 704 "src/ens.y"
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
                    }
#line 2158 "ens.tab.c"
    break;

  case 48:
#line 722 "src/ens.y"
                    {numregla=27;
           	     numtoken=1;}
#line 2165 "ens.tab.c"
    break;

  case 49:
#line 725 "src/ens.y"
                    {numtoken=2;}
#line 2171 "ens.tab.c"
    break;

  case 50:
#line 727 "src/ens.y"
                    {numtoken=3;
                     operando=3;}
#line 2178 "ens.tab.c"
    break;

  case 51:
#line 731 "src/ens.y"
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
                    }
#line 2205 "ens.tab.c"
    break;

  case 52:
#line 755 "src/ens.y"
                    {numregla=28;
           	     numtoken=1;}
#line 2212 "ens.tab.c"
    break;

  case 53:
#line 758 "src/ens.y"
                    {numtoken=2;
                     operando=1;}
#line 2219 "ens.tab.c"
    break;

  case 54:
#line 761 "src/ens.y"
                    {
                     listadatos=(int *)malloc(sizeof(int)*1000); 
                     plistadatos=0;
                    }
#line 2228 "ens.tab.c"
    break;

  case 55:
#line 767 "src/ens.y"
                    {numtoken=3;
                     operando=3;}
#line 2235 "ens.tab.c"
    break;

  case 56:
#line 771 "src/ens.y"
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
#line 2261 "ens.tab.c"
    break;

  case 57:
#line 794 "src/ens.y"
                    {numregla=29;
           	     numtoken=1;}
#line 2268 "ens.tab.c"
    break;

  case 58:
#line 797 "src/ens.y"
                    {numtoken=2;
                     operando=1;}
#line 2275 "ens.tab.c"
    break;

  case 59:
#line 800 "src/ens.y"
                    {numtoken=3;
                     operando=3;}
#line 2282 "ens.tab.c"
    break;

  case 60:
#line 804 "src/ens.y"
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
                    }
#line 2306 "ens.tab.c"
    break;

  case 61:
#line 825 "src/ens.y"
                    {numregla=30;
           	     numtoken=1;}
#line 2313 "ens.tab.c"
    break;

  case 62:
#line 828 "src/ens.y"
                    {numtoken=2;
                     operando=3;}
#line 2320 "ens.tab.c"
    break;

  case 63:
#line 832 "src/ens.y"
                    {
                     nlin++;
					 return(0);
                    }
#line 2329 "ens.tab.c"
    break;

  case 64:
#line 841 "src/ens.y"
            {
             yyval=-yyvsp[0];
            }
#line 2337 "ens.tab.c"
    break;

  case 65:
#line 850 "src/ens.y"
            {
             yyval=yyvsp[-2]+yyvsp[0];
            }
#line 2345 "ens.tab.c"
    break;

  case 66:
#line 859 "src/ens.y"
            {
             yyval=yyvsp[-2]-yyvsp[0];
            }
#line 2353 "ens.tab.c"
    break;

  case 67:
#line 866 "src/ens.y"
            {
             yyval=yyvsp[0];
            }
#line 2361 "ens.tab.c"
    break;

  case 68:
#line 873 "src/ens.y"
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
            }
#line 2378 "ens.tab.c"
    break;

  case 69:
#line 891 "src/ens.y"
              {
               yyval=yyvsp[-2]*yyvsp[0];
              }
#line 2386 "ens.tab.c"
    break;

  case 70:
#line 900 "src/ens.y"
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
              }
#line 2402 "ens.tab.c"
    break;

  case 71:
#line 917 "src/ens.y"
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
              }
#line 2418 "ens.tab.c"
    break;

  case 72:
#line 932 "src/ens.y"
              {
               yyval=yyvsp[0];
              }
#line 2426 "ens.tab.c"
    break;

  case 73:
#line 941 "src/ens.y"
              {
               yyval=yyvsp[-1];
              }
#line 2434 "ens.tab.c"
    break;

  case 74:
#line 948 "src/ens.y"
              {
               yyval=yyvsp[0];
              }
#line 2442 "ens.tab.c"
    break;

  case 75:
#line 955 "src/ens.y"
              {
               listadatos[plistadatos]=yyvsp[0];
               plistadatos=plistadatos+1;
              }
#line 2451 "ens.tab.c"
    break;

  case 77:
#line 967 "src/ens.y"
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
#line 2492 "ens.tab.c"
    break;

  case 79:
#line 1009 "src/ens.y"
              {
               InformarError(ERR_LISTA_DATOS_ERRONEA,nlin,"<EOL>");
               generarcodigo=0;
              }
#line 2501 "ens.tab.c"
    break;


#line 2505 "ens.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 1022 "src/ens.y"


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
