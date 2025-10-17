#pragma once
#include "Nodo.h"
class SparseMatrix {
private:
    Nodo* start;
public:
    SparseMatrix();
    void add(int X, int Y, int valor);
    int get(int X, int Y);
    int remover(int X, int Y);
    void printStoredValues();
    int density();
    SparseMatrix* multiply(SparseMatrix* otraMatriz);
    Nodo* getStart() const;
    ~SparseMatrix();
};
