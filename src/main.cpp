#include <iostream>
#include "Arbol.hpp"

bool inspeccionar(nodo N, unsigned int fin){             //Se observa si el nodo N es el final.
  return (N.get_ID() == fin);
}

int main(int argc, char **argv) {
  if (argc == 3){
    
    std::string cadena = argv[1];

    std::string heur = argv[2];

    Arbol B(cadena);

    std::cout << B.G;


    B.A_star_search(1, 8, heur);

  }
  else{
    std::cout << "Introduzca dos ficheros válido." << std::endl;
  }

  return 0;
}
