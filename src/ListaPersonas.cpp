#include "ListaPersonas.hpp"

using namespace std;

template<typename T>

ListaPersonas<T>::ListaPersonas(){
    cantNodos = 0;
    head = NULL;
}
template<typename T>
void ListaPersonas<T>::add_primero(T persona){
    NodoPersona<T> *Nodo = new NodoPersona<T>(persona);
    NodoPersona<T> *aux =  head;

    if(!aux){
        head = Nodo;
    }else{
        Nodo->next = head;
        head = Nodo*;

        while(aux){
            aux=aux->next;
        }
    }
    cantNodos++;
}
template<typename T>
T ListaPersonas<T>::buscar(T persona_){
    NodoPersona<T> *aux = head;
    int cont = 1;
    int con2 = 0;

    while(aux){
        if(aux->persona = persona_ ){
            cout << "El dato se encontro en la posicion: " << cont << endl;
            cont2++;
            return persona_;
        }
        aux = aux->next;
        cont++;
    }
    if(cont2 == 0){
        cout << "El dato no existye" << endl;
    }
    return 0;
}
//aqui se debe calcular la distancia de los centros.

template<typename T>
void ListaPersonas<T>::print(){
    NodoPersona<T> *aux = head;
    if(!head){
        cout << "La lista esta vacia" << endl;
    }else{
        while(aux){
            aux->print();
            if(!aux->next) cout << "NULL";
            aux = aux->next;
        }
    }
    cout << endl << endl;
}
template<typename T>
bool ListaPersonas<T>::isEmpty(){
    NodoPersona<T> *aux = head;
    if(aux == "NULL"){
        return true;
    }
    return false;
}
