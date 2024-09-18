#include <iostream>
#include "ArbolBinarioOrd.h"

int main() {
    ArbolBinarioOrd<int> arbol;

    std::cout << "¿El árbol está vacío? " << (arbol.esVacio() ? "Sí" : "No") << std::endl;

    std::cout << "Insertando 10" << std::endl;
    if (!arbol.insertar(10)) {
        std::cout << "Error al insertar 10" << std::endl;
    }
    std::cout << "Insertando 5" << std::endl;
    if (!arbol.insertar(5)) {
        std::cout << "Error al insertar 5" << std::endl;
    }
    std::cout << "Insertando 20" << std::endl;
    if (!arbol.insertar(20)) {
        std::cout << "Error al insertar 20" << std::endl;
    }
    std::cout << "Insertando 15" << std::endl;
    if (!arbol.insertar(15)) {
        std::cout << "Error al insertar 15" << std::endl;
    }
    if (!arbol.insertar(15)) {
        std::cout << "Error al insertar 15" << std::endl;
    }

    std::cout << "¿El árbol está vacío? " << (arbol.esVacio() ? "Sí" : "No") << std::endl;
    std::cout << "Dato en la raíz: " << arbol.datoRaiz() << std::endl;
    std::cout << "Altura del árbol: " << arbol.altura() << std::endl;
    arbol.preOrden();
    std::cout << std::endl;
    arbol.inOrden();
    std::cout << std::endl;
    arbol.posOrden();
    std::cout << std::endl;
    arbol.nivelOrden();
    std::cout << std::endl;
    

    return 0;
}
