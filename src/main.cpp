#include <iostream>
#include "Arbol.hpp"

int main(int argc, char **argv) {
  //if (argc == 2){

    // std::string cadena = argv[1];


    std::string cadena = "Grafo2.txt";

    std::string heur = "Grafo2Heuristica1.txt";

    Arbol B(cadena);

    B.A_star_search(1, 2, heur);
  //
  // }
  // else{
  //   std::cout << "Introduzca un fichero válido." << std::endl;
  // }
  return 0;
}
