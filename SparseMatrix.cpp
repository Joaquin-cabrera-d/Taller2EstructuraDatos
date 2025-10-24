#include "SparseMatrix.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

SparseMatrix::SparseMatrix() : filaHeads(), colHeads() {}
SparseMatrix::SparseMatrix(const SparseMatrix& other) : SparseMatrix() {
    for (const auto& p : other.filaHeads) {
        Nodo* cursor = p.second;
        while (cursor) {
            addInternal(cursor->x, cursor->y, cursor->valor);
            cursor = cursor->right;
        }
    }
}
void SparseMatrix::addInternal(int X, int Y, int valor) {
    if (valor == 0) return;
    auto iterarFila = filaHeads.find(X);
    if (iterarFila != filaHeads.end() && iterarFila->second != nullptr) {
        Nodo* prev = nullptr;
        Nodo* cursor = iterarFila->second;
        while (cursor && cursor->y < Y) {
            prev = cursor;
            cursor = cursor->right;
        }
        if (cursor && cursor->y == Y) {
            cursor->valor = valor;
            return;
        }
    }

    Nodo* nodo = new Nodo(valor, X, Y);
    nodo->right = nullptr;
    nodo->down = nullptr;

    if (iterarFila == filaHeads.end() || iterarFila->second == nullptr) {
        filaHeads[X] = nodo;
    }
    else {
        Nodo* prev = nullptr;
        Nodo* cursor = filaHeads[X];
        if (cursor->y > Y) {
            nodo->right = cursor;
            filaHeads[X] = nodo;
        }
        else {
            while (cursor && cursor->y < Y) {
                prev = cursor;
                cursor = cursor->right;
            }
            prev->right = nodo;
            nodo->right = cursor;
        }
    }
    auto iterarCol = colHeads.find(Y);
    if (iterarCol == colHeads.end() || iterarCol->second == nullptr) {
        colHeads[Y] = nodo;
    }
    else {
        Nodo* prev = nullptr;
        Nodo* cursor = colHeads[Y];
        if (cursor->x > X) {
            nodo->down = cursor;
            colHeads[Y] = nodo;
        }
        else {
            while (cursor && cursor->x < X) {
                prev = cursor;
                cursor = cursor->down;
            }
            prev->down = nodo;
            nodo->down = cursor;
        }
    }
}

SparseMatrix& SparseMatrix::operator=(const SparseMatrix& other) {
    if (this == &other) {
        return *this;
    }
    for (auto& p : filaHeads) {
        Nodo* cursor = p.second;
        while (cursor) {
            Nodo* next = cursor->right;
            delete cursor;
            cursor = next;
        }
    }
    filaHeads.clear();
    colHeads.clear();
    for (const auto& p : other.filaHeads) {
        Nodo* cursor = p.second;
        while (cursor) {
            addInternal(cursor->x, cursor->y, cursor->valor);
            cursor = cursor->right;
        }
    }
    return *this;
}

void SparseMatrix::add(int X, int Y, int valor) {
    auto t0 = std::chrono::high_resolution_clock::now();
    if (valor == 0) return;
    addInternal(X, Y, valor);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
}
void SparseMatrix::addRandom(int X, int Y, int valor) {
    if (valor == 0) return;
	addInternal(X, Y, valor);
}

