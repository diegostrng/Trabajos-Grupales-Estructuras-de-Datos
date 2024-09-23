#include <iostream>
#include "ArbolAVL.h"

int main() {
    ArbolAVL<int> arbol;

    std::cout << "¿El árbol está vacío? " << (arbol.esVacio() ? "Sí" : "No") << std::endl;

    std::cout << "Insertando 10" << std::endl;
    arbol.insertar(10);
    std::cout << "Insertando 20" << std::endl;
    arbol.insertar(20);
    std::cout << "Insertando 30" << std::endl;
    arbol.insertar(30);
    std::cout << "Insertando 40" << std::endl;
    arbol.insertar(40);
    std::cout << "Insertando 50" << std::endl;
    arbol.insertar(50);
    std::cout << "Insertando 25" << std::endl;
    arbol.insertar(25);
    arbol.insertar(35);

    std::cout << "¿El árbol está vacío? " << (arbol.esVacio() ? "Sí" : "No") << std::endl;
    std::cout << "Dato en la raíz: " << arbol.datoRaiz() << std::endl;
    std::cout << "Altura del árbol: " << arbol.altura() << std::endl;

    std::cout << "Recorrido en preorden: ";
    arbol.preOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en inorden: "; //no sirve
    arbol.inOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en posorden: "; //no sirve
    arbol.posOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en nivel orden: "; 
    arbol.nivelOrden();
    std::cout << std::endl;

    std::cout << "Eliminando 40" << std::endl;
    arbol.eliminar(40);
    std::cout << "Recorrido en inorden después de eliminar 40: "; //no sirve (obviamente)
    arbol.inOrden();
    std::cout << std::endl;

    return 0;
}