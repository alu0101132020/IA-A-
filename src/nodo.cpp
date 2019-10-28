#include "nodo.hpp"

  nodo::nodo(unsigned int ID_, nodo* padre_, unsigned int prof_, float heuristica_, float coste_): ID(ID_), padre(padre_), profundidad(prof_), heuristica(heuristica_), coste(coste_){
  }

  nodo::nodo(void): ID(-1), profundidad(-1), heuristica(FLT_MAX), coste(FLT_MAX){
    padre = nullptr;
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

  float nodo::get_heuristica(){
    return heuristica;
  }

  float nodo::get_coste(){
    return coste;
  }

  float nodo::get_estimado(){
    return coste + heuristica;
  }
