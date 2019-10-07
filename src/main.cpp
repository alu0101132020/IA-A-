#include <iostream>
#include "grafo.hpp"

int main(int argc, char **argv) {
  if (argc == 2){

    std::string cadena = argv[1];

    grafo A(cadena);

    A.write();

  }
  return 0;
}
