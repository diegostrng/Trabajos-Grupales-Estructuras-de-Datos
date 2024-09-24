#include "ArbolBinarioOrd.h"
#include "ArbolAVL.h"

template <class T>
bool ArbolAVL<T>::buscar(T val) {
    return buscarRec(this->raiz, val);
}

template <class T>
bool ArbolAVL<T>::buscarRec(NodoBinario<T>* nodo, T val) {
    if (nodo == nullptr) {
        return false;
    }

    if (val < nodo->obtenerDato()) {
        return buscarRec(nodo->obtenerHijoIzq(), val);
    } else if (val > nodo->obtenerDato()) {
        return buscarRec(nodo->obtenerHijoDer(), val);
    } else {
        return true; // Valor encontrado
    }
}

//Funcion de Insertar
template <class T>
NodoBinario<T>* ArbolAVL<T>::insertar(NodoBinario<T>* nodo, T val) {
    // Realizar la inserción normal en el BST
    if (nodo == nullptr) 
        return new NodoBinario<T>(val);

    if (val < nodo->obtenerDato()) 
        nodo->fijarHijoIzq(insertar(nodo->obtenerHijoIzq(), val));
    else if (val > nodo->obtenerDato()) 
        nodo->fijarHijoDer(insertar(nodo->obtenerHijoDer(), val));
    else // No se permiten valores duplicados
        return nodo;

    // Actualizar la altura de este nodo ancestro
    nodo->setAltura(1 + std::max(obtenerAltura(nodo->obtenerHijoIzq()), obtenerAltura(nodo->obtenerHijoDer())));

    // Obtener el factor de balance de este nodo ancestro
    int balance = obtenerBalance(nodo);

    // Si este nodo se vuelve desequilibrado, entonces hay 4 casos

    // Caso Izquierda Izquierda
    if (balance > 1 && val < nodo->obtenerHijoIzq()->obtenerDato()) 
        return rotarDerecha(nodo);

    // Caso Derecha Derecha
    if (balance < -1 && val > nodo->obtenerHijoDer()->obtenerDato()) 
        return rotarIzquierda(nodo);

    // Caso Izquierda Derecha
    if (balance > 1 && val > nodo->obtenerHijoIzq()->obtenerDato()) { 
        nodo->fijarHijoIzq(rotarIzquierda(nodo->obtenerHijoIzq())); 
        return rotarDerecha(nodo); 
    } 

    // Caso Derecha Izquierda
    if (balance < -1 && val < nodo->obtenerHijoDer()->obtenerDato()) { 
        nodo->fijarHijoDer(rotarDerecha(nodo->obtenerHijoDer())); 
        return rotarIzquierda(nodo); 
    } 

    // Retornar el puntero del nodo (sin cambios)
    return nodo; 
}


template <class T>
bool ArbolAVL<T>::eliminar(T val) {
    this->raiz = eliminarRec(this->raiz, val);
    return true;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::eliminarRec(NodoBinario<T>* nodo, T val) {
    if (nodo == nullptr) {
        return nodo;
    }

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(eliminarRec(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(eliminarRec(nodo->obtenerHijoDer(), val));
    } else {
        if ((nodo->obtenerHijoIzq() == nullptr) || (nodo->obtenerHijoDer() == nullptr)) {
            NodoBinario<T>* temp = nodo->obtenerHijoIzq() ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();
            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            } else {
                *nodo = *temp;
            }
            delete temp;
        } else {
            NodoBinario<T>* temp = minValueNode(nodo->obtenerHijoDer());
            nodo->fijarDato(temp->obtenerDato());
            nodo->fijarHijoDer(eliminarRec(nodo->obtenerHijoDer(), temp->obtenerDato()));
        }
    }

    if (nodo == nullptr) {
        return nodo;
    }

    return balancear(nodo);
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::minValueNode(NodoBinario<T>* nodo) {
    NodoBinario<T>* current = nodo;
    while (current->obtenerHijoIzq() != nullptr) {
        current = current->obtenerHijoIzq();
    }
    return current;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::maxValueNode(NodoBinario<T>* nodo) {
    NodoBinario<T>* current = nodo;
    while (current->obtenerHijoDer() != nullptr) {
        current = current->obtenerHijoDer();
    }
    return current;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::balancear(NodoBinario<T>* nodo) {
    int balance = obtenerBalance(nodo);

    if (balance > 1 && obtenerBalance(nodo->obtenerHijoIzq()) >= 0) {
        return rotarDerecha(nodo);
    }

    if (balance > 1 && obtenerBalance(nodo->obtenerHijoIzq()) < 0) {
        nodo->fijarHijoIzq(rotarIzquierda(nodo->obtenerHijoIzq()));
        return rotarDerecha(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->obtenerHijoDer()) <= 0) {
        return rotarIzquierda(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->obtenerHijoDer()) > 0) {
        nodo->fijarHijoDer(rotarDerecha(nodo->obtenerHijoDer()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotarDerecha(NodoBinario<T>* y) {
    NodoBinario<T>* x = y->obtenerHijoIzq();
    NodoBinario<T>* T2 = x->obtenerHijoDer();

    x->fijarHijoDer(y);
    y->fijarHijoIzq(T2);

    return x;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotarIzquierda(NodoBinario<T>* x) {
    NodoBinario<T>* y = x->obtenerHijoDer();
    NodoBinario<T>* T2 = y->obtenerHijoIzq();

    y->fijarHijoIzq(x);
    x->fijarHijoDer(T2);

    return y;
}

template <class T>
int ArbolAVL<T>::obtenerAltura(NodoBinario<T>* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return std::max(obtenerAltura(nodo->obtenerHijoIzq()), obtenerAltura(nodo->obtenerHijoDer())) + 1;
}

template <class T>
int ArbolAVL<T>::obtenerBalance(NodoBinario<T>* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return obtenerAltura(nodo->obtenerHijoIzq()) - obtenerAltura(nodo->obtenerHijoDer());
}