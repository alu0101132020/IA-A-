#include <iostream>
#include "Arbol.hpp"
#include <chrono>


int main(int argc, char **argv) {
  if (argc == 3){
    int par1, par2;

    std::string cadena = argv[1];

    std::string heur = argv[2];

    std::cout << "Introduzca el nodo inicial: ";

    std::cin >> par1;

    std::cout << "Introduzca el nodo final: ";

    std::cin >> par2;

    Arbol B(cadena);

    if(0 < (par1 && par2) && (par1 && par2) <= B.G.get_nodos()){

        auto start = std::chrono::high_resolution_clock::now();
        B.A_star_search(par1, par2, heur);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "\nTiempo ejecutando: " << duration.count() << "microsegundos\n\n";
    }
    else{
        std::cout << "Esos parámetros están fuera del rango.\n";
    }

  }
  else{
    std::cout << "Introduzca dos ficheros válido." << std::endl;
  }

  return 0;
}



    //std::cout << B.G;
