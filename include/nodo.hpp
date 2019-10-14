

class nodo{

  private:

    int ID;
    nodo *padre;
    int profundidad;
    int heuristica;
    int coste;

  public:

    nodo();

    int get_ID();
    nodo* get_padre();
    int get_profundidad();
    int get_heuristica();
    int get_coste()

}
