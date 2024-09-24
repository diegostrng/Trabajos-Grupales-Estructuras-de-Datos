#include "ArbolBinarioOrd.h"
#include "ArbolAVL.h"

//Buscar
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
NodoBinario<T>* ArbolAVL<T>::eliminar(NodoBinario<T>* nodo, T val) {
    // Paso 1: Realizar la eliminación estándar en el BST
    if (nodo == nullptr)
        return nodo;

    // Si el valor a eliminar es menor que el valor del nodo, se encuentra en el subárbol izquierdo
    if (val < nodo->obtenerDato())
        nodo->fijarHijoIzq(eliminar(nodo->obtenerHijoIzq(), val));

    // Si el valor a eliminar es mayor que el valor del nodo, se encuentra en el subárbol derecho
    else if (val > nodo->obtenerDato())
        nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), val));

    // Si el valor es igual al valor del nodo, este es el nodo a eliminar
    else {
        // Nodo con un solo hijo o sin hijos
        if ((nodo->obtenerHijoIzq() == nullptr) || (nodo->obtenerHijoDer() == nullptr)) {
            NodoBinario<T>* temp = nodo->obtenerHijoIzq() ? 
                                   nodo->obtenerHijoIzq() : 
                                   nodo->obtenerHijoDer();

            // Caso sin hijos
            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            } else // Caso con un solo hijo
                *nodo = *temp; // Copiar el contenido del hijo no vacío
            delete temp;
        } else {
            // Nodo con dos hijos: obtener el sucesor en orden (el más pequeño en el subárbol derecho)
            NodoBinario<T>* temp = minValueNode(nodo->obtenerHijoDer());

            // Copiar los datos del sucesor en orden a este nodo
            nodo->setDato(temp->obtenerDato());

            // Eliminar el sucesor en orden
            nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), temp->obtenerDato()));
        }
    }

    // Si el árbol tenía solo un nodo, retornar
    if (nodo == nullptr)
        return nodo;

    // Paso 2: Actualizar la altura del nodo actual
    nodo->setAltura(1 + std::max(obtenerAltura(nodo->obtenerHijoIzq()), obtenerAltura(nodo->obtenerHijoDer())));

    // Paso 3: Obtener el factor de balance de este nodo (para verificar si este nodo se volvió desequilibrado)
    int balance = obtenerBalance(nodo);

    // Si este nodo se vuelve desequilibrado, entonces hay 4 casos

    // Caso Izquierda Izquierda
    if (balance > 1 && obtenerBalance(nodo->obtenerHijoIzq()) >= 0)
        return rotarDerecha(nodo);

    // Caso Izquierda Derecha
    if (balance > 1 && obtenerBalance(nodo->obtenerHijoIzq()) < 0) {
        nodo->fijarHijoIzq(rotarIzquierda(nodo->obtenerHijoIzq()));
        return rotarDerecha(nodo);
    }

    // Caso Derecha Derecha
    if (balance < -1 && obtenerBalance(nodo->obtenerHijoDer()) <= 0)
        return rotarIzquierda(nodo);

    // Caso Derecha Izquierda
    if (balance < -1 && obtenerBalance(nodo->obtenerHijoDer()) > 0) {
        nodo->fijarHijoDer(rotarDerecha(nodo->obtenerHijoDer()));
        return rotarIzquierda(nodo);
    }

    return nodo;
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