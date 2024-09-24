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
    void search(const T& value);
    void insert(const T& value); 
    void eliminar (const T& value);  
    void inordenEnLista(std::list<T>& lista);
    std::list<T> inOrdenRecursivo(int i);
    int tam();
};

#endif// __MONTICULO_H__
