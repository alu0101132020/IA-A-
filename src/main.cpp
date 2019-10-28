#include <iostream>
#include "Arbol.hpp"

bool inspeccionar(nodo N, unsigned int fin){             //Se observa si el nodo N es el final.
  return (N.get_ID() == fin);
}

int main(/*int argc, char **argv*/) {
  // //if (argc == 2){
  //
    // std::string cadena = argv[1];

    std::string cadena = "Grafo1.txt";

    std::string heur = "Grafo1Heuristica1.txt";

    Arbol B(cadena);

    std::cout << B.G;


    B.A_star_search(1, 8, heur);
  //
  // }
  // else{
  //   std::cout << "Introduzca un fichero válido." << std::endl;
  // }

  return 0;
}



// nodo Ini(1, nullptr, 0, 0, 0);
// std::list<nodo> Generados;
// nodo sec(3, nullptr, 0, 0, 0);
// nodo third(5, nullptr, 0, 0, 0);
// Generados.push_back(Ini);
// Generados.push_back(sec);
// Generados.push_back(third);
// while(!inspeccionar((*Generados.begin()), 4)){
//   std::cout << "El nodo " << (*Generados.begin()).get_ID() << " va a ser destruido.";                //Compruebo si el nodo es el final, si no, genero sus suscesores.
// Generados.erase(Generados.begin());
//        }
//        std::cout << "El nodo restante es " << (*Generados.begin()).get_ID() << "." << std::endl;
