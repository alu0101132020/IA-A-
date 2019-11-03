#include "grafo.hpp"




    grafo::grafo(std::string n_fichero): m_incidencia(0), nodos (-1)
    {
      aristas = 0;
      std::ifstream fichero;
      fichero.open(n_fichero);
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
                  aristas++;

              }

            }

          }

          fichero.close();

        }
    }

    unsigned int grafo::get_nodos(){
      return m_incidencia.size();
    }

    grafo::~grafo(){}


    std::ostream& grafo::write(std::ostream& os){

      for(unsigned int i = 0; i < nodos; i++){
          os << i << ": ";
          for (unsigned int j = 0; j < m_incidencia.at(i).size(); j++){
              os << "[" << m_incidencia.at(i).at(j).first << ", " << m_incidencia.at(i).at(j).second << " ] \t";
          }
          os << std::endl;
      }
      return os;
    }

    std::vector<std::pair<unsigned int, float> > grafo::get_v_sucesores(int i){
      return m_incidencia.at(i);
    }

    unsigned int grafo::get_aristas(){
      return aristas;
    }
