

class nodo{

  private:

    unsigned int ID;
    nodo *padre;
    unsigned int profundidad;
    float heuristica;
    unsigned int coste;

  public:

    nodo(unsigned int ID_, nodo* padre_, unsigned int prof_, unsigned int heuristica_, unsigned int coste_);

    unsigned int get_ID();
    nodo* get_padre();
    unsigned int get_profundidad();
    unsigned int get_heuristica();
    unsigned int get_coste()

}
