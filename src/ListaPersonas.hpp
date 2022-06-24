#ifndef LISTAPERSONAS_H
#define LISTAPERSONAS_H

#include <iostream>

#include "NodoPersona.hpp"
#include "NodoPersona.cpp"
using namespace std;

template <class T>
class ListaPersonas{
    private:
        NodoPersona<T> *head;
        int cantNodos;
    public:
        ListaPersonas():
        ~ListaPersonas();

        void add_primero(T);
        //void add_final(T)
        void del_dato(T);
        T buscar(T);
        void print();
        bool isEmpty();
};
#endif
