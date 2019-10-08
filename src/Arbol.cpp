#include "Arbol.hpp"



Arbol::Arbol(std::string n_fichero1, std::string n_fichero2): G(n_fichero1)
{
  std::ifstream fichero;
  fichero.open(n_fichero2);
  float cost;

  if(!fichero){
    std::cout << "No se ha podido abrir el fichero." << std::endl;
  }
  else{

      fichero >> nodos;

      m_incidencia.resize(nodos);

      for(unsigned int i = 0 ; i < nodos - 1; i++){

        for(unsigned int j = i + 1; j < nodos; j++){

          fichero >> cost;
          if(cost > 0){
            std::pair<unsigned int, float> dummy;
            dummy.first = j;
            dummy.second = cost;
            m_incidencia.at(i).push_back(dummy);
            dummy.first = i;
            m_incidencia.at(j).push_back(dummy);

          }

        }

      }

      fichero.close();

    }
  }
