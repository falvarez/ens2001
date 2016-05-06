/*Definiciones e includes comunes*/
#ifndef _DEFINICIONES_H_
#define _DEFINICIONES_H_

#define NO      0
#define SI      1

/*Parametros de configuracion*/

#define MAXINT  65535 //Mayor entero representable
#define MININT  0 //Menor entero representable

#define MAXDESP 255 //Mayor desplazamiento representable
#define MINDESP 0 //Menor desplazamiento representable

/*Entornos de ejecucion*/

#define ENT_DOS         0
#define ENT_WIN32       1
#define ENT_LINUX       2

/*Modos de ejecucion procesador*/

#define ME_NORMAL       0
#define ME_PASOAPASO    1

/*Condiciones de fin de ejecucion*/

#define EJ_SIGUIENTE    0
#define EJ_PASOAPASO    1
#define EJ_HALT         2
#define EJ_PUNTORUPTURA 3
#define EJ_EXCEPCION    4

/*Excepciones*/

#define EX_NORMAL                       0
#define EX_ENTERO_FUERA_DE_RANGO        1
#define EX_DIVISION_POR_CERO            2
#define EX_FINALMEMORIA                 3
#define EX_COPERRONEO                   4
#define EX_MDIRERRONEO                  5
#define EX_REGISTRO_NO_EXISTE           6
#define EX_MEMORIA_FUERA_DE_RANGO       7
#define EX_DESPLAZ_FUERA_DE_RANGO       8
#define EX_BIESTABLE_NO_EXISTE          9
#define EX_MODOPILA_INCORRECTO          10
#define EX_INSTRUCCION_NO_IMPLEMENTADA  11
#define EX_PC_INVADE_PILA               12
#define EX_SP_INVADE_CODIGO             13
#define EX_DETENIDO_POR_USUARIO         14

/*Modos de direccionamiento*/

#define MD_NO_OPERANDO  0
#define MD_INMEDIATO    1
#define MD_REGISTRO     2
#define MD_MEMORIA      3
#define MD_INDIRECTO    4
#define MD_RELATIVO_IX  5
#define MD_RELATIVO_IY  6
#define MD_RELATIVO_PC  7

/*Codigos de operacion*/

#define NOP             0
#define HALT            1
#define MOVE            2
#define PUSH            3
#define POP             4
#define ADD             5
#define SUB             6
#define MUL             7
#define DIV             8
#define MOD             9
#define INC             10
#define DEC             11
#define NEG             12
#define CMP             13
#define AND             14
#define OR              15
#define XOR             16
#define NOT             17
#define BR              18
#define BZ              19
#define BNZ             20
#define BP              21
#define BN              22
#define BV              23
#define BNV             24
#define BC              25
#define BNC             26
#define BE              27
#define BO              28
#define CALL            29
#define RET             30
#define INCHAR          31
#define ININT           32
#define INSTR           33
#define WRCHAR          34
#define WRINT           35
#define WRSTR           36

/*Registros*/
/*Se numeran secuencialmente para poder almacenarlos en un vector*/
#define NUM_REGISTROS   16

#define R0      0
#define R1      1
#define R2      2
#define R3      3
#define R4      4
#define R5      5
#define R6      6
#define R7      7
#define R8      8
#define R9      9
#define A       10
#define SR      11
#define IX      12
#define IY      13
#define SP      14
#define PC      15

/*Biestables de Estado*/
/*Se numeran secuencialmente para poder almacenarlos en un vector*/
#define NUM_BIESTABLES  6

#define BS_Z 0
#define BS_C 1
#define BS_V 2
#define BS_P 3
#define BS_S 4
#define BS_H 5

/*Tipos de objeto*/

#define OBJ_OPERANDO    0
#define OBJ_INSTRUCCION 1

/*Funcionamiento de la pila*/

#define PILA_CRECIENTE 0
#define PILA_DECRECIENTE 1

/*Operaciones de la ALU*/

#define ALU_SUMA        0
#define ALU_RESTA       1
#define ALU_PRODUCTO    2
#define ALU_DIVISION    3
#define ALU_MODULO      4
#define ALU_INC         5
#define ALU_DEC         6
#define ALU_CAMBIO_SIG  7
#define ALU_AND         8
#define ALU_OR          9
#define ALU_NOT         10
#define ALU_XOR         11

/*Condiciones de bifurcacion*/

#define BIF_INCOND      0
#define BIF_Z           1
#define BIF_NZ          2
#define BIF_P           3
#define BIF_N           4
#define BIF_V           5
#define BIF_NV          6
#define BIF_C           7
#define BIF_NC          8
#define BIF_E           9
#define BIF_O           10

/*Bases de representacion numerica*/

#define BASE_DECIMAL            10
#define BASE_HEXADECIMAL        16
#define BASE_OCTAL              8
#define BASE_BINARIA            2

/*Errores compilacion*/
#define ERR_MODO_DIR_1_ERRONEO          1  //sm
#define ERR_MODO_DIR_2_ERRONEO          2  //sm
#define ERR_INSTRUCCION_NO_RECONOCIDA   3  //st
#define ERR_OP1_INCORRECTO              4  //st
#define ERR_OP2_INCORRECTO              5  //st
#define ERR_ETIQUETA_DUPLICADA          6  //sm
#define ERR_ETIQUETA_NO_DEFINIDA        7  //gc
#define ERR_ENTRADA_INCORRECTA          8  //lx
#define ERR_EXPRESION_ERRONEA           9  //st
#define ERR_ORG_FUERA_LIMITE_MEMORIA    10 //sm
#define ERR_RES_FUERA_LIMITE_MEMORIA    11 //sm
#define ERR_DATA_FUERA_LIMITE_MEMORIA   12 //sm
#define ERR_EXPRESION_FUERA_DE_RANGO    13 //sm
#define ERR_NOMBRE_ETIQUETA_RESERVADO   14 //sm
#define ERR_ENTERO_FUERA_DE_RANGO	15 //lx
#define ERR_SE_ESPERABA_OP1		16 //st
#define ERR_SE_ESPERABA_OP2		17 //st
#define ERR_SE_ESPERABA_EOL		18 //st
#define ERR_SE_ESPERABA_SEPARADOR	19 //st
#define ERR_LISTA_DATOS_ERRONEA		20 //st
#define ERR_DESPLAZAMIENTO_FUERA_RANGO  21 //gc
#define ERR_ASIGNACION_MEMORIA          22 //gral
#define ERR_DESBORDAMIENTO_PILA_ANALIZADOR	23 //gral

/*Codigos de teclas*/
#define KEY_INTRO       13
#define KEY_BACKSPACE   8
#define KEY_ESCAPE      27

/*Caracteres especiales*/
#define AGUDO 		39
#define GRAVE 		59
#define CIRCUNFLEJO 	58
#define DIERESIS 	34
#define CONTROL         256

/*Estados del analizador lexico*/
#define ESTADO_INICIAL		0
#define ESTADO_EXPRESION	1
#define	ESTADO_DATOS		2
#define ESTADO_CADENA		3

/*Ficheros usados*/
#define FICHERO_AYUDA "ayuda.txt"
#define FICHERO_CONFIGURACION "ens2001.cfg"
#define FICHERO_CONFIGURACION_WINDOWS "wens2001.cfg"
#define FICHERO_TEMPORAL_ERRORES "errores.tmp"
#define FICHERO_TEMPORAL_MEMORIA "memoria.tmp"
#define FICHERO_TEMPORAL_FUENTE "fuente.tmp"

#endif /*_DEFINICIONES_H_*/
