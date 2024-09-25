#include "ArbolBinarioOrd.h"
#include <queue>

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
  this->raiz = NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
  if(this->raiz != NULL){
    delete this->raiz;
    this->raiz = NULL;
  }
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio(){
  return this->raiz == NULL;
}

template <class T>
T ArbolBinarioOrd<T>::datoRaiz(){
  return (this->raiz)->obtenerDato();
}

//recursiva
template <class T>
int ArbolBinarioOrd<T>::altura(){
  if(this->esVacio()){
    return -1;
  } else {
    return this->altura(this->raiz);
  }
}

template <class T>
int ArbolBinarioOrd<T>::altura(NodoBinario<T>* nodo){
  int valt;
  if(nodo->esHoja()){
    valt = 0;
  } else {
    int valt_izq = -1;
    int valt_der = -1;
    if(nodo->obtenerHijoIzq() != NULL){
      valt_izq = this->altura(nodo->obtenerHijoIzq());
    }
    if(nodo->obtenerHijoDer() != NULL){
      valt_der = this->altura(nodo->obtenerHijoDer());
    }
    if(valt_izq > valt_der){
      valt = valt_izq + 1;
    } else {
      valt = valt_der + 1;
    }
  }
  return valt;
}

//recusriva
template <class T>
int ArbolBinarioOrd<T>::tamano(){
  if(this->esVacio()){
    return -1;
  } else {
    return this->tamano(this->raiz);
  }
}

template <class T>
int ArbolBinarioOrd<T>::tamano(NodoBinario<T>* nodo){
  int valt;
  if(nodo->esHoja()){
    valt = 1;
  } else {
    int valt_izq = -1;
    int valt_der = -1;
    if(nodo->obtenerHijoIzq() != NULL){
      valt_izq = this->tamano(nodo->obtenerHijoIzq);
    }
    if(nodo->obtenerHijoDer() != NULL){
      valt_der = this->tamano(nodo->obtenerHijoDer());
    }
    valt = valt_izq + valt_der + 1;
    
  }
  return valt;
}

//iterativa
template <class T>
bool ArbolBinarioOrd<T>::insertar(T val){
  if (this->raiz == nullptr) {  // Verificamos si la raíz es nula
      NodoBinario<T>* nuevo = new NodoBinario<T>(val);
      this->raiz = nuevo;
      return true;
  }
  NodoBinario<T>* nodo = this->raiz;
  NodoBinario<T>* padre = this->raiz;
  bool insertado = false;
  bool duplicado = false;
  
  while(nodo != NULL){
    padre = nodo;
    if(val < nodo->obtenerDato()){
      nodo = nodo->obtenerHijoIzq();
    } else if(val > nodo->obtenerDato()){
      nodo = nodo->obtenerHijoDer();
    } else {
      duplicado = true;
      break;
    }
  }
  if(!duplicado){
    NodoBinario<T>* nuevo = new NodoBinario<T>(val);
    if(nuevo != NULL){
      if(val < padre->obtenerDato()){
        padre->fijarHijoIzq(nuevo);
      } else {
        padre->fijarHijoDer(nuevo);
      }
    }
    insertado = true;
  }
  return insertado;
}

