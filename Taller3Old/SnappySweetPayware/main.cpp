#include <iostream>
#include "ArbolBinarioOrd.h"
#include "ArbolAVL.h"

int main() {

    //Prueba de árbol binario de búsqueda
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
    
    //Prueba de árbol AVL
    ArbolAVL<int> arbol2;

    std::cout << "¿El árbol está vacío? " << (arbol2.esVacio() ? "Sí" : "No") << std::endl;

    std::cout << "Insertando 10" << std::endl;
    arbol2.insertar(10);
    std::cout << "Insertando 20" << std::endl;
    arbol2.insertar(20);
    std::cout << "Insertando 30" << std::endl;
    arbol2.insertar(30);
    std::cout << "Insertando 40" << std::endl;
    arbol2.insertar(40);
    std::cout << "Insertando 50" << std::endl;
    arbol2.insertar(50);
    std::cout << "Insertando 25" << std::endl;
    arbol2.insertar(25);

    std::cout << "¿El árbol está vacío? " << (arbol2.esVacio() ? "Sí" : "No") << std::endl;
    std::cout << "Dato en la raíz: " << arbol2.datoRaiz() << std::endl;
    std::cout << "Altura del árbol: " << arbol2.altura() << std::endl;

    std::cout << "Recorrido en preorden: ";
    arbol2.preOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en inorden: "; //no sirve
    arbol2.inOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en posorden: "; //no sirve
    arbol2.posOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en nivel orden: "; 
    arbol2.nivelOrden();
    std::cout << std::endl;

    std::cout << "Eliminando 40" << std::endl;
    arbol2.eliminar(40);
    std::cout << "Recorrido en inorden después de eliminar 40: "; //no sirve (obviamente)
    arbol2.inOrden();
    std::cout << std::endl;



    return 0;
}
