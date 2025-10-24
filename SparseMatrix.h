#pragma once
#include "Nodo.h"
#include <unordered_map>

class SparseMatrix {
private:
    std::unordered_map<int, Nodo*> filaHeads;
    std::unordered_map<int, Nodo*> colHeads;
public:
    SparseMatrix();
    void add(int X, int Y, int valor);
    int get(int X, int Y);
    int remover(int X, int Y);
    void printStoredValues();
    int density();
    SparseMatrix* multiply(SparseMatrix* otraMatriz);
    std::pair<int, int> getDimensions() const;
    Nodo* getStart() const;
    ~SparseMatrix();
};
