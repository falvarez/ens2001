/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