//iterativa
template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val){
  //comparar con dato en nodo para bajar por izq o der
  //saber si val esta en el arbol
    bool eliminado = false;
    bool encontrado = false;
  if(!this->esVacio()){
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = this->raiz;
    
    while(nodo != NULL && !encontrado){
      padre = nodo;
      if(val < nodo->obtenerDato()){
        nodo = nodo->obtenerHijoIzq();
      } else {
        nodo = nodo->obtenerHijoDer();
      }
      if(val == nodo->obtenerDato()){
        encontrado = true;
      }
      
    }
    if(encontrado){
      //caso 1: nodo hoja
      if(nodo->esHoja()){
        if(nodo == this->raiz){
          this->raiz = NULL;
        } else {
          if(nodo == padre->obtenerHijoIzq()){
            padre->fijarHijoIzq(NULL);
          } else {
            padre->fijarHijoDer(NULL);
          }
        }
        delete nodo;
        nodo = NULL;
        eliminado = true;
      } 
      //caso 2: nodo con un hijo
      else if(nodo->obtenerHijoIzq() != NULL && nodo->obtenerHijoDer() == NULL) {
        if(nodo == this->raiz){
          this->raiz = nodo->obtenerHijoIzq();
        } else {
          if(nodo == padre->obtenerHijoIzq()){
            padre->fijarHijoIzq(nodo->obtenerHijoIzq());
          }
        }
        delete nodo;
        nodo = NULL;
        eliminado = true;
      } else if(nodo->obtenerHijoIzq() == NULL && nodo->obtenerHijoDer() != NULL){
        if(nodo == this->raiz){
          this->raiz = nodo->obtenerHijoDer();
        } else if(nodo == padre->obtenerHijoIzq()){
          padre->fijarHijoIzq(nodo->obtenerHijoDer());
        } else {
          padre->fijarHijoDer(nodo->obtenerHijoDer());
        }
        delete nodo;
        nodo = NULL;
        eliminado = true;
      }
      //caso 3: nodo con dos hijos
      if(nodo->obtenerHijoIzq() != NULL && nodo->obtenerHijoDer() != NULL){
        NodoBinario<T>* aux = nodo->obtenerHijoIzq();
        while(aux->obtenerHijoDer() != NULL){
          aux = aux->obtenerHijoDer();
           
        } 
        nodo->fijarDato(aux->obtenerDato());
        if(aux == nodo->obtenerHijoIzq()){
          nodo->fijarHijoIzq(NULL);
          
        } 
      }
      }
    } 
  return eliminado;
  //si val esta en el arbol
  //verificar situacion de eliminacion
  //1. nodo hoja borrarlo
  //2. nodo con un solo hijo, usar hijo para reemplazar nodo
  //3. nodo con dos hijos, usar maximo del subarbol izquierdo para reemplazar nodo
}

//iterativa
template <class T>
bool ArbolBinarioOrd<T>::buscar(T val){
  NodoBinario<T>* nodo = this->raiz;
  bool encontrado = false;

  while(nodo != NULL && !encontrado){
    if(val < nodo->obtenerDato()){
      nodo = nodo->obtenerHijoIzq();
    } else if(val > nodo->obtenerDato()){
      nodo = nodo->obtenerHijoDer();
    } else {
      encontrado = true;
    }
  }
  return encontrado;
}

//recursiva
template <class T>
void ArbolBinarioOrd<T>::preOrden(){
  if(!this->esVacio()){
    this->preOrden(this->raiz);
  }
}

template <class T>
void ArbolBinarioOrd<T>::preOrden(NodoBinario<T>* nodo){
  if(nodo != NULL){
    std::cout << nodo->obtenerDato() << " ";
    this->preOrden(nodo->obtenerHijoIzq());
    this->preOrden(nodo->obtenerHijoDer());
  }
}

//recursiva
template <class T>
void ArbolBinarioOrd<T>::inOrden(){
  if(!this->esVacio()){
    this->inOrden(this->raiz);
  }
}

template <class T>
void ArbolBinarioOrd<T>::inOrden(NodoBinario<T>* nodo){
  if(nodo->obtenerHijoIzq() != NULL){
    this->inOrden(nodo->obtenerHijoIzq());
    std::cout << nodo->obtenerDato() << " ";
    this->inOrden(nodo->obtenerHijoDer());
  }
}

//recursiva
template <class T>
void ArbolBinarioOrd<T>::posOrden(){
  if(!this->esVacio()){
    this->posOrden(this->raiz);
  }
}

template <class T>
void ArbolBinarioOrd<T>::posOrden(NodoBinario<T>* nodo){
  if(nodo->obtenerHijoIzq() != NULL){
    this->posOrden(nodo->obtenerHijoIzq());
    this->posOrden(nodo->obtenerHijoDer());
    std::cout << nodo->obtenerDato() << " ";
  }
}


//iterativa
template <class T>
void ArbolBinarioOrd<T>::nivelOrden(){
  if(this->raiz != NULL){
    std::queue<NodoBinario<T>*> cola;
    cola.push(this->raiz);
    NodoBinario<T>* nodo;
    while(!cola.empty()){
      nodo = cola.front();
      cola.pop();
      std::cout << nodo->obtenerDato() << " ";
      if(nodo->obtenerHijoIzq() != NULL){
        cola.push(nodo->obtenerHijoIzq());
      }
      if(nodo->obtenerHijoDer() != NULL){
        cola.push(nodo->obtenerHijoDer());
      }
    }
  }
}