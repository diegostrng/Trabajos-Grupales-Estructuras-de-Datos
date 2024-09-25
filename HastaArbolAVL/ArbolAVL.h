#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__

#include "ArbolBinarioOrd.h"

template <class T>
class arbolAVL : public ArbolBinarioOrd<T> {
public:

    //Pongo en publico para poder utilizar estos metodos que se nos piden en el taller

    void insertar(T val) {
        this->raiz = insertar(this->raiz, val);
    }

    void eliminar(T val) {
        this->raiz = eliminar(this->raiz, val);
    }

    void buscar(T val);

private:
    NodoBinario<T>* insertar(NodoBinario<T>* nodo, T val);
    NodoBinario<T>* eliminar(NodoBinario<T>* nodo, T val);
    NodoBinario<T>* minValueNode(NodoBinario<T>* nodo);
    NodoBinario<T>* maxValueNode(NodoBinario<T>* nodo);
    int obtenerAltura(NodoBinario<T>* nodo);
    int obtenerBalance(NodoBinario<T>* nodo);
    NodoBinario<T>* rotarDerecha(NodoBinario<T>* y);
    NodoBinario<T>* rotarIzquierda(NodoBinario<T>* x);
    NodoBinario<T>* balancear(NodoBinario<T>* nodo);
    bool buscarRec(NodoBinario<T>* nodo, T val);
    
};

#include "ArbolAVL.hxx"

#endif
