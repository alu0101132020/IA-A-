#pragma once
#include <climits>
#include <cfloat>
#include <vector>

class nodo{

  private:

    unsigned int ID;
    nodo *padre;
    unsigned int profundidad;
    float heuristica;
    float coste;

  public:

    nodo(unsigned int ID_, nodo *padre_, unsigned int prof_, float heuristica_, float coste_);
    nodo(void);

    unsigned int get_ID();
    nodo* get_padre();
    unsigned int get_profundidad();
    float get_heuristica();
    float get_coste();
    float get_estimado();

};
