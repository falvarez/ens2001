/*cadenas_ascii.h*/

/*Definicion de cadenas*/
/*Util para representacion en varios idiomas*/

#include "compilacion.h"

#ifdef _IDIOMA_ESPANOL_
#define S_CADENA_001 "*NO IMPLEMENTADA* "
#define S_CADENA_002 "Líneas procesadas: "
#define S_CADENA_003 "ERROR: Leyendo el fichero "
#define S_CADENA_004 "Fichero "
#define S_CADENA_005 " ensamblado correctamente"
#define S_CADENA_006 " con errores"
#define S_CADENA_007 "Error al ensamblar fichero "
#define S_CADENA_008 "Representación en base decimal"
#define S_CADENA_009 "Representación en base hexadecimal"
#define S_CADENA_010 "La pila crece en sentido ascendente"
#define S_CADENA_011 "La pila crece en sentido descendente"
#define S_CADENA_012 "Se detendrá la ejecucion si se encuentra un punto de ruptura"
#define S_CADENA_013 "Se ignorarán los puntos de ruptura establecidos"
#define S_CADENA_014 "Ejecución Paso A Paso"
#define S_CADENA_015 "Ejecución Normal"
#define S_CADENA_016 "Base de representación incorrecta - "
#define S_CADENA_017 "Valores posibles: 10, 16"
#define S_CADENA_018 "AVISO: Se sobrepasa el límite de memoria"
#define S_CADENA_019 "ERROR: Parámetro incorrecto - "
#define S_CADENA_020 "Banco de Registros"
#define S_CADENA_021 "ERROR: Registro inexistente"
#define S_CADENA_022 "ERROR: Valor fuera de rango"
#define S_CADENA_023 "Punto de Ruptura Desactivado"
#define S_CADENA_024 "Punto de Ruptura Activado"
#define S_CADENA_025 "Modo Paso A Paso. Se detuvo la ejecución"
#define S_CADENA_026 "Fin del programa. Instrucción HALT"
#define S_CADENA_027 "Se ha generado una excepción"
#define S_CADENA_028 "Entero Fuera De Rango"
#define S_CADENA_029 "División Por Cero"
#define S_CADENA_030 "Sobrepasado el Límite de Memoria"
#define S_CADENA_031 "Código de Operación No Reconocido"
#define S_CADENA_032 "Modo de Direccionamiento Erróneo"
#define S_CADENA_033 "Registro Inexistente"
#define S_CADENA_034 "Acceso a Memoria Fuera de Rango"
#define S_CADENA_035 "Desplazamiento Fuera de Rango"
#define S_CADENA_036 "Biestable Inexistente"
#define S_CADENA_037 "Modo de Pila Incorrecto"
#define S_CADENA_038 "Instrucción No Implementada"
#define S_CADENA_039 "Excepción no contemplada"
#define S_CADENA_040 "Punto de Ruptura Incondicional. Se detuvo la ejecución"
#define S_CADENA_041 "Caso no contemplado"
#define S_CADENA_042 "ERROR: Dirección incorrecta o fuera de rango"
#define S_CADENA_043 "ERROR: Contenido del fichero "
#define S_CADENA_044 " erróneo"
#define S_CADENA_045 "¿Seguro que desea salir (S/N)? "
#define S_CADENA_046 "ERROR: Número de parámetros incorrecto"
#define S_CADENA_047 "ERROR: Comando no reconocido"
#define S_CADENA_048 "Modo Direccionamiento Operando 1"
#define S_CADENA_049 "Modo Direccionamiento Operando 2"
#define S_CADENA_050 "Operando 1 Fuera de Rango"
#define S_CADENA_051 "Operando 2 Fuera de Rango"
#define S_CADENA_052 "Instrucción no reconocida"
#define S_CADENA_053 "Operando 1 Incorrecto"
#define S_CADENA_054 "Operando 2 Incorrecto"
#define S_CADENA_055 "Valor de la Etiqueta erróneo"
#define S_CADENA_056 "Etiqueta Duplicada"
#define S_CADENA_057 "Etiqueta No Definida"
#define S_CADENA_058 "Entrada Incorrecta"
#define S_CADENA_059 "Expresión Erronea"
#define S_CADENA_060 "Operando Incorrecto"
#define S_CADENA_061 "Número de Operandos Erróneo"
#define S_CADENA_062 "Inicio del Programa Fuera de la Memoria"
#define S_CADENA_063 "Reserva de Espacio Excede los Límites de la Memoria"
#define S_CADENA_064 "Datos en Memoria Exceden los Límites"
#define S_CADENA_065 "Valor de Expresión Fuera de Rango"
#define S_CADENA_066 "Error no Tratado"
#define S_CADENA_067 "Falta el fichero ayuda.txt"
#define S_CADENA_068 "No se inicializarán los registros antes de ejecutar"
#define S_CADENA_069 "Se inicializarán los registros antes de ejecutar"
#define S_CADENA_070 "Nombre de Etiqueta No Válido"
#define S_CADENA_071 "Error en asignación de memoria"
#define S_CADENA_072 "No se comprobará si PC invade el espacio de pila"
#define S_CADENA_073 "Se comprobará si PC invade el espacio de pila"
#define S_CADENA_074 "No se comprobará si SP invade el espacio de código"
#define S_CADENA_075 "Se comprobará si SP invade el espacio de código"
#define S_CADENA_076 "El Contador de Programa (PC) invadió la zona de pila"
#define S_CADENA_077 "El Puntero de Pila (SP) invadió la zona de código"
#define S_CADENA_078 "ERROR: Guardando el fichero "
#define S_CADENA_079 "Ejecución detenida por el usuario"
#define S_CADENA_080 "ERROR: SP Invade el Código"
#define S_CADENA_081 "ERROR: PC Invade la Pila"
#define S_CADENA_082 "Entero fuera de rango"
#define S_CADENA_083 "Lista de datos no válida"
#define S_CADENA_084 "ERROR: Escribiendo el fichero memoria.tmp"
#define S_CADENA_085 "ERROR: Escribiendo el fichero errores.tmp"
#define S_CADENA_086 "ERROR: Escribiendo el fichero fuente.tmp"
#define S_CADENA_087 "El directorio de trabajo está lleno o protegido contra escritura"
#define S_CADENA_088 "Se esperaba primer operando"
#define S_CADENA_089 "Se esperaba segundo operando"
#define S_CADENA_090 "Se esperaba fin de línea (<EOL>)"
#define S_CADENA_091 "Se esperaba coma (,)"
#define S_CADENA_092 "Desplazamiento fuera de rango"
#define S_CADENA_093 "Ensamblando fichero "
#define S_CADENA_094 "Versión "
#define S_CADENA_095 "Desbordamiento de pila en el analizador sintáctico"
#define S_CADENA_096 "División por cero"

#endif
