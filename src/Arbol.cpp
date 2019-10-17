#include "Arbol.hpp"



    Arbol::Arbol(std::string n_fichero): G(n_fichero),  v_h(0){}

    void Arbol::change_heuris(std::string n_fichero){
      v_h.clear();
      std::ifstream fichero;
      fichero.open(n_fichero);
      float cost;

      if(!fichero)
        std::cout << "No se ha podido abrir el fichero." << std::endl;

      else{

          for(unsigned int i = 0 ; i < v_h.size(); i++){
              fichero >> cost;
              if(cost > 0)
                  v_h.push_back(cost);
                  else
                  v_h.push_back(-1);
          }

          fichero.close();

        }
    }

    void Arbol::A_star_search(unsigned int ini, unsigned int fin, std::string heur){
      change_heuris(heur);
      nodo Ini(ini, root, 0, v_h.at(ini), 0);

    }
