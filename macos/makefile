# makefile para ens2001, version 1.0

# MAC Universal Binary
CC++ = c++
MOVER = mv
BORRAR = rm
ENS2001 = ens2001
O = o
OUTDIR = out
CFLAGS += -std=gnu89 -Wno-implicit-function-declaration -arch arm64 -arch x86_64 -Isrc
CXXFLAGS += -std=c++98 -arch arm64 -arch x86_64 -Isrc

OBJECTS = $(OUTDIR)/cconfiguracion.$(O) $(OUTDIR)/cmemoria.$(O) $(OUTDIR)/cbancoregistros.$(O) \
          $(OUTDIR)/cprocesador.$(O) $(OUTDIR)/cinstruccion.$(O) $(OUTDIR)/cgestorinstrucciones.$(O) \
          $(OUTDIR)/centero16b.$(O) $(OUTDIR)/centradasalida.$(O) $(OUTDIR)/cinterfazconsola.$(O) \
          $(OUTDIR)/cdesensamblador.$(O) $(OUTDIR)/cinterfazdisco.$(O) $(OUTDIR)/cgestorpuntosruptura.$(O) \
          $(OUTDIR)/censamblador.$(O) $(OUTDIR)/ccadena.$(O) $(OUTDIR)/ens_lex.$(O) $(OUTDIR)/ens_tab.$(O) \
          $(OUTDIR)/funcionesauxiliares.$(O) $(OUTDIR)/gestionerrores.$(O) $(OUTDIR)/gestionetiquetas.$(O) \
          $(OUTDIR)/gestionmemoria.$(O) 

DEFS = src/definiciones.h src/cadenas_ansi.h src/cadenas_ascii.h src/compilacion.h

# Crear directorio de salida si no existe
$(shell mkdir -p $(OUTDIR))

$(ENS2001) : src/ens2001.cpp $(OBJECTS)
	$(CC++) $(CXXFLAGS) -o$(ENS2001) src/ens2001.cpp $(OBJECTS)
	
$(OUTDIR)/cconfiguracion.$(O) : src/cconfiguracion.cpp src/cconfiguracion.h $(DEFS) src/defscpp.h \
                      src/cmemoria.h src/cbancoregistros.h src/cprocesador.h \
                      src/cgestorpuntosruptura.h
	$(CC++) $(CXXFLAGS) -c src/cconfiguracion.cpp -o $(OUTDIR)/cconfiguracion.$(O)
	
$(OUTDIR)/cmemoria.$(O) : src/cmemoria.cpp src/cmemoria.h $(DEFS) src/defscpp.h src/cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c src/cmemoria.cpp -o $(OUTDIR)/cmemoria.$(O)
	
$(OUTDIR)/cbancoregistros.$(O) : src/cbancoregistros.cpp src/cbancoregistros.h $(DEFS) src/defscpp.h \
                       src/cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c src/cbancoregistros.cpp -o $(OUTDIR)/cbancoregistros.$(O)
	
$(OUTDIR)/cprocesador.$(O) : src/cprocesador.cpp src/cprocesador.h $(DEFS) src/defscpp.h
	$(CC++) $(CXXFLAGS) -c src/cprocesador.cpp -o $(OUTDIR)/cprocesador.$(O)
	
$(OUTDIR)/cinstruccion.$(O) : src/cinstruccion.cpp src/cinstruccion.h $(DEFS) src/defscpp.h \
                    src/cconfiguracion.h src/centradasalida.h
	$(CC++) $(CXXFLAGS) -c src/cinstruccion.cpp -o $(OUTDIR)/cinstruccion.$(O)
	
$(OUTDIR)/cgestorinstrucciones.$(O) : src/cgestorinstrucciones.cpp src/cgestorinstrucciones.h \
                            $(DEFS) src/defscpp.h src/cinstruccion.h src/cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c src/cgestorinstrucciones.cpp -o $(OUTDIR)/cgestorinstrucciones.$(O)	

$(OUTDIR)/centero16b.$(O) : src/centero16b.cpp src/centero16b.h $(DEFS) src/defscpp.h
	$(CC++) $(CXXFLAGS) -c src/centero16b.cpp -o $(OUTDIR)/centero16b.$(O)
	
$(OUTDIR)/centradasalida.$(O) : src/centradasalida.cpp src/centradasalida.h $(DEFS) src/defscpp.h \
                      src/cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c src/centradasalida.cpp -o $(OUTDIR)/centradasalida.$(O)
	
$(OUTDIR)/cinterfazconsola.$(O) : src/cinterfazconsola.cpp src/cinterfazconsola.h $(DEFS) \
                        src/defscpp.h src/cconfiguracion.h src/cdesensamblador.h \
                        src/censamblador.h src/cinterfazdisco.h src/ens_tab.h
	$(CC++) $(CXXFLAGS) -c src/cinterfazconsola.cpp -o $(OUTDIR)/cinterfazconsola.$(O)
	