int SparseMatrix::get(int X, int Y) {
    auto t0 = std::chrono::high_resolution_clock::now();

    auto iterarFila = filaHeads.find(X);
    if (iterarFila == filaHeads.end() || iterarFila->second == nullptr) {
        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = t1 - t0;
        std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
        return 0;
    }
    Nodo* cursor = iterarFila->second;
    while (cursor && cursor->y <= Y) {
        if (cursor->y == Y) {
            auto t1 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsed = t1 - t0;
            std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
            return cursor->valor;
        }
        cursor = cursor->right;
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
    return 0;
}

int SparseMatrix::remover(int X, int Y) {
    auto t0 = std::chrono::high_resolution_clock::now();

    auto iterarFila = filaHeads.find(X);
    if (iterarFila == filaHeads.end() || iterarFila->second == nullptr) {
        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = t1 - t0;
        std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
        return 0;
    }
    Nodo* cursorFila = iterarFila->second;
    while (cursorFila && cursorFila->y < Y) {
        cursorFila = cursorFila->right;
    }
    if (!cursorFila || cursorFila->y != Y) {
        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = t1 - t0;
        std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
        return 0;
    }
    cursorFila->valor = 0;

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
    return 1;
}

void SparseMatrix::printStoredValues() {
    auto t0 = std::chrono::high_resolution_clock::now();

    if (filaHeads.empty()) {
        std::cout << "La matriz esta vacia" << std::endl;
        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = t1 - t0;
        std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
        return;
    }

    std::vector<int> filas;
    filas.reserve(filaHeads.size());
    for (const auto& p : filaHeads) filas.push_back(p.first);
    std::sort(filas.begin(), filas.end());

    for (int r : filas) {
        Nodo* cursor = filaHeads[r];
        while (cursor) {
            if (cursor->valor != 0)
                std::cout << "(" << cursor->x << "," << cursor->y << ") --> " << cursor->valor << std::endl;
            cursor = cursor->right;
        }
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
}

int SparseMatrix::density() {
    auto t0 = std::chrono::high_resolution_clock::now();
    int count = 0;
    int maxX = 0, maxY = 0;
    for (const auto& p : filaHeads) {
        Nodo* cursor = p.second;
        while (cursor) {
            if (cursor->valor != 0) {
                ++count;
                if (cursor->x > maxX) maxX = cursor->x;
                if (cursor->y > maxY) maxY = cursor->y;
            }
            cursor = cursor->right;
        }
    }
    if (maxX == 0 || maxY == 0) return 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
    return (count*100) / (maxX * maxY);
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second) {
    auto t0 = std::chrono::high_resolution_clock::now();

    std::unordered_map<int, std::vector<std::pair<int, int>>> filasA;
    std::unordered_map<int, std::vector<std::pair<int, int>>> filasB;

    for (const auto& p : filaHeads) {
        int i = p.first;
        Nodo* cursor = p.second;
        while (cursor) {
            if (cursor->valor != 0) filasA[i].push_back({ cursor->y, cursor->valor }); // (k, aval)
            cursor = cursor->right;
        }
    }

    for (const auto& p : second->filaHeads) {
        int i = p.first;
        Nodo* cursor = p.second;
        while (cursor) {
            if (cursor->valor != 0) filasB[i].push_back({ cursor->y, cursor->valor }); // (j, bval) stored under Fila k
            cursor = cursor->right;
        }
    }

    std::unordered_map<int, std::unordered_map<int, long long>> result;

    for (const auto& filaA : filasA) {
        int i = filaA.first;
        for (const auto& ak : filaA.second) {
            int k = ak.first;
            int valorA = ak.second;
            auto iterarB = filasB.find(k);
            if (iterarB == filasB.end()) continue;
            for (const auto& bj : iterarB->second) {
                int j = bj.first;
                int valorB = bj.second;
                result[i][j] += static_cast<long long>(valorA) * static_cast<long long>(valorB);
            }
        }
    }

    SparseMatrix* res = new SparseMatrix();
    for (const auto& FilaPair : result) {
        int i = FilaPair.first;
        for (const auto& colPair : FilaPair.second) {
            int j = colPair.first;
            long long val = colPair.second;
            if (val != 0) res->add(i, j, static_cast<int>(val));
        }
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t1 - t0;
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " ms" << std::endl;
    return res;
}
std::pair<int, int> SparseMatrix::getDimensions() const {
    int maxX = 0, maxY = 0;
    for (const auto& p : filaHeads) {
        Nodo* cursor = p.second;
        while (cursor) {
            if (cursor->x > maxX) maxX = cursor->x;
            if (cursor->y > maxY) maxY = cursor->y;
            cursor = cursor->right;
        }
    }
    return { maxX, maxY };
}

Nodo* SparseMatrix::getStart() const {
    if (filaHeads.empty()) return nullptr;
    int minFila = INT_MAX;
    for (const auto& p : filaHeads) if (p.first < minFila) minFila = p.first;
    auto it = filaHeads.find(minFila);
    if (it == filaHeads.end()) return nullptr;
    return it->second;
}

SparseMatrix::~SparseMatrix() {
    for (auto& p : filaHeads) {
        Nodo* cursor = p.second;
        while (cursor) {
            Nodo* next = cursor->right;
            delete cursor;
            cursor = next;
        }
        p.second = nullptr;
    }
    filaHeads.clear();
    colHeads.clear();
}
