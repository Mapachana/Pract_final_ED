INC = ./include
LIB     = ./lib
SRC	= ./src
OBJ	= ./obj
BIN	= ./bin


#all : $(BIN)/diccionario $(BIN)/guiatlf
all : $(OBJ)/Diccionario.o $(OBJ)/Letra.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(BIN)/testdiccionario $(BIN)/cantidad_letras $(BIN)/letras

# diccionario : $(BIN)/diccionario

# guiatlf : $(BIN)/guiatlf

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

# $(BIN)/diccionario : $(OBJ)/usodiccionario.o $(INC)/diccionario.h
#	g++ -std=c++11 -o $(BIN)/diccionario -I$(INC) $(OBJ)/usodiccionario.o 

# $(OBJ)/usodiccionario.o : $(SRC)/usodiccionario.cpp $(INC)/diccionario.h
#	g++ -c -std=c++11 -o $(OBJ)/usodiccionario.o -I$(INC) $(SRC)/usodiccionario.cpp

# $(BIN)/guiatlf : $(OBJ)/miusoguia.o $(OBJ)/guiatlf.o
#	g++ -std=c++11 -o $(BIN)/guiatlf -I$(INC) $(OBJ)/miusoguia.o $(OBJ)/guiatlf.o

# $(OBJ)/miusoguia.o : $(SRC)/miusoguia.cpp $(INC)/guiatlf.h
#	g++ -std=c++11 -c -o $(OBJ)/miusoguia.o -I$(INC) $(SRC)/miusoguia.cpp

# $(OBJ)/guiatlf.o : $(SRC)/guiatlf.cpp $(INC)/guiatlf.h 
#	g++ -std=c++11 -c -o $(OBJ)/guiatlf.o -I$(INC) $(SRC)/guiatlf.cpp

$(BIN)/testdiccionario : $(OBJ)/Diccionario.o $(INC)/Diccionario.h $(SRC)/testdiccionario.cpp
	g++ -std=c++11 -o $(BIN)/testdiccionario -I$(INC) $(SRC)/testdiccionario.cpp  $(OBJ)/Diccionario.o

$(BIN)/cantidad_letras : $(OBJ)/Diccionario.o $(INC)/Diccionario.h $(SRC)/cantidad_letras.cpp
	g++ -std=c++11 -g -o $(BIN)/cantidad_letras -I$(INC) $(SRC)/cantidad_letras.cpp $(OBJ)/Diccionario.o

$(BIN)/letras : $(OBJ)/Diccionario.o $(INC)/Diccionario.h $(OBJ)/Bolsa_Letras.o $(INC)/Bolsa_Letras.h $(OBJ)/Letra.o $(INC)/Letra.h $(SRC)/letras.cpp
	g++ -std=c++11 -g -o $(BIN)/letras -I$(INC) $(SRC)/letras.cpp $(OBJ)/Diccionario.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letra.o

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INC)/Diccionario.h
	g++ -std=c++11 -g -c -o $(OBJ)/Diccionario.o -I$(INC) $(SRC)/Diccionario.cpp

$(OBJ)/Bolsa_Letras.o : $(SRC)/Bolsa_Letras.cpp $(INC)/Bolsa_Letras.h $(OBJ)/Conjunto_Letras.o $(OBJ)/Letra.o
	g++ -std=c++11 -c -o $(OBJ)/Bolsa_Letras.o -I$(INC) $(SRC)/Bolsa_Letras.cpp

$(OBJ)/Conjunto_Letras.o : $(SRC)/Conjunto_Letras.cpp $(INC)/Conjunto_Letras.h $(INC)/Letra.h
#$(OBJ)/Letra.o $(INC)/Letra.h
	g++ -std=c++11 -c -o $(OBJ)/Conjunto_Letras.o -I$(INC) $(SRC)/Conjunto_Letras.cpp

$(OBJ)/Letra.o : $(SRC)/Letra.cpp $(INC)/Letra.h
	g++ -std=c++11 -c -o $(OBJ)/Letra.o -I$(INC) $(SRC)/Letra.cpp





# Dependencias de las clases:
# Diccionario : -
# Letra : -
# Conjunto_Letras : Letra
# Bolsa_Letras : Conjunto_Letras


