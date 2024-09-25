#ifndef __MONTICULO_H__
#define __MONTICULO_H__

#include <deque>
#include <algorithm>
#include <list>

template< class T >
class Monticulo{
  private:
    std::deque<T> datos;
  public:
    Monticulo();
    ~Monticulo();
    void search(std::string id);
    void insert(const T& value); 
    void eliminar (std::string id);  
    void inordenEnLista(std::list<T>& lista);
    std::list<T> inOrdenRecursivo(int i);
    int tam();
};

#include "Monticulo.hxx"

#endif// __MONTICULO_H__