#include "grafo.hpp"




    grafo::grafo(std::string n_fichero): m_incidencia(0), nodos (-1)
    {
      std::ifstream fichero;
      fichero.open(n_fichero);
      float y;

      if(!fichero){
        std::cout << "No se ha podido abrir el fichero." << std::endl;
      }
      else{

        fichero >> nodos;

        m_incidencia.resize(nodos);

        for(unsigned int i = 0 ; i < nodos - 1; i++){

          for(unsigned int j = i + 1; j < nodos; j++){

            fichero >> y;
            if(y > 0){
              std::pair<unsigned int, float> dummy;
              dummy.first = j;
              dummy.second = y;
              m_incidencia.at(i).push_back(dummy);
              dummy.first = i;
              m_incidencia.at(j).push_back(dummy);

            }

          }

        }

      fichero.close();

      }
    }



    void grafo::write(){

      for(unsigned int i = 0; i < nodos; i++){
          std::cout << i + 1 << ": ";
          for (unsigned int j = 0; j < m_incidencia.at(i).size(); j++){
              std::cout << m_incidencia.at(i).at(j).first + 1 << " ";
          }
          std::cout << std::endl;
      }
    }
