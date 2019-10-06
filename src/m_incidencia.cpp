#include "m_incidencia.hpp"
#include <fstream>





    m_incidencia::m_incidencia(std::string n_fichero): m_incidencia1(0), nodos (-1)
    {
      ifstream fichero;
      fichero.open(n_fichero);
      float y;

      if(!fichero){
        std::cout << "No se ha podido abrir el fichero." << std::cout;
        return exit(1);
      }

      fichero >> nodos;

      m_incidencia1.resize(nodos);

      for(unsigned int i = 0 ; i < nodos; i++){

        for(unsigned int j = i; j < nodos; j++){

          fichero >> y;
          if(y > 0){
            std::pair<unsigned int, float> dummy;
            dummy.first = j;
            dummy.second = y;
            m_incidencia1(i).push_back(dummy);
            dummy.first = i;
            m_incidencia1(j).push_back(dummy);

          }

        }

      }

      fichero.close();

    }
