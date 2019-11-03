#include "Arbol.hpp"



    Arbol::Arbol(std::string n_fichero): G(n_fichero),  v_h(0), root(nullptr), n_generados(0), n_inspeccionados(0){
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
      fin --;                                                                                           //Se decrementan los índices para poder trabajar correctamente con la matriz de incidencia y se establece el número de nodos inspeccionados y generados a 0 (Aún no ha empezado la búsqueda)
      n_inspeccionados = 0;
      n_generados = 0;
      change_heuris(heur);
      nodo *Ini = new nodo(ini, root, 0, v_h.at(ini), 0);
      Generados.push_back(Ini);

      nodo *result = search(Ini, fin);                                                                //Ya establecido el nodo origen y las heurística, se llama a la función para relizar la búsqueda propiamente dicha

      mostrar_camino(result);
      sacar_a_fichero(result, ini, fin);
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
            n_generados ++;
          }
      }


    }

    bool Arbol::inspeccionar(nodo* &N, unsigned int fin){             //Se observa si el nodo N es el final y se suma  1 al número de nodos inspeccionados;
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
      n_inspeccionados ++;
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

    bool fexists(const std::string& filename) {
      std::ifstream ifile(filename.c_str());
      return (bool)ifile;
    }

    void Arbol::mostrar_camino(nodo* &N){                                           //Mostramos el camino, para ello cogemos el nodo final, hacemos el recorrido hasta la raíz del árbol y vamos almacenando los nodos en una pila para después mostrar el camino inverso (desde el inicio hasta el final).
      std::stack<nodo*> Pila;
      nodo* naux = N;
      float coste = 0;
      while(naux->get_padre() != nullptr){
          Pila.push(naux);
          naux = naux->get_padre();
      }
      Pila.push(naux);
      naux = naux->get_padre();
      std::cout << "Número de nodos:" << G.get_nodos() << std::endl;
      std::cout << "Número de aristas:" << G.get_aristas() << std::endl;
      std::cout << "El camino es: ";
      while(!Pila.empty()){
        naux = Pila.top();
        Pila.pop();
        std::cout << naux->get_ID() + 1 << " -> ";
      }
      coste = naux->get_coste();
      std::cout << "Destino" << std::endl;

      std::cout << "Con coste " << coste << "unidades." << std::endl;
      std::cout << "Número de nodos generados: " << n_generados << ".\nNúmero de nodos inspeccionados: " << n_inspeccionados << ".\n";
    }


    void Arbol::sacar_a_fichero(nodo* &N, unsigned int ini, unsigned int fin){
      std::string n_fichero = "Export2.txt";
      std::ofstream fichero;
      if(!fexists(n_fichero)) {
        fichero.open(n_fichero);
        fichero << "Nodos" << "\t";
        fichero << "Aristas" << "\t";
        fichero << "N_Ini" << "\t";
        fichero << "N_Fin" << "\t";
        fichero << "Camino" << "\t\t\t\t\t";
        fichero << "Distancia" << "\t";
        fichero << "N_Generados" << "\t";
        fichero << "N_Inspeccionados" << "\t" << std::endl;
        fichero.close();
      }

      fichero.open(n_fichero, std::ios::app);
      std::stack<nodo*> Pila;
      nodo* naux = N;
      float coste = 0;
      while(naux->get_padre() != nullptr){
          Pila.push(naux);
          naux = naux->get_padre();
      }
      Pila.push(naux);
      naux = naux->get_padre();
      fichero << G.get_nodos() ;
      fichero << "\t";
      fichero << G.get_aristas();
      fichero << "\t";
      fichero << ini << "\t";
      fichero << fin << "\t";

      while(!Pila.empty()){
        naux = Pila.top();
        Pila.pop();
        fichero << naux->get_ID() + 1 << " -> ";
      }
      coste = naux->get_coste();


      fichero << "\t";
      fichero << coste;
      fichero << "\t";
      fichero << n_generados;
      fichero << "\t";
      fichero << n_inspeccionados;
      fichero << "\n";

    }
