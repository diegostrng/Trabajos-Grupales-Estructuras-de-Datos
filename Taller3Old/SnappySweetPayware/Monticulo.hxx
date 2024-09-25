#include <iostream>
#include <algorithm>
#include <deque>
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
void Monticulo<T>::search(const T& value){
 for(int i=0; i<datos.size(); i++){
    if (datos[i]==value){
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
}

template <typename T>
void Monticulo<T>::eliminar(const T& value){
    
}

template <typename T>
void inOrdenRecursivo(const std::deque<T>& datos, std::deque<T>& resultado, int i) {
    if (i>=datos.size()) return;  
    inOrdenRecursivo(datos, resultado, 2*i+1); 
    resultado.push_back(datos[i]);                
    inOrdenRecursivo(datos, resultado, 2*i+2); 
}

template <typename T>
void preOrdenRecursivo(const std::deque<T>& datos, std::deque<T>& resultado, int i) {
    if (i>=datos.size()) return;
    resultado.push_back(datos[i]);                  
    preOrdenRecursivo(datos, resultado, 2*i+1);  
    preOrdenRecursivo(datos, resultado, 2*i+2);  
}

template <typename T>
void posOrdenRecursivo(const std::deque<T>& datos, std::deque<T>& resultado, int i) {
    if (i>=datos.size()) return;
    posOrdenRecursivo(datos, resultado,2*i+1);  
    posOrdenRecursivo(datos, resultado,2*i+2);  
    resultado.push_back(datos[i]);                 
}

template <typename T>
std::deque<T> Monticulo<T>::inOrden() {
    std::deque<T> resultado;
    inOrdenRecursivo(datos, resultado, 0);  // Llamar a la función recursiva empezando en la raíz (índice 0)
    return resultado;
}

template <typename T>
std::deque<T> Monticulo<T>::preOrden() {
    std::deque<T> resultado;
    preOrdenRecursivo(datos, resultado, 0);  // Empezar en la raíz (índice 0)
    return resultado;
}

template <typename T>
std::deque<T> Monticulo<T>::posOrden() {
    std::deque<T> resultado;
    posOrdenRecursivo(datos, resultado, 0);  // Empezar en la raíz (índice 0)
    return resultado;
}

template <typename T>
std::deque<T> Monticulo<T>:: niveles (){
  return datos;
}             
