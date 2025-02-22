# makefile para ens2001, version 1.0

#LINUX
CC++ = c++
MOVER = mv
BORRAR = rm
ENS2001 = ens2001
O = o

#MSDOS-WINDOWS
#CC = bcc32 -Id:\pfc\fuentes -Id:\pfc\fuentes\windows -nd:\pfc
#CC = gcc 
#CC++ = bcc32 -Id:\pfc\fuentes -Id:\pfc\fuentes\windows -nd:\pfc
#CC++ = gpp
#MOVER = move
#BORRAR = del
#ENS2001 = ens2001.exe
#O = o
#O = obj

# MAC Universal Binary
CFLAGS += -std=gnu89 -Wno-implicit-function-declaration -arch arm64 -arch x86_64
CXXFLAGS += -std=c++98 -arch arm64 -arch x86_64

OBJECTS = cconfiguracion.$(O) cmemoria.$(O) cbancoregistros.$(O) \
          cprocesador.$(O) cinstruccion.$(O) cgestorinstrucciones.$(O) \
          centero16b.$(O) centradasalida.$(O) cinterfazconsola.$(O) \
          cdesensamblador.$(O) cinterfazdisco.$(O) cgestorpuntosruptura.$(O) \
          censamblador.$(O) ccadena.$(O) ens_lex.$(O) ens_tab.$(O) \
          funcionesauxiliares.$(O) gestionerrores.$(O) gestionetiquetas.$(O) \
          gestionmemoria.$(O) 

DEFS = definiciones.h cadenas_ansi.h cadenas_ascii.h compilacion.h

$(ENS2001) : ens2001.cpp $(OBJECTS)
	$(CC++) $(CXXFLAGS) -o$(ENS2001) ens2001.cpp $(OBJECTS)
	
cconfiguracion.$(O) : cconfiguracion.cpp cconfiguracion.h $(DEFS) defscpp.h \
                      cmemoria.h cbancoregistros.h cprocesador.h \
                      cgestorpuntosruptura.h
	$(CC++) $(CXXFLAGS) -c cconfiguracion.cpp
	
cmemoria.$(O) : cmemoria.cpp cmemoria.h $(DEFS) defscpp.h cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c cmemoria.cpp
	
cbancoregistros.$(O) : cbancoregistros.cpp cbancoregistros.h $(DEFS) defscpp.h \
                       cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c cbancoregistros.cpp
	
cprocesador.$(O) : cprocesador.cpp cprocesador.h $(DEFS) defscpp.h
	$(CC++) $(CXXFLAGS) -c cprocesador.cpp
	
cinstruccion.$(O) : cinstruccion.cpp cinstruccion.h $(DEFS) defscpp.h \
                    cconfiguracion.h centradasalida.h
	$(CC++) $(CXXFLAGS) -c cinstruccion.cpp
	
cgestorinstrucciones.$(O) : cgestorinstrucciones.cpp cgestorinstrucciones.h \
                            $(DEFS) defscpp.h cinstruccion.h cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c cgestorinstrucciones.cpp	

centero16b.$(O) : centero16b.cpp centero16b.h $(DEFS) defscpp.h
	$(CC++) $(CXXFLAGS) -c centero16b.cpp
	
centradasalida.$(O) : centradasalida.cpp centradasalida.h $(DEFS) defscpp.h \
                      cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c centradasalida.cpp
	
cinterfazconsola.$(O) : cinterfazconsola.cpp cinterfazconsola.h $(DEFS) \
                        defscpp.h cconfiguracion.h cdesensamblador.h \
                        censamblador.h cinterfazdisco.h ens_tab.h
	$(CC++) $(CXXFLAGS) -c cinterfazconsola.cpp
	
cdesensamblador.$(O) : cdesensamblador.cpp cdesensamblador.h $(DEFS) defscpp.h \
                       cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c cdesensamblador.cpp
	
cinterfazdisco.$(O) : cinterfazdisco.cpp cinterfazdisco.h $(DEFS) defscpp.h \
                      cmemoria.h
	$(CC++) $(CXXFLAGS) -c cinterfazdisco.cpp
	
cgestorpuntosruptura.$(O) : cgestorpuntosruptura.cpp cgestorpuntosruptura.h \
                             $(DEFS) defscpp.h cconfiguracion.h centero16b.h
	$(CC++) $(CXXFLAGS) -c cgestorpuntosruptura.cpp
	
censamblador.$(O) : censamblador.cpp censamblador.h $(DEFS) defscpp.h \
                    cconfiguracion.h ens_tab.h
	$(CC++) $(CXXFLAGS) -c censamblador.cpp

ccadena.$(O) : ccadena.cpp ccadena.h $(DEFS) defscpp.h
	$(CC++) $(CXXFLAGS) -c ccadena.cpp
	
ens_lex.$(O) : ens_lex.c ens.l $(DEFS) defsc.h ens_tab.h funcionesauxiliares.h \
               gestionerrores.h
	$(CC) $(CFLAGS) -c ens_lex.c
	
ens_lex.c : ens.l $(DEFS) defsc.h ens_tab.h funcionesauxiliares.h \
            gestionerrores.h
	flex -8 -t ens.l > ens_lex.c
	 
ens_tab.$(O) : ens_tab.c ens_tab.h ens.y $(DEFS) defsc.h funcionesauxiliares.h \
               gestionetiquetas.h gestionerrores.h gestionmemoria.h 
	$(CC) $(CFLAGS) -c ens_tab.c
	
ens_tab.c : ens.y $(DEFS) defsc.h funcionesauxiliares.h \
            gestionetiquetas.h gestionerrores.h gestionmemoria.h 
	bison --defines ens.y
	$(MOVER) ens.tab.h ens_tab.h
	$(MOVER) ens.tab.c ens_tab.c
	
ens_tab.h : ens_tab.c
        	
funcionesauxiliares.$(O) : funcionesauxiliares.c funcionesauxiliares.h $(DEFS) \
                           defsc.h
	$(CC) $(CFLAGS) -c funcionesauxiliares.c
	
gestionerrores.$(O) : gestionerrores.c gestionerrores.h $(DEFS) defsc.h \
                      funcionesauxiliares.h
	$(CC) $(CFLAGS) -c gestionerrores.c
	
gestionetiquetas.$(O) : gestionetiquetas.c gestionetiquetas.h $(DEFS) defsc.h \
                        gestionerrores.h gestionmemoria.h
	$(CC) $(CFLAGS) -c gestionetiquetas.c
	
gestionmemoria.$(O) : gestionmemoria.c gestionmemoria.h $(DEFS) defsc.h
	$(CC) $(CFLAGS) -c gestionmemoria.c
	
clean :
	$(BORRAR) ens2001.$(O) $(OBJECTS)
