#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix() : start(nullptr) {}

void SparseMatrix::add(int X, int Y, int value) {
    Nodo* nodo = new Nodo();        // nodo sin argumentos
    nodo->x = X;
    nodo->y = Y;
    nodo->value = value;
    nodo->right = nullptr;
    nodo->down = nullptr;

    if (!start) {
        start = nodo;
        return;
    }
    Nodo* cursor = start;
    while (cursor->right) cursor = cursor->right;
    cursor->right = nodo;
}

int SparseMatrix::get(int X, int Y) {
    Nodo* cursor = start;
    while (cursor) {
        if (cursor->x == X && cursor->y == Y) return cursor->value;
        cursor = cursor->right;
    }
    return 0;
}

int SparseMatrix::remover(int X, int Y) {
    Nodo* cursor = start;
    Nodo* prev = nullptr;
    while (cursor) {
        if (cursor->x == X && cursor->y == Y) {
            if (prev) prev->right = cursor->right;
            else start = cursor->right;
            delete cursor;
            return 1;
        }
        prev = cursor;
        cursor = cursor->right;
    }
    return 0;
}

void SparseMatrix::printStoredValues() {
    Nodo* cursor = start;
    while (cursor) {
        std::cout << "(" << cursor->x << "," << cursor->y << ")=" << cursor->value << std::endl;
        cursor = cursor->right;
    }
}

int SparseMatrix::density() {
    int count = 0, maxX = 0, maxY = 0;
    Nodo* cursor = start;
    while (cursor) {
        count++;
        if (cursor->x > maxX) maxX = cursor->x;
        if (cursor->y > maxY) maxY = cursor->y;
        cursor = cursor->right;
    }
    if (maxX == 0 || maxY == 0) return 0;
    return (count * 100) / (maxX * maxY);
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second) {
    return nullptr;
}

Nodo* SparseMatrix::getStart() const {
    return start;
}

SparseMatrix::~SparseMatrix() {
    Nodo* cursor = start;
    while (cursor) {
        Nodo* next = cursor->right;
        delete cursor;
        cursor = next;
    }
}