$(OUTDIR)/cdesensamblador.$(O) : src/cdesensamblador.cpp src/cdesensamblador.h $(DEFS) src/defscpp.h \
                       src/cconfiguracion.h
	$(CC++) $(CXXFLAGS) -c src/cdesensamblador.cpp -o $(OUTDIR)/cdesensamblador.$(O)
	
$(OUTDIR)/cinterfazdisco.$(O) : src/cinterfazdisco.cpp src/cinterfazdisco.h $(DEFS) src/defscpp.h \
                      src/cmemoria.h
	$(CC++) $(CXXFLAGS) -c src/cinterfazdisco.cpp -o $(OUTDIR)/cinterfazdisco.$(O)
	
$(OUTDIR)/cgestorpuntosruptura.$(O) : src/cgestorpuntosruptura.cpp src/cgestorpuntosruptura.h \
                             $(DEFS) src/defscpp.h src/cconfiguracion.h src/centero16b.h
	$(CC++) $(CXXFLAGS) -c src/cgestorpuntosruptura.cpp -o $(OUTDIR)/cgestorpuntosruptura.$(O)
	
$(OUTDIR)/censamblador.$(O) : src/censamblador.cpp src/censamblador.h $(DEFS) src/defscpp.h \
                    src/cconfiguracion.h src/ens_tab.h
	$(CC++) $(CXXFLAGS) -c src/censamblador.cpp -o $(OUTDIR)/censamblador.$(O)

$(OUTDIR)/ccadena.$(O) : src/ccadena.cpp src/ccadena.h $(DEFS) src/defscpp.h
	$(CC++) $(CXXFLAGS) -c src/ccadena.cpp -o $(OUTDIR)/ccadena.$(O)
	
$(OUTDIR)/ens_lex.$(O) : src/ens_lex.c src/ens.l $(DEFS) src/defsc.h src/ens_tab.h src/funcionesauxiliares.h \
               src/gestionerrores.h
	$(CC) $(CFLAGS) -c src/ens_lex.c -o $(OUTDIR)/ens_lex.$(O)
	
src/ens_lex.c : src/ens.l $(DEFS) src/defsc.h src/ens_tab.h src/funcionesauxiliares.h \
            src/gestionerrores.h
	cd src && flex -8 -t ens.l > ens_lex.c
	 
$(OUTDIR)/ens_tab.$(O) : src/ens_tab.c src/ens_tab.h src/ens.y $(DEFS) src/defsc.h src/funcionesauxiliares.h \
               src/gestionetiquetas.h src/gestionerrores.h src/gestionmemoria.h 
	$(CC) $(CFLAGS) -c src/ens_tab.c -o $(OUTDIR)/ens_tab.$(O)
	
src/ens_tab.c : src/ens.y $(DEFS) src/defsc.h src/funcionesauxiliares.h \
            src/gestionetiquetas.h src/gestionerrores.h src/gestionmemoria.h 
	cd src && bison --defines ens.y
	cd src && $(MOVER) ens.tab.h ens_tab.h
	cd src && $(MOVER) ens.tab.c ens_tab.c
	
src/ens_tab.h : src/ens_tab.c
        	
$(OUTDIR)/funcionesauxiliares.$(O) : src/funcionesauxiliares.c src/funcionesauxiliares.h $(DEFS) \
                           src/defsc.h
	$(CC) $(CFLAGS) -c src/funcionesauxiliares.c -o $(OUTDIR)/funcionesauxiliares.$(O)
	
$(OUTDIR)/gestionerrores.$(O) : src/gestionerrores.c src/gestionerrores.h $(DEFS) src/defsc.h \
                      src/funcionesauxiliares.h
	$(CC) $(CFLAGS) -c src/gestionerrores.c -o $(OUTDIR)/gestionerrores.$(O)
	
$(OUTDIR)/gestionetiquetas.$(O) : src/gestionetiquetas.c src/gestionetiquetas.h $(DEFS) src/defsc.h \
                        src/gestionerrores.h src/gestionmemoria.h
	$(CC) $(CFLAGS) -c src/gestionetiquetas.c -o $(OUTDIR)/gestionetiquetas.$(O)
	
$(OUTDIR)/gestionmemoria.$(O) : src/gestionmemoria.c src/gestionmemoria.h $(DEFS) src/defsc.h
	$(CC) $(CFLAGS) -c src/gestionmemoria.c -o $(OUTDIR)/gestionmemoria.$(O)
	
clean :
	$(BORRAR) -f $(ENS2001)
	$(BORRAR) -rf $(OUTDIR)
