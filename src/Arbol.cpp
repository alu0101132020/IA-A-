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
                  v_h.push_back(FLT_MAX);
          }

          fichero.close();

        }
    }

    void Arbol::A_star_search(unsigned int ini, unsigned int fin, std::string heur){
      change_heuris(heur);
      nodo Ini(ini, root, 0, v_h.at(ini), 0);
      Generados.push_back(Ini);
      nodo result = search(Ini, fin);
    }

    nodo Arbol::search(nodo N, unsigned int fin){
      if(!inspeccionar(N, fin)){
          generar(N);

          unsigned int next = seleccionar();
          search(Generados.at(next), fin);
      }
      return N;
    }

    void Arbol::generar(nodo N){
      int id = N.get_ID();

      std::vector<std::pair<unsigned int, float> > aux = G.get_v_sucesores(id);

      for(int i = 0; i <  aux.size(); i++){
          bool notnew = false;
          for(int j = 0; j < Generados.size(); j++){
              if(Generados.at(j).get_ID() == aux.at(i).first){
                  notnew =  true;
                  if(Generados.at(j).get_estimado() > (N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) ) ){
                    nodo nuevo(aux.at(i).first, &N, N.get_profundidad() + 1, v_h.at(aux.at(i).first), N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) );
                    Generados.at(j) = nuevo;
                  }
              }
          }
          if (notnew == false){
              nodo nuevo(aux.at(i).first, &N, N.get_profundidad() + 1, v_h.at(aux.at(i).first), N.get_coste() + aux.at(i).second + v_h.at(aux.at(i).first) );
              Generados.push_back(nuevo);
          }
      }

    }

    bool Arbol::inspeccionar(nodo N, unsigned int fin){
      return (N.get_ID() == fin);
    }

    unsigned int Arbol::seleccionar(){
      float min_coste = FLT_MAX;
      unsigned int indice = -1;

      for(int i = 0; i < Generados.size(); i++){
          if(Generados.at(i).get_coste() < min_coste)
              min_coste = Generados.at(i).get_coste();
              indice = i;
      }

      return indice;
    }
