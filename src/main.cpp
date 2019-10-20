#include <iostream>
#include "Arbol.hpp"

int main(int argc, char **argv) {
  if (argc == 2){

    std::string cadena = argv[1];

    Arbol B(cadena);

  }
  else{
    std::cout << "Introduzca un fichero válido." << std::endl;
  }
  return 0;
}
