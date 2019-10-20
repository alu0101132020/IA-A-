#pragma once

#include "grafo.hpp"
#include "nodo.hpp"
#include <list>

class Arbol{

  private:

    grafo G;

    std::vector<float> v_h;

    nodo* root;

    std::list<nodo> Generados;

    std::vector<nodo> Explorados;

  public:

    Arbol(std::string n_fichero);

    void change_heuris(std::string n_fichero);

    void A_star_search(unsigned int ini, unsigned int fin, std::string heur);

    nodo search(nodo N, unsigned int fin);

    void generar(nodo N);

    bool inspeccionar(nodo N, unsigned int fin);

    nodo seleccionar(void);

    std::vector<unsigned int> get_predecesores(nodo N);

};
