#pragma once

#include "grafo.hpp"

class Arbol{

  private:

    grafo G;

    std::vector<float> v_h;

  public:

    Arbol(std::string n_fichero, std::string n_fichero2);
}
