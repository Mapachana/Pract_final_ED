INCLUDE = ./include
LIB     = ./lib
SRC	= ./src
OBJ	= ./obj
BIN	= ./bin


all : $(BIN)/diccionario $(BIN)/guiatlf

diccionario : $(BIN)/diccionario

guiatlf : $(BIN)/guiatlf

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*

# ************** Compilacion de modulos ********

$(BIN)/diccionario : $(OBJ)/usodiccionario.o $(INCLUDE)/diccionario.h
	g++ -std=c++11 -o $(BIN)/diccionario -I$(INCLUDE) $(OBJ)/usodiccionario.o 

$(OBJ)/usodiccionario.o : $(SRC)/usodiccionario.cpp $(INCLUDE)/diccionario.h
	g++ -c -std=c++11 -o $(OBJ)/usodiccionario.o -I$(INCLUDE) $(SRC)/usodiccionario.cpp

$(BIN)/guiatlf : $(OBJ)/miusoguia.o $(OBJ)/guiatlf.o
	g++ -std=c++11 -o $(BIN)/guiatlf -I$(INCLUDE) $(OBJ)/miusoguia.o $(OBJ)/guiatlf.o

$(OBJ)/miusoguia.o : $(SRC)/miusoguia.cpp $(INCLUDE)/guiatlf.h
	g++ -std=c++11 -c -o $(OBJ)/miusoguia.o -I$(INCLUDE) $(SRC)/miusoguia.cpp

$(OBJ)/guiatlf.o : $(SRC)/guiatlf.cpp $(INCLUDE)/guiatlf.h 
	g++ -std=c++11 -c -o $(OBJ)/guiatlf.o -I$(INCLUDE) $(SRC)/guiatlf.cpp



