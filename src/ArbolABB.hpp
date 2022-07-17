#include "ArbolABB.hpp"
#include <stack>
using namespace std;

void ArbolABB::Insertar(const int dat){
    Nodo *padre = nullptr;
    actual = raiz;
    while (!Vacio(actual) && dat != actual->dato){
        padre = actual;
        if(dat > actual->dato) actual = actual->der;
        else if(dat < actual->dato) actual = actual->izq;
    }
    
    if(!Vacio(actual)) return;

    if(Vacio(padre)) raiz = new Nodo(dat);
    else if(dat < padre->dato) padre->izq = new Nodo(dat);
    else if(dat > padre->dato) padre->der = new Nodo(dat);
}
int ArbolABB::NumeroNodosIzq(){
    contador = 0;
    auxContador(raiz->izq);
    return contador;
}
void ArbolABB::auxContador(Nodo *nodo){
    contador++;
    if(nodo->izq) auxContador(nodo->izq);
    if(nodo->der) auxContador(nodo->der);
}
int ArbolABB::NumeroNodosDer(){
    contador = 0;
    auxContador(raiz->der);
    return contador;
}



