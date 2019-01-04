INC = ./include
LIB     = ./lib
SRC	= ./src
OBJ	= ./obj
BIN	= ./bin


all : $(BIN)/testdiccionario $(BIN)/cantidad_letras $(BIN)/letras

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/letras.doxy

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f -r $(BIN)/* ./doc/html/* ./doc/latex/*

# ************** Compilacion de modulos ********

$(BIN)/testdiccionario : $(OBJ)/Diccionario.o $(INC)/Diccionario.h $(SRC)/testdiccionario.cpp
	g++ -std=c++11 -o $(BIN)/testdiccionario -I$(INC) $(SRC)/testdiccionario.cpp  $(OBJ)/Diccionario.o

$(BIN)/cantidad_letras : $(OBJ)/Diccionario.o $(INC)/Diccionario.h $(SRC)/cantidad_letras.cpp
	g++ -std=c++11 -o $(BIN)/cantidad_letras -I$(INC) $(SRC)/cantidad_letras.cpp $(OBJ)/Diccionario.o

$(BIN)/letras : $(OBJ)/Diccionario.o $(INC)/Diccionario.h $(OBJ)/Bolsa_Letras.o $(INC)/Bolsa_Letras.h $(OBJ)/Letra.o $(INC)/Letra.h $(SRC)/letras.cpp
	g++ -std=c++11 -o $(BIN)/letras -I$(INC) $(SRC)/letras.cpp $(OBJ)/Diccionario.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INC)/Diccionario.h
	g++ -std=c++11 -c -o $(OBJ)/Diccionario.o -I$(INC) $(SRC)/Diccionario.cpp

$(OBJ)/Bolsa_Letras.o : $(SRC)/Bolsa_Letras.cpp $(INC)/Bolsa_Letras.h $(OBJ)/Letra.o $(OBJ)/Diccionario.o
	g++ -std=c++11 -c -o $(OBJ)/Bolsa_Letras.o -I$(INC) $(SRC)/Bolsa_Letras.cpp

$(OBJ)/Letra.o : $(SRC)/Letra.cpp $(INC)/Letra.h
	g++ -std=c++11 -c -o $(OBJ)/Letra.o -I$(INC) $(SRC)/Letra.cpp



