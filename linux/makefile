# makefile para ens2001, version 1.0

# Docker image name
DOCKER_IMAGE = ens2001-build

# Docker command to run tools
DOCKER = docker run --rm -v $(PWD):/app -w /app $(DOCKER_IMAGE)

# Compiler and tools through Docker
CC++ = $(DOCKER) c++ -std=c++98
CC = $(DOCKER) cc
FLEX = $(DOCKER) flex
BISON = $(DOCKER) bison
MOVER = $(DOCKER) mv
BORRAR = $(DOCKER) rm -f

# Directories
SRC = src
OUT = out
ENS2001 = ens2001
O = o

# Default target
all: dirs $(ENS2001)

# Create output directory
dirs:
	mkdir -p $(OUT)

# Create Docker image for building
docker-image:
	@echo "Building Docker image..."
	@docker inspect $(DOCKER_IMAGE) >/dev/null 2>&1 || docker build -t $(DOCKER_IMAGE) -f Dockerfile .

# Object files with paths
OBJECTS = $(OUT)/cconfiguracion.$(O) $(OUT)/cmemoria.$(O) $(OUT)/cbancoregistros.$(O) \
          $(OUT)/cprocesador.$(O) $(OUT)/cinstruccion.$(O) $(OUT)/cgestorinstrucciones.$(O) \
          $(OUT)/centero16b.$(O) $(OUT)/centradasalida.$(O) $(OUT)/cinterfazconsola.$(O) \
          $(OUT)/cdesensamblador.$(O) $(OUT)/cinterfazdisco.$(O) $(OUT)/cgestorpuntosruptura.$(O) \
          $(OUT)/censamblador.$(O) $(OUT)/ccadena.$(O) $(OUT)/ens_lex.$(O) $(OUT)/ens_tab.$(O) \
          $(OUT)/funcionesauxiliares.$(O) $(OUT)/gestionerrores.$(O) $(OUT)/gestionetiquetas.$(O) \
          $(OUT)/gestionmemoria.$(O)

DEFS = $(SRC)/definiciones.h $(SRC)/cadenas_ansi.h $(SRC)/cadenas_ascii.h $(SRC)/compilacion.h

$(ENS2001): docker-image $(SRC)/ens2001.cpp $(OBJECTS)
	$(CC++) -o$(ENS2001) $(SRC)/ens2001.cpp $(OBJECTS)

$(OUT)/cconfiguracion.$(O): docker-image $(SRC)/cconfiguracion.cpp $(SRC)/cconfiguracion.h $(DEFS) $(SRC)/defscpp.h \
                      $(SRC)/cmemoria.h $(SRC)/cbancoregistros.h $(SRC)/cprocesador.h \
                      $(SRC)/cgestorpuntosruptura.h
	$(CC++) -c $(SRC)/cconfiguracion.cpp -o $(OUT)/cconfiguracion.$(O)

$(OUT)/cmemoria.$(O): docker-image $(SRC)/cmemoria.cpp $(SRC)/cmemoria.h $(DEFS) $(SRC)/defscpp.h $(SRC)/cconfiguracion.h
	$(CC++) -c $(SRC)/cmemoria.cpp -o $(OUT)/cmemoria.$(O)

$(OUT)/cbancoregistros.$(O): docker-image $(SRC)/cbancoregistros.cpp $(SRC)/cbancoregistros.h $(DEFS) $(SRC)/defscpp.h \
                       $(SRC)/cconfiguracion.h
	$(CC++) -c $(SRC)/cbancoregistros.cpp -o $(OUT)/cbancoregistros.$(O)

$(OUT)/cprocesador.$(O): docker-image $(SRC)/cprocesador.cpp $(SRC)/cprocesador.h $(DEFS) $(SRC)/defscpp.h
	$(CC++) -c $(SRC)/cprocesador.cpp -o $(OUT)/cprocesador.$(O)

$(OUT)/cinstruccion.$(O): docker-image $(SRC)/cinstruccion.cpp $(SRC)/cinstruccion.h $(DEFS) $(SRC)/defscpp.h \
                    $(SRC)/cconfiguracion.h $(SRC)/centradasalida.h
	$(CC++) -c $(SRC)/cinstruccion.cpp -o $(OUT)/cinstruccion.$(O)

$(OUT)/cgestorinstrucciones.$(O): docker-image $(SRC)/cgestorinstrucciones.cpp $(SRC)/cgestorinstrucciones.h \
                            $(DEFS) $(SRC)/defscpp.h $(SRC)/cinstruccion.h $(SRC)/cconfiguracion.h
	$(CC++) -c $(SRC)/cgestorinstrucciones.cpp -o $(OUT)/cgestorinstrucciones.$(O)

$(OUT)/centero16b.$(O): docker-image $(SRC)/centero16b.cpp $(SRC)/centero16b.h $(DEFS) $(SRC)/defscpp.h
	$(CC++) -c $(SRC)/centero16b.cpp -o $(OUT)/centero16b.$(O)

$(OUT)/centradasalida.$(O): docker-image $(SRC)/centradasalida.cpp $(SRC)/centradasalida.h $(DEFS) $(SRC)/defscpp.h \
                      $(SRC)/cconfiguracion.h
	$(CC++) -c $(SRC)/centradasalida.cpp -o $(OUT)/centradasalida.$(O)

$(OUT)/cinterfazconsola.$(O): docker-image $(SRC)/cinterfazconsola.cpp $(SRC)/cinterfazconsola.h $(DEFS) \
                        $(SRC)/defscpp.h $(SRC)/cconfiguracion.h $(SRC)/cdesensamblador.h \
                        $(SRC)/censamblador.h $(SRC)/cinterfazdisco.h $(SRC)/ens_tab.h
	$(CC++) -c $(SRC)/cinterfazconsola.cpp -o $(OUT)/cinterfazconsola.$(O)

