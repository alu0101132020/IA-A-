#include <iostream>
#include "Arbol.hpp"
#include <chrono>

bool inspeccionar(nodo N, unsigned int fin){             //Se observa si el nodo N es el final.
  return (N.get_ID() == fin);
}

int main(int argc, char **argv) {
  if (argc == 3){

    std::string cadena = argv[1];

    std::string heur = argv[2];

    Arbol B(cadena);

    std::cout << B.G;

    auto start = std::chrono::high_resolution_clock::now();
    B.A_star_search(1, 8, heur);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nTiempo ejecutando: " << duration.count() << "microsegundos\n\n";

  }
  else{
    std::cout << "Introduzca dos ficheros válido." << std::endl;
  }

  return 0;
}
