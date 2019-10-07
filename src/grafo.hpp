#pragma once

#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <iostream>

class grafo
{

    private:

    std::vector<std::vector<std::pair<unsigned int, float> > > m_incidencia;

    unsigned int nodos;

    public:

    grafo(std::string);


    void write(void);

};
