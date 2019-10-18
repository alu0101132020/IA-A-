#include "nodo.hpp"

  nodo::nodo(unsigned int ID_, nodo* padre_, unsigned int prof_, float heuristica_, unsigned int coste_): ID(ID_), profundidad(prof_), heuristica(heuristica_), coste(coste_){
    padre = padre_;
  }

  unsigned int nodo::get_ID(){
    return ID;
  }

  nodo* nodo::get_padre(){
    return padre;
  }

  unsigned int nodo::get_profundidad(){
    return profundidad;
  }

  unsigned int nodo::get_heuristica(){
    return heuristica;
  }

  unsigned int nodo::get_coste(){
    return coste;
  }
