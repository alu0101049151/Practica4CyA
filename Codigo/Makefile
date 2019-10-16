
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Transicion.o Estado.o Automata.o Eliminador.o mainUnComment.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o unComment ${OBJS}

clean:
	rm -rf *.o *.txt unComment

