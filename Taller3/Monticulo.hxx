#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include "Monticulo.h"

template <typename T>
Monticulo<T>::Monticulo() {
  //Constructr
}

template <typename T>
Monticulo<T>::~Monticulo() {
    // Destructor
}

template <typename T>
void Monticulo<T>::search(std::string id){
 for(int i=0; i<datos.size(); i++){
    if (datos[i].getID()==id){
       std::cout<<"El valor se encuentra en la posición: "<<i<<std::endl;
       return;
    }
 }
 std::cout<<"No se encontro el valor"<<std::endl;
}

template <typename T>
void Monticulo<T>::insert(const T& value){
  datos.push_back(value);            
  std::push_heap(datos.begin(), datos.end());
  std::make_heap(datos.begin(), datos.end());
}

template <typename T>
void Monticulo<T>::eliminar (std::string id){
    for(int i=0; i<datos.size(); i++){
        if (datos[i].getID()==id){
        datos.erase(datos.begin() + i); 
            std::make_heap(datos.begin(), datos.end());
            return;
        }
    }
    std::cout<<"No se encontro el valor"<<std::endl;
}

template <typename T>
std::list<T> Monticulo<T>::inOrdenRecursivo(int i) {
    std::list<T> aux;
    if (i < datos.size()) {
        std::list<T> izquierda = inOrdenRecursivo(2*i+1); 
        aux.insert(aux.end(), izquierda.begin(), izquierda.end());  
        aux.push_back(datos[i]);       
        std::list<T> derecha = inOrdenRecursivo(2*i+2); 
        aux.insert(aux.end(), derecha.begin(), derecha.end());  
    }
    return aux;  
}


template <typename T>
void Monticulo<T>::inordenEnLista(std::list<T>& lista) {
    lista = inOrdenRecursivo(0);  
}

template <typename T>
int Monticulo<T>::tam(){
    return datos.size();
}