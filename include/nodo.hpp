

class nodo{

  private:

    unsigned int ID;
    nodo *padre;
    unsigned int profundidad;
    float heuristica;
    unsigned int coste;

  public:

    nodo();

    int get_ID();
    nodo* get_padre();
    int get_profundidad();
    int get_heuristica();
    int get_coste()

}
