#include "NodoPersona.hpp"

template<typename T>

NodoPersona<T>::NodoPersona(T persona, int id, int contador ){
    persona = persona;
    id = id;
    contador = contador;
    next = null;
}

template<typename T>
void NodoPersona<T>::eliminar_todo(){
    if(next)
        next->eliminar_todo();
    delete this;
}
template<typename T>
void NodoPersona<T>::print(){
    cout<< "NodoPersona ->"<< "id: "<< id << "contador: "<< contador<<; 
}