$(OUT)/cdesensamblador.$(O): docker-image $(SRC)/cdesensamblador.cpp $(SRC)/cdesensamblador.h $(DEFS) $(SRC)/defscpp.h \
                       $(SRC)/cconfiguracion.h
	$(CC++) -c $(SRC)/cdesensamblador.cpp -o $(OUT)/cdesensamblador.$(O)

$(OUT)/cinterfazdisco.$(O): docker-image $(SRC)/cinterfazdisco.cpp $(SRC)/cinterfazdisco.h $(DEFS) $(SRC)/defscpp.h \
                      $(SRC)/cmemoria.h
	$(CC++) -c $(SRC)/cinterfazdisco.cpp -o $(OUT)/cinterfazdisco.$(O)

$(OUT)/cgestorpuntosruptura.$(O): docker-image $(SRC)/cgestorpuntosruptura.cpp $(SRC)/cgestorpuntosruptura.h \
                             $(DEFS) $(SRC)/defscpp.h $(SRC)/cconfiguracion.h $(SRC)/centero16b.h
	$(CC++) -c $(SRC)/cgestorpuntosruptura.cpp -o $(OUT)/cgestorpuntosruptura.$(O)

$(OUT)/censamblador.$(O): docker-image $(SRC)/censamblador.cpp $(SRC)/censamblador.h $(DEFS) $(SRC)/defscpp.h \
                    $(SRC)/cconfiguracion.h $(SRC)/ens_tab.h
	$(CC++) -c $(SRC)/censamblador.cpp -o $(OUT)/censamblador.$(O)

$(OUT)/ccadena.$(O): docker-image $(SRC)/ccadena.cpp $(SRC)/ccadena.h $(DEFS) $(SRC)/defscpp.h
	$(CC++) -c $(SRC)/ccadena.cpp -o $(OUT)/ccadena.$(O)

$(OUT)/ens_lex.$(O): docker-image $(SRC)/ens_lex.c $(SRC)/ens.l $(DEFS) $(SRC)/defsc.h $(SRC)/ens_tab.h $(SRC)/funcionesauxiliares.h \
               $(SRC)/gestionerrores.h
	$(CC) -c $(SRC)/ens_lex.c -o $(OUT)/ens_lex.$(O)

$(SRC)/ens_lex.c: docker-image $(SRC)/ens.l $(DEFS) $(SRC)/defsc.h $(SRC)/ens_tab.h $(SRC)/funcionesauxiliares.h \
            $(SRC)/gestionerrores.h
	$(FLEX) -8 -t $(SRC)/ens.l > $(SRC)/ens_lex.c

$(OUT)/ens_tab.$(O): docker-image $(SRC)/ens_tab.c $(SRC)/ens_tab.h $(SRC)/ens.y $(DEFS) $(SRC)/defsc.h $(SRC)/funcionesauxiliares.h \
               $(SRC)/gestionetiquetas.h $(SRC)/gestionerrores.h $(SRC)/gestionmemoria.h 
	$(CC) -c $(SRC)/ens_tab.c -o $(OUT)/ens_tab.$(O)

$(SRC)/ens_tab.c: docker-image $(SRC)/ens.y $(DEFS) $(SRC)/defsc.h $(SRC)/funcionesauxiliares.h \
            $(SRC)/gestionetiquetas.h $(SRC)/gestionerrores.h $(SRC)/gestionmemoria.h 
	cd $(SRC) && $(BISON) --defines $(SRC)/ens.y
	cd $(SRC) && $(MOVER) ens.tab.h ens_tab.h
	cd $(SRC) && $(MOVER) ens.tab.c ens_tab.c

$(SRC)/ens_tab.h: $(SRC)/ens_tab.c

$(OUT)/funcionesauxiliares.$(O): docker-image $(SRC)/funcionesauxiliares.c $(SRC)/funcionesauxiliares.h $(DEFS) \
                           $(SRC)/defsc.h
	$(CC) -c $(SRC)/funcionesauxiliares.c -o $(OUT)/funcionesauxiliares.$(O)

$(OUT)/gestionerrores.$(O): docker-image $(SRC)/gestionerrores.c $(SRC)/gestionerrores.h $(DEFS) $(SRC)/defsc.h \
                      $(SRC)/funcionesauxiliares.h
	$(CC) -c $(SRC)/gestionerrores.c -o $(OUT)/gestionerrores.$(O)

$(OUT)/gestionetiquetas.$(O): docker-image $(SRC)/gestionetiquetas.c $(SRC)/gestionetiquetas.h $(DEFS) $(SRC)/defsc.h \
                        $(SRC)/gestionerrores.h $(SRC)/gestionmemoria.h
	$(CC) -c $(SRC)/gestionetiquetas.c -o $(OUT)/gestionetiquetas.$(O)

$(OUT)/gestionmemoria.$(O): docker-image $(SRC)/gestionmemoria.c $(SRC)/gestionmemoria.h $(DEFS) $(SRC)/defsc.h
	$(CC) -c $(SRC)/gestionmemoria.c -o $(OUT)/gestionmemoria.$(O)

# Clean generated files
clean: docker-image
	$(BORRAR) $(ENS2001) $(OBJECTS)
	$(BORRAR) $(SRC)/ens_lex.c $(SRC)/ens_tab.c $(SRC)/ens_tab.h

# Force rebuild
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild dirs docker-image
