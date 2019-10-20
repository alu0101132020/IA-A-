#include "Arbol.hpp"



    Arbol::Arbol(std::string n_fichero): G(n_fichero),  v_h(0){
      Explorados.resize(G.get_nodos());

    }

    void Arbol::change_heuris(std::string n_fichero){                                             //Método para dado un fichero preparar el vector de heurística
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
                  v_h.push_back(FLT_MAX);
          }

          fichero.close();

        }
    }

    void Arbol::A_star_search(unsigned int ini, unsigned int fin, std::string heur){                        //Se inicializa la búsqueda, poniendo el nodo de inicio, el final, y cargando el fichero de heurística.
      change_heuris(heur);
      nodo Ini(ini, root, 0, v_h.at(ini), 0);
      Generados.push_back(Ini);
      nodo result = search(Ini, fin);
    }

    nodo Arbol::search(nodo N, unsigned int fin){
      for(std::list<nodo>::iterator it = Generados.begin(); it != Generados.end(); ++it){             //Quito el nodo de la lista de hojas.
          if ((*it).get_ID() == N.get_ID())
              Generados.erase(it);
      }
      if(!inspeccionar(N, fin)){                //Compruebo si el nodo es el final, si no, genero sus suscesores.
          generar(N);
          Explorados.at(N.get_ID()) = N;

          nodo next = seleccionar();            //Sekecciono entre las hojas la más prometedora.
          search(next, fin);
      }
      return N;
    }

    void Arbol::generar(nodo N){                                          //Se generan los sucesores
      int id = N.get_ID();

      std::vector<std::pair<unsigned int, float> > aux = G.get_v_sucesores(id);           //Se busca en el grafo los sucesores directos del nodo N
      std::vector<unsigned int> pred = get_predecesores(N);                           //Se obtiene el vector con los id de los antecesores de N
      for(int i = 0; i < aux.size(); i++){                              //Se eliminan de los posibles sucesores aquellos que son antecesores en el árbol de N
          for(int j = 0; j < pred.size(); j++){
              if(aux.at(i).first == pred.at(j))
                  aux.erase(aux.begin() + i);
          }
      }


      for(int i = 0; i < aux.size(); i++){                          //Se comprueba si los sucesores de N están entre los nodos prometedores (hojas),
          bool notnew = false;                                       //si están y son mejores, son sustituidos, y si no están, se añaden como hojas.
          for(std::list<nodo>::iterator it = Generados.begin(); it != Generados.end(); ++it){
              if((*it).get_ID() == aux.at(i).first){
                  notnew =  true;
                  if((*it).get_estimado() > (N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) ) ){
                    nodo nuevo(aux.at(i).first, &N, N.get_profundidad() + 1, v_h.at(aux.at(i).first), N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) );
                    (*it) = nuevo;
                  }
              }
          }
          if (notnew == false){
              nodo nuevo(aux.at(i).first, &N, N.get_profundidad() + 1, v_h.at(aux.at(i).first), N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) );
              Generados.push_back(nuevo);
          }
      }

    }

    bool Arbol::inspeccionar(nodo N, unsigned int fin){             //Se observa si el nodo N es el final.
      return (N.get_ID() == fin);
    }

    nodo Arbol::seleccionar(){                          //método para recorrer la lista de hojas y seleccionar la más prometedora.
      float min_coste = FLT_MAX;
      nodo indice;

      for(std::list<nodo>::iterator it = Generados.begin(); it != Generados.end(); ++it){
          if((*it).get_coste() < min_coste)
              min_coste = (*it).get_coste();
              indice = (*it);
      }

      return indice;
    }

    std::vector<unsigned int> Arbol::get_predecesores(nodo N){                  //Recorrido hasta la raíz del árbol para obtener los ID's que conforman el camino.
      std::vector<unsigned int> pred;
      while(N.get_profundidad() > 0){
          unsigned int aux = N.get_padre().get_ID();
          N = N.get_padre();
          pred.push_back(aux);
          }
      return pred;
    }
