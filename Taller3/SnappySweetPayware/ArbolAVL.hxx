#include "ArbolBinarioOrd.h"
#include "ArbolAVL.h"

template <class T>
bool ArbolAVL<T>::insertar(T val) {
    this->raiz = insertarRec(this->raiz, val);
    return true;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::insertarRec(NodoBinario<T>* nodo, T val) {
    if (nodo == nullptr) {
        return new NodoBinario<T>(val);
    }

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(insertarRec(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(insertarRec(nodo->obtenerHijoDer(), val));
    } else {
        return nodo; // No se permiten valores duplicados
    }

    return balancear(nodo);
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