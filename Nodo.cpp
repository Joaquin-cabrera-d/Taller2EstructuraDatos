#include "Nodo.h"
struct Nodo {
    int x;
    int y;
    int dato;           // Valor del nodo (puede ser cualquier tipo)
    Nodo* derecha;      // Puntero al siguiente nodo en la fila
    Nodo* abajo;        // Puntero al nodo en la columna inferior

    Nodo() {
        dato = 0;
		derecha = nullptr; 
		abajo = nullptr;
    }
    Nodo(int valor) {
        dato = valor;
        derecha = nullptr;
        abajo = nullptr;
    }
};
