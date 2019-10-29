#include "Arbol.hpp"



    Arbol::Arbol(std::string n_fichero): G(n_fichero),  v_h(0), root(nullptr){
    }

    void Arbol::change_heuris(std::string n_fichero){                                             //Método para dado un fichero preparar el vector de heurística
      v_h.clear();
      std::ifstream fichero;
      fichero.open(n_fichero);
      float cost;
      int nodos;

      if(!fichero)
        std::cout << "No se ha podido abrir el fichero." << std::endl;

      else{
          fichero >> nodos;
          v_h.resize(nodos);

          for(unsigned int i = 0 ; i < v_h.size(); i++){
              fichero >> cost;
              if(cost >= 0)
                  v_h.at(i) = cost;
                  else
                  v_h.at(i) = FLT_MAX;
          }

          fichero.close();

        }
    }

    void Arbol::A_star_search(unsigned int ini, unsigned int fin, std::string heur){                        //Se inicializa la búsqueda, poniendo el nodo de inicio, el final, y cargando el fichero de heurística.
      ini --;
      fin --;
      change_heuris(heur);
      nodo *Ini = new nodo(ini, root, 0, v_h.at(ini), 0);
      Generados.push_back(Ini);

      nodo *result = search(Ini, fin);
      // // std::cout << result.get_ID();
      mostrar_camino(result);

    }

    nodo* Arbol::search(nodo* &N, unsigned int fin){
      while(!inspeccionar(N, fin)){                //Compruebo si el nodo es el final, si no, genero sus suscesores.

        for(std::list<nodo*>::iterator it = Generados.begin(); it != Generados.end(); ++it){             //Quito el nodo de la lista de hojas.
            if ((*(*it)).get_ID() == (*N).get_ID()){
                Generados.erase(it);
                break;
              }
        }

        generar(N);

        N = seleccionar();            //Selecciono entre las hojas la más prometedora.
        }
      return N;
    }


    void Arbol::generar(nodo* &N){

                                          //Se generan los sucesores
      std::vector<std::pair<unsigned int, float> > aux = G.get_v_sucesores(N->get_ID());           //Se busca en el grafo los sucesores directos del nodo N
      std::vector<unsigned int> pred = get_predecesores(N);                           //Se obtiene el vector con los id de los antecesores de N



      for(int i = 0; i < aux.size(); i++){                              //Se eliminan de los posibles sucesores aquellos que son antecesores en el árbol de N
          bool antecesor = false;
          for(int j = 0; j < pred.size(); j++){
              if(aux.at(i).first == pred.at(j)){
                  antecesor = true;
                }
          }
          if (antecesor == false){
            nodo *nuevo = new nodo(aux.at(i).first, N, N->get_profundidad() + 1, v_h.at(aux.at(i).first), N->get_coste() + aux.at(i).second);
            Generados.push_back(nuevo);
          }
      }

                      //Se comprueba si los sucesores de N están entre los nodos prometedores (hojas),
            // bool notnew = false;                                       //si están y son mejores, son sustituidos, y si no están, se añaden como hojas.
            // if((N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first)) < Explorados.at(i).get_estimado()){
            //     nodo nuevo(aux.at(i).first, &N, N.get_profundidad() + 1, v_h.at(aux.at(i).first), N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) );
            //     Explorados.at(i) = nuevo;
            //     notnew =  true;

          /*for(std::list<nodo>::iterator it = Generados.begin(); it != Generados.end(); ++it){
              if((*it).get_ID() == aux.at(i).first){
                  notnew =  true;
                  if((*it).get_estimado() > (N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) ) ){
                    nodo nuevo(aux.at(i).first, &N, N.get_profundidad() + 1, v_h.at(aux.at(i).first), N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) );
                    (*it) = nuevo;
                  }
              }
          }*/
          // if (notnew == false){
          //     nodo nuevo(aux.at(i).first, &N, N.get_profundidad() + 1, v_h.at(aux.at(i).first), N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) );
          //     Generados.push_back(nuevo);
          // }
      // }

    }

    bool Arbol::inspeccionar(nodo* &N, unsigned int fin){             //Se observa si el nodo N es el final.
      return (N->get_ID() == fin);
    }

    nodo* Arbol::seleccionar(){                          //método para recorrer la lista de hojas y seleccionar la más prometedora.
      float min_coste = FLT_MAX;
      nodo *indice;
      std::list<nodo*>::iterator it;
      for( it = Generados.begin(); it != Generados.end(); ++it){
          if((*it)->get_estimado() < min_coste){
              min_coste = (*it)->get_estimado();
              indice = (*it);
            }
      }
      return indice;
    }

    std::vector<unsigned int> Arbol::get_predecesores(nodo* &N){                  //Recorrido hasta la raíz del árbol para obtener los ID's que conforman el camino.
      std::vector<unsigned int> pred;
      nodo* auxn = N;
      while(auxn->get_padre() != nullptr){
          unsigned int aux = auxn->get_padre()->get_ID();
          auxn = auxn->get_padre();
          pred.push_back(aux);
          }

      return pred;
    }

    void Arbol::mostrar_camino(nodo* &N){
      std::stack<nodo*> Pila;
      nodo* naux = N;
      float coste = 0;
      while(naux->get_padre() != nullptr){
          Pila.push(naux);
          naux = naux->get_padre();
      }
      Pila.push(naux);
      naux = naux->get_padre();

      std::cout << "El camino es: ";
      while(!Pila.empty()){
        naux = Pila.top();
        Pila.pop();
        std::cout << naux->get_ID() + 1 << " -> ";
      }
      coste = naux->get_coste();
      std::cout << "Destino" << std::endl;
      std::cout << "Con coste " << coste << "unidades." << std::endl;
    }
