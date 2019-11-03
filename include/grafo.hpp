#pragma once

#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

class grafo
{

    private:

    std::vector<std::vector<std::pair<unsigned int, float> > > m_incidencia;

    unsigned int nodos;

    unsigned int aristas;

    public:

    grafo(std::string);

    ~grafo();

    std::ostream& write(std::ostream& os);

    unsigned int get_nodos(void);

    std::vector<std::pair<unsigned int, float> > get_v_sucesores(int i);

    friend std::ostream& operator<<(std::ostream& os, grafo G)
    {
        G.write(os);
        return os;
    }

    unsigned int get_aristas(void);

};
