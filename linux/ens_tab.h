/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
