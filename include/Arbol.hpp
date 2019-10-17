#pragma once

#include "grafo.hpp"
#include "nodo.hpp"

class Arbol{

  private:

    grafo G;

    std::vector<float> v_h;

    nodo* root;

  public:

    Arbol(std::string n_fichero);

    void change_heuris(std::string n_fichero);

    void A_star_search(unsigned int ini, unsigned int fin, std::string heur);
};
