IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

.PHONY: all

_OBJ = main.o grafo.o Arbol.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: A*_search

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/grafo.hpp $(IDIR)/Arbol.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grafo.o: $(ODIR)/grafo.cpp $(IDIR)/grafo.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/Arbol.o: $(ODIR)/Arbol.cpp $(IDIR)/Arbol.hpp $(IDIR)/grafo.hpp
	$(CC) -c -o $@ $< $(CFLAGS)


A*_search: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)




.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./A*_search
