
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Transicion.o Estado.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o unComment ${OBJS}

clean:
	rm -rf *.o *.txt unComment

