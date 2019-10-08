#pragma once

#include "grafo.hpp"

class Arbol{

  private:

    grafo G;

    std::vector<float> heuri;

  public:

    Arbol(std::string n_fichero1, std::string n_fichero2);
};
