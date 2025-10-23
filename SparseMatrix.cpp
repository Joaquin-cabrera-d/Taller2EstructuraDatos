#include "SparseMatrix.h"
#include <iostream>
#include <chrono>

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
    auto t0 = std::chrono::high_resolution_clock::now();

    Nodo* cursor = start;
    while (cursor) {
        if (cursor->x == X && cursor->y == Y) return cursor->value;
        cursor = cursor->right;
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;

    return 0;
}

int SparseMatrix::remover(int X, int Y) {
    auto t0 = std::chrono::high_resolution_clock::now();
    Nodo* cursor = start;
    Nodo* prev = nullptr;
    while (cursor != nullptr) {
        if (cursor->x == X && cursor->y == Y) {
            if (prev) prev->right = cursor->right;
            else start = cursor->right;
            delete cursor;
            return 1;
        }
        prev = cursor;
        cursor = cursor->right;
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
    return 0;
}

void SparseMatrix::printStoredValues() {
    auto t0 = std::chrono::high_resolution_clock::now();
    Nodo* cursor = start;
    while (cursor!=nullptr) {
        std::cout << "(" << cursor->x << "," << cursor->y << ") --> " << cursor->value << std::endl;
        cursor = cursor->right;
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
}

int SparseMatrix::density() {
    auto t0 = std::chrono::high_resolution_clock::now();
    int count = 0, Xtotal = 0, Ytotal = 0;
    Nodo* cursor = start;
    while (cursor) {
        count++;
        if (cursor->x > Xtotal) Xtotal = cursor->x;
        if (cursor->y > Ytotal) Ytotal = cursor->y;
        cursor = cursor->right;
    }
    if (Xtotal == 0 || Ytotal == 0) return 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
    return (count * 100) / (Xtotal * Ytotal);
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second) {
    auto t0 = std::chrono::high_resolution_clock::now();
    //codigo aca

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
    return nullptr;
}

SparseMatrix::~SparseMatrix() {
    auto t0 = std::chrono::high_resolution_clock::now();
    Nodo* cursor = start;
    while (cursor) {
        Nodo* next = cursor->right;
        delete cursor;
        cursor = next;
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
}
