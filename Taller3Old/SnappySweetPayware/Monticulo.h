#ifndef __MONTICULO_H__
#define __MONTICULO_H__

#include <deque>
#include <algorithm>


template< class T >
class Monticulo{
  private:
    std::deque<T> datos;
  public:
    Monticulo();
    ~Monticulo();
    void search(const T& value);
    void insert(const T& value); 
    void eliminar(const T& value);  
    std::deque<T> inOrden();
    std::deque<T> posOrden();
    std::deque<T> preOrden();
    std::deque<T> niveles();             

};

#endif// __MONTICULO_H__