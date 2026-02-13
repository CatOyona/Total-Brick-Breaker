BIN = bin
EXEC = $(BIN)/executable.out
SRC = src
OBJ = obj

all: $(EXEC)

$(EXEC): $(OBJ)/main.o $(OBJ)/Level.o $(OBJ)/Ball.o $(OBJ)/Game.o
	g++ -g $(OBJ)/main.o $(OBJ)/Level.o $(OBJ)/Ball.o $(OBJ)/Game.o -o $(EXEC) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/Game.h
	g++ -g -Wall -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/Level.o: $(SRC)/Level.cpp $(SRC)/Level.h
	g++ -g -Wall -c $(SRC)/Level.cpp -o $(OBJ)/Level.o

$(OBJ)/Ball.o: $(SRC)/Ball.cpp $(SRC)/Ball.h $(SRC)/Level.h
	g++ -g -Wall -c $(SRC)/Ball.cpp -o $(OBJ)/Ball.o

$(OBJ)/Game.o: $(SRC)/Game.cpp $(SRC)/Game.h $(SRC)/Level.h $(SRC)/Ball.h
	g++ -g -Wall -c $(SRC)/Game.cpp -o $(OBJ)/Game.o

clean:
	rm -f *.o

veryclean: clean
	rm -f $(EXEC)