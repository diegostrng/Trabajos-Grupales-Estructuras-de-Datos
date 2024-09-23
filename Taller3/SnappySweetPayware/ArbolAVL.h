#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__

#include "ArbolBinarioOrd.h"

template <class T>
class ArbolAVL : public ArbolBinarioOrd<T> {
public:
    bool insertar(T val);
    bool eliminar(T val);

private:
    NodoBinario<T>* insertarRec(NodoBinario<T>* nodo, T val);
    NodoBinario<T>* eliminarRec(NodoBinario<T>* nodo, T val);
    NodoBinario<T>* minValueNode(NodoBinario<T>* nodo);
    NodoBinario<T>* maxValueNode(NodoBinario<T>* nodo);
    int obtenerAltura(NodoBinario<T>* nodo);
    int obtenerBalance(NodoBinario<T>* nodo);
    NodoBinario<T>* rotarDerecha(NodoBinario<T>* y);
    NodoBinario<T>* rotarIzquierda(NodoBinario<T>* x);
    NodoBinario<T>* balancear(NodoBinario<T>* nodo);
};

#include "ArbolAVL.hxx"

#endif