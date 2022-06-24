#ifndef NODEPERSONA_H
#define NODEPERSONA_H

#include <iostream>

using namespace std;

template <class T>

class NodoPersona
{
    
public:
    NodoPersona(T, int, int);
    ~NodoPersona();

    T persona;
    int id;
    int contador;
    NodoPersona *next;
    
    void eliminar_todo();
    void print();
};

#endif
